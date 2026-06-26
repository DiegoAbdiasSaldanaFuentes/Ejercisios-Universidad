#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define ROTL(a, b) (((a) << (b)) | ((a) >> (32 - (b))))

#define QUARTER_ROUND(a, b, c, d) ( \
    a += b, d ^= a, d = ROTL(d, 16), \
    c += d, b ^= c, b = ROTL(b, 12), \
    a += b, d ^= a, d = ROTL(d, 8),  \
    c += d, b ^= c, b = ROTL(b, 7)   \
)

void chacha20_block_offset(uint32_t *base_state, uint32_t block_offset, uint8_t *keystream) {
    uint32_t state[16];
    memcpy(state, base_state, 64);
    state[12] += block_offset; // El hilo calcula su propio bloque para no colisionar

    uint32_t working_state[16];
    int i;
    for (i = 0; i < 16; i++) working_state[i] = state[i];

    for (i = 0; i < 10; i++) {
        QUARTER_ROUND(working_state[0], working_state[4], working_state[8],  working_state[12]);
        QUARTER_ROUND(working_state[1], working_state[5], working_state[9],  working_state[13]);
        QUARTER_ROUND(working_state[2], working_state[6], working_state[10], working_state[14]);
        QUARTER_ROUND(working_state[3], working_state[7], working_state[11], working_state[15]);
        
        QUARTER_ROUND(working_state[0], working_state[5], working_state[10], working_state[15]);
        QUARTER_ROUND(working_state[1], working_state[6], working_state[11], working_state[12]);
        QUARTER_ROUND(working_state[2], working_state[7], working_state[8],  working_state[13]);
        QUARTER_ROUND(working_state[3], working_state[4], working_state[9],  working_state[14]);
    }

    for (i = 0; i < 16; i++) {
        uint32_t val = working_state[i] + state[i];
        keystream[(i * 4) + 0] = (val >> 0)  & 0xFF;
        keystream[(i * 4) + 1] = (val >> 8)  & 0xFF;
        keystream[(i * 4) + 2] = (val >> 16) & 0xFF;
        keystream[(i * 4) + 3] = (val >> 24) & 0xFF;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;
    omp_set_num_threads(atoi(argv[2]));

    uint32_t state[16] = {
        0x61707865, 0x3320646e, 0x79622d32, 0x6b206574,
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
        0x00000000, 0x09, 0x0A, 0x0B
    };

    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");
    if (!fin || !fout) return 1;

    fseek(fin, 0, SEEK_END);
    long size = ftell(fin);
    rewind(fin);

    uint8_t *buffer = malloc(size);
    fread(buffer, 1, size, fin);

    long num_blocks = (size + 63) / 64;

    // ZONA CRITICA PARALELIZADA
    #pragma omp parallel for
    for (long b = 0; b < num_blocks; b++) {
        uint8_t keystream[64];
        chacha20_block_offset(state, b, keystream);
        
        long offset = b * 64;
        long bytes_to_xor = (size - offset < 64) ? (size - offset) : 64;
        
        for (long i = 0; i < bytes_to_xor; i++) {
            buffer[offset + i] ^= keystream[i];
        }
    }

    fwrite(buffer, 1, size, fout);

    fclose(fin); fclose(fout);
    free(buffer);
    return 0;
}
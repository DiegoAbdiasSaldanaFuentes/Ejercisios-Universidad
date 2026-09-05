#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ROTL(a, b) (((a) << (b)) | ((a) >> (32 - (b))))

#define QUARTER_ROUND(a, b, c, d) ( \
    a += b, d ^= a, d = ROTL(d, 16), \
    c += d, b ^= c, b = ROTL(b, 12), \
    a += b, d ^= a, d = ROTL(d, 8),  \
    c += d, b ^= c, b = ROTL(b, 7)   \
)

void chacha20_block(uint32_t *state, uint8_t *keystream) {
    uint32_t working_state[16];
    int i;
    for (i = 0; i < 16; i++) *(working_state + i) = *(state + i);

    for (i = 0; i < 10; i++) {
        QUARTER_ROUND(*(working_state + 0), *(working_state + 4), *(working_state + 8),  *(working_state + 12));
        QUARTER_ROUND(*(working_state + 1), *(working_state + 5), *(working_state + 9),  *(working_state + 13));
        QUARTER_ROUND(*(working_state + 2), *(working_state + 6), *(working_state + 10), *(working_state + 14));
        QUARTER_ROUND(*(working_state + 3), *(working_state + 7), *(working_state + 11), *(working_state + 15));
        
        QUARTER_ROUND(*(working_state + 0), *(working_state + 5), *(working_state + 10), *(working_state + 15));
        QUARTER_ROUND(*(working_state + 1), *(working_state + 6), *(working_state + 11), *(working_state + 12));
        QUARTER_ROUND(*(working_state + 2), *(working_state + 7), *(working_state + 8),  *(working_state + 13));
        QUARTER_ROUND(*(working_state + 3), *(working_state + 4), *(working_state + 9),  *(working_state + 14));
    }

    for (i = 0; i < 16; i++) {
        uint32_t val = *(working_state + i) + *(state + i);
        *(keystream + (i * 4) + 0) = (val >> 0)  & 0xFF;
        *(keystream + (i * 4) + 1) = (val >> 8)  & 0xFF;
        *(keystream + (i * 4) + 2) = (val >> 16) & 0xFF;
        *(keystream + (i * 4) + 3) = (val >> 24) & 0xFF;
    }
    (*(state + 12))++;
}

int main(int argc, char* argv[]) {
    if (argc < 4) return 1;

    char* clave_str = argv[3];

    uint32_t state[16] = {
        0x61707865, 0x3320646e, 0x79622d32, 0x6b206574, 
        0, 0, 0, 0, 0, 0, 0, 0, 
        0x00000001, 0x09, 0x0A, 0x0B                                
    };

    uint8_t key_bytes[32] = {0};
    for(int i = 0; i < 32 && clave_str[i] != '\0'; i++) {
        key_bytes[i] = clave_str[i];
    }
    
    // Mover los 32 bytes a los 8 bloques de 32 bits del State
    for(int i = 0; i < 8; i++) {
        state[4+i] = (key_bytes[i*4]) | (key_bytes[i*4+1]<<8) | (key_bytes[i*4+2]<<16) | (key_bytes[i*4+3]<<24);
    }

    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    if (!fin || !fout) return 1;

    uint8_t buffer[64];
    uint8_t keystream[64];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, 64, fin)) > 0) {
        chacha20_block(state, keystream);
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= keystream[i];
        }
        fwrite(buffer, 1, bytes_read, fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
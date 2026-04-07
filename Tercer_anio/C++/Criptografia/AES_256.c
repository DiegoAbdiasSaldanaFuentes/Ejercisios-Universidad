#include <stdio.h>      // Manejo de archivos (fopen, fread, fwrite)
#include <stdlib.h>     // Memoria dinÃ¡mica (malloc, free)
#include <stdint.h>     // Tipos exactos (uint8_t)
#include <string.h>     // memcpy, memset

// ParÃ¡metros de AES
#define Nb 4   // NÃºmero de columnas del estado (siempre 4 en AES)
#define Nk 8   // NÃºmero de palabras de la clave (AES-256 = 8)
#define Nr 14  // NÃºmero de rondas (AES-256 = 14)

// S-Box: tabla de sustituciÃ³n usada en SubBytes
uint8_t sbox[256] = {
    // âš ï¸ Mantener tu S-Box original aquÃ­
};

// ==================== FUNCIONES AES ====================

// ðŸ” SubBytes
// Sustituye cada byte del estado usando la S-Box
void sub_bytes(uint8_t *state) {
    for (int i = 0; i < 16; i++) {
        *(state + i) = sbox[*(state + i)];
    }
}

// ðŸ”„ ShiftRows
// Desplaza filas de la matriz de estado
void shift_rows(uint8_t *state) {
    uint8_t temp;

    // Fila 1 (shift de 1)
    temp = *(state + 1);
    *(state + 1) = *(state + 5);
    *(state + 5) = *(state + 9);
    *(state + 9) = *(state + 13);
    *(state + 13) = temp;

    // Fila 2 (shift de 2)
    temp = *(state + 2);
    *(state + 2) = *(state + 10);
    *(state + 10) = temp;

    temp = *(state + 6);
    *(state + 6) = *(state + 14);
    *(state + 14) = temp;

    // Fila 3 (shift de 3)
    temp = *(state + 3);
    *(state + 3) = *(state + 15);
    *(state + 15) = *(state + 11);
    *(state + 11) = *(state + 7);
    *(state + 7) = temp;
}

// ðŸ”¢ MultiplicaciÃ³n en GF(2^8)
// Usada en MixColumns
uint8_t gmul(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    for (int i = 0; i < 8; i++) {
        if (b & 1)
            p ^= a;

        uint8_t hi = a & 0x80;
        a <<= 1;

        if (hi)
            a ^= 0x1b;

        b >>= 1;
    }
    return p;
}

// ðŸ”€ MixColumns
// Mezcla cada columna usando operaciones en GF(2^8)
void mix_columns(uint8_t *state) {
    uint8_t tmp[16];
    memcpy(tmp, state, 16);

    for (int i = 0; i < 4; i++) {
        int col = i * 4;

        *(state + col) =
            gmul(*(tmp + col), 2) ^
            gmul(*(tmp + col + 1), 3) ^
            *(tmp + col + 2) ^
            *(tmp + col + 3);

        *(state + col + 1) =
            *(tmp + col) ^
            gmul(*(tmp + col + 1), 2) ^
            gmul(*(tmp + col + 2), 3) ^
            *(tmp + col + 3);

        *(state + col + 2) =
            *(tmp + col) ^
            *(tmp + col + 1) ^
            gmul(*(tmp + col + 2), 2) ^
            gmul(*(tmp + col + 3), 3);

        *(state + col + 3) =
            gmul(*(tmp + col), 3) ^
            *(tmp + col + 1) ^
            *(tmp + col + 2) ^
            gmul(*(tmp + col + 3), 2);
    }
}

// âž• AddRoundKey
// Aplica XOR entre el estado y la clave de ronda
void add_round_key(uint8_t *state, uint8_t *roundKey) {
    for (int i = 0; i < 16; i++) {
        *(state + i) ^= *(roundKey + i);
    }
}

// ðŸ” Cifrado de un bloque de 16 bytes
void aes_encrypt_block(uint8_t *input, uint8_t *output, uint8_t *roundKeys) {
    uint8_t state[16];

    // Copiar entrada al estado
    memcpy(state, input, 16);

    // Ronda inicial
    add_round_key(state, roundKeys);

    // Rondas principales
    for (int round = 1; round < Nr; round++) {
        sub_bytes(state);
        shift_rows(state);
        mix_columns(state);
        add_round_key(state, roundKeys + round * 16);
    }

    // Ronda final (sin MixColumns)
    sub_bytes(state);
    shift_rows(state);
    add_round_key(state, roundKeys + Nr * 16);

    // Copiar resultado al output
    memcpy(output, state, 16);
}

// ==================== MAIN ====================

int main() {

    // Abrir archivos
    FILE *in = fopen("input.bin", "rb");
    FILE *out = fopen("output.enc", "wb");

    if (!in || !out) {
        printf("Error al abrir archivos\n");
        return 1;
    }

    // Obtener tamaÃ±o del archivo
    fseek(in, 0, SEEK_END);
    long size = ftell(in);
    rewind(in);

    // Reservar memoria para el archivo
    uint8_t *buffer = malloc(size);

    // Leer contenido
    fread(buffer, 1, size, in);

    // Padding (relleno a mÃºltiplos de 16 bytes)
    long padded = ((size + 15) / 16) * 16;

    buffer = realloc(buffer, padded);
    memset(buffer + size, 0, padded - size);

    // Clave de 256 bits (32 bytes)
    uint8_t key[32] = {0};  // âš ï¸ Puedes modificarla

    // Round keys (expansiÃ³n de clave)
    uint8_t roundKeys[240];

    // âš ï¸ AquÃ­ debes llamar a tu funciÃ³n de Key Expansion

    uint8_t output[16];

    // Procesar bloque por bloque
    for (long i = 0; i < padded; i += 16) {

        // Cifrar bloque
        aes_encrypt_block(buffer + i, output, roundKeys);

        // Escribir resultado
        fwrite(output, 1, 16, out);
    }

    // Liberar recursos
    fclose(in);
    fclose(out);
    free(buffer);

    printf("Cifrado completado correctamente\n");

    return 0;
}
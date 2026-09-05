#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// 1. Lógica ARX: Macro para la rotación de bits hacia la izquierda
// Esto asegura que la rotación sea eficiente y no corrompa los datos.
#define ROTL(a, b) (((a) << (b)) | ((a) >> (32 - (b))))

// Función del "Cuarto de Ronda" (Quarter Round) usando ARX (Add, Rotate, XOR)
#define QUARTER_ROUND(a, b, c, d) ( \
    a += b, d ^= a, d = ROTL(d, 16), \
    c += d, b ^= c, b = ROTL(b, 12), \
    a += b, d ^= a, d = ROTL(d, 8),  \
    c += d, b ^= c, b = ROTL(b, 7)   \
)

// Función para generar un bloque de 64 bytes de flujo de cifrado (keystream)
void chacha20_block(uint32_t *state, uint8_t *keystream) {
    uint32_t working_state[16];
    int i;

    // Aritmética de punteros: Copiar el estado original al estado de trabajo
    for (i = 0; i < 16; i++) {
        *(working_state + i) = *(state + i);
    }

    // 20 Rondas de ChaCha20 (10 de columnas y 10 diagonales)
    for (i = 0; i < 10; i++) {
        // Rondas de Columna
        QUARTER_ROUND(*(working_state + 0), *(working_state + 4), *(working_state + 8),  *(working_state + 12));
        QUARTER_ROUND(*(working_state + 1), *(working_state + 5), *(working_state + 9),  *(working_state + 13));
        QUARTER_ROUND(*(working_state + 2), *(working_state + 6), *(working_state + 10), *(working_state + 14));
        QUARTER_ROUND(*(working_state + 3), *(working_state + 7), *(working_state + 11), *(working_state + 15));
        
        // Rondas Diagonales
        QUARTER_ROUND(*(working_state + 0), *(working_state + 5), *(working_state + 10), *(working_state + 15));
        QUARTER_ROUND(*(working_state + 1), *(working_state + 6), *(working_state + 11), *(working_state + 12));
        QUARTER_ROUND(*(working_state + 2), *(working_state + 7), *(working_state + 8),  *(working_state + 13));
        QUARTER_ROUND(*(working_state + 3), *(working_state + 4), *(working_state + 9),  *(working_state + 14));
    }

    // Sumar el estado de trabajo al estado original y pasarlo al buffer de bytes (keystream)
    for (i = 0; i < 16; i++) {
        uint32_t val = *(working_state + i) + *(state + i);
        // Descomponer el entero de 32 bits en 4 bytes (Little Endian)
        *(keystream + (i * 4) + 0) = (val >> 0)  & 0xFF;
        *(keystream + (i * 4) + 1) = (val >> 8)  & 0xFF;
        *(keystream + (i * 4) + 2) = (val >> 16) & 0xFF;
        *(keystream + (i * 4) + 3) = (val >> 24) & 0xFF;
    }

    // Incrementar el contador de bloque (posición 12 del arreglo State)
    (*(state + 12))++;
}

int main() {
    // 2. Punteros: Gestionar el "Estado" (Array de 16 enteros de 32 bits)
    // El estado incluye constantes, clave, contador y nonce. Usamos datos de ejemplo.
    uint32_t state[16] = {
        0x61707865, 0x3320646e, 0x79622d32, 0x6b206574, // Constantes de ChaCha20
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, // Clave (8 enteros = 32 bytes)
        0x00000001,                                     // Contador (Inicia en 1)
        0x09, 0x0A, 0x0B                                // Nonce (3 enteros = 12 bytes)
    };

    // Abrir archivos de Entrada/Salida según las instrucciones generales
    FILE *fin = fopen("input.bin", "rb");
    FILE *fout = fopen("output.enc", "wb");

    if (!fin || !fout) {
        printf("Error: No se pudo abrir input.bin o crear output.enc\n");
        return 1;
    }

    uint8_t buffer[64];
    uint8_t keystream[64];
    size_t bytes_read;

    // Leer el archivo en bloques de 64 bytes
    while ((bytes_read = fread(buffer, 1, 64, fin)) > 0) {
        // Generar la llave para este bloque específico
        chacha20_block(state, keystream);

        // Aritmética de punteros obligatoria para recorrer los buffers
        uint8_t *ptr_buffer = buffer;
        uint8_t *ptr_key = keystream;
        
        for (size_t i = 0; i < bytes_read; i++) {
            // Operación XOR entre el archivo y el keystream
            *(ptr_buffer + i) ^= *(ptr_key + i);
        }

        // Escribir el bloque cifrado en el archivo de salida
        fwrite(buffer, 1, bytes_read, fout);
    }

    fclose(fin);
    fclose(fout);
    
    printf("¡Cifrado ChaCha20 completado! Archivo output.enc generado.\n");
    return 0;
}
"""
Autor: Diego Saldaña
Proyecto: Multiplicación de matrices en Python con multiprocessing
Equivalente al código en C con OpenMP
"""

import time
import multiprocessing

# Parámetros
TAM = 5000
NUM_PROCESOS = 20

# Generar las matrices de entrada
def inicializar_matrices():
    matris1 = [[0 for _ in range(TAM)] for _ in range(TAM)]
    matris2 = [[0 for _ in range(TAM)] for _ in range(TAM)]
    num = 0
    for i in range(TAM):
        for j in range(TAM):
            matris1[i][j] = num
            matris2[i][j] = num
            num += 1
    return matris1, matris2

# Multiplicación de un rango de filas
def multiplicar_filas(rango):
    matris1, matris2, inicio, fin = rango
    resultado_parcial = []
    for i in range(inicio, fin):
        fila_res = []
        for j in range(TAM):
            suma = 0
            for k in range(TAM):
                suma += matris1[i][k] * matris2[k][j]
            fila_res.append(suma)
        resultado_parcial.append((i, fila_res))
    return resultado_parcial

if __name__ == "__main__":
    matris1, matris2 = inicializar_matrices()

    # Dividir el trabajo por rangos de filas
    rango_trabajo = []
    chunk = TAM // NUM_PROCESOS
    for i in range(NUM_PROCESOS):
        inicio = i * chunk
        fin = (i+1)*chunk if i != NUM_PROCESOS-1 else TAM
        rango_trabajo.append( (matris1, matris2, inicio, fin) )

    # Iniciar temporizador
    tiempo_inicio = time.perf_counter()

    with multiprocessing.Pool(processes=NUM_PROCESOS) as pool:
        resultados = pool.map(multiplicar_filas, rango_trabajo)

    # Reconstruir resultado completo
    resultado = [ [0]*TAM for _ in range(TAM) ]
    for bloque in resultados:
        for (fila_idx, fila_valores) in bloque:
            resultado[fila_idx] = fila_valores

    # Guardar resultado en archivo
    with open("resultado_multiplicacion.txt", "w") as f:
        for i in range(TAM):
            for j in range(TAM):
                f.write(f"{resultado[i][j]} ")
            f.write("\n")

    # Finalizar tiempo
    tiempo_fin = time.perf_counter()
    tiempo_total = tiempo_fin - tiempo_inicio

    print("\nVersión paralela de la multiplicación de matrices (Python)")
    print(f"fila y columna {TAM}x{TAM}")
    print(f"cantidad de procesos usados: {NUM_PROCESOS}")
    print(f"tiempo total: {tiempo_total:.4f} segundos\n")

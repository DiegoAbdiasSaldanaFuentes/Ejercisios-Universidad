import time

# Tamaño de las matrices
TAM = 500

# Inicializar matrices
matris1 = [[0 for _ in range(TAM)] for _ in range(TAM)]
matris2 = [[0 for _ in range(TAM)] for _ in range(TAM)]
resultado = [[0 for _ in range(TAM)] for _ in range(TAM)]

# Llenar matrices con valores
num = 0
for i in range(TAM):
    for j in range(TAM):
        matris1[i][j] = num
        matris2[i][j] = num
        resultado[i][j] = 0
        num += 1

# Temporizadores
start_time = time.time()
start_cpu = time.process_time()

# Multiplicación de matrices
for i in range(TAM):
    for j in range(TAM):
        for k in range(TAM):
            resultado[i][j] += matris1[i][k] * matris2[k][j]

# Guardar resultado
with open("resultado_multiplicacion_secuencial.txt", "w") as f:
    for i in range(TAM):
        for j in range(TAM):
            f.write(f"{resultado[i][j]} ")
        f.write("\n")

# Finalizar tiempos
end_cpu = time.process_time()
end_time = time.time()
tiempo_cpu = end_cpu - start_cpu
tiempo_real = end_time - start_time

# Mostrar tiempos
print("Versión secuencial de la multiplicación de matrices")
print(f"Fila y columna {TAM}x{TAM}")
print(f"Tiempo de CPU: {tiempo_cpu:.4f} segundos")
print(f"Tiempo real: {tiempo_real:.4f} segundos")


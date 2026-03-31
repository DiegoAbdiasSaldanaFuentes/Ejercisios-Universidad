
# Si queremos hacer la funcion F(x) = x^2 - 9 / x -3


# Definimos el punto al que queremos acercarnos
objetivo = 0

# --- LADO IZQUIERDO (Valores menores a 3) ---
izq1 = 2.9
izq2 = 2.99
izq3 = 2.999

# Calculamos f(x) manualmente para cada uno
# f(x) = (x^2 - 9) / (x - 3)
res_izq1 = (izq1**2 - 9) / (izq1 - 3)
res_izq2 = (izq2**2 - 9) / (izq2 - 3)
res_izq3 = (izq3**2 - 9) / (izq3 - 3)

# --- LADO DERECHO (Valores mayores a 3) ---
der1 = 3.1
der2 = 3.01
der3 = 3.001

res_der1 = (der1**2 - 9) / (der1 - 3)
res_der2 = (der2**2 - 9) / (der2 - 3)
res_der3 = (der3**2 - 9) / (der3 - 3)

# --- MOSTRAR RESULTADOS ---
print("TABLA POR LA IZQUIERDA")
print("x:", izq1, " -> f(x):", res_izq1)
print("x:", izq2, " -> f(x):", res_izq2)
print("x:", izq3, " -> f(x):", res_izq3)

print("\nTABLA POR LA DERECHA")
print("x:", der1, " -> f(x):", res_der1)
print("x:", der2, " -> f(x):", res_der2)
print("x:", der3, " -> f(x):", res_der3)
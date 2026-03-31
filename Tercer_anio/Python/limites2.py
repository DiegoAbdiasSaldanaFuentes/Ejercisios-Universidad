import math

# F(x)= X/raiz(x+1-1)

x=3

# --- LADO IZQUIERDO (Valores menores a 3) ---
izq1 = 4.9
izq2 = 4.99
izq3 = 4.999


# Calculamos f(x) manualmente para cada uno
# F(x)= X/raiz(x+1-1)

res_izq1 = (izq1) / (math.sqrt(izq1 + 1 - 1))
res_izq2 = (izq2) / (math.sqrt(izq2 + 1 - 1))
res_izq3 = (izq3) / (math.sqrt(izq3 + 1 - 1))



# --- LADO DERECHO (Valores mayores a 3) ---
der1 = 5.1
der2 = 5.01
der3 = 5.001


# Calculamos f(x) manualmente para cada uno
# F(x)= X/raiz(x+1-1)

res_der1 = (der1) / (math.sqrt(der1 + 1 - 1))
res_der2 = (der2) / (math.sqrt(der2 + 1 - 1))
res_der3 = (der3) / (math.sqrt(der3 + 1 - 1))




# --- MOSTRAR RESULTADOS ---
print("TABLA POR LA IZQUIERDA")
print("x:", izq1, " -> f(x):", res_izq1)
print("x:", izq2, " -> f(x):", res_izq2)
print("x:", izq3, " -> f(x):", res_izq3)

print("\nTABLA POR LA DERECHA")
print("x:", der1, " -> f(x):", res_der1)
print("x:", der2, " -> f(x):", res_der2)
print("x:", der3, " -> f(x):", res_der3)
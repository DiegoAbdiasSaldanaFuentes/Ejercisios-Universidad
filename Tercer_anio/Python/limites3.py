# Paso 1: Definición del problema
def evaluar_limite(x):
    return (x**2 + x - 6) / (x + 3)

a = -3

# Paso 2: Evaluación por sustitución directa
try:
    resultado = evaluar_limite(a)
    print("El límite por sustitución directa es:", resultado)
except ZeroDivisionError:
    print("Sustitución directa fallida: Indeterminación matemática (División por cero). Se requiere estudio numérico.")

# Paso 3: Estudio numérico mediante límites laterales
print("\n--- INICIANDO ---")

# Estas son las distancias con las que nos acercaremos al -3
deltas = [0.1, 0.01, 0.001, 0.0001]

print("\nTabla por la Izquierda (valores menores a -3):")
for d in deltas:
    x_izq = a - d                    # Restamos la distancia: -3 - 0.1 = -3.1
    f_izq = evaluar_limite(x_izq)    # Evaluamos ese valor en la función

    print(f"x: {x_izq:.4f}  ->  f(x): {f_izq:.4f}")

print("\nTabla por la Derecha (valores mayores a -3):")
for d in deltas:
    x_der = a + d                    # Sumamos la distancia: -3 + 0.1 = -2.9
    f_der = evaluar_limite(x_der)    # Evaluamos ese valor en la función
    print(f"x: {x_der:.4f}  ->  f(x): {f_der:.4f}")
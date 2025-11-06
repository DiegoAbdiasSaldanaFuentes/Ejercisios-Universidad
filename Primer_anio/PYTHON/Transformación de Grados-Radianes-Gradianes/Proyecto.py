# Importamos la libreria Math para que nos facilite 
# a la hora de trabajar con conceptos como el numero "Pi"
import math

# Lista de ángulos en grados
grados = [30, 45, 60, 90, 120, 180, 255, 300, 330]
# Crear la tabla de conversión ultilizando los F string y
#  especificando que queremos una separacion de 10, 15 y 15  espacios
print(f"{'Grados':<10} {'Radianes':<15} {'Gradianes':<15}")
# Creamos una linea para separar los: Grados, Radianes y Gradianes, 
# esta adicion es unicamente estetico
print("-" * 40)

# Creamos un bucle que itere por cada numero en grados resolviendo
#  lo grados para radianes y gradianes
for grado in grados:
    # Usamo el Round para redondear el resultado
    radianes = round(grado * (math.pi / 180), 6)  # Convertir a radianes
    gradianes = round(grado * (10 / 9), 6)  # Convertir a gradianes
    print(f"{grado:<10} {radianes:<15} {gradianes:<15}")

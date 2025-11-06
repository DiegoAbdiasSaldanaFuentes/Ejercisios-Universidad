def angulo_interior(n):
    # Retornamos el resultado usando 
    # la formula para los angulos interiores
    return (n - 2) * 180 / n

# Cálculos para un cuadrado (4 lados), 
# pentágono (5 lados)
# y hexágono (6 lados) y  usamo un diccionario
poligonos = {"Cuadrado": 4, "Pentágono": 5, "Hexágono": 6}

# Creamos un bucle denominando nuevos valores como nombre y 
# lados y utilizamo el ".items()" para que pueda iterar
# la clave y valor
for nombre, lados in poligonos.items():
    angulo = angulo_interior(lados)
    print(f"El ángulo interior de un {nombre} con {lados} lados es: {angulo:.2f} grados")

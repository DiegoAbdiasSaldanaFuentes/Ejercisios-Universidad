# Programa para mostrar la tabla de multiplicar del 7

def tabla_del_7():
    numero = 7
    for i in range(1, 11):
        resultado = numero * i
        print(f"{numero} x {i} = {resultado}")

# Llamamos a la función para mostrar la tabla
tabla_del_7()

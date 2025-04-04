import os

def limpiar():
    """Limpia la pantalla según el sistema operativo."""
    if os.name == 'posix':
        os.system('clear')
    else:
        os.system('cls')

def lee_datos():
    """Lee el archivo 'datos.txt' y devuelve el contenido como una lista de listas."""
    datos = []
    for linea in open('datos.txt'):
        linea = linea.strip()  # Quitamos los espacios en blanco
        # Convertimos la línea en una lista de números, ignorando líneas vacías
        if linea:  # Aún necesitamos esta línea para evitar errores al convertir
            datos.append([int(num) for num in linea.split()])
    return datos

def enlista(datos):
    """Convierte la lista de líneas en una lista de secuencias, separando cada secuencia por ceros."""
    secuencias = []
    secuencia_actual = []

    for linea in datos:
        for num in linea:
            if num == 0:
                secuencias.append(secuencia_actual)  # Guardamos la secuencia
                secuencia_actual = []  # Reiniciamos la secuencia
            else:
                secuencia_actual.append(num)  # Agregamos el número a la secuencia actual

    # Añadimos la última secuencia si queda alguna
    if secuencia_actual:
        secuencias.append(secuencia_actual)

    print("Secuencias:", secuencias)
    return secuencias

def calcula(secuencias):
    """Identifica las "cimas" en cada secuencia."""
    cimas = []

    for secuencia in secuencias:
        for i in range(1, len(secuencia) - 1):
            # Verifica si el número es una cima
            if secuencia[i] > secuencia[i - 1] and secuencia[i] > secuencia[i + 1]:
                cimas.append((secuencia[i], i + 1))  # Guardamos el valor y su posición

    print("Cimas:", cimas)
    return cimas

def guarda_resultados(cimas):
    """Guarda las cimas encontradas en el archivo 'cimas.txt'."""
    with open('cimas.txt', 'a') as archivo:  # Usamos 'a' para añadir resultados
        for valor, posicion in cimas:
            archivo.write(f"{valor} {posicion}\n")
        archivo.write("***\n")  # Añadimos un delimitador al final

    print("Resultados guardados en cimas.txt")

if __name__ == '__main__':
    limpiar()
    datos = lee_datos()
    secuencias = enlista(datos)
    cimas = calcula(secuencias)
    guarda_resultados(cimas)

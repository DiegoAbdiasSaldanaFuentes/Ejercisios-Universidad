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
    with open('datos.txt') as archivo:  # Usar 'with' para manejar el archivo
        for linea in archivo:
            linea = linea.strip()  # Quitamos los espacios en blanco
            # Convertimos la línea en una lista de números, ignorando líneas vacías
            if linea:  
                datos.append([int(num) for num in linea.split()])
    return datos

def enlista(datos):
    """Convierte la lista de líneas en una lista de secuencias, separando cada secuencia por ceros."""
    secuencias = []
    secuencia_actual = []

    for linea in datos:
        for num in linea:
            if num == 0:
                if secuencia_actual:  
                    secuencias.append(secuencia_actual)  
                    secuencia_actual = []  
            else:
                secuencia_actual.append(num)  

    if secuencia_actual:
        secuencias.append(secuencia_actual)

    print("Secuencias:", secuencias)
    return secuencias

def calcula(secuencias):
    """Identifica las "cimas" en cada secuencia."""
    cimas = []

    for secuencia in secuencias:
        # Verificar extremos
        if len(secuencia) > 1 and secuencia[0] > secuencia[1]:
            cimas.append((secuencia[0], 1))  
        for i in range(1, len(secuencia) - 1):
            if secuencia[i] > secuencia[i - 1] and secuencia[i] > secuencia[i + 1]:
                cimas.append((secuencia[i], i + 1))  
        if len(secuencia) > 1 and secuencia[-1] > secuencia[-2]:
            cimas.append((secuencia[-1], len(secuencia)))  

    print("Cimas:", cimas)
    return cimas

def guarda_resultados(cimas):
    """Guarda las cimas encontradas en el archivo 'cimas.txt'."""
    with open('cimas.txt', 'w') as archivo:  
        for valor, posicion in cimas:
            archivo.write(f"{valor} {posicion}\n")
        archivo.write("***\n")  

    print("Resultados guardados en cimas.txt")

if __name__ == '__main__':
    limpiar()
    datos = lee_datos()
    secuencias = enlista(datos)
    cimas = calcula(secuencias)
    guarda_resultados(cimas)
#Autores: Diego Saldaña y Victor Farias
#Fecha: 04/12/2024
#Profesor: Hugo Araya

# Función que lee los datos del archivo
def lectura_datos(archivo):
    ent = open(archivo)
    lineas = ent.readlines()
    ent.close()
    return lineas

# Función para leer las dimensiones de la casa
def leer_dimensiones(linea):
    dimensiones = linea.split()
    m = int(dimensiones[0])  # Leer las dimensiones
    n = int(dimensiones[1])
    return m, n

# Función para leer las posiciones de Tom y Jerry
def leer_posiciones(linea):
    posiciones = linea.split()
    tom = [int(posiciones[0]), int(posiciones[1])]  # Posición de Tom
    jerry = [int(posiciones[2]), int(posiciones[3])]  # Posición de Jerry
    return tom, jerry

# Función para leer los obstáculos
def leer_obstaculos(lineas, k):
    obstaculos = []
    for i in range(3, 3 + k):
        coords = lineas[i].split()
        obstaculos.append([int(coords[0]), int(coords[1]), int(coords[2]), int(coords[3])])  # Obstáculos
    return obstaculos

# Función para validar las dimensiones
def validar_dimensiones(m, n):
    if m <= 0 or n <= 0:
        return "ERROR E0"  # Dimensiones no válidas
    return None

# Función para validar las posiciones de Tom y Jerry
def validar_posiciones(m, n, tom, jerry):
    if not (0 <= tom[0] < m and 0 <= tom[1] < n and 0 <= jerry[0] < m and 0 <= jerry[1] < n):
        return "ERROR E1"  # Posiciones fuera del rango
    if tom == jerry:
        return "ERROR E2"  # Tom y Jerry en la misma casilla
    return None

# Función para validar los obstáculos
def validar_obstaculos(m, n, obstaculos):
    casillas_obstaculos = []
    for obstaculo in obstaculos:
        x1, y1, x2, y2 = obstaculo
        if not (0 <= x1 < m and 0 <= x2 < m and 0 <= y1 < n and 0 <= y2 < n):
            return "ERROR E3"  # Coordenadas no válidas
        if x1 > x2 or y1 > y2:
            return "ERROR E4"  # Vértices no válidos
        for x in range(x1, x2 + 1):
            for y in range(y1, y2 + 1):
                if [x, y] in casillas_obstaculos:
                    return "ERROR E5"  # Obstáculos solapados
                casillas_obstaculos.append([x, y])
    return casillas_obstaculos

# Función para validar si Tom o Jerry están en un obstáculo
def validar_posiciones_en_obstaculos(tom, jerry, casillas_obstaculos):
    if tom in casillas_obstaculos or jerry in casillas_obstaculos:
        return "ERROR E6"  # Tom o Jerry están en un obstáculo
    return None

# Función para dibujar la casa
def dibujar_casa(m, n, tom, jerry, obstaculos):
    casa = []
    for i in range(m):
        fila = []
        for j in range(n):
            fila.append('o')  # Casilla vacía
        casa.append(fila)

    casa[tom[0]][tom[1]] = 'T'  # Marca posición de Tom
    casa[jerry[0]][jerry[1]] = 'J'  # Marca posición de Jerry

    for obstaculo in obstaculos:
        x1, y1, x2, y2 = obstaculo
        for x in range(x1, x2 + 1):
            for y in range(y1, y2 + 1):
                casa[x][y] = 'x'  # Marcar obstáculos
    return casa

# Función para validar todo el proceso de la casa
def validar_todo(m, n, tom, jerry, obstaculos):
    # Validamos dimensiones
    error = validar_dimensiones(m, n)
    if error:
        escribir_salida(error, True)
    else:
        # Validamos las posiciones de Tom y Jerry
        error = validar_posiciones(m, n, tom, jerry)
        if error:
            escribir_salida(error, True)
        else:
            # Validamos los obstáculos
            casillas_obstaculos = validar_obstaculos(m, n, obstaculos)
            if isinstance(casillas_obstaculos, str):  # Si hay un error en los obstáculos
                escribir_salida(casillas_obstaculos, True)
            else:
                # Validamos si Tom o Jerry están en un obstáculo
                error = validar_posiciones_en_obstaculos(tom, jerry, casillas_obstaculos)
                if error:
                    escribir_salida(error, True)
                else:
                    # Si todo es válido, dibujamos la casa y escribimos la salida
                    casa = dibujar_casa(m, n, tom, jerry, obstaculos)
                    escribir_salida(casa, False)

# Funcion para escribir la salida
def escribir_salida(contenido, es_error):
    sal = open('error.txt', 'w')
    if es_error:
        sal.write(contenido + '\n')  # Escribir el error
    else:
        for fila in contenido:  # Escribir la casa
            for casilla in fila:
                sal.write(casilla)
            sal.write('\n')
    sal.close()

if __name__ == "__main__":
    lineas = lectura_datos('casa.txt')
    m, n = leer_dimensiones(lineas[0])
    tom, jerry = leer_posiciones(lineas[1])
    k = int(lineas[2])  # Número de obstáculos
    obstaculos = leer_obstaculos(lineas, k)
    validar_todo(m, n, tom, jerry, obstaculos)
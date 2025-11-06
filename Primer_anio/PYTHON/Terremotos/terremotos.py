# Autor: Diego Saldaña
# Fecha: 18/08/2024
# Version: 0.0




# entradas de datos
def leer_datos(i):
    ent = open(i)
    datos = []
    for linea in ent:
        linea = linea.rstrip("\n")
        separador = linea.split(" ")
        datos.append(separador)
    ent.close()
    return datos

# indica la fecha y hora del mayor sismo registrado
def funcion_a(datos):
    max_sismo = max(datos, key=lambda x: float(x[4]))
    return max_sismo

def funcion_b(datos):
    suma = 0
    for linea in datos:
        if  float(linea[4])>= 7 and float(linea[4]) < 8:
            suma = suma + 1
    return suma



def funcion_c(datos):
    suma = 0
    for linea in datos:
        if  float(linea[4])>= 8 and float(linea[4]) < 9:
            suma = suma + 1
    return suma

def funcion_d(datos):
    suma = 0
    for linea in datos:
        if  float(linea[4])>= 9:
            suma = suma + 1
    return suma

def funcion_e(datos):
    suma = 0
    for linea in datos:
        fecha = linea[0]
        fecha = fecha.split("/")
        if float(linea[2])>= 1600 and float(linea[2]) < 1700:
            suma = suma + 1
    return suma





if __name__ == "__main__":
    lectura_datos = leer_datos("terremotos_datos.txt")
    fecha_hora_mayor_registrado = funcion_a(lectura_datos)
    sismo_mayor_7_menor_8 = funcion_b(lectura_datos)
    sismo_mayor_8_menor_9 = funcion_c(lectura_datos)
    sismo_mayor_9 = funcion_d(lectura_datos)
    sismo_por_siglo_XVII = funcion_e(lectura_datos)


print(sismo_por_siglo_XVII)
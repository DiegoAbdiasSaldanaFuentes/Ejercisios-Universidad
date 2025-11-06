import re
import matplotlib.pyplot as plt
def lectura_de_datos (archivo):
    ent = open(archivo)
    datos=[]
    for linea in ent:
        linea= linea.rstrip("\n")
        partes = re.split("[-. ]",linea)
        datos.append(partes)
    ent.close
    return datos

def funcion_a (datos):
    return datos[-1][0:3]

def funcion_b(datos):
    total_casos = 0
    for sep_2020 in datos:
        fecha = sep_2020[0:3]
        if '2020' and '09' in fecha:
            total_casos += int(sep_2020[3])
    return total_casos
#creamos un bloque para contar todos los casos que se han visto en cada mes
def funcion_c(datos):
    casos_mes= {}
    for casos_vistos in datos:
        mes = casos_vistos [1]
        casos = int(casos_vistos[3])
        if mes not in casos_mes:
            casos_mes[mes] = 0
        casos_mes[mes] += casos
    return casos_mes


#creamos el grafico
def funcion_d(datos):
    pass
   



if __name__== "__main__":
    covid = lectura_de_datos("TotalesNacionales.txt")
    ultimo_dia_registrado= funcion_a(covid)
    casos_mes_septiembre= funcion_b(covid)
    casos_por_mes= funcion_c(covid)
    datos_grafica=funcion_d(covid)

print(casos_por_mes)

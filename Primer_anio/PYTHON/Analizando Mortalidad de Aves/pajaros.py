# cantidad de aves muertas por región
# cantidad de aves muertas para el mes de enero 2023
# cantidad de muertes de la especie tagua en la comuna de cartagena
# cantidad muertes de piquero dia 12 debrero 2023
# graficar
import re

def leer_archivo(archivo):
    try:
        with open(archivo, 'r') as nombre_archivo:  # Usando 'with' para manejar el archivo
            resultados = []  # Lista para almacenar los resultados
            for linea in nombre_archivo:
                separador = re.split('[,-]', linea.strip())  # Quitar espacios y saltos de línea
                resultados.append(separador)  # Agregar los resultados a la lista
            return resultados  # Retornar los resultados
    except FileNotFoundError:
        return 'El archivo no existe'

if __name__ == '__main__':
    archivo = 'aves.txt'
    contenido = leer_archivo(archivo)
    print(contenido)  # Imprimir el contenido procesado

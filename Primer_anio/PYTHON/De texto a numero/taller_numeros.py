#Autores: Diego Saldaña y Victor Farias
#Fecha: 30/10/2024
#Profesor: Hugo Araya


def lectura_datos(archivo):
    ent = open(archivo)
    datos = []
    for linea in ent:
        lin = linea.strip()
        #implementamos el lower para evitar que el programa cometa errores al ejecutar
        lin = lin.lower()
        datos.append(lin)  
    ent.close()
    return datos


def numeros():
    num = {
        'zero': 0, 'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5,
        'six': 6, 'seven': 7, 'eight': 8, 'nine': 9,
        'ten': 10, 'eleven': 11, 'twelve': 12, 'thirteen': 13,
        'fourteen': 14, 'fifteen': 15, 'sixteen': 16, 'seventeen': 17,
        'eighteen': 18, 'nineteen': 19, 'twenty': 20,
        'thirty': 30, 'forty': 40, 'fifty': 50, 'sixty': 60,
        'seventy': 70, 'eighty': 80, 'ninety': 90,
        'hundred': 100, 'thousand': 1000, 'million': 1000000, 'billion': 1000000000
    }
    return num


def convertir_a_numeros(entrada_numeros_texto, numeros):
    # Lista para almacenar los resultados finales
    resultados = []
    
    for linea in entrada_numeros_texto:
        palabras = linea.split()
        # Acumulador del número total
        total = 0  
        # Acumulador temporal para manejar cientos, miles, etc.
        temp_total = 0
        # Para manejar los números negativos
        multiplicador_negativo = 1  

        for palabra in palabras:
            if palabra == "negative":
                # Marcamos el número como negativo
                multiplicador_negativo = -1
            elif palabra in numeros:
                # Obtenemos el valor de la palabra
                valor = numeros[palabra]

                if valor == 100:
                    # Multiplicamos temp_total por 100
                    temp_total *= valor
                elif valor >= 1000:
                    # Multiplicamos temp_total por mil, millón, etc.
                    temp_total *= valor
                    # Agregamos el valor acumulado al total
                    total += temp_total
                    # Reiniciamos temp_total
                    temp_total = 0  
                else:
                    # Sumamos el valor a temp_total
                    temp_total += valor
        # Agregamos el último bloque de números 
        total += temp_total
        # Aplicamos el signo negativo si es necesario
        total *= multiplicador_negativo
        # Guardamos el resultado final en la lista
        resultados.append(total)  
    
    return resultados


def escribir_resultados(resultados):
    sal = open("en_numeros.txt", 'w')
    for resultado in resultados:
        sal.write(str(resultado) + '\n\n')
    
    sal.close()


if __name__ == "__main__":
    # Lee el archivo de entrada
    entrada_texto = lectura_datos("en_palabras.txt")
    # Diccionario con los números en texto y sus valores
    numer = numeros()
    # Convierte texto a números
    resultados = convertir_a_numeros(entrada_texto, numer)
    # Escribe los resultados en el archivo de salida
    escribir_resultados(resultados) 
def lee_datos():
    # Lista con números en texto, por ejemplo incluyendo "negative" para números negativos
    entrada_numeros_texto = ['negative nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine']
    
    # Diccionario con palabras numéricas y sus valores
    numeros = {
        'zero': 0, 'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5,
        'six': 6, 'seven': 7, 'eight': 8, 'nine': 9,
        'ten': 10, 'eleven': 11, 'twelve': 12, 'thirteen': 13, 'fourteen': 14,
        'fifteen': 15, 'sixteen': 16, 'seventeen': 17, 'eighteen': 18, 'nineteen': 19,
        'twenty': 20, 'thirty': 30, 'forty': 40, 'fifty': 50, 'sixty': 60,
        'seventy': 70, 'eighty': 80, 'ninety': 90,
        'hundred': 100, 'thousand': 1000, 'million': 1000000, 'billion': 1000000000,
        'negative': -1
    }
    return entrada_numeros_texto, numeros

def proceso(entrada_numeros_texto, numeros):
    resultados = []  # Lista para almacenar los resultados finales
    
    for linea in entrada_numeros_texto:
        palabras = linea.split()  # Dividimos la línea en palabras
        total = 0  # Acumulador del número total
        temp_total = 0  # Acumulador temporal para manejar cientos, miles, etc.
        multiplicador_negativo = 1  # Para manejar los números negativos
        
        for palabra in palabras:
            # Verificamos si la palabra es "negative" o "minus"
            if palabra in ["negative"]:
                multiplicador_negativo = -1  # Marcamos el número como negativo
            elif palabra in numeros:
                valor = numeros[palabra]  # Obtenemos el valor de la palabra
                
                # Si la palabra es "hundred", multiplicamos el acumulador temporal por 100
                if valor == 100:
                    temp_total *= valor
                # Si la palabra es "thousand", "million" o "billion", multiplicamos
                # temp_total por el valor correspondiente y lo sumamos al total
                elif valor >= 1000:
                    temp_total *= valor
                    total += temp_total
                    temp_total = 0  # Reiniciamos temp_total después de sumar
                else:
                    # Para números menores que 100, sumamos a temp_total
                    temp_total += valor
        
        # Sumamos cualquier cantidad restante en temp_total al total
        total += temp_total
        # Aplicamos el signo negativo si es necesario
        total *= multiplicador_negativo
        resultados.append(total)  # Guardamos el resultado final en la lista
    
    return resultados

if __name__ == '__main__':
    # Llamamos a las funciones y mostramos el resultado
    entrada_numeros_texto, numeros = lee_datos()
    comparacion = proceso(entrada_numeros_texto, numeros)
    print(comparacion)  # Esto imprimirá el número entero, incluso los negativos

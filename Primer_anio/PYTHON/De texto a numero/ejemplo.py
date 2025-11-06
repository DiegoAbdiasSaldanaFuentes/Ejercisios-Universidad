   

def separador():
    resultado = []
    for numeros_texto  in entrada_numeros_texto:
        palabra = numeros_texto.split()

def lee_datos():
    entrada_numeros_texto = ['five hundred twenty two']
    numeros = {
        'five' : 5,
        'hundred' : 100,
        'twenty' : 20,
        'two' : 2,
    }
    return entrada_numeros_texto , numeros

def proceso():
    for linea in entrada_numeros_texto:
        if linea in numeros:
            a ='si'
    return a

if __name__ == '__main__':
    entrada_numeros_texto, numeros = lee_datos()
    comparacion = proceso(entrada_numeros_texto,numeros)
""""file = open('soyuntexto.txt', 'r')
# print(file)
lineas = file.readlines()
linea = lineas
print(lineas)
file.close()"""

with open('data1.txt','r') as archivo:
    lineas = archivo.read()
    print(lineas)

'''for l in lineas:
    print(l.replace('\n', ''))'''

'''with open('data1.txt','r') as archivo:
    contenido = archivo.read()
    lineas = contenido.split('\n')
    print(lineas)'''


'''with open('data1.txt','r') as archivo:
    #ver que posicion en que estamos en el archivo de texto
    contenido = archivo.read()
    lineas =contenido.split('\n')
    pos = archivo.tell()
    print(pos)
    print('el archivo tine {0} caracteres de longitud'.format(pos))'''

'''with open('data1.txt','r') as archivo:
    archivo.seek(7)
    pos = archivo.tell()
    print(pos)
    print(archivo)'''



#lista = ['lucas', 'dalto',True, 1.85]
#tupla = ('lucas', 'dalto',True, 1.85)
#conjunto = {'lucas', 'Diego',1.43}

#a = ['hola', 'pendejo']
#for i in a:
#    print(i)

'print(conjunto[1])'

#igualque = 5 == 6 
#if igualque != True:
#    print('puto')

#nombre = 'diego'
#n = 'diego'
#contrasena = '123'
#contra = '123'
#if nombre == n and contrasena == contra:
#    print('bienvenido')
#else:
#    print('ingresaste mal tus datos')

#cadena1 = 'hola soy diego'
#cadena2 = ['hola']
#metodo es porque tiene el metodo al final w, si estubiera al frente seria funcion
#resultado = cadena1.upper()
#print(resultado)

#desempaquetado
#datos = ('lucas','dalto',1000000)
#nombre,apellido,sus = datos
#print(sus)


#conjunto1 = {1,2,3,8} 
#conjunto2 = {3,8} 
#con que un digito sea igual entre los dos conjuntos ya es false
#resultado = conjunto1.isdisjoint(conjunto2)
# verificando si es un superconjunto
#resultado1 = conjunto1.issuperset(conjunto2)

#print('resultado con isdisjoint:',resultado)
#print('resultado con issuperset:',resultado1)

#conjunto = set(['Dato 1'])

#conjunto1 = frozenset(['Dato 1','Dato  2'])
#conjunto2 = {conjunto1,'dato 3'}
#print(conjunto2)

diccionario = {
    'Nombre' : 'Lucas',
    'Apellido' : 'Dalto',
    'subs' : 10000000
}
#no devuelve las llaves osea  la clave solamente, no el valor
#claves = diccionario.keys()
#usar get es m'as optimo para que l programa no termine con excepcion mientras que con get el programa continua sin excepciones aunque este incorrecto
#valor_de_Nombre = diccionario.get('Nombre')

#eliminando todo del diccionario
#diccionario_eliminado = diccionario.clear()

#eliminando un elemento de un diccionario

#diccionario_eliminar_pop = diccionario.pop('subs')

#obteniendo un elemento dict_items iterable
#diccionario_iterable = diccionario.items()

#print(diccionario_iterable)


animales = ['gato','perro','loro','cocodrillo']

#for animal in animales:
#    print(animal)

numeros = [22,76,90,12,32]
#for numeros in numero:
#    resultado = numeros * 12
#    print(resultado)

#zip para poder ejecutar dos lisstas a la vez
#for numero,animal in zip(animales,numeros):
#    print(numero)
#    print(animal)

#for num in range(5,10):
#    print(num)


#for num in range(len(numeros)):
    #tenemos que especificar que quiera mostrar los numeros de la lista
    #de lo contrario mostrara 0 1 2 3 4 
#    print(numeros[num])

for num in enumerate(numeros):
    indice = num[0]
    valor =  num[1]
    print(f'el indice es: {indice} y el valor es: {valor}')
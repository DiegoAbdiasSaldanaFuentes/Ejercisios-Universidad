#creamos una funcion que nos cree una contraseñam aleatoria y definimos nuestro parametro como ´num´
def crear_contraseña_random(num):
    #chars es la cadena de texto con la cual vamos a crear nuestra contraseña
    chars='abcdefghij'
# transformamos nuestro numero a un string
    num_entero = str(num)
#utilizamos el numero del parametro num y lo transformamos en string y tomamos el primer caracter, esto nos evita por si 
#colocamos un numero que supere nuestra lista causando algun error, osea si entregamos el numero 56 solo tomara el 5
    num = int(num_entero[0])
# aqui restamos num
    c1 = num -2
# aqui deajamos num tal y como esta
    c2 = num
# aqui restamos num otra vez
    c3 = num -5
    # el paso mas crucial, ahora que tenemos numeros aleatorios por haber restado num y guardarlo en distintos variables
    # le decimos a la cadena de texto chars que toma un caracter en la posicion c1 por ejemplo y el numero del resultado de ese numero
    # tomara la posicion del carcter, para luego para finalizar num siendo multiplicado por dos para que la contraseña termine con un numero
    contraseña = f'{chars[c1]}{chars[c2]}{chars[c3]}{num * 2}'
    # printiamos nuestra contraseña
    print(contraseña)
# aqui llamamos a nuestra funcion y le entregamos el parametro 4
crear_contraseña_random(4)
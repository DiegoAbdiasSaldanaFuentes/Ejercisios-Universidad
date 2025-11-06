

def datos():
    verificador_nombre = ["pepito", 'diego']
    nombre = input("ingrese su nombre:").lower()
    edad = int(input("ingrese su edad:"))
    cargo_preguntar = (input('ingrese su cargo:')).lower()
    return nombre,edad,cargo_preguntar,verificador_nombre


def verificador(nombre,edad,cargo_preguntar,verificador_nombre):
    if nombre not in verificador_nombre:
        return 'usted no esta en la lista'
    if edad < 18:
        return 'Usted es menor de edad tiene el acceso denegado'
    if cargo_preguntar == 'profesor':
        return f"Bienvenido {nombre} su salario es de 2000"
    elif cargo_preguntar == 'estudiante':
        return f"Bienvenido {nombre} su salario es de 600"

    


def mostrar_pantalla(resultado): 
    print(resultado)

if __name__== '__main__':
    nombre,edad,cargo_preguntar,verificador_nombre = datos()
    resultado = verificador(nombre,edad,cargo_preguntar, verificador_nombre)
    mostrar_pantalla(resultado)






"""Edad y Nombre verificar si está en un lista(la lista contiene nombres) si ese nombre no está en la lista aparezca el mensaje no está en la lista si esta te lleve al siguiente proceso pero ojo para el caso edad deber ser igual debe tener mayoría de edad para pasar así que debes hacer que las dos condiciones sean verdaderas
Una vez accedido 
Esta cargo si cargo=estudiante solo tiene  dólares 600 
Pero si cargo= profesor tiene 2000
Y eso es la primera parte hace eso primero"""
#ejercisio Escribir una función que muestre por pantalla el saludo ¡Hola amiga! cada vez que se la invoque.

#MI RESPUESTA

#def saludo ():
    #saludar = "¡Hola amiga!"
    #return saludar

#if __name__ =="__main__":
    #saludar = saludo()

#print(saludar)

#RESULTADO DE LA PAGINA 
#def greet():
   # """Función que muestra el saluco ¡Hola amiga! por pantalla."""
   # print('¡Hola amiga!')
   # return

#greet()

#EJERCISIO: Escribir una función a la que se le pase una cadena <nombre> y muestre por pantalla el saludo ¡hola <nombre>!.

#MI RESULTADO

#def name():
    #nombre = input("ingrese su nombre:").capitalize()
   # return nombre

#if __name__ == "__main__":
   # nombre = name()

#print(f"¡Hola {nombre}!")

#EJERCISIO Escribir una función que calcule el total de una factura tras aplicarle el IVA.
#  La función debe recibir la cantidad sin IVA y el porcentaje de IVA a aplicar,
#  y devolver el total de la factura.
#  Si se invoca la función sin pasarle el porcentaje de IVA, deberá aplicar un 21%.

#mi respuesta (MAALA)

#def impuesto(funcion_a):
   # iva = 0.21
#    factura = float(input("ingrese plata: "))
 #   factura_iva = factura - iva 
   # return funcion_a
#if __name__ == "__main__":
   # funcion_a =impuesto()

#print(funcion_a)

#respuesta de la pagina
#def invoice(amount, vat=21):
  #  """Función de aplica el IVA a una factura.
  #  Parametros
  #  amount: Es la cantidad sin IVA
  #  vat: Es el porcentaje de IVA
  #  Devuelve el total de la factura una vez aplicado el IVA. 
   # """
  #  return amount + amount*vat/100

#print(invoice(1000,10))
#print(invoice(1000))
    

#ejercisio Escribir una función que calcule el área de un círculo y otra que calcule el volumen de un cilindro usando la primera función.
#ejercisio sin resolver
#def circle_area(radius):
   # """Función que calcula el area de un círculo.
   # Parámetros
   # radius: Es el radio del círculo.
    #Devuelve el área del círculo de radio radius. 
   # """
    #pi = 3.1415
   # return pi*radius**2

#def cilinder_volume(radius, high):
  #  """Función que calcula el volumen de un cilindro.
   # Parámetros
   # radius: Es el radio de la base del cilindro.
  # high: Es la altura del cilindro.
  #  Devuelve el volumen del clindro de radio radius y altura high.
   # """
   # return circle_area(radius)*high

#print(cilinder_volume(3,5))




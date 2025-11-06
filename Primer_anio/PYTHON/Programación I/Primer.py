#Autor: Victor Farias y Diego Saldaña
#Fecha: 22/08/2024

lado_1 = int(input("ingrese el primer lado del triangulo:"))
lado_2 = int(input("ingrese el segundo lado del triangulo:"))
lado_3 = int(input("ingrese el tercer lado del triangulo:"))

def triangulo(lado_1,lado_2,lado_3):
    if lado_1 + lado_2 > lado_3 and lado_2 + lado_3 > lado_1 and lado_3 + lado_1 >lado_2:
        print("es un triangulo")
        if  lado_1 == lado_2 == lado_3:
         print("es un equilatero")
        elif lado_1 == lado_2 !=lado_3 or lado_2 == lado_3 != lado_2 or lado_1 == lado_3 != lado_2:
         print("es isoceles")
        else:
         print("es escaleno")
    else:
      print("no es un triangulo")
    




if __name__ =="__main__":
    funcion_a = triangulo(lado_1,lado_2,lado_3)

    
    
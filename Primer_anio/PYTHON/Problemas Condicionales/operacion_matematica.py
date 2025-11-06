#programa que realize una operación matematica dependiendo del usuario
numero1= int(input("ingrese un numero:"))
numero2= int(input("ingrese un numero:"))
#sum para sumar, multi para multiplicar, divi para dividir, rest para restar
operacion_matematia= str(input("ingrese la operación que desea hacer 'sum' para sumar 'multi' para multiplicar 'divi' para dividir y 'rest' para restar: "))
if operacion_matematia =="sum":
    resultado= numero1 + numero2
    print(f"el resultado de {numero1} y {numero2} es {resultado}")
elif operacion_matematia=="multi":
    resultado= numero1*numero2
    print(f"el resultado de {numero1} y {numero2} es {resultado}")
elif operacion_matematia=="divi":
        resultado= numero1/numero2
        print(f"el resultado de {numero1} y {numero2} es {resultado}")  
elif operacion_matematia=="rest":
    resultado= numero1-numero2
    print(f"el resultado de {numero1} y {numero2} es {resultado}")
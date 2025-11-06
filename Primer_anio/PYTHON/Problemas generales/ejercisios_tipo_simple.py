#ejercicio numero 1 
#escribir un programa que pregunte al usuario por el numero de horas trabajadas y el coste por hora
#despues debe mostrar por pantalla la paga correspondiente

#MI RESPUESTA
"""horas_trabajadas  = int(input("ingrese la cantidad de horas trabajadas:"))
coste_por_hora = float(input("ingrese coste por hora:"))

def paga (horas_trabajadas,coste_por_hora):
    a_pagar = horas_trabajadas * coste_por_hora
    return a_pagar

total_pagar = paga(horas_trabajadas, coste_por_hora)
print(total_pagar)"""

#RESPUESTA DE LA PAGINA
"""horas = float(input("Introduce las horas:"))
coste = float(input("Introduce lo que ganas:"))
paga = horas * coste
print("tu paga es", paga)"""

#EJERCISIO 2
#escribir un programa que lea un entero positivo,n, introducido por el usuario y después muestre
#en pantalla la suma de todos los enteros desde 1 hasta n, la suma de los n primeros enteros positivos

#MI RESULTADO
#n = int(input("ingrese el valor de N:"))
#print(((n + 1)*n)/2)

#RESULTADO DE LA PAGINA
#n = int(input("introduce un numero entero:"))
#suma = n * (n + 1) /  2
#print("la suma es de:",suma)

#pregunte al usuario una cantidad a invertir, el interes porcentual anueal y  el numero de  años y muestre por pantalla

#SOLUCION
# el capital obtenido en la inversión redondeando condods decimales
#cantidad = float(input("cantidad a invertir: "))
#interes =  float(input("interes porcentual anual:"))
#años = int(input("años:"))
#print("capital final:" + str(round(cantidad * (interes / 100 + 1)** años, 2)))

#pregunta: una  jugeterua tiene mucho exito en dos de sus productos:payasos y muñecas suelen hacer venta por correoy la empresa logistica es cobra por peso de cada paquete asi qye deben calcular
#el  peso de los payasos y muñecas que saldran en cada paquete a demanda. cada payaso pesa 112g y cada muñeca 75g, escribir programa que lea el numero
#de payasos

#MI SOLUCION
#cantidad_payasos = int(input("ingrese la cantidad de payasos:"))
#cantidad_muñecas = int(input("ingrese la cantidad de payasos:"))
#payaso = 112
#mueñcas = 75
#print((cantidad_payasos * payaso)+(mueñcas * cantidad_muñecas))

#Solucion de paginas

#peso_payaso = int(input("ingrese la cantidad de payasos:"))
#peso_muñeca = int(input("ingrese la cantidad de payasos:"))
#payaso = 112
#mueñcas = 75
#peso_total = peso_payaso * payaso + peso_muñeca * muñecas
#print("el pso  total del  paquete es" + str(peso_total))

#PROBLEMA:Imagina que acabas de abrir una nueva cuenta de ahorros que te ofrece el 4% de interés al año.
#  Estos ahorros debido a intereses, que no se cobran hasta finales de año, se te añaden al balance final de tu cuenta de ahorros.
#  Escribir un programa que comience leyendo la cantidad de dinero depositada en la cuenta de ahorros,
#  introducida por el usuario. Después el programa debe calcular y mostrar por pantalla la cantidad de ahorros 
# tras el primer, segundo y tercer años. Redondear cada cantidad a dos decimales.

#resutado malo
#dinero = float(input("ingrese su cantidad de dinero depositada en su cuenta de ahorro:"))
#año1 = int(input("ingrese su cantidad de años:"))
#ahorro  = 0.04
#cobro_anual = dinero * ahorro
#años = round(año1 * cobro_anual)
#print(f"su cuenta de ahorro es:{años}")

#RESULTADO DE LA PAGINA: 
#inversion = float(input("Introduce la inversión inicial: "))
#interes = 0.04
#balance1 = inversion * (1 + interes)
#print("Balance tras el primer año:" + str(round(balance1, 2)))
#balance2 = balance1 * (1 + interes)
#print("Balance tras el segundo año:" + str(round(balance2, 2)))
#balance3 = balance2 * (1 + interes)
#print("Balance tras el tercer año:" + str(round(balance3, 2)))

#Ejersicio : Una panadería vende barras de pan a 3.49€ cada una.
#  El pan que no es el día tiene un descuento del 60%. 
# Escribir un programa que comience leyendo el número de barras vendidas que no son del día. 
# Después el programa debe mostrar el precio habitual de una barra de pan, 
# el descuento que se le hace por no ser fresca y el coste final total.


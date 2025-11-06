import os  

def limpiar_pantalla():
    if os.name == "nt":
        os.system ("cls")
    else:
        os.system ("clear")
    
def entrega_de_datos():
    nombre_apelido = input("ingrese su nombre y apellido:")
    sueldo_base = float(input("ingrese su sueldo base:"))
    nombre_afp = input("ingrese el nombre de su afp:").lower()
    cantidad_de_meses_trabajados = int(input("ingrese la cantidad de meses trabajados: "))
    cantidad_de_hijos = int(input("ingrese la cantidad de hijos que tenga:"))
    return nombre_afp, nombre_apelido, sueldo_base, cantidad_de_meses_trabajados, cantidad_de_hijos

def calcular_base_imponible(sueldo_base,cantidad_de_meses_trabajados,cantidad_de_hijos):
    bono_mes_trabajado = sueldo_base* 0.01 * cantidad_de_meses_trabajados
    asignacion_familiar = cantidad_de_hijos * 0.05 * sueldo_base
    base_imponible = sueldo_base + bono_mes_trabajado + asignacion_familiar
    return bono_mes_trabajado, asignacion_familiar,  base_imponible

def cotizacion_fonasa(base_imponible):
    fonasa = base_imponible * 0.07
    return fonasa

def afp_seleccion(nombre_afp, base_imponible):
    if nombre_afp ==  "felices":
        cotizacion_afp =  base_imponible * 0.12
    elif nombre_afp == "forrados":
        cotizacion_afp = base_imponible * 0.114
    else:
        print("la afp seleccionada es incorrecta")
        cotizacion_afp = 0
    return cotizacion_afp 
    
def a_pago (base_imponible, fonasa,cotizacion_afp):
    total_pagar = base_imponible-fonasa- cotizacion_afp
    return total_pagar

if __name__ == "__main__":
    limpiar_pantalla()
    nombre_afp, nombre_apelido, sueldo_base, cantidad_de_meses_trabajados, cantidad_de_hijos = entrega_de_datos()
    bono_mes_trabajado, asignacion_familiar,  base_imponible = calcular_base_imponible(sueldo_base,cantidad_de_meses_trabajados,cantidad_de_hijos)
    fonasa = cotizacion_fonasa(base_imponible)
    cotizacion_afp = afp_seleccion(nombre_afp, base_imponible)
    total_pagar = a_pago (base_imponible, fonasa,cotizacion_afp)

print(f"Nombre : {nombre_apelido}")
print(f"Sueldo Base : {sueldo_base}")
print(f"AFP : {nombre_afp}")
print(f"Hijos : {cantidad_de_hijos}")
print(f"Bonificacion Mes : {bono_mes_trabajado:.2f}")
print(f"Bonificacion Hijos : {asignacion_familiar:.2f}")
print(f"Base Imponible : {base_imponible:.2f}")
print(f"Fonasa : {fonasa:.2f}")
print(f"AFP : {cotizacion_afp:.2f}")
print(f"A pago : {total_pagar:.2f}")

    
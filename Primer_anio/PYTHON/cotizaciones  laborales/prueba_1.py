import os 

def limpiar_pantalla():
    if os.name =="nt":
        os.system("cls")
    else:
        os.system("clear")

def entrega_datos ():
    nombre = input("ingrese su nombre: ")
    sueldo_base = float(input("ingrese su sueldo base: "))
    afp = input("ingrese su AFP: ").lower()
    meses = int(input("ingrese la cantidad de meses que ah trabajado: "))
    hijos = int(input("ingrese la cantidad de hijos que tenga: "))

    return nombre,sueldo_base,afp,meses,hijos

def calcular_base_imponible(sueldo_base,hijos,meses):
    bonificacion_meses= sueldo_base*0.01*meses
    asignacion_familiar= sueldo_base*0.05*hijos
    base_imponible= sueldo_base+asignacion_familiar+bonificacion_meses
    
    return bonificacion_meses, asignacion_familiar, base_imponible

def fonasa(base_imponible):
    cotizacion_fonasa = base_imponible * 0.07
    
    return cotizacion_fonasa

def afp_seleccion(afp,base_imponible):
    if afp =="felices":
        cotizacion_afp = base_imponible*0.12
    elif afp == "forrados":
        cotizacion_afp = base_imponible*0.114
    else:
        print("la afp ingresada es invalida")
        cotizacion_afp = 0

    return cotizacion_afp

def total_pagar(base_imponible,cotizacion_afp,cotizacion_fonasa):
    a_pago= base_imponible-cotizacion_afp-cotizacion_fonasa    
    return a_pago

if __name__ == "__main__":           
    limpiar_pantalla()
    nombre, sueldo_base, afp, meses, hijos =  entrega_datos()
    bonificacion_meses,asignacion_familiar,base_imponible=calcular_base_imponible(sueldo_base, hijos, meses)
    cotizacion_fonasa = fonasa(base_imponible)
    cotizacion_afp = afp_seleccion(afp, base_imponible)
    a_pago = total_pagar(base_imponible, cotizacion_afp ,cotizacion_fonasa)

    print(f"Nombre: {nombre}")
    print(f"Sueldo Base: ${sueldo_base:.2f}")
    print(f"Bonificación Meses: ${bonificacion_meses:.2f}")
    print(f"Asignación Familiar: ${asignacion_familiar:.2f}")
    print(f"Base Imponible: ${base_imponible:.2f}")
    print(f"Cotización Fonasa: ${cotizacion_fonasa:.2f}")
    print(f"Cotización AFP: ${cotizacion_afp:.2f}")
    print(f"A pagar: ${a_pago:.2f}")


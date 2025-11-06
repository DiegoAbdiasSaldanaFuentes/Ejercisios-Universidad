def saludo (name,year):
    if year < 20:
        return f'hola soy {name} y tengo {year} años y no puedo molerte a golpes'
    else:
        return f'hola soy {name} y tengo {year} años y voy a molerte a golpes'
    



nombrecito= input('ingrese su nombre: ')
edad = int(input('ingrese su edad: '))
print(saludo(nombrecito,edad))

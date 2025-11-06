
def determina(coef):
        if coef[0] > 0:
                salida = 'Minimo'
        else:
                salida = 'Maximo'
        return salida


def straint(datos):
        salida = []
        for elem in datos:
                salida.append(int(elem))
        return salida

def coeficiente(nombre):
        ar = open(nombre)
        coef = ar.readline().rstrip('\n').split(';')
        coef = straint(coef)
        return coef

def vertex(coef):
        vertice = []
        x = coef[1] / (2 * coef[0])
        vertice.append(x)
        y = coef[0] *(x**2) + coef[1] * x + coef[2]
        vertice.append(y)
        return vertice

def muestra(coef, vert, dete):
        print(coef, vert, dete)

if __name__ == '__main__':
        coef = coeficiente('bases\Ejercisios_Logica\leer_datos\dato.txt')
        vert = vertex(coef)
        dete = determina(coef)
        muestra(coef, vert, dete)
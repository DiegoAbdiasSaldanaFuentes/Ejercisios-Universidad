def largo(vari):
    cont = 0
    for elem in vari:
        cont += 1
    return cont

def busca (lista):
    n1 = largo(lista[0])
    n2 = largo(lista[1])
    n3 = largo(lista[2])
    if n1 > n2:
        if n1> n3:
            return n1
        else:
            return n3
    else:
        if n2 > n3:
            return n2
        else:
            return n3
    
def suma(lista):
    su = 0
    for elem in lista:
        su = su + len(elem)
    return su

def procedimiento(lista):
    l = []
    p = ''
    for elem in lista :
        p = ''
        i= 0
        while i < elem:
            p = p + "*"
            i = i +1
        l.append(p)
    return l

def muestra(elem, lista):
    salida = [[elem], [lista]]
    print(salida)

if __name__ == '__main__':
    l = [4,9,7]
    l = procedimiento(l)
    elem = busca(l)
    l = suma(l)
    muestra(elem, l)

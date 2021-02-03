# OprArreglos.py
from ModulosPY.ItemBase import ItemBase
TMAX = 50
def Ascendente(x, y):
    return x.Comparar(y) <= 0
def Descendente(x, y):
    return x.Comparar(y) >= 0
def LeerArreglo():
    print("INGRESAR EL ARREGLO: ")
    X = []
    ra = range(0, TMAX)
    for n in ra:
        y = ItemBase(0, 0, "")
        y, estado = y.Leer(n)
        if estado == 0:
            return X, n
        X.append(y)
    return X, n
def EscribirArreglo(X, n, ms):
    print(ms)
    cad = ""
    rx = range(0, n)
    for i in rx:
        cad = X[i].Mostrar(cad)
    print(cad, "\n")

def feval(funcName, *args):
    return eval(funcName)(*args)
def Copiar(Fuente, n):
    X = []
    r1 = range(0, n)
    for i in r1:
        X.append(Fuente[i])
    return X
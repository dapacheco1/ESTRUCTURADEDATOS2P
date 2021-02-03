# OrdSimpleArreglos.py
# METODOS DE ORDENAMIENTO SIMPLE EN ARREGLOS DE OBJETOS
from ModulosPY.ItemBase import ItemBase
import OprArreglos as oar
def OrdBurbuja(X, n, O):
    i = 0
    while i < n - 1:
        k = n - 2
        r2 = range(n-2, i - 1, -1)
        for j in r2:
            if not oar.feval(O, X[j], X[j + 1]):
                X[j], X[j + 1] = X[j + 1], X[j]
                k = j
        i = k + 1
def OrdSacudida(X, n, O):
    Iz = 0
    De = n - 1
    while Iz <De:
        k = De - 1
        r2 = range(De - 1, Iz - 1, -1)
        for j in r2:
            if not oar.feval(O, X[j], X[j + 1]):
                X[j], X[j + 1] = X[j + 1], X[j]
                k = j
        Iz = k + 1
        r2 = range(k + 1, De)
        for j in r2:
            if not oar.feval(O, X[j], X[j + 1]):
                X[j], X[j + 1] = X[j + 1], X[j]
                k = j
        De = k
def OrdInsLineal(A, n, O):
    x = ItemBase(0, 0, "")
    A.append(x)
    r1 = range(n - 2, -1, -1)
    for i in r1:
        j = i
        X = A[j]
        A[n] = X
        while not oar.feval(O, X, A[j + 1]):
            A[j] = A[j+1]
            j += 1
        A[j] = X
# METODO POR SELECCION
def MaxArr(A, n, O):
    Ind = 0
    X = A[0]
    r1 = range(1, n)
    for i in r1:
        if oar.feval(O, X, A[i]):
            Ind = i
            X = A[i]
    return Ind, X

def OrdSeleccion(A, n, O):
    r1 = range(n - 1, 0, -1)
    for i in r1:
        j, X = MaxArr(A, i + 1, O)
        A[j] = A[i]
        A[i] = X
# Funcion Principal
ItemBase.Indicador = 0 # Para Leer y Escribir por clave
A, tl = oar.LeerArreglo()
oar.EscribirArreglo(A, tl, "ARREGLO INGRESADO:")
B = oar.Copiar(A, tl)
OrdBurbuja(B, tl, "Ascendente")
oar.EscribirArreglo(B, tl, "METODO DE LA BURBUJA: ORDENADO ASCENDENTEMENTE:")
B = oar.Copiar(A, tl)
OrdBurbuja(B, tl, "Descendente")
oar.EscribirArreglo(B, tl, "METODO DE LA BURBUJA: ORDENADO DESCENDENTEMENTE:")
B = oar.Copiar(A, tl)
OrdSacudida(B, tl, "Ascendente")
oar.EscribirArreglo(B, tl, "METODO DE LA SACUDIDA: ORDENADO ASCENDENTEMENTE:")
B = oar.Copiar(A, tl)
OrdSacudida(B, tl, "Descendente")
oar.EscribirArreglo(B, tl, "METODO DE LA SACUDIDA: ORDENADO DESCENDENTEMENTE:")
B = oar.Copiar(A, tl)
OrdInsLineal(B, tl, "Ascendente")
oar.EscribirArreglo(B, tl, "METODO DE INSERCION LINEAL: ORDENADO ASCENDENTEMENTE:")
B = oar.Copiar(A, tl)
OrdInsLineal(B, tl, "Descendente")
oar.EscribirArreglo(B, tl, "METODO DE INSERCION LINEAL: ORDENADO DESCENDENTEMENTE:")
B = oar.Copiar(A, tl)
OrdSeleccion(B, tl, "Ascendente")
oar.EscribirArreglo(B, tl, "METODO DE SELECCION: ORDENADO ASCENDENTEMENTE:")
B = oar.Copiar(A, tl)
OrdSeleccion(B, tl, "Descendente")
oar.EscribirArreglo(B, tl, "METODO DE SELECCION: ORDENADO DESCENDENTEMENTE:")

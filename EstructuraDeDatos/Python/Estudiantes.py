# Estudiantes.py
TMAX = 50
from ModulosPY.CEstudiante import CEstudiante
#import CEstudiante as ces
TMAX = 50
def Ascendente(x, y):
    return x.Comparar(y) <= 0
def Descendente(x, y):
    return x.Comparar(y) >= 0
def LeerNomina():
    print("INGRESAR LA NOMINA DE ESTUDIANTES: ")
    X = []
    ra = range(0, TMAX)
    for n in ra:
        y = CEstudiante("", "", 0, 0, 0)
        y, estado = y.Leer(n)
        if estado == 0:
            return X, n
        X.append(y)
    return X, n

def EscribirNomina(X, n, ms):
    print(ms)
    print("CEDULA NOMBRE NOTA1 NOTA2 NOTA3 PROMEDIO OBSERVACION")
    rx = range(0, n)
    for i in rx:
        X[i].Mostrar()
    print("\n")

def feval(funcName, *args):
    return eval(funcName)(*args)
def Ordenar(X, n, O, cn):
    CEstudiante.Indicador = cn
    ri = range(0, n - 1)
    for i in ri:
        rj = range(i+1, n)
        for j in rj:
            if not feval(O, X[i], X[j]):
                X[i], X[j] = X[j], X[i]
    return X
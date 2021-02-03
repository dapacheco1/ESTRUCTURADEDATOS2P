# BsqArreglos.py
TMAX = 50
from ModulosPY.CEstudiante import CEstudiante
import Estudiantes as est

def BsqSecuencial(A, n, X):
    ri = range(0, n)
    for i in ri:
        if X.Comparar(A[i])== 0:
            return i
    return -1

def BsqBinaria(A, n, X):
    izq = 0
    der = n -1
    while izq <= der:
        med = (izq + der) // 2
        if X.Comparar(A[med])> 0:
            izq = med + 1
        elif X.Comparar(A[med])< 0:
            der = med - 1
        else:
            return med
    return -1

# Funcion Principal
CEstudiante.Indicador = 0 # Busqueda por cedula
A, tl = est.LeerNomina()
X = CEstudiante("", "", 0, 0, 0)
est.EscribirNomina(A, tl, "NOMINA INGRESADA:")
print("BUSQUEDA SECUENCIAL:")
while tl > 0:
    cad = input("INGRESAR LA CEDULA A BUSCAR (SALIR VACIA): ")
    if len(cad) == 0:
        break
    X.SetCedula(cad)
    pos = BsqSecuencial(A, tl, X)
    if pos < 0:
        print(cad, " NO SE ENCUENTRA EN EL ARREGLO")
    else:
        print(cad, " SE ENCUENTRA EN LA POSICION ", pos)
        A[pos].Mostrar()
    A = est.Ordenar(A, tl, "Ascendente", 0)
    print("BUSQUEDA BINARIA:")
    while tl > 0:
        cad = input("INGRESAR LA CEDULA A BUSCAR (SALIR VACIA): ")
        if len(cad) == 0:
            break
        X.SetCedula(cad)
        pos = BsqBinaria(A, tl, X)
        if pos < 0:
            print(cad, " NO SE ENCUENTRA EN EL ARREGLO")
        else:
            print(cad, " SE ENCUENTRA EN LA POSICION ", pos)
            A[pos].Mostrar()

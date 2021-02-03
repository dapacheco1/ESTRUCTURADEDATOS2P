# CEstudiante.py
class CEstudiante:
    Indicador = 0
    def __init__(elm, ced, nom, nt1, nt2, nt3):
        elm.cedula = ced
        elm.nombre = nom
        elm.nota1 = nt1
        elm.nota2 = nt2
        elm.nota3 = nt3

    def Leer(elm, ind):
        cad = input("ALUMNO[" + str(ind) + "], cedula (salir = NULA): ")
        if len(cad) == 0:
            return elm, 0
        elm.cedula = cad
        cad = input("nombre (salir = NULO): ")
        if len(cad) == 0:
            return elm, 0
        elm.nombre = cad
        elm.nota1 = float(input("nota 1: "))
        elm.nota2 = float(input("nota 2: "))
        elm.nota3 = float(input("nota 3: "))
        return elm, 1
    def Mostrar(x):
        prom = round((x.nota1 + x.nota2 + x.nota3) / 3, 2)
        print(x.cedula, " ", x.nombre, " ", x.nota1, " ", x.nota2, " ", x.nota3, " ",
        prom, "REPRUEBA" if prom < 14 else "APRUEBA")
    def Comparar(elm, y):
        if CEstudiante.Indicador == 0:
            if elm.cedula < y.cedula:
                return -1
            if elm.cedula > y.cedula:
                return 1
            return 0
        if elm.nombre < y.nombre:
            return -1
        if elm.nombre > y.nombre:
            return 1
        return 0
    def SetCedula(elm, x):
        elm.cedula = x
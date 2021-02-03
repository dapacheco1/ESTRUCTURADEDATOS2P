# ItemBase.py
class ItemBase:
    Indicador = 0
    def __init__(elm, clv, cuenta, dato):
        elm.clave = clv
        elm.cuenta = cuenta
        elm.dato = dato

    def Leer(elm, ind):
        val = int(input("ITEM[" + str(ind) + "], clave (salir <= 0): "))
        if val <= 0:
            return elm, 0
        elm.clave = val
        if ItemBase.Indicador == 0:
            return elm, 1
        cad = input("dato (salir = NULO): ")
        if len(cad) == 0:
            return elm, 0
        elm.dato = cad
        return elm, 1
    def Mostrar(x, cad):
        cad += str(x.clave)+ " "
        if ItemBase.Indicador == 0:
            return cad
        if ItemBase.Indicador >= 1:
            cad += str(x.cuenta)+ " "
        if ItemBase.Indicador == 1:
            return cad
        cad += str(x.dato)+ "\n "
        return cad
    def Comparar(elm, y):
        return elm.clave - y.clave
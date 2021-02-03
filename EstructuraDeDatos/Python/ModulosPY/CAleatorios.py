# CAleatorios.py
import time
import random
t = int(time.time())
random.seed(t)
class CAleatorios:
    def __init__(self, a, n):
        self.a = a
        self.n = n
    def Aleatorio(elm, m, n):
        return random.randint(m, n)
    def GetVal(elm, i):
        return elm.a[i]

    def Buscar(elm, tl, x):
        for pos in range(tl):
            if x == elm.a[pos]:
                return -1
    def Generar(elm):
        i = 0
        n = elm.n
        while (i < n):
            alt = elm.Aleatorio(0, n - 1)
            pos =elm.Buscar(i, alt)
            if pos<0:
                elm.a.append(alt)
                i += 1
                
    def Mostrar(elm):
        cad = ""
        for i in range(elm.n):
            cad += str(elm.a[i])+ " "
        print(cad)
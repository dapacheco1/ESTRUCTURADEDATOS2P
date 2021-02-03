# MovCaballo.py
from ModulosPY.CAleatorios import CAleatorios
def Intentar(I, X, Y):
    global TerminoRecorrido
    K = -1
    while (not TerminoRecorrido and K < 7):
        K += 1
        Val = alt.GetVal(K)
        U = X + A[Val]
        V = Y + B[Val]
        if (U >= 0 and U < DimTab and V >= 0 and V < DimTab and Tablero[U][V] == 0):
            Tablero[U][V] = I
            if (I < DimTab * DimTab ):
                Intentar(I+1,U,V)
                if (not TerminoRecorrido):
                    Tablero[U][V] = 0
            else:
                TerminoRecorrido = True
def EscribirResultado():
    print( "\nMOVIMIENTOS DEL CABALLO")
    print("DIMENSION DEL TABLERO: ", DimTab)
    print("UBICACION INICIAL DEL CABALLO: (" , X0, ", ", Y0, ")\nTIPOS DE MOVIMIENTOS ALEATORIOS:")
    alt.Mostrar()
    print("")
    for I in range(DimTab):
        Tablero.append([])
        for J in range(DimTab):
            Tablero[I].append(0)
    Tablero[X0][Y0] = 1
    Intentar(2, X0, Y0)
    if (TerminoRecorrido):
        for I in range(DimTab):
            cad = ""
            for J in range(DimTab):
                cad += str(Tablero[I][J]) + " "
            print(cad)
    else:
        print("NO HAY SOLUCION")
        print("\n")

# Funcion Principal:
MaxTab = 8
alt = CAleatorios([], 8)
alt.Generar()
A = [2, 1, -1, -2, -2, -1, 1, 2]
B = [1, 2, 2, 1, -1, -2, -2, -1]
Tablero = []
TerminoRecorrido = False
DimTab = 0
X0 = 0
Y0 = 0
while (1):
    DimTab = int(input( "INGRESAR LA DIMENSION DEL TABLERO (DE 3 A " + str(MaxTab)+ ", SINO SALE): "))
    if (DimTab < 3 or DimTab > MaxTab):
        break
    print( "INGRESAR LAS COORDENADAS INICIALES DEL CABALLO ")
    X0 = int(input( "X0, PARA SALIR DIGITAR VALORES FUERA DE RANGO: "))
    Y0 = int(input( "Y0, PARA SALIR DIGITAR VALORES FUERA DE RANGO: "))
    if (X0 < 0 or X0 > DimTab or Y0 < 0 or Y0 > DimTab):
        break
    Tablero = []
    TerminoRecorrido = False
    EscribirResultado()
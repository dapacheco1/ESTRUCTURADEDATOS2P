# TorresHanoi.py
def NomPoste(argument):
    Poste = {
        0: "Izquierdo",
        1: "Medio",
        2: "Derecho"
    }
    return Poste.get(argument, "N/A")

def PasarDisco(n, org, dst):
     print( "Pasar el disco " + str( n)+ " desde el poste " + NomPoste(org)+ " hacia el poste " + NomPoste(dst))

def MoverDiscos(nm, org, dst, aux):
    if (nm == 1):
        PasarDisco(nm, org, dst)
    else :
        MoverDiscos(nm - 1, org, aux, dst)
        PasarDisco(nm, org, dst)
        MoverDiscos(nm - 1, aux, dst, org)

# Funcion Principal:
while (1):
    n = int(input( "Ingresar el numero de discos (salir < 1 o > 10): "))
    if (n < 1 or n > 10):
        break
    print("Ingresar el poste origen:")
    origen = int(input( "0 --> Izquierdo, 1 --> Medio, 2 --> derecho (salir --> otro valor): "))
    if (origen < 0 or origen > 2):
        break
    print("Ingresar el poste destino:")
    destino = int(input( "0 --> Izquierdo, 1 --> Medio, 2 --> derecho (salir --> otro valor): "))
    if (destino < 0 or destino > 2 or origen == destino):
        break
    print( "Secuencia de pasos para mover " + str( n) + " discos desde el poste " +NomPoste(origen) + " hacia el poste " + NomPoste(destino))
    MoverDiscos(n, origen, destino, 3 - origen - destino)
    print("")
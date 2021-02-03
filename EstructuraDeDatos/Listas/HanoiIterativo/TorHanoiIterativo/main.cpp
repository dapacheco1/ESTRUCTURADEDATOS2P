// TorHanoiIterativo
#include "CHanoi.h"
int main()
{
 int n, origen, destino;
 CHanoi CH;
 while (1) {
 cout << "Ingresar el numero de discos (salir < 1 o > 10): ";
 cin >> n;
 if (n < 1 || n > 10) break;
 cout << "Ingresar el poste origen:\n";
 cout << "0 --> Izquierdo, 1 --> Medio, 2 --> derecho (salir --> otro valor): ";
 cin >> origen;
 if (origen < 0 || origen > 2) break;
 cout << "Ingresar el poste destino:\n";
 cout << "0 --> Izquierdo, 1 --> Medio, 2 --> derecho (salir --> otro valor): ";
 cin >> destino;
 if (destino < 0 || destino > 2 || origen == destino) break;
 cout << "Secuencia de pasos para mover " << n << " discos desde el poste ";
 CH.EscribirPoste(origen);
 cout <<" hacia el poste ";
 CH.EscribirPoste(destino);
 cout << endl;
 CH.MoverDiscosI(n, origen, destino, 3 - origen - destino);
 cout << endl;
 }
 return 0;
}

// TorresHanoi
#include <iostream>
using namespace std;
// Prototipado:
void MoverDiscos(int, int, int, int);
void PasarDisco(int, int, int);
void EscribirPoste(int);
// Definicion de funciones:
int main()
{
 int n, origen, destino;
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
 EscribirPoste(origen);
 cout <<" hacia el poste ";
 EscribirPoste(destino);
 cout << endl;
 MoverDiscos(n, origen, destino, 3 - origen - destino);
 cout << endl;
 }
 return 0;
}
void MoverDiscos(int nm, int org, int dst, int aux) {
 if (nm == 1)
 PasarDisco(nm, org, dst);
 else {
 MoverDiscos(nm - 1, org, aux, dst);
  PasarDisco(nm, org, dst);
 MoverDiscos(nm - 1, aux, dst, org);
 }
}
void PasarDisco(int n, int org, int dst) {
 cout << "Pasar el disco " << n << " desde el poste ";
 EscribirPoste(org);
 cout << " hacia el poste ";
 EscribirPoste(dst);
 cout << endl;
}
void EscribirPoste(int p) {
 switch (p) {
 case 0: cout << "izquierdo"; break;
 case 1: cout << "medio"; break;
 case 2: cout << "derecho"; break;
 }
}

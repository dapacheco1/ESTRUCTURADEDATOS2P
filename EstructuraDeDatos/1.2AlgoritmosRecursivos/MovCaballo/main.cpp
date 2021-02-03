// MovCaballo
#include <iostream>
#include <CAleatorios.h>
#define MaxTab 8
using namespace std;
// Variables globales
CAleatorios Alt(8);
static int A[] = {2, 1, -1, -2, -2, -1, 1, 2},
 B[] = {1, 2, 2, 1, -1, -2, -2, -1};
int Tablero[MaxTab][MaxTab], TerminoRecorrido, DimTab, X0, Y0;
// Prototipos
void Intentar(int I, int X, int Y);
void EscribirResultado();
// Funciones
int main()
{
 while (1) {
 cout << "INGRESAR LA DIMENSION DEL TABLERO (DE 3 A " <<
 MaxTab << ", SINO SALE): ";
 cin >> DimTab;
 if (DimTab < 3 || DimTab > MaxTab)
 break;
 cout << "INGRESAR LAS COORDENADAS INICIALES DEL CABALLO \n";
 cout << "PARA SALIR DIGITAR VALORES FUERA DE RANGO: ";
 cin >> X0 >> Y0;
 if (X0 < 0 || X0 > DimTab || Y0 < 0 || Y0 > DimTab)
 break;
 EscribirResultado();
 }
}
void Intentar(int I, int X, int Y)
{ // Intentar
 int U,V,K = -1;
 do {
 U = X + A[Alt.a[++K]];
 V = Y + B[Alt.a[K]];
 if (U >= 0 && U < DimTab && V >= 0 && V < DimTab &&
 Tablero[U][V] == 0) {
 Tablero[U][V] = I;
 if (I < DimTab * DimTab ) {
 Intentar(I+1,U,V);
 if (!TerminoRecorrido)
 Tablero[U][V] = 0;
 }
 else
 TerminoRecorrido = 1;
 }
 }
 while (!TerminoRecorrido && K < 7);
} // Intentar;
void EscribirResultado() {
 int I, J;
 cout << "\nMOVIMIENTOS DEL CABALLO\n"
 "DIMENSION DEL TABLERO: " << DimTab << endl <<
 "UBICACION INICIAL DEL CABALLO: (" << X0 << ", " << Y0 <<
 ")\nTIPOS DE MOVIMIENTOS ALEATORIOS:\n";
 Alt.Mostrar();
 cout << endl;
 TerminoRecorrido = 0;
 for (I = 0; I < DimTab ; I++)
 for (J = 0; J < DimTab; J++)
     Tablero[I][J] = 0;
 Tablero[X0][Y0] = 1;
 Intentar(2, X0, Y0);
 if (TerminoRecorrido)
 for (I = 0; I < DimTab; I++)
 for (J = 0; J < DimTab; J++)
 cout << Tablero[I][J] << (J == DimTab - 1 ? "\n" : " ");
 else
 cout << "NO HAY SOLUCION\n";
 cout << endl << endl;
}

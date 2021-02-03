// BusquedaArreglos
/* Utiliza un arreglo de punteros a objetos y
 asignacion dinamica de memoria */
#include <OprArreglos.h>
int BsqSecuencial(TArrObj, int, ItemOrden);
int BsqBinaria(TArrObj, int, ItemOrden);
// DEFINICION DE FUNCIONES:
int Elemento::m_Indicador = 0; // Para buscar por cedula
int main()
{
 TArrObj A;
 char cad[11];
 ItemOrden X;
 int pos, tl = LeerArreglo(A,"INGRESAR LA NOMINA DE ESTUDIANTES:");
 EscribirArreglo(A, tl, "NOMINA INGRESADA:", true);
 cout << "BUSQUEDA SECUENCIAL:" << endl;
 while (tl > 0) {
 cout << "INGRESAR LA CEDULA A BUSCAR (SALIR VACIA): ";
 gets(cad);
 if (strlen(cad) == 0) break;
 X.SetCedula(cad);
 pos = BsqSecuencial(A, tl, X);
 if (pos < 0)
 cout << cad << " NO SE ENCUENTRA EN EL ARREGLO" << endl;
 else {
 cout << "SE ENCUENTRA EN LA POSICION " << pos << endl;
 A[pos]->Muestra();
 }
 }
 Ordenar(A, &ItemOrden::Ascendente, tl, 0);
 cout << "BUSQUEDA BINARIA:" << endl;
 while (tl > 0) {
 cout << "INGRESAR LA CEDULA A BUSCAR (SALIR VACIA): ";
 gets(cad);
 if (strlen(cad) == 0) break;
 X.SetCedula(cad);
 pos = BsqBinaria(A, tl, X);
 if (pos < 0)
 cout << cad << " NO SE ENCUENTRA EN EL ARREGLO" << endl;
 else {
 cout << "SE ENCUENTRA EN LA POSICION " << pos << endl;
 A[pos]->Muestra();
 }
 }
 LiberarArreglo(A, tl);
 return 0;
}
int BsqSecuencial(TArrObj A, int n, ItemOrden X) {
 int p;
 for (p = 0; p < n; p ++)
 if (X == *A[p])
 return p;
 return -1;
}
int BsqBinaria(TArrObj A, int n, ItemOrden X) {
 int izq, med, der;
 for (izq = 0, der = n - 1; izq <= der;) {
med = (izq + der) / 2;
 if (X > *A[med])
 izq = med + 1;
 else if (X < *A[med])
 der = med - 1;
 else
 return med;
 }
 return -1;
}

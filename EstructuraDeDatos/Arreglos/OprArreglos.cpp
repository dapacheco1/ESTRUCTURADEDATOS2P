// OprArreglos.cpp
// Operaciones en arreglos de punteros a objetos
/* Utiliza un asignacion dinamica de memoria */
#include <OprArreglos.h>
int LeerArreglo(TArrObj X, char *mg) {
 int n;
 cout << mg << endl;
 for (n = 0; n < TMAX; n ++) {
 X[n] = new ItemOrden; // Crea dinamicamente memoria para X[n]
 if (!X[n]->Lee(n)) return n;
 }
 return n;
}
void EscribirArreglo(TArrObj X, int n, char *ms, bool cabecera) {
 int i;
 cout << ms << endl;
 if (cabecera)
 cout << "CEDULA NOMBRE NOTA1 NOTA2 NOTA3 PROMEDIO OBSERVACION\n";
 for (i = 0; i < n; i++)
 X[i]->Muestra();
 cout << endl;
}
void Copiar(TArrObj Fuente, TArrObj Destino, int n) {
 int i;
 for (i = 0; i < n; i ++) {
 Destino[i] = new ItemOrden;
 Destino[i]->Copia(*Fuente[i]);
 }
}
void Intercambia(ItemOrden **x, ItemOrden **y) {
 ItemOrden *aux = *x;
 *x = *y;
 *y = aux;
}
void Ordenar(TArrObj X, ItemOrden::ORDEN Ord, int n, int dis) {
 int i, j;
 Elemento::m_Indicador = dis;
 for (i = 0; i < n - 1; i ++)
 for (j = i + 1; j < n; j ++)
 if (!(X[i]->*Ord)(*X[j]))
 Intercambia(&X[i], &X[j]);
}
void LiberarArreglo(TArrObj A, int n) {
 int i;
 for (i = 0; i < n; i ++)
 delete A[i];
}

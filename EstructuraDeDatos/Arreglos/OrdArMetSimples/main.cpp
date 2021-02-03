// OrdArMetSimples
/* Ordenamiento en arreglos por los metodos simples
Utiliza un arreglo de punteros a objetos y
 asignacion dinamica de memoria */
#include <OprArreglos.h>
void OrdBurbuja(TArrObj, ItemOrden::ORDEN, int);
void OrdSacudida(TArrObj, ItemOrden::ORDEN, int);
void OrdInsLineal(TArrObj, ItemOrden::ORDEN, int);
void OrdSeleccion(TArrObj, ItemOrden::ORDEN, int);
// DEFINICION DE FUNCIONES:
int Elemento::m_Indicador = 0; // Para leer y escribir solo la clave
int main()
{
 TArrObj A, B;
 int tl = LeerArreglo(A, "INGRESAR EL ARREGLO:");
 EscribirArreglo(A, tl, "Arreglo INGRESADO:", false);
 Copiar(A, B, tl);
 OrdBurbuja(B, &ItemOrden::Ascendente, tl);
 EscribirArreglo(B, tl,
 "METODO DE LA BURBUJA: ORDENADO ASCENDENTEMENTE:", false);
 LiberarArreglo(B, tl);
 Copiar(A, B, tl);
 OrdBurbuja(B, &ItemOrden::Descendente, tl);
 EscribirArreglo(B, tl,
 "METODO DE LA BURBUJA: ORDENADO DESCENDENTEMENTE:", false);
 LiberarArreglo(B, tl);
 Copiar(A, B, tl);
 OrdSacudida(B, &ItemOrden::Ascendente, tl);
 EscribirArreglo(B, tl,
 "METODO DE LA SACUDIDA: ORDENADO ASCENDENTEMENTE:", false);
 LiberarArreglo(B, tl);
 Copiar(A, B, tl);
 OrdSacudida(B, &ItemOrden::Descendente, tl);
 EscribirArreglo(B, tl,
 "METODO DE LA SACUDIDA: ORDENADO DESCENDENTEMENTE:", false);
 LiberarArreglo(B, tl);
 Copiar(A, B, tl);
 OrdInsLineal(B, &ItemOrden::Ascendente, tl);
 EscribirArreglo(B, tl,
 "METODO DE INSERCION LINEAL: ORDENADO ASCENDENTEMENTE:", false);
 LiberarArreglo(B, tl);
 Copiar(A, B, tl);
 OrdInsLineal(B, &ItemOrden::Descendente, tl);
 EscribirArreglo(B, tl,
 "METODO DE INSERCION LINEAL: ORDENADO DESCENDENTEMENTE:", false);
 LiberarArreglo(B, tl);
 Copiar(A, B, tl);
 OrdSeleccion(B, &ItemOrden::Ascendente, tl);
 EscribirArreglo(B, tl,
 "METODO DE SELECCION: ORDENADO ASCENDENTEMENTE:", false);
 LiberarArreglo(B, tl);
 Copiar(A, B, tl);
 OrdSeleccion(B, &ItemOrden::Descendente, tl);
 EscribirArreglo(B, tl,
 "METODO DE SELECCION: ORDENADO DESCENDENTEMENTE:", false);
 LiberarArreglo(B, tl);
}
void OrdBurbuja(TArrObj X, ItemOrden::ORDEN Ord, int n) {
 int i, j, k; // k=posicion donde se produjo el ultimo intercambio
 for (i = 0; i < n - 1; i = k + 1)
 for (j = k = n - 2; j >= i; j --)
 if (!(X[j]->*Ord)(*X[j + 1])) {
 Intercambia(&X[j], &X[j + 1]);
 k = j;
 }
}
void OrdSacudida(TArrObj X, ItemOrden::ORDEN Ord, int n) {
 int Iz, De, j, k; // k=posicion donde se produjo el ultimo intercambio
 for (Iz = 0, De = n - 1; Iz < De; De = k) {
 for (k = j = De - 1; j >= Iz; j--)
 if (!(X[j]->*Ord)(*X[j + 1])) {
 Intercambia(&X[j], &X[j + 1]);
 k = j;
 }
 for (Iz = j = k + 1; j < De; j++)
 if (!(X[j]->*Ord)(*X[j + 1])) {
 Intercambia(&X[j], &X[j + 1]);
 k = j;
 }
 }
}
void OrdInsLineal(TArrObj A, ItemOrden::ORDEN Ord, int n) {
 int i, j;
 ItemOrden *X;
 for (i = n - 2; i >= 0; i--) {
 for (j = i, X = A[j], A[n] = X; !(X->*Ord)(*A[j + 1]); j++)
 A[j] = A[j + 1];
 A[j] = X;
 }
}
void MaxArr(TArrObj A, ItemOrden::ORDEN Ord, int n,
 ItemOrden **X, int *Ind)
{// MaxArr
 int i;
 for (*Ind = 0, *X = A[0], i = 1; i < n; i++)
 if (((*X)->*Ord)(*A[i])) {
 *Ind = i; *X = A[i];
 }
}// MaxArr
void OrdSeleccion(TArrObj A, ItemOrden::ORDEN Ord, int n) {
 int i, j;
  ItemOrden *X;
 for (i = n - 1; i > 0; i--) {
 MaxArr(A, Ord, i + 1, &X, &j);
 A[j] = A[i]; A[i] = X;
 }
}

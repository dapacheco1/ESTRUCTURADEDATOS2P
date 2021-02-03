// PrbListaSEInsel
#include "CLstSEInsel.h"
using namespace std;
int Elemento::m_Indicador = 0; // Solo claves
int main()
{ int i, op;
 CLstSEInsel L, C;
 Elemento X;
 LISTA P = NULL;
 for (i = 1; i <= 10; i ++) {
 X.SetClave(i);
 if (i > 2) P = P->GetSUC();
 P = L.InsDespues(P, X);
 }
 L.EscribeLista("LISTA DE NUMEROS NATURALES:");
 L.VaciaLista();
 L.LeeLista();
 L.EscribeLista("LISTA INGRESADA:");
 L.Copiar(C);
 C.EscribeLista("LISTA COPIADA:");
 while (C.GetPrimero()) {
 cout << "1->InsDespues, 2->InsAntes, "
 "3->EliDespues, 4->EliNodo, otro->Salir: ";
 cin >> op;
 if (op < 1 || op > 4) break;
 do {
cout << "Ingresar el patron de busqueda: ";
 cin >> i;
 X.SetClave(i);
 if (!(P = C.Buscar(X)))
 cout << "No se encuentra " << i << " en la lista\n";
 }
 while (!P);
 if (op < 3) {
 cout << "Ingresar la clave a insertar: ";
 cin >> i;
 X.SetClave(i);
 }
 switch (op) {
 case 1: P = C.InsDespues(P, X); break;
 case 2: P = C.InsAntes(P, X); break;
 case 3: P = C.EliDespues(P, X); break;
 default: P = C.EliNodo(P, X);
 }
 if (op < 3)
 C.Escribir(X, "INGRESADO: ");
 else
 C.Escribir(X, "ELIMINADO: ");
 C.EscribeLista("LISTA RESULTANTE:");
 }
 C.VaciaLista();
 for (P = L.GetPrimero(); P; P = P->GetSUC()) {
 X.Copiar(P->GetDato());
 C.Empuja(X);
 }
 C.EscribeLista("PILA GENERADA");
 cout << "ELIMINACION DE LA PILA:\n";
 while (C.GetPrimero()) {
 C.Retira(X);
 X.Mostrar();
 }
 cout << endl;
 L.Copiar(C);
 L.EscribeLista("COLA GENERADA:");
 cout << "ELIMINACION DE LA COLA:\n";
 while (C.GetPrimero()) {
 C.EliCola(X);
 X.Mostrar();
 }
 cout << endl;
 L.VaciaLista();
 return 0;
}

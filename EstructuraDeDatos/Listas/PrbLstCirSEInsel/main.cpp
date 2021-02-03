// PrbLstCirSEInsel
#include "CLstCirSEInsel.h"

using namespace std;
int Elemento::m_Indicador = 0; // Solo claves
int main()
{ int i, op;
CLstCirSEInsel L, C;
Elemento X;
LISTA P = NULL, Q;
L.IniciaCola();
for (i = 1; i <= 10; i ++) {
X.SetClave(i);
L.InsCola(X);
}
L.EscribeLista("LISTA CIRCULAR DE NUMEROS NATURALES:");
L.VaciaLista();
L.LeeLista();
L.EscribeLista("LISTA CIRCULAR INGRESADA:");
L.Copiar(C);
C.EscribeLista("LISTA CIRCULAR COPIADA:");
while (C.GetUltimo() && C.GetUltimo()->GetSUC()) {
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
C.EscribeLista("LISTA CIRCULAR RESULTANTE:");
}
C.VaciaLista();
if (L.GetUltimo()) {
P = Q = L.GetUltimo()->GetSUC();
do {
X.Copiar(Q->GetDato());
C.Empuja(X);
Q = Q->GetSUC();
}
while (P != Q);
}
C.EscribeLista("PILA CIRCULAR GENERADA");
cout << "ELIMINACION DE LA PILA:\n";
while (C.GetUltimo()) {
C.Retira(X);
X.Mostrar();
}
cout << endl;
L.Copiar(C);
L.EscribeLista("COLA CIRCULAR GENERADA:");
cout << "ELIMINACION DE LA COLA:\n";
while (C.GetUltimo()) {
C.EliCola(X);
X.Mostrar();
}
cout << endl;
L.VaciaLista();
return 0;
}

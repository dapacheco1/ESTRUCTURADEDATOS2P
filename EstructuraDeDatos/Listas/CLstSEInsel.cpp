// CLstSEInsel.cpp
#include "CLstSEInsel.h"
/* INSERCION ELIMINACION EN LISTAS LINEALES CON SIMPLE
 ENLACE */
Error Er("MODULO INSERCION - ELIMINACION EN L.L.S.E.");
CLstSEInsel::CLstSEInsel()
{
 //ctor
 IniciaCola();
}
CLstSEInsel::~CLstSEInsel()
{
 //dtor
}
void CLstSEInsel::VaciaLista()
{ // VaciaLista
 LISTA Q;
 while (Primero) {
 Q = Primero;
 Primero = Primero->GetSUC();
 delete Q;
 }
} // VaciaLista
void CLstSEInsel::LeeLista()
{ // LeeLista
 int i;
 for (IniciaCola(), i = 0; ; i ++) {
 if (!Leer(i)) break;
 InsCola(GetDato());
 }
 } // LeeLista
void CLstSEInsel::EscribeLista(char *m)
{ // EscribeLista
 LISTA Q;
 cout << m << endl;
 for (Q = Primero; Q ; Q = Q->GetSUC())
 Q->Mostrar();
 cout << endl;
} // EscribeLista
LISTA CLstSEInsel::InsDespues(LISTA P, Elemento X)
{ // InsDespuesP
 LISTA Q = Obtiene(P ? P->GetSUC() : P, X);
 if (!Primero) return (Primero = Q);
 P->SetSUC(Q);
 return (P);
} // InsDespues
LISTA CLstSEInsel::InsAntes(LISTA P, Elemento X)
{ // InsAntes
 LISTA Q = InsDespues(P, X);
 if (!P)
 P = Q;
 else {
 Q = P->GetSUC();
 Elemento Y = P->GetDato();
 P->SetDato(X);
 Q->SetDato(Y);
 }
 return (P);
} // InsAntes;
LISTA CLstSEInsel::EliDespues(LISTA P, Elemento &X)
{ // EliDespues
 if (!Primero || !P) Er.Mensaje(1,
 "Error en la funcion EliDespues, Lista vacia");
 if (Primero != P && !P->GetSUC()) Er.Mensaje(1,
 "Error en la funcion EliDespues, No se puede eliminar el ultimo nodo");
 LISTA Q;
 if (!P->GetSUC()) {
 Q = P;
 Primero = P = NULL;
 }
 else {
 Q = P->GetSUC();
 P->SetSUC(Q->GetSUC());
 }
 X = Q->GetDato();
 delete Q;
 return (P);
} // EliDespues
LISTA CLstSEInsel::EliNodo(LISTA P, Elemento &X)
{ // EliNodo
 if (!Primero || !P) Er.Mensaje(1,
 "Error en la funcion EliNodo, Lista vacia");
 if (Primero != P && !P->GetSUC()) Er.Mensaje(1,
 "Error en la funcion EliNodo, No se puede eliminar el ultimo nodo");
 LISTA Q;
 X = P->GetDato();
 if (!P->GetSUC()) {
 Q = P;
 Primero = P = NULL;
 }
 else {
 Q = P->GetSUC();
 *P = *Q;
 }
 delete Q;
 return (P);
} // EliNodo
void CLstSEInsel::Empuja(Elemento X)
{ // Empuja
 Primero = Obtiene(Primero, X);
} // Empuja
void CLstSEInsel::Retira(Elemento &X)
{ // Retira
 if (!Primero) Er.Mensaje(1,
 "Error en la funcion Retira, Pila vacia");
 LISTA Q = Primero;
 X = Q->GetDato();
 Primero = Q->GetSUC();
 delete Q;
} // Retira
void CLstSEInsel::InsCola(Elemento X)
{ // InsCola
 LISTA Q = Obtiene(NULL, X);
 if (!Primero) Primero = Q;
 else Ultimo->SetSUC(Q);
 Ultimo = Q;
} // InsCola
void CLstSEInsel::EliCola(Elemento &X)
{ // EliCola
 if (!Primero) Er.Mensaje(1,
 "Error en la funcion EliCola, Cola vacia");
 Retira(X);
 if (!Primero) Ultimo = Primero;
} // EliCola
void CLstSEInsel::Copiar(CLstSEInsel &Dst)
{ // Copiar
 LISTA P = Primero, Q;
 Elemento X;
 for (Dst.IniciaCola(); P; P = P->GetSUC()) {
 X = P->GetDato();
 Dst.InsCola(X);
 }
} // Copiar
LISTA CLstSEInsel::Buscar(Elemento X)
{ // Buscar
 LISTA P;
  for (P = Primero; P; P = P->GetSUC())
 if (X.Compara(P->GetDato()) == 0) return P;
 return NULL;
} // Buscar
void CLstSEInsel::Escribir(Elemento X, char *m) {
 cout << m << " ";
 X.Mostrar();
 cout << endl;
}

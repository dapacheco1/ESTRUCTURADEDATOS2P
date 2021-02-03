// CLstCirSEInsel.cpp
#include "CLstCirSEInsel.h"
/* INSERCION ELIMINACION EN LISTAS CIRCULARES CON SIMPLE
 ENLACE */
Error Er("MODULO INSERCION - ELIMINACION EN L.C.S.E.");
CLstCirSEInsel::CLstCirSEInsel()
{
 //ctor
 IniciaCola();
}
CLstCirSEInsel::~CLstCirSEInsel()
{
 //dtor
}
void CLstCirSEInsel::VaciaLista()
{ // VaciaLista
 if (Ultimo) {
 LISTA P, Q, R;
 P = Q = Ultimo->GetSUC();
 do {
 R = Q;
 Q = Q->GetSUC();
 delete R;
 }
 while (Q != P);
 Ultimo = NULL;
 }
} // VaciaLista
int CLstCirSEInsel::LeeLista()
{ // LeeLista
 int i;
 for (IniciaCola(), i = 0; ; i ++) {
 if (!Leer(i)) break;
 InsCola(GetDato());
 }
 return i;
 } // LeeLista
void CLstCirSEInsel::EscribeLista(char *m)
{ // EscribeLista
 LISTA P, Q;
 cout << m << endl;
 if (Ultimo) {
 P = Q = Ultimo->GetSUC();
 do {
 Q->Mostrar();
 Q = Q->GetSUC();
 }
 while (Q != P);
 }
 cout << endl;
} // EscribeLista
LISTA CLstCirSEInsel::InsDespues(LISTA P, Elemento X)
{ // InsDespuesP
 LISTA Q = Obtiene(P ? P->GetSUC() : P, X);
 if (!Ultimo) Ultimo = P = Q;
 P->SetSUC(Q);
 return (P);
} // InsDespues
LISTA CLstCirSEInsel::InsAntes(LISTA P, Elemento X)
{ // InsAntes
 LISTA Q;
 if (!Ultimo) Ultimo = P = Q =Obtiene(NULL, X);
 else {
 Elemento Y = P->GetDato();
 Q = Obtiene(P->GetSUC(), Y);
 P->SetDato(X);
 }
 P->SetSUC(Q);
 if (P == Ultimo) Ultimo = P->GetSUC();
 return (P);
} // InsAntes;
LISTA CLstCirSEInsel::EliDespues(LISTA P, Elemento &X)
{ // EliDespues
 if (!Ultimo || !P) Er.Mensaje(1,
 "Error en la funcion EliDespues, Lista vacia");
 LISTA Q;
 if (P == P->GetSUC()) {
 Q = P;
  Ultimo = P = NULL;
 }
 else {
 Q = P->GetSUC();
 P->SetSUC(Q->GetSUC());
 if (Ultimo == Q) Ultimo = Q->GetSUC();
 }
 X = Q->GetDato();
 delete Q;
 return (P);
} // EliDespues
LISTA CLstCirSEInsel::EliNodo(LISTA P, Elemento &X)
{ // EliNodo
 if (!Ultimo || !P) Er.Mensaje(1,
 "Error en la funcion EliNodo, Lista vacia");
 LISTA Q;
 X = P->GetDato();
 if (P == P->GetSUC()) {
 Q = P;
 Ultimo = P = NULL;
 }
 else {
 Q = P->GetSUC();
 *P = *Q;
 if (Ultimo == Q) Ultimo = Q->GetSUC();
 }
 delete Q;
 return (P);
} // EliNodo
void CLstCirSEInsel::Empuja(Elemento X)
{ // Empuja
 LISTA Q = Obtiene(Ultimo ? Ultimo->GetSUC() : Ultimo, X);
 if (!Ultimo) Ultimo = Q;
 Ultimo->SetSUC(Q);
} // Empuja
void CLstCirSEInsel::Retira(Elemento &X)
{ // Retira
 if (!Ultimo) Er.Mensaje(1,
 "Error en la funcion Retira, Pila vacia");
 LISTA Q = Ultimo->GetSUC();
 X = Q->GetDato();
 if (Q == Ultimo) Ultimo = NULL;
 else Ultimo->SetSUC(Q->GetSUC());
  delete Q;
} // Retira
void CLstCirSEInsel::InsCola(Elemento X)
{ // InsCola
 Empuja(X);
 Ultimo = Ultimo->GetSUC();
} // InsCola
void CLstCirSEInsel::EliCola(Elemento &X)
{ // EliCola
 if (!Ultimo) Er.Mensaje(1,
 "Error en la funcion EliCola, Cola vacia");
 Retira(X);
} // EliCola
void CLstCirSEInsel::Copiar(CLstCirSEInsel &Dst)
{ // Copiar
 Dst.IniciaCola();
 if (Ultimo) {
 LISTA P, Q;
 Elemento X;
 P = Q = Ultimo->GetSUC();
 do {
 X = Q->GetDato();
 Dst.InsCola(X);
 Q = Q->GetSUC();
 }
 while (P != Q);
 }
} // Copiar
LISTA CLstCirSEInsel::Buscar(Elemento X)
{ // Buscar
 if (Ultimo) {
 LISTA P, Q;
 P = Q = Ultimo->GetSUC();
 do {
 if (X.Compara(Q->GetDato()) == 0) return Q;
 Q = Q->GetSUC();
 }
 while (P != Q);
 }
 return NULL;
} // Buscar
void CLstCirSEInsel::Escribir(Elemento X, char *m) {
 cout << m << " ";
 X.Mostrar();
 cout << endl;
}

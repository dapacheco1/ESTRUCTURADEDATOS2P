// CLstSEInsel.h
#ifndef CLSTSEINSEL_H
#define CLSTSEINSEL_H
#include <CListaSE.h>
class CLstSEInsel : public CListaSE
{
 public:
 CLstSEInsel();
 virtual ~CLstSEInsel();
 LISTA GetPrimero() {return Primero; }
 void SetPrimero(LISTA P) {Primero = P; }
 LISTA GetUltimo() {return Ultimo; }
 void SetUltimo(LISTA U) {Ultimo = U; }
 void VaciaLista();
 void EscribeLista(char *);
 void LeeLista();
 LISTA InsDespues(LISTA, Elemento);
 LISTA InsAntes(LISTA, Elemento);
 LISTA EliDespues(LISTA, Elemento &);
 LISTA EliNodo(LISTA, Elemento &);
 void Empuja(Elemento);
 void Retira(Elemento &);
 void IniciaCola() {
 Primero = Ultimo = NULL;
 }
 void InsCola(Elemento);
 void EliCola(Elemento &);
 void Copiar(CLstSEInsel &);
 LISTA Buscar(Elemento);
 void Escribir(Elemento, char *);
 protected:
 LISTA Primero, Ultimo;
 private:
};
#endif // CLSTSEINSEL_H

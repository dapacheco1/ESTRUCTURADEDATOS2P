// CLstCirSEInsel.h
#ifndef CLSTCIRSEINSEL_H
#define CLSTCIRSEINSEL_H
#include <CListaSE.h>
class CLstCirSEInsel : public CListaSE
{
 public:
 CLstCirSEInsel();
 virtual ~CLstCirSEInsel();
 LISTA GetUltimo() {return Ultimo; }
 void SetUltimo(LISTA U) {Ultimo = U; }
 void VaciaLista();
 void EscribeLista(char *);
int LeeLista();
 LISTA InsDespues(LISTA, Elemento);
 LISTA InsAntes(LISTA, Elemento);
 LISTA EliDespues(LISTA, Elemento &);
 LISTA EliNodo(LISTA, Elemento &);
 void Empuja(Elemento);
 void Retira(Elemento &);
 void IniciaCola() {
 Ultimo = NULL;
 }
 void InsCola(Elemento);
 void EliCola(Elemento &);
 void Copiar(CLstCirSEInsel &);
 LISTA Buscar(Elemento);
 void Escribir(Elemento, char *);
 protected:
 LISTA Ultimo;
 private:
};
#endif // CLSTCIRSEINSEL_H

// ItemOrden.h
#ifndef ITEMORDEN_H
#define ITEMORDEN_H
 //#include "CEstudiante.h"
#include "ItemBase.h"
/* ESTRUCTURA BASICA PARA ORDENAR ARREGLOS, ARCHIVOS,
LISTAS, ARBOLES, ETC. */
class ItemOrden : public Elemento
{
 public:
 ItemOrden();
 virtual ~ItemOrden();
 typedef int (ItemOrden::*ORDEN)(ItemOrden &);
 int Lee(int);
 void Copia(ItemOrden);
 int Lee(FILE *);
 void Muestra();
 void Muestra(FILE *);
 int Comparar(ItemOrden &);
 int Ascendente(ItemOrden &);
 int Descendente(ItemOrden &);
 int Desordenado(ItemOrden &);
 int operator > (ItemOrden &);
  int operator < (ItemOrden &);
 int operator >= (ItemOrden &);
 int operator <= (ItemOrden &);
 int operator == (ItemOrden &);
 int operator != (ItemOrden &);
 protected:
 private:
};
#endif // ITEMORDEN_H

// CListaSE.h
#ifndef CLISTASE_H
#define CLISTASE_H
#include <ItemOrden.h>
//#include<ItemHanoi.h> descomentar para hanoi iterativo
/* ESTRUCTURA PARA LISTAS CON SIMPLE ENLACE LINEALES
 Y CIRCULARES USANDO ASIGNACION DINAMICA DE MEMORIA */
class CListaSE;
typedef CListaSE *LISTA;
class CListaSE : public Elemento
{
 public:
 CListaSE();
 virtual ~CListaSE();
 Elemento GetDato() {return GetEste(); }
 void SetDato(Elemento X) {Copiar(X); }
 LISTA GetSUC() {return SUC; }
 void SetSUC(LISTA P) {SUC = P; }
 LISTA Obtiene(const LISTA, Elemento);
 void Libera(int = 0);
 protected:
 LISTA SUC;
 private:
};
#endif // CLISTASE_H

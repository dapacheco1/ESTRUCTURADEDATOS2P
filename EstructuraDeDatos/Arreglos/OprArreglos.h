// OprArreglos.h
#ifndef OPRARREGLOS_H_INCLUDED
#define OPRARREGLOS_H_INCLUDED
// Ordarreg.cpp
// Operaciones en arreglos de punteros a objetos
#include <ItemOrden.h>
#define TMAX 50
// Definicion de tipos:
typedef ItemOrden *TArrObj[TMAX];
// Prototipos:
int LeerArreglo(TArrObj, char *);
void EscribirArreglo(TArrObj, int, char *, bool);
void Copiar(TArrObj, TArrObj, int);
void Intercambia(ItemOrden **, ItemOrden **);
void Ordenar(TArrObj,ItemOrden::ORDEN, int, int);
void LiberarArreglo(TArrObj, int);
#endif // OPRARREGLOS_H_INCLUDED

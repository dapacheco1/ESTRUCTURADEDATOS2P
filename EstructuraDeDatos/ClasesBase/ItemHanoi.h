// ItemHano.h
#ifndef ITEMHANOI_H
#define ITEMHANOI_H
#include <iostream>
#include <stdio.h>
#include<cstdlib>
#include <string.h>
#include <Error.h>
using namespace std;
class Elemento
{
 public:
 int Alt, Org, Dst, Aux;
 Elemento() {}
 virtual ~Elemento() {}
 Elemento GetDato() {return GetEste(); }
 void SetDato(Elemento X) {Copiar(X); }
 Elemento GetEste() {return *this; }
 void Copiar(Elemento X) {*this = X;}
 int Leer(int) {}
 void Mostrar() {}
 int Compara(Elemento) {}
 protected:
 private:
};
#endif // ITEMHANOI_H

// ItemBase.h
#ifndef ITEMBASE_H
#define ITEMBASE_H
#include <iostream>
#include <stdio.h>
#include<cstdlib>
#include <string.h>
#include <Error.h>
using namespace std;
class Elemento
{
 public:
 Elemento();
 virtual ~Elemento();
 static int m_Indicador; /* Lectura: < 2: solo clave
 caso contrario clave y dato; Escritura: 0: solo clave;
 1: clave y cuenta; 2: clave y dato; 3: clave, cuenta y dato */
 unsigned int GetCounter() { return m_Counter; }
 void SetCounter(unsigned int val) { m_Counter = val; }
 Elemento GetEste() { return *this; }
 int GetClave() { return m_Clave; }
 void SetClave(int val) { m_Clave = val; }
 char *GetDato() { return m_Dato; }
 void SetDato(char *val) { strcpy(m_Dato,val); }
 int Leer(int);
 void Mostrar();
 int Leer(FILE *);
 void Mostrar(FILE *);
 int Compara(Elemento);
 void Copiar(Elemento);
 protected:
 unsigned int m_Counter;
 int m_Clave;
 char m_Dato[50];
 private:
};
#endif // ITEMBASE_H

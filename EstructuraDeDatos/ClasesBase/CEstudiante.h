// CEstudiante.h
#ifndef CESTUDIANTE_H
#define CESTUDIANTE_H
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
     static int m_Indicador; /* Comparacion: = 0: por cedula;
     caso contrario por nombre */
     unsigned int GetCounter() { return m_Counter; }
     void SetCounter(unsigned int val) { m_Counter = val; }
     Elemento GetEste() { return *this; }
     char *GetCedula() { return m_Cedula; }
     void SetCedula(char *val) { strcpy(m_Cedula, val); }
     char *GetNombre() { return m_Nombre; }
     void SetNombre(char *val) { strcpy(m_Nombre,val); }
     float GetNota1() { return m_Nota1; }
     void SetNota1(float val) { m_Nota1 = val; }
     float GetNota2() { return m_Nota2; }
     void SetNota2(float val) { m_Nota2 = val; }
     float GetNota3() { return m_Nota3; }
     void SetNota3(float val) { m_Nota3 = val; }
     int Leer(int);
     void Mostrar();
     int Leer(FILE *);
     void Mostrar(FILE *);
     int Compara(Elemento);
     void Copiar(Elemento);
     protected:
     unsigned int m_Counter;
     char m_Cedula[11];
     char m_Nombre[50];
     float m_Nota1, m_Nota2, m_Nota3;
 private:
};
#endif // CESTUDIANTE_H

#ifndef CALEATORIOS_H
#define CALEATORIOS_H
#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class CAleatorios
{
 public:
 int *a, n;
 CAleatorios(int n = 0);
 void Mostrar();
 unsigned Aleatorio(unsigned, unsigned);
 virtual ~CAleatorios();
 protected:
 private:
 int Buscar(int, int);
};
#endif // CALEATORIOS_H

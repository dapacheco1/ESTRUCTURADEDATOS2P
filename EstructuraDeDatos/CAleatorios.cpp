#include "CAleatorios.h"
CAleatorios::CAleatorios(int n)
{
 //ctor
 int pos, alt;
 srand((unsigned)time(NULL));
 if (n == 0)
 return;
 this->n = n;
 a = new int[n];
 for (int i = 0;;) {
 alt = Aleatorio(0, n - 1);
 pos = Buscar(i, alt);
 if (pos < 0) {
 a[i] = alt;
 i ++;
 }
 if (i >= n) break;

  }
}
CAleatorios::~CAleatorios()
{
 //dtor
 delete a;
}
void CAleatorios::Mostrar()
{
 for (int i = 0; i < n; i ++)
 cout << a[i] << " ";
 cout << endl;
}
unsigned CAleatorios::Aleatorio(unsigned A, unsigned B)
{
 return (A + abs(rand())%(B-A+1));
}
int CAleatorios::Buscar(int tl, int x)
{
 //Buscar
 int pos;
 for (pos = 0; pos < tl; pos ++)
 if (x == a[pos])
 return pos;
 return -1;
}

// CHanoi.h
#ifndef CHANOI_H
#define CHANOI_H
#include <CLstSEInsel.h>
class CHanoi : public CLstSEInsel
{
 public:
 CHanoi();
 virtual ~CHanoi();
 void MoverDiscosI(int, int, int, int);
 void PasarDisco(int, int, int);
 void EscribirPoste(int);
 void Intercambia(int &a, int &b)
 {
 int aux = a;
 a = b;
 b = aux;
 }
 protected:
 private:
};
#endif // CHANOI_H

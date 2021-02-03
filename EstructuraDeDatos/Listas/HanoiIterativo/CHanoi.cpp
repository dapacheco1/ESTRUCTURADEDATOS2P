// CHanoi.cpp
#include "CHanoi.h"
/* DESCRIPCION DE LAS FUNCIONES PARA LAS TORRES DE HANOI
 VERSION ITERATIVA USANDO PILAS */
CHanoi::CHanoi()
{
 //ctor
}
CHanoi::~CHanoi()
{
 //dtor
}
void CHanoi::PasarDisco(int n, int org, int dst) {
 cout << "Pasar el disco " << n << " desde el poste ";
 EscribirPoste(org);
 cout << " hacia el poste ";
  EscribirPoste(dst);
 cout << endl;
}
void CHanoi::EscribirPoste(int p) {
 switch (p) {
 case 0: cout << "izquierdo"; break;
 case 1: cout << "medio"; break;
 case 2: cout << "derecho"; break;
 }
}
void CHanoi::MoverDiscosI(int Altura, int Origen,
 int Destino, int Auxiliar)
{ // MoverDiscosI
 Elemento Reg;
 int PrimLlam = 1;
 do {
 if (PrimLlam) {
 Reg.Alt = Altura;
 Reg.Org = Origen;
 Reg.Dst = Destino;
 Reg.Aux = Auxiliar;
 PrimLlam = 0;
 }
 else {
 Retira(Reg);
 PasarDisco(Reg.Alt,Reg.Org,Reg.Dst);
 Reg.Alt--;
 Intercambia(Reg.Org, Reg.Aux);
 }
 while (Reg.Alt > 1) {
 Empuja(Reg);
 Reg.Alt--;
 Intercambia(Reg.Dst, Reg.Aux);
 }
 PasarDisco(Reg.Alt,Reg.Org,Reg.Dst);
 }
 while (Primero);
} // MoverDiscosI

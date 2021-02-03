// ItemOrden.cpp
#include "ItemOrden.h"
ItemOrden::ItemOrden()
{
 //ctor
}
ItemOrden::~ItemOrden()
{
 //dtor
}
int ItemOrden::Lee(int n)
{
 return Leer(n);
}
void ItemOrden::Muestra()
{
 Mostrar();
}
int ItemOrden::Lee(FILE * F)
{
 return Leer(F);
}
void ItemOrden::Muestra(FILE *G)
{
 Mostrar(G);
}

void ItemOrden::Copia(ItemOrden x)
{
 Copiar(x.GetEste());
}
int ItemOrden::Comparar(ItemOrden &Y)
{ // Compara
 return (Compara(Y.GetEste()));
} // Compara
int ItemOrden::Ascendente(ItemOrden &Y)
{ // Ascendente
 return (*this <= Y);
} // Ascendente
int ItemOrden::Descendente(ItemOrden &Y)
{ // Descendente
 return (*this >= Y);
} // Descendente
int ItemOrden::Desordenado(ItemOrden &Y)
{ // Desordenado
 return (*this == Y);
} // Desordenado
int ItemOrden::operator > (ItemOrden &Y)
{ // Operador de comparacion >
 return (Comparar(Y) > 0);
} // Operador >
int ItemOrden::operator < (ItemOrden &Y)
{ // Operador de comparacion <
 return (Comparar(Y) < 0);
} // Operador <
int ItemOrden::operator >= (ItemOrden &Y)
{ // Operador de comparacion >=
 return (Comparar(Y) >= 0);
} // Operador >=
int ItemOrden::operator <= (ItemOrden &Y)
{ // Operador de comparacion <=
 return (Comparar(Y) <= 0);
} // Operador <=
int ItemOrden::operator == (ItemOrden &Y)
{ // Operador de comparacion ==
 return (Comparar(Y) == 0);
} // Operador ==
int ItemOrden::operator != (ItemOrden &Y)
{ // Operador de comparacion !=
 return (Comparar(Y) != 0);
} // Operador !=

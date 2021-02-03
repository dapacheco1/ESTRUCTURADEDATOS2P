// ItemBase.cpp
#include "ItemBase.h"
Elemento::Elemento()
{
 //ctor
}
Elemento::~Elemento()
{
 //dtor
}
int Elemento::Leer(int ind)
{
 cout << "ITEM[" << ind << "], clave (salir <= 0): ";
 cin >> m_Clave;
 if (m_Clave <= 0) return 0;
 if (m_Indicador > 1) {
 getchar(); // Limpiar el buffer
 cout << "dato (salir = NULO): ";
 gets(m_Dato);
 if (strlen(m_Dato) == 0) return 0;
 }
 m_Counter = 0;
 return 1;
}
int Elemento::Leer(FILE *F)
{
 int est = fscanf(F, "%d", &m_Clave);
 if (est < 0 || m_Clave <= 0) return 0;
 if (m_Indicador > 1) {
 fgetc(F); // Limpiar el buffer
 if (!fgets(m_Dato, 50, F)) return 0;
 m_Dato[strlen(m_Dato) - 1] = '\0';
 if (strlen(m_Dato) == 0) return 0;
 }
 m_Counter = 0;
 return 1;
}
void Elemento::Mostrar()
{
 cout << m_Clave << " ";
 if (m_Indicador == 1 || m_Indicador == 3)
 cout << m_Counter << " ";
 if (m_Indicador > 1)
 cout << m_Dato << endl;
}
void Elemento::Mostrar(FILE *G)
{
 fprintf(G, "%d ", m_Clave);
 if (m_Indicador == 1 || m_Indicador == 3)
 fprintf(G, "%d ", m_Counter);
 if (m_Indicador > 1)
 fprintf(G, "%s\n", m_Dato);
}
int Elemento::Compara(Elemento x)
{
 return m_Clave - x.m_Clave;
}
void Elemento::Copiar(Elemento x)
{
 *this = x;
}

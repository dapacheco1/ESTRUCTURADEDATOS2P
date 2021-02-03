// CEstudiante.cpp
#include "CEstudiante.h"
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
 cout << "ALUMNO[" << ind << "], cedula (salir = NULA): ";
 gets(m_Cedula);
 if (strlen(m_Cedula) == 0) return 0;
 cout << "nombre (salir = NULO): ";
 gets(m_Nombre);
 if (strlen(m_Nombre) == 0) return 0;
 cout << "notas de los 3 parciales: ";
 cin >> m_Nota1 >> m_Nota2 >> m_Nota3;
 // Limpiar el buffer:
 getchar();
 return 1;
}
int Elemento::Leer(FILE *F)
{
 if (!fgets(m_Cedula, 50, F)) return 0;
 m_Cedula[strlen(m_Cedula) - 1] = '\0';
 if (!fgets(m_Nombre, 50, F)) return 0;
 m_Nombre[strlen(m_Nombre) - 1] = '\0';
 fscanf(F, "%f %f %f", &m_Nota1, &m_Nota2, &m_Nota3);
 // Limpiar el buffer:
 fgetc(F);
 return 1;
}
void Elemento::Mostrar()
{
 float prom = (m_Nota1 + m_Nota2 + m_Nota3) / 3;
 printf("%s %s %.2f %.2f %.2f %.2f %s\n",
 m_Cedula, m_Nombre, m_Nota1, m_Nota2, m_Nota3, prom,
 prom < 14 ? "REPRUEBA" : "APRUEBA");
}
void Elemento::Mostrar(FILE *G)
{
 float prom = (m_Nota1 + m_Nota2 + m_Nota3) / 3;
 fprintf(G, "%s %s %.2f %.2f %.2f %.2f %s\n",
 m_Cedula, m_Nombre, m_Nota1, m_Nota2, m_Nota3, prom,
 prom < 14 ? "REPRUEBA" : "APRUEBA");
}
int Elemento::Compara(Elemento x)
{
 if (m_Indicador == 0)
 return strcmpi(m_Cedula, x.GetCedula());
 return strcmpi(m_Nombre, x.GetNombre());
}
void Elemento::Copiar(Elemento x)
{
 *this = x;
}

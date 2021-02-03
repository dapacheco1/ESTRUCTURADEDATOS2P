// Calificaciones1
// Clasificacion en arreglo de punteros a objetos y
#include <OprArreglos.h>
// DEFINICION DE FUNCIONES:
int Elemento::m_Indicador;
int main()
{
 TArrObj A;
 int tl = LeerArreglo(A,"INGRESAR LA NOMINA DE ESTUDIANTES:");
 EscribirArreglo(A, tl, "NOMINA INGRESADA:", true);
 Ordenar(A, &ItemOrden::Ascendente, tl, 0);
 EscribirArreglo(A, tl, "NOMINA ORDENADA ASCENDENTEMENTE "
 "POR CEDULA:", true);
 Ordenar(A, &ItemOrden::Descendente, tl, 0);
 EscribirArreglo(A, tl, "NOMINA ORDENADA DESCENDENTE"
 "MENTE POR CEDULA:", true);
 Ordenar(A, &ItemOrden::Ascendente, tl, 1);
 EscribirArreglo(A, tl, "NOMINA ORDENADA ASCENDENTEMENTE "
 "POR NOMBRE:", true);
 Ordenar(A, &ItemOrden::Descendente, tl, 1);
 EscribirArreglo(A, tl, "NOMINA ORDENADA DESCENDENTE"
 "MENTE POR NOMBRE:", true);
 LiberarArreglo(A, tl);
 return 0;
}


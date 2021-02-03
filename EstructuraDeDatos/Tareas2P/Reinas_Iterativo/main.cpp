#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Tablero.h"

using namespace std;

//@Grupo 5

void encabezado()
{
	printf("                                            Universidad De Las Fuerzas Armadas                                                                                                    'ESPE'\n");
    printf("\n");
    printf("                                    Ingenieria en tecnologias de la informacion  \n");
    printf("                                           \t Estructura de Datos      \n");
    printf("\n\n Realizado por: GRUPO 5 \n");
    printf("\t\t Crespo Teresa \n");
    printf("\t\t Loachamin Gisselle \n");
    printf("\t\t Noboa Andres \n");
    printf("\t\t Onate Paul \n");
    printf("\t\t Pacheco Danny \n");
    printf(" Nrc: 2865\n");
    printf(" Fecha: 30 de Enero de 2021 \n");
    printf(" Noviembre 2020 - Abril 2021\n\n");
    printf("\n\t\t\t\t\t############################################\n");
	printf("\t  \t\t\t  \t QUEEN PROBLEM - PROCESO ITERATIVO \n");
	printf("\n\t\t\t\t\t############################################\n\n");
}

int main()
{
    Tablero t1=Tablero();
    int n;
    char c;
    encabezado();
    do
    {
        cout << "-= Encuentra todas las soluciones posibles para las N-Reinas =-\n";
        do
        {
            cout << "\tIntroduzca un entero n tal que 3 < N < " << MAX_REINAS + 1;
            cout << "\nN = ";
            cin >> n;
            if (n < 4 || n > MAX_REINAS)
                cout << "Invalido!\n";
        } while (n < 4 || n > MAX_REINAS);
        t1.EncontrarSoluciones(n);
        cout << "Resolver otro puzzle de N-Reinas (Y/N) ? ";
        cin >> c;
        cout << "\n\n";
    } while (c != 'N' && c != 'n');
    getchar();
    return 0;
}


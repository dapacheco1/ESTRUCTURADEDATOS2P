#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
// se define un limite de 14 reinas porque un n mayor creara un overflow en el
// archivo, resultando en una solucion incompleta.
#define MAX_REINAS 14
// definicion de una tablero de ajedrez global , este no sera utilizado para el calculo
 // si no para imprimir el tablero en pantalla

extern bool tablero[MAX_REINAS][MAX_REINAS];

class Tablero
{
    public:
        Tablero();
        ~Tablero();
        void LimpiarTablero(int);
        void Colocarpiezasentablero(std::vector <int> &);
        void DibujarTablero(int,unsigned long int,std::ofstream &);
        void EncontrarSoluciones(int n);
        bool UltimaPiezaValida(int,std::vector<int> &);
 };

#endif


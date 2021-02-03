// ERROR.HPP
/* ESTRUCTURA PARA PARA INTERRUMPIR LA EJECUCION
DE UN PROCESO */
#ifndef ERROR_HPP
#define ERROR_HPP
#include <STDARG.H>
#include <STDIO.H>
#include <STDLIB.H>
#include <CONIO.H>
 class Error {
 char *ParteMensaje;
 public:
 Error (char *M = NULL) // Consturctor
 { // Error
 ParteMensaje = M;
 } // Error
 void PAUSA(void);
 void Mensaje(int, char *, ...);
};
#endif

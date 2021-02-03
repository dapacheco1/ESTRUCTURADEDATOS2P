// ERROR.CPP
#include <Error.H>
void Error::PAUSA()
{ // PAUSA
printf("PULSE CUALQUIER TECLA PARA CONTINUAR");
 getch();
 printf("\n");
} // PAUSA
void Error::Mensaje(int Salir, char *CF, ...)
{ // Mensaje
 va_list PARAMETROS;
va_start(PARAMETROS,CF);
 printf("%s\n",ParteMensaje);
 vprintf(CF,PARAMETROS);
 printf("\n");
 va_end(PARAMETROS);
 PAUSA();
 if (Salir) exit(1);
} // Mensaje

//Syscall time
//Autor: Santiago Cadavid Bustamante & Juan Fernando Giraldo Cardona
//Compilar: gcc -Wall mytime.c -o mytime

#include <stdio.h>
#include <time.h>

int main ()
{
  time_t current_time;

  char* current;
  current_time = time(NULL);        //La función time modifica la fecha a valor abs de los segundos que han pasado
                                    //desde 1970
  current = ctime(&current_time);   //La función ctime, recibe como parámetro un time_t que será modificado a la fecha
                                    //actual del sistema, también formateandola a string

  printf ("%s", current);
  return 0;
}

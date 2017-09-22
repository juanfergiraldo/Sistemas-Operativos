//Evaluación laboratorio #3 Sistemas Operativos 2017-2
//Autor: Santiago Cadavid Bustamante & Juan Fernando Giraldo Cardona
//Compilar: make
//Ejecutar: ./shellbasico

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

#include "parser.h"

#define SIZE 100

int main(){
  char ** parameters;
  int numParam, background;
  char expression[SIZE];
  char * command;

  while(1){
    printf("\033[31;1mdanny.munera@PC-LIS:~$ \033[0m");
    fgets(expression, SIZE, stdin);
    numParam = separaItems(expression, &parameters, &background);
    if(numParam){             //strcmp(expression, "\n")
      command = parameters[0];        //NO DIO EL SWITCH CON STRINGS
      if(!strcmp(command, "myclr")){  //myclr
        //printf("\e[1;1H\e[2J");
        system("clear");
      }
      if(!strcmp(command, "myecho")){ //myecho
        for(int i = 1; i < numParam;  i++){
          printf("%s ", parameters[i]);
        }
        printf("\n");
      }
      if(!strcmp(command, "myexit")){ //myexit
        exit(0);
      }
      if(!strcmp(command, "mytime")){
        //time();
        pid_t pid_mytime = fork();
        int status;
        switch(pid_mytime){
          case 0:   //hijo
            execl("./mytime", "mytime", NULL);
            break;
          default:  //daddy yankee
            wait(&status);
            break;
        }
      }
      if(!strcmp(command, "mypwd")){
        pid_t pid_mypwd = fork();
        int status;
        switch(pid_mypwd){
          case 0:   //hijo
            execl("./mypwd", "mypwd", NULL);
            break;
          default:  //daddy yankee
            wait(&status);
            break;
        }
      }
      //implementar %s: command not found
    }

    //
    //printf("|%s\n", command);

  }
  //Ordenes internas: myclr, myecho, myexit,
  //Ordenes externas: mypwd, mycd, mykill, mycp, mypause, mytime


  liberaItems (parameters); //Liberar espacio de parameters

  return 0;
}
/*printf ("Numero de parametros: %d\n", numParam);

if (numParam>0)
{
  for (i=0; i<numParam; i++)
    printf ("%d \"%s\"\n", i+1, parameters[i]);

  printf ("Background: %d\n", background);


}*/

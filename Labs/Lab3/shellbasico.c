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
#include <pwd.h>
#include "parser.h"

void createPrompt();

#define SIZE 100

int main(){
  char ** parameters;
  int numParam, background;
  char expression[SIZE];
  char * command, user [200], host [200];
  createPrompt(user, host);

  while(1){
    printf("\033[31;1m%s@%s:~$ \033[0m", user, host);
    fgets(expression, SIZE, stdin);
    numParam = separaItems(expression, &parameters, &background);
    if(numParam){
      command = parameters[0];
      if(!strcmp(command, "myclr")){  //myclr
        printf("\e[1;1H\e[2J");
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
        pid_t pid_mytime = fork();
        int status;
        switch(pid_mytime){
          case 0:   //hijo
            execl("./mytime", "mytime", NULL);
            break;
          default:  //padre
            wait(&status);  //validar si el retorno es != 0
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
          default:  //padre
            wait(&status);  //validar si el retorno es != 0
            break;
        }
      }

      if(!strcmp(command, "mycd")){
        pid_t pid_mycd = fork();
        int status;
        switch(pid_mycd){
          case 0:   //hijo
            if(numParam == 1){
              execl("./mycd", "mycd", NULL); //no se hace necesario poner el nombre del ejecutable
            }else{
              execl("./mycd", "mycd", parameters[1], NULL);
            }
            break;
          default:  //padre
            wait(&status);  //validar si el retorno es != 0
            break;
        }
      }
      if(!strcmp(command, "mydir")){
        pid_t pid_mydir = fork();
        int status;
        switch (pid_mydir) {
          case 0:
          if(numParam ==1){
            execl("./mydir", "mydir", NULL);
          }else{
            execl("./mydir", "mydir", parameters[1], NULL);
          }
          break;
          default:
          wait(&status);
          break;
        }
      }

      if(!strcmp(command, "id")){
      }

              //system("ls");
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

void createPrompt(char * user, char * host){
  uid_t iduser = getuid();
  struct passwd * us = getpwuid(iduser);
  strcpy(user, (*us).pw_name);
  gethostname(host, sizeof(host));
}

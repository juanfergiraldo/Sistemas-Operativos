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
#include <signal.h>

#include "parser.h"

char * getHome();
void createPrompt();
void handler_term(int sig);
void handler_pause(int sig);

#define SIZE 100

int main(){
  char ** parameters;
  int numParam, background, status;
  char expression[SIZE];
  char * command;
  struct sigaction ctrlc;
  struct sigaction sigterm;
  struct sigaction sigpause;
  char exeplace [4096];
  getcwd(exeplace, sizeof(exeplace));

  while(1){
    createPrompt();

    //Obtener la señal
    ctrlc.sa_handler = SIG_IGN;
    ctrlc.sa_flags = SA_RESTART;
    sigaction(SIGINT, &ctrlc, NULL);

    sigpause.sa_handler = handler_pause;
    sigpause.sa_flags = SA_RESTART;
    for(int i = 1; i <= 62; i++){
      if(i != 2 && i != 15 && i!= 17){
        sigaction(i, &sigpause, NULL);
      }
    }

    sigterm.sa_handler = handler_term;
    sigterm.sa_flags = SA_RESTART;
    sigaction(SIGTERM, &sigterm, NULL);

    fgets(expression, SIZE, stdin);
    numParam = separaItems(expression, &parameters, &background);

    if(numParam){
      command = parameters[0];
      if(!strcmp(command, "myclr")){  //myclr   INTERNA
        printf("\e[1;1H\e[2J");
      }else{
      if(!strcmp(command, "myecho")){ //myecho    INTERNA
        for(int i = 1; i < numParam;  i++){
          printf("%s ", parameters[i]);
        }
        printf("\n");
      }else{
      if(!strcmp(command, "myexit")){ //myexit    INTERNA
        exit(0);
      }else{
      if(!strcmp(command, "mycd")){   //mycd    INTERNA
        int err;
        char * home = getHome();
        if(numParam == 1 || !strcmp(parameters[1], "~")){
          err = chdir(home);
        }else{
          err = chdir(parameters[1]);
        }
        if(err != 0){
          printf("mycd: %s: No such file or directory\n", parameters[1]);
        }
      }else{
      if(!strcmp(command, "mytime")){ //mytime    EXTERNA
        pid_t pid_mytime = fork();
        switch(pid_mytime){
          case 0:
            execl(strcat(exeplace, "/mytime"), "mytime", NULL);
            break;
          default:
            if(!background){
              wait(&status);
            }
            break;
        }
      }else{
      if(!strcmp(command, "mypwd")){  //mypwd     EXTERNA
        pid_t pid_mypwd = fork();
        switch(pid_mypwd){
          case 0:   //hijo
            execl(strcat(exeplace, "/mypwd"), "mypwd", NULL);
            break;
          default:  //padre
            if(!background){
              wait(&status);
            }
            break;
        }
      }else{

      if(!strcmp(command, "mydir")){    //mydir     EXTERNA
        pid_t pid_mydir = fork();
        switch (pid_mydir) {
          case 0:
            if(numParam ==1){
              execl(strcat(exeplace, "/mydir"), "mydir", NULL);
            }else{
              execl(strcat(exeplace, "/mydir"), "mydir", parameters[1], NULL);
            }
            break;
          default:
            if(!background){
              wait(&status);
            }
            break;
        }
      }else{
      if(!strcmp(command, "mycp")){         //mycp    EXTERNA
        if(!(numParam > 3)){
          char * fileName = parameters[1];
          char * dest = parameters[2];
          pid_t pid_mycp = fork();
          switch (pid_mycp) {
            case 0:
              execl(strcat(exeplace, "/mycp"), "mycp", fileName, dest, NULL);
              break;
            default:
              if(!background){
                wait(&status);
              }
              break;
          }
        }
      }else{
      if(!strcmp(command, "mykill")){   //mykill  EXTERNA
        pid_t pid_mykill = fork();
        switch (pid_mykill) {
          case 0:
            execl(strcat(exeplace, "/mykill"), "mykill", parameters[1], parameters[2], NULL);
            break;
          default:
            if(!background){
              wait(&status);
            }
            break;
        }
      }else{
      if(!strcmp(command, "mypause")){    //mypause   INTERNA
        pause();
      }else{
        printf("shellbasico: '%s' command not found\n", command);
      }}}}}}}}}}
    }
  }
  liberaItems (parameters); //Liberar espacio de parameters

  return 0;
}

void createPrompt(){
  char abspath[4096], relativepath[4096] = "", host[4096];
  uid_t iduser = getuid();
  struct passwd * us = getpwuid(iduser);
  gethostname(host, sizeof(host));
  getcwd(abspath, sizeof(abspath));
  if((int)(strlen(abspath) - strlen((*us).pw_dir)) >= 0){
    memcpy(relativepath, &abspath[strlen((*us).pw_dir)], strlen(abspath) - strlen((*us).pw_dir));
    printf("\033[31;1m%s@%s:~%s$ \033[0m", (*us).pw_name, host, relativepath);
  }else{
    printf("\033[31;1m%s@%s:%s$ \033[0m", (*us).pw_name, host, abspath);
  }
}

char * getHome(){               //Retorna el directorio home
  uid_t iduser = getuid();
  struct passwd * us = getpwuid(iduser);
  return (*us).pw_dir;
}

void handler_term(int sig) {
    printf("Impossible exit with 'SIGTERM' use command 'myexit'\n");
}

void handler_pause(int sig) {
    printf("The signal arrived %d \n", sig);
}

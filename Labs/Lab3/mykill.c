//Syscall kill
//Autor: Santiago Cadavid Bustamante & Juan Fernando Giraldo Cardona
//Compilar: gcc -Wall mykill.c -o mykill

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("mykill: not enough parameters\n");
    return -1;
  }

  int psignal = atoi(argv[1]);
  pid_t pid = atoi(argv[2]);

  if(kill(pid, psignal) != 0){
    printf("mykill: process with pid %d does not exist\n", (int)pid);
  }
  return 0;
}

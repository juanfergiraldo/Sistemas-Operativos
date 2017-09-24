//Syscall pwd -> prompt
//Autor: Santiago Cadavid Bustamante & Juan Fernando Giraldo Cardona
//Compilar: gcc -Wall prompt.c -o prompt

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  char buff[200];
  char * pointer = buff;
  if(getcwd(buff, sizeof(buff)) != NULL){    //Retorna NULL cuando no se puede almacenar en el buff
     //printf("%s\n", buff);                  //Almacena en el buff el directorio actual

  }
  else
    perror("getbuff() error");
  return 0;
}

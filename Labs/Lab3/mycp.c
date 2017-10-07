//Syscall cp
//Autor: Santiago Cadavid Bustamante & Juan Fernando Giraldo Cardona
//Compilar: gcc -Wall mycp.c -o mycp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void makeCopy(FILE *, FILE *);  //Método para pasar los datos de un file a otro

int main(int argc, char *argv[]){

  FILE * ptr_file = fopen(argv[1], "r");  //Se accede al file lectura que se va a hacer copia
  if(ptr_file == NULL){
    printf("mycp: could not execute command on '%s': does not exist the file or directory\n", argv[1]);
    return -1;
  }
  FILE * ptr_cpfile;
  if(chdir(argv[2])){
    printf("mycp: %s: No such file or directory\n", argv[2]);
    return -1;
  }
  ptr_cpfile = fopen(argv[1], "w");   //Después del chdir se hace la copia
  if(ptr_cpfile == NULL){
    printf("mycp: could not execute command: error creating new file\n");
    return -1;
  }
  makeCopy(ptr_file, ptr_cpfile);
  fclose(ptr_file);
  fclose(ptr_cpfile);
  return 0;
}

void makeCopy(FILE * ptr_file, FILE * ptr_cpfile){
  char buffer[4096];
  while(fgets(buffer, sizeof(buffer), ptr_file)){
    fputs(buffer, ptr_cpfile);
  }
}

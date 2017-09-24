//Syscall cd
//Autor: Santiago Cadavid Bustamante & Juan Fernando Giraldo Cardona
//Compilar: gcc -Wall mycd.c -o mycd

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

char * getHome();

int main(int argc, char *argv[]){   //Siempre hay un parámetro en el argv[]
  int err;
  char * home = getHome();
  if(argc == 1){
    err = chdir(home);
  }else{
    err = chdir(argv[1]);
  }
  if(err != 0){
    printf("mycd: %s: No such file or directory\n", argv[1]);
  }
  return 0;
}

char * getHome(){               //Retorna el directorio home
  uid_t iduser = getuid();
  struct passwd * us = getpwuid(iduser);
  return (*us).pw_dir;
}

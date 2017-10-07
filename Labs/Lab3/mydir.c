//Syscall cp
//Autor: Santiago Cadavid Bustamante & Juan Fernando Giraldo Cardona
//Compilar: gcc -Wall mydir.c -o mydir

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RED     "\x1b[31m"

int main(int argc, char const *argv[]) {
  int counter = 0;
  char buf[PATH_MAX];
  struct dirent *reffile;
  DIR *refdir; //directorio que se va a leer.

  if(argc == 1){ //Verificar cuántos parámetros se están enviando.
    refdir = opendir((getcwd(buf, sizeof(buf))));
  }else{
    refdir = opendir(argv[1]);
  }

  while ((reffile = readdir(refdir)) != NULL) { //readdir retorna un puntero tipo DIR a una estructura dirent.
    if((counter % 5) == 0){
      printf("\n");
    }

    switch (reffile->d_type) {
      case DT_DIR:
        printf(ANSI_COLOR_MAGENTA "%-17s", reffile->d_name);
        break;
      case DT_REG:
        printf(ANSI_COLOR_CYAN "%-17s", reffile->d_name);
        break;
      case DT_UNKNOWN:
        printf(ANSI_COLOR_RED "%-17s", reffile->d_name);
        break;
        default:
          printf("%-15s", reffile->d_name);
          break;
    }
    counter++;
  }
  closedir(refdir);
  printf("\n");
  return 0;
}

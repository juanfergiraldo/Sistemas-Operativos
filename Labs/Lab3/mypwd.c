#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  char buff[200];
   if (getcwd(buff, sizeof(buff)) != NULL){    //Retorna NULL cuando no se puede almacenar en el buff
       printf("%s\n", buff);
       //printf("%s\n", get_current_dir_name());    //Otra opción más directa
     }
   else
       perror("getbuff() error");
   return 0;
}

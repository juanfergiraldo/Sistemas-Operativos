/*Realizar un programa que capture la edad de un usuario en años y de acuerdo
a la misma,indicar si es un bebé (0 a 2), un niño (3 a 12), un adolescente (13 a 17)
o un adulto (18 en adelante) y mostrar su edad en meses.*/

#include <stdio.h>
#include <string.h>

int main(){
  int edad;
  int edadm;
  char frase[64];
  char cla[64];
  char ed[64];

printf("Por favor ingrese su edad en años: ");
scanf("%d", &edad);
edadm = edad * 12;
strcpy(cla, "Clasificación por edad: ");
strcpy(ed, "Edad en meses: ");

if (edad == 0 || edad <= 2){
  strcpy(frase, "Usted es un bebé");
}else if (edad == 3 || edad <= 12){
  strcpy(frase, "Usted es un niño.");
}else if (edad == 13 || edad <= 17){
  strcpy(frase, "Usted es un dolescente.");
}else{
  strcpy(frase, "Usted es un adulto.");
}

printf("|%-25s|%-25s| \n|%25s|%25d|\n", cla, ed, frase, edadm);
  return 0;
}

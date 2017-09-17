/*Haga un programa que reciba la edad de un usuario y muestre esta edad en meses.
 Debe almacenar la edad en memoria dinámica. */

#include <stdio.h>
#include <stdlib.h>

int main(){
  int *edad;
  edad = (int*)malloc(sizeof(int));
  printf("Por favor ingrese su edad: ");
  //setbuf(stdin, NULL);
  scanf("%d", edad);
  printf("Su edad en meses es: %d", *edad * 12);
  free(edad);
  return 0;
}

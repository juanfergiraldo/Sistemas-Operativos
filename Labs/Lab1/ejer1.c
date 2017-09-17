/*1. Diseñe un programa que lea un entero y determine si es par o impar. */
#include <stdio.h>

int main () {
  int num;
  printf("Por favor introduzca un número: \n");
  scanf("%d", &num);
  if(num % 2 == 0){
    printf("El número %d es par.", num);
  }else{
    printf("El número %d es impar.", num);
  }
  return 0;
}

/*Realice un programa que determine cuál es el valor más grande en un arreglo de
100 posiciones. El programa debe generar el arreglo automáticamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100


void generar (int*);
int mayor (int*);

int main(){
  int *apt = malloc(sizeof(int)*MAX);
  int ma;
  generar (apt);
  ma = mayor(apt);
  printf("El mayor número del arreglo es: %d\n", ma);
  free(apt);
}

void generar(int *apt) {
  int ran;
  for (int i = 0; i < MAX; i++){
    ran = rand() % 1000;
    *apt = ran;
    *apt++;
  }
}

int mayor(int *apt) {
  int i =0;
  int aux;
  int mayor = *apt;
  while (i < MAX-1) {
    aux = *(apt +1);
    if(mayor < aux){
      mayor = aux;
    }
    i++;
    apt++;
  }
  return mayor;
}

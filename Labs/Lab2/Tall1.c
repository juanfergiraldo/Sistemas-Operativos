/*Realice un programa que reciba 3 números enteros. Utilice un apuntador que
contenga la dirección del primer número ingresado. Utilice incrementos para
“recorrer” la memoria e imprima los tres números en consola.*/

#include <stdio.h>
#include <stdlib.h>

void recibir(int*);

int main(){
  int *apuntador = (int*)malloc(sizeof(int)*3);
  //int *aptAux = *apuntador;
  recibir(apuntador);
  for (int i = 0; i <3; i++){
    printf("%d\n", *apuntador +i);
  }
  free(apuntador);
  return 0;
}

void recibir(int *apuntador){
  printf("Por favor ingrese 3 números\n");
  for (int i = 0; i < 3; i++){
    printf("#%d: ", i+1);
    scanf("%d", apuntador + i);
  }
}

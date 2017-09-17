/*Haga un programa que reciba ‘n’ números y calcule la resta de 100 menos todos estos números: ‘100 - #1 - #2 - #3 - ...’.
Debe almacenar todos los números en memoria dinámica. Suponga que ‘n’ puede tomar un valor
máximo 10 y que el usuario siempre ingrese la información válida (no requiere hacer validaciones).*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10

void recibir (int*, int*);
int resta(int*, int*);

int *numeros;
int *size;
int main(){

  numeros = (int*)malloc(sizeof(int)*MAX_N);
  int nTam = MAX_N;
  int dif;
  size = &nTam;
  recibir(numeros, size);
  dif = resta(numeros, size);
  printf("La resta es igual a: %d\n", dif);
  return 0;
}

void recibir(int *aptVect, int *size){
  printf("Por favor ingrese el total de números a ingresar, máximo 10: ");
  setbuf(stdin, NULL);
  scanf("%d", size);
  printf("%d\n",*size);
  if(*size > MAX_N*2){
    printf("Error, el tamano máximo es 10. Ingrese otro valor: \n");
    scanf("%d", size);
    //aptVect = (int*)realloc(aptVect, 2*sizeof(int)*MAX_N);
  }else{
    //aptVect = (int*)realloc(aptVect, 2*sizeof(int)*MAX_N);
  }
  printf("Por favor ingrese sus números: ");
  for (int i = 0; i < *size; i++){
    printf("#%d: ", i+1);
    setbuf(stdin, NULL);
    scanf("%d", aptVect+i);
    //aptVect[i] = num;
    /*if (i == size-1 && ban == 1){
      size = size*2;
      aptVect = (int*)realloc(aptVect, 2*sizeof(int)*MAX_N);
      numeros = aptVect;
      ban = 0;
    }*/
  }
}
int resta(int *aptVect, int *size){
  int dif = 100;
  for (int i = 0; i < *size; i++){
    dif = dif - *(aptVect + i);
  }
  return dif;
}

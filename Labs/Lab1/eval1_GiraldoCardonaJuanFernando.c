#include <stdio.h>
#include <stdlib.h>
int potencia2(int);
int dec2bin(int);
int dec2oct(int);
int decimal(int[], int*);
void salir();

int main(){
  int opc;
  int n;
  int arr[64];
  do{
    printf("Por favor ingrese la actividad a desarrollar: \n1) Calcular la potencia de 2 a la n. \n2) Convertir un número de sistema decimal a binario.\n3) Convertir un número de sistema decimal a octal.\n4) Salir del programa.\n");
    scanf("%d", &opc);

    if(opc == 1){
      printf("1) Por favor ingrese un número entero: ");
      scanf("%d", &n);
      potencia2(n);
    }
    if(opc == 2){
      printf("2) Por favor ingrese un número entero: ");
      scanf("%d", &n);
      dec2bin(n);
    }
    if(opc==3){
      printf("3) Por favor ingrese un número entero: ");
      scanf("%d", &n);
      dec2oct(n);
    }
    if(opc==4){
      salir();
    }
  }while(opc != 4);
  return 0;
}

int potencia2(int n) {
  int pot= 1;
  for (int j = 0; j<n; j++){
    pot = pot * 2;
  }
  printf("La potencia %d de 2, es %d\n", n,pot);
  printf("%d\n", n);
  return 0; //Falta implementar el retorno
}

int dec2bin(int n){
  int cociente = n;
  int res[9];
  int k =0;
  while (cociente != 1) {
    res[k] = cociente%2;
    cociente = cociente/2;
    //printf("El cociente es: %d\n", cociente);
    k++;
    if (cociente == 1){
      res[k] = cociente;
    }
  }
  printf("La representación binaria de %d, es: \n", n );
  for(int i = k; i >= 0; i--){
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}

int dec2oct(int n){
  int cociente = n;
  int res[9];
  int k =0;
  while (cociente >= 8) {
    res[k] = cociente%8;
    cociente = cociente/8;
    //printf("El cociente es: %d\n", cociente);
    k++;
    if (cociente < 8){
      res[k] = cociente;
    }
  }
  for(int i = k; i >= 0; i--){
    printf("%d", res[i]);
  }
  printf("\n");
  return 0;
}

void salir(){
  printf("Salípor método\n");
  exit(0);
}

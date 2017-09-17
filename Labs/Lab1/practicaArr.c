#include <stdio.h>

int *binario(int, int, int*);
void imprime(int[], int);
int main(){
  int arr[64];
  int n, b, size;
  printf("Por favor ingrese el número a convertir: ");
  scanf("%d", &n);
  printf("Por favor ingrese la base: ");
  scanf("%d", &b);
  *arr = binario(n, b, arr);
  printf("El número %d en base %d es: \n",n, b);
  size = sizeof(arr)/sizeof(int);
  imprime(arr, size);
return 0;
}

int *binario(int n, int b, int arr[]){
  int *arra[64];
  int cosc = n;
  int k = 0;
  int j=0;
    while(cosc >= b){
      arra[k] = n%b;
      cosc = cosc/b;
      k++;
      if(cosc < b){
        arra[k] = cosc;
      }
      for(int i = k; i>=0; i--){
        arr[j] = arra[k];
        j++;
      }
    }
  return arr;
}
void imprime(int arr[], int size){
  for (int i = 0; i < size; i++){
      printf("%s", arr[i]);
  }
}

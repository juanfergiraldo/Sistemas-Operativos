#include <stdio.h>
#include <string.h>
int main(){
char nombre[64];
char array[5][64];
int size;
for(int i = 0; i < 5; i++){
  printf("Por favor digite un nombre: ");
  strcpy(array[i], fgets(nombre, sizeof(nombre), stdin));
}
size = sizeof(array)/sizeof(array[0]);
printf("%d\n", sizeof(array)/sizeof(array[0]));


for (int j = 0; j < size; j++){
  printf("Su nombre es: %s\n", array[j]);
}
return 0;
}

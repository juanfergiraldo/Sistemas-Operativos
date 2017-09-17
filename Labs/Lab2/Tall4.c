/*Realizar una calculadora de dos variables usando un menú de selección, como se muestra a continuación:
  MENU
  1. Suma
  2. Resta
  3. Multiplicación
  4. División
  Seleccione una opción:
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float suma(int*);
float resta(int*, int, int);
float multi(int*, int, int);
float div(int*, int, int);


int main(){
  char *apt;
  float val1=0;
  float val2=0;
  char vect[5][10];
  apt = (char*) vect;
  char opc;
  printf("Por favor ingrese la opción que desee: \n");
  while (opc != 'q') {
    printf("MENU: \n1. Suma\n2. Resta\n3. Multiplicación\n4. División\n5.'q' Para salir\n");
    scanf("%s\n", opc);
    switch (opc) {
      case '1':
        valores(&val1, &val2);
        suma(apt);
      case '2':
        valores(&val1, &val2);
        resta(apt);
      case '3':
        valores(&val1, &val2);
        multi(apt);
      case '4':
        valores(&val1, &val2);
        div(apt);
    }
  }
  return 0;
}
float valores (int *val1, int *val2){
  printf("Por favor ingrese el primer valor: ");
  setbuf(stdin, NULL);
  scanf("%.4f\n", val1);

  printf("Por favor ingrese el segundo valor: ");
  setbuf(stdin, NULL);
  scanf("%.4f\n", val2);
}
float suma(float *apt, float *val1, float *val2){
  float result;

  result = val1+val2;

  return result;
}

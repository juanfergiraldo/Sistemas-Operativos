/*  Diseñe un programa que reciba 5 nombres de pacientes junto con su estatura en metros.*/
#include <stdio.h>
#include <string.h>

int main() {
  char nombres[5][64]; //Se separan los 64 espacios para cada posición del arreglo
  float estaturas[5];
  char nom[64];
  float est;
  int size;

  for(int i = 0; i < 5; i++){
    /*printf("Por favor ingrece el nombre del paciente:\n");
    strcpy(nombres[i], fgets(nom, sizeof(nom), stdin));*/
    printf("Ingrese la estatura del paciente #%d en metros:\n", i+1);
    scanf("%f\n", &est); //Lee dos veces
    estaturas[i] = est;
    //strcpy(estaturas[i], est);
  }
  size = sizeof(estaturas)/sizeof(float);
  //printf("%d\n", sizeof(estaturas));
  for (int j = 0; j < size; j++){
    printf("El paciente #%d,  mide: %.2f metros.\n", j+1, estaturas[j]);
  }
return 0;
}

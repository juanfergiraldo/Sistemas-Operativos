/*Haga un programa que reciba el nombre del usuario y muestre un mensaje de despedida.
 Debe almacenar el nombre en memoria dinámica.
 Suponga que el nombre del usuario puede tener como máximo 10 caracteres.*/

#include <stdio.h>
#include <stdlib.h>

 int main(){
   char *nombre;
   nombre = (char*)malloc(sizeof(char)*10);
   printf("Por favor ingrese su nombre: ");
   scanf("%s", nombre);
   printf("Hasta luego: %s\n", nombre);
   free(nombre);
   return 0;
 }

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

//Varible global x
int x = 0;

void ft(){
  int i;
  printf("Identificador de hilo: %d.\nX tiene el valor de, %d antes de ser incrementado 1000 veces por este hilo \n", (int)getpid(), x);
  for(i = 1; i<=1000; i++) x++;
}

int main(){
  pthread_t hilos_ids[4];
  for (int i = 0; i < 4; ++i) pthread_create(&hilos_ids[i], NULL, (void*)ft, NULL);
  for (int i = 0; i < 4; ++i) pthread_join(hilos_ids[i], NULL);
  printf("Hilo principal: x = %d\n", x);
}

#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

void* calcular_primo(void* arg);

int main(){
  pthread_t hilo_id;
  int cual_primo = 5000;
  int primo;
  struct timeval t0, t1, dt;

  gettimeofday(&t0, NULL);
  //Inicia el hilo, se requiere el 5000 é-simo número primo.
  pthread_create(&hilo_id, NULL, &calcular_primo, &cual_primo);
  //Se puede hacer algo mientras...si quiero.
  //Espero que el número sea calulado y me sea entregado.
  pthread_join(hilo_id, (void*) &primo);
  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &dt);
  printf("La ejecución del hilo demora %ld.%06ld\n", dt.tv_sec, dt.tv_usec);
  //Imprimo el número entregado.
  printf("El número primo es; %d\n", primo);
}

/*Calcula los primos sucesivamente,
retorna en N-ésimo número primo
donde N es el valor apuntado por *ARG. */
void* calcular_primo(void* arg){
  int candidato = 2;
  int n = *((int*)arg);
  while(1){
    int factor;
    int es_primo = 1;
    for(factor = 2; factor < candidato; ++factor)
      if (candidato % factor == 0){
        es_primo = 0;
        break;
      }
    if(es_primo){
      //printf("%d, ", n);
      if (--n == 0){
        printf("Entré\n");
        return (void*) candidato;
      }
    }
    ++candidato;
  }

  return NULL;
}

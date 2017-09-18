#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct proc_{
  int id;
  char nombre[40];
  int tam;
  //TODO
} PROC;

char print_menu();
int load_procs(FILE* procf_desc, PROC** p_procs);
void print_procs(PROC* p_procs, int n_entries);
int create_proc(PROC**, int*);
int delete_proc(PROC**, int*);
void save_procs(PROC* p_procs, int n_entries, FILE* procf_desc);
int modify_procs(PROC**, int);
void gout(FILE* procf_desc, PROC** p_procs);


// File name
char* proc_file_name = "proc_file";



int main(){
  int n_entries;
  char opc;
  // TODO: open file proc_file or create it if it does not exist
  PROC *ptr_procs;
  FILE *procf_desc = fopen(proc_file_name, "r+");

  if(procf_desc == NULL){
    printf("El archivo %s no pudo abrirse.\n", proc_file_name);
    exit(1);
  }

  //TODO: Load file information into HEAP memory
   n_entries = load_procs(procf_desc, &ptr_procs);

    do{
     opc = print_menu();
     switch (opc) {
       case '1' :
          create_proc(&ptr_procs, &n_entries);
       break;
       case '2' :
          modify_procs(&ptr_procs, n_entries);
       break;
       case '3' :
          delete_proc(&ptr_procs, &n_entries);
       break;
       case '4' :
          print_procs(ptr_procs, n_entries);
       break;
       case '5' :
       procf_desc = fopen(proc_file_name, "w");
          save_procs(ptr_procs, n_entries, procf_desc);
       break;
       case '6' :
          gout(procf_desc, &ptr_procs);
       break;
       default:
          printf("Por favor ingrese un valor permitido\n");
       break;
     }
   }while (1);
  //TODO: Show menu to create, modify and delete entries
  //      (and save changes to file)
  //TODO: Close file
  return 0;
}

char print_menu(){
  char option = 'x';
    printf("Por favor elija una opción:\n");
    printf("1. Crear un proceso.\n");
    printf("2. Modificar un proceso.\n");
    printf("3. Eliminar un proceso.\n");
    printf("4. Mostrar los procesos\n");
    printf("5. Guardar los cambios\n");
    printf("6. Salir\n");
    scanf("%c", &option);
  return option;
}

int create_proc(PROC** p_procs, int* n_entries){
  int id;
  char nom[40];
  int size;
  int ban = 0;
  printf("\n");
  printf("Por favor ingrese el id del proceso, el nombre y el tamaño, usando tabulador o enter para separar c/u.\n");
  scanf("%d\t %10s\t %10d", &id, nom, &size);
  printf("\n");
  for (int i = 0; i < *n_entries; i++){
    if((*p_procs)[i].id == id){
      ban = 1;
    }
  }
  if (ban == 0){
    *p_procs = (PROC*)realloc(*p_procs, sizeof(PROC)*(*n_entries+1));
    (*p_procs)[*n_entries].id = id;
    strcpy((*p_procs)[*n_entries].nombre, nom);
    (*p_procs)[*n_entries].tam = size;
    *n_entries = *n_entries + 1;
  }else{
    printf("Error, el id ingesado ya existe\n");
  }
  return 0;
}

int modify_procs(PROC** p_procs, int n_entries){
  int id;
  int counter = 0;
  printf("Por favor ingrese el id del proceso que desea modificar\n");
  scanf("%d", &id);
  printf("\n");
  for (int i = 0; i < n_entries; i++){
    if((*p_procs)[i].id == id){
      counter = i;
    }
  }
  printf("Por favor ingrese el nombre, y tamaño, usando tabulador o enter para separar c/u.\n");
  scanf("%10s\t %10d", (*p_procs)[counter].nombre, &(*p_procs)[counter].tam);
  return 0;
}

int delete_proc(PROC** p_procs, int *n_entries){
  int id;
  int counter = -1;
  printf("Por favor ingrese el id del proceso que desea eliminar\n");
  scanf("%d", &id);
  printf("\n");
  for (int i = 0; i < *n_entries; i++){
    if((*p_procs)[i].id == id){
      counter = i;
    }
  }
  if(counter >= 0){
    while(counter < *n_entries){
      (*p_procs)[counter].id = (*p_procs)[counter+1].id;
      strcpy((*p_procs)[counter].nombre, (*p_procs)[counter+1].nombre);
      (*p_procs)[counter].tam = (*p_procs)[counter+1].tam ;
      counter++;
    }
    *n_entries = *n_entries -1;
    *p_procs = (PROC*)realloc(*p_procs, sizeof(PROC)*(*n_entries));
  }else{
    printf("Error, el id ingesado no existe");
  }
  return 0;
}

int load_procs(FILE* procf_desc, PROC** p_procs){

  int counter = 0;
  char nom[40];
  int id;
  int size;

  *p_procs = (PROC*)malloc(sizeof(PROC));

  while(feof(procf_desc) == 0){
    fscanf(procf_desc, "%d\t %10s\t %10d\t", &id, nom, &size);
    counter++;
    (*p_procs)[counter-1].id = id;
    strcpy((*p_procs)[counter - 1].nombre, nom);
    (*p_procs)[counter-1].tam = size;
    *p_procs = (PROC*)realloc(*p_procs, sizeof(PROC)* (counter+1));

  }
  return counter;
}

void print_procs(PROC* p_procs, int n_entries){
  for (int i = 0; i < n_entries; i++){
    printf("%d\t %10s\t %10d\n", (p_procs)[i].id,
                                (p_procs)[i].nombre, (p_procs)[i].tam);
  }
}

void save_procs(PROC* p_procs, int n_entries, FILE* procf_desc){
  //rewind(procf_desc);
  for (int i = 0; i < n_entries; i++){
    fprintf(procf_desc, "%d\t %10s\t %10d\n", (p_procs)[i].id,
                                (p_procs)[i].nombre, (p_procs)[i].tam);
  }
  printf("Todos los cambios guardados.\n");
}

void gout(FILE* procf_desc, PROC** p_procs){
  free(*p_procs);
  printf("Saliendo...\n");
  fclose(procf_desc);
  exit(1);
}

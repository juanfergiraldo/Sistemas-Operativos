#include<stdio.h>
#include<stdlib.h>


/* This program can create, multiply and print 2D-matrices*/

/* Functions to provide */
int** create_matrix(int order);
void print_matrix(int** matrix, int order);
void free_matrix(int**, int order);
int** mult_matrix(int** m_A, int** m_B, int order);

int main(int argc, char *argv[]){

  int** matrix_A;
  int** matrix_B;
  int** matrix_R;
  int order;

  if( argc != 2 ){
    printf("ERROR: you need to provide the square matrices order\n");
    return -1;
  }
  else{
    printf("The matrices order is %s x %s\n",argv[1],argv[1]);
  }

  order = atoi(argv[1]);

  printf("Creating Matrix A:\n");
  // TODO: call function to create matrix_A
  matrix_A = create_matrix(order);
  // TODO: call function to print matrix_A
  print_matrix(matrix_A, order);

  printf("Creating Matrix B:\n");
  // TODO: call function to create matrix_B
  matrix_B = create_matrix(order);
  // TODO: call function to print matrix_B
  print_matrix(matrix_B, order);

  printf("Multiplying Matrices A * B:\n");
  // TODO: call function to multiply A * B
  matrix_R = mult_matrix(matrix_A, matrix_B, order);
  // TODO: call function to print result R
  print_matrix(matrix_R, order);

  printf("freeing memory...\n");
  // TODO: call function to free matrices memory
  free_matrix(matrix_A, order);
  free_matrix(matrix_B, order);
  free_matrix(matrix_R, order);
  return 0;
}

int** create_matrix(int order){
  // TODO: reserve memory an square matrix of order "order"
  int **p_m = (int**)malloc(sizeof(int*)*order);
  for(int i = 0; i<order; i++){
    p_m[i]=(int*)malloc(sizeof(int)*order);
  }

  // TODO: initilize matrix's values
  for (int j = 0; j<order; j++){
    for (int k =0; k<order; k++){
      p_m[j][k]= rand()%100;
    }
  }
  printf("In create_matrix\n");
  return p_m;
}

void print_matrix(int** matrix, int order){
  // TODO: print matrix
  for(int i =0; i <order; i++){
    printf("\n");
    for (int j = 0; j < order; j++){
      printf("%d ", matrix[i][j]);
    }
  }
  printf("\nIn print_matrix\n");
}

void free_matrix(int** matrix, int order){
  // TODO: use free() to free matrix's memory
  for(int i = 0; i<order; i++){
    free(matrix[i]);
  }
  free(matrix);
  printf("In free_matrix\n");
}

int** mult_matrix(int** m_A, int** m_B, int order){
  // TODO: create memory to result matrix
  int **m_R =(int**)malloc(sizeof(int*)*order);
  for(int p = 0; p < order; p++){
    m_R[p]=(int*)malloc(sizeof(int)*order);
  }
  // TODO: Multiply matrices
  int sum = 0;
  int k=0;
  for (int i = 0; i < order; i++){
    for(int j = 0; j < order; j++){
      for (k = 0; k < order; k++){
        sum = sum + (m_A[i][k] * m_B[k][j]);
      }
      m_R[i][j] = sum;
      sum = 0;
    }
  }
  printf("In mult_matrix\n");
  return m_R;
}

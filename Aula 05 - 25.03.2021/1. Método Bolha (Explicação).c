#include <stdio.h>
#define N 5

int main(void) {
 
  //Métodos de Ordenação
  //Bolha
  //ordem correta =  3. 39. 41. 56. 85

  int valores[N] = {41, 3, 85, 39, 56}; //{0, 1, 2, 3, 4}
  int i, j;
  int aux;

  printf("\nAntes da Ordenação: \n");
  for(i=0; i<N; i++){
      printf("%d ", valores[i]);
  }

  printf("\n\nDepois da Ordenação: \n");
  for(i=0; i<N; i++){
      for(j=0; j<(N-1)-i; j++){
          if(valores[j] > valores[j+1]){
            aux = valores[j];
            valores[j] = valores[j+1];
            valores[j+1] = aux;
          }
      }
  }

  for(i=0; i<N; i++){
      printf("%d ", valores[i]);
  }

  return 0;
}

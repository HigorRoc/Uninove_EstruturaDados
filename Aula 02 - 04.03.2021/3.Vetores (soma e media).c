#include <stdio.h>
#define N 5

int main(void) {
  
  //Com Soma e Média
  int notas[5]={};
  int i;
  float media, soma;
  
  for(i=0; i<N; i++){
   printf("Digite o %dº valor = ", i+1);
   scanf("%d", &notas[i]);
   soma += notas[i];
  }

  printf("\n------------\nListar Notas\n\n");
  for(i=0; i<N; i++){
   printf("notas[%d] = %d\n", i, notas[i]);
  }

  media = soma / N;
  printf("\nMedia = %2.f\n", media);


  return 0;
}

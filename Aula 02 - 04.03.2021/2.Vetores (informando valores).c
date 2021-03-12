#include <stdio.h>

int main(void) {
  
  //Usuário informar valores
  int notas[5]={};
  int i;

  for(i=0; i<N; i++){
   printf("Digite o %dº valor = ", i+1);
   scanf("%d", &notas[i]);
  }

  printf("\nListar Notas\n\n");
  for(i=0; i<N; i++){
   printf("notas[%d] = %d\n", i, notas[i]);
  }

  return 0;
}

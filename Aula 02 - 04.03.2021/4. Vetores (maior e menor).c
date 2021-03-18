#include <stdio.h>
#define N 5

int main(void) {

  //Maior e Menor nota!
  float notas[N]={};
  int i;
  float media=0, soma=0, maior, menor;
  
  for(i=0; i<N; i++){
    printf("Digite o %dº valor = ", i+1);
    scanf("%f", &notas[i]);
    soma += notas[i];
   

    if(i==0){
        maior = notas[i];
        menor = notas[i];
    }

    if(notas[i] > maior)
        maior = notas[i];

    if(notas[i] < menor)
        menor = notas[i];
  }

  printf("\n------------\nListar Notas\n\n");
  for(i=0; i<N; i++){
   printf("notas[%d] = %2.f\n", i, notas[i]);
  }

  media = soma / N;
  printf("\nMedia = %2.f\n", media);
  printf("\nMaior Nota = %2.f\n", maior);
  printf("\nMenor Nota = %2.f\n", menor);

  return 0;
}

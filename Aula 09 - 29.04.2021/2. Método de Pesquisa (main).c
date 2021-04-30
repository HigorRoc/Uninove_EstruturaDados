#include <stdio.h>
#include <time.h>
#include "dados.h"

//#define N 1000

void exibir(int indice){
  //printf("Valor encontrado = %d\n", n_1000[indice]);
  printf("Indice [%d]\n", indice);
}

int main(void) {
  int i, x, tam, indEncontrado;
  clock_t tempo;

  // TAMANHO DO VETOR
  tam = (int)sizeof(n_1000)/sizeof(n_1000[0]);
  
  // IMPRESSÃO
  for(i=0; i<tam; i++){
    printf("Valor[%d]: %d\n", i, n_1000[i]);
  }
  printf("\nTamanho: %d\n", tam);

  // BUSCA
  printf("Digite um valor a pesquisar: ");
  scanf("%d", &x);


  tempo = clock(); // INICIO
  for(i=0; i<tam; i++){

    if(n_1000[i] == x){
      indEncontrado = i;

      tempo = clock() - tempo; // FINAL
      exibir(indEncontrado);
      break;
    }
  }

  // TEMPO
  printf("Total de %ld Ciclos (%f segundos)\n", tempo, (float) tempo / CLOCKS_PER_SEC);
  return 0;
}

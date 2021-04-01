#include <stdio.h>

int sorteio[5] = {41, 3, 85, 39, 56}; //{0, 1, 2, 3, 4}

void exibir(int V[], int n){
    int i;
    for(i=0; i<5; i++){
      printf("%.2d ", V[i]);
    }
    printf("\n");
}

void sortear(int V[], int n){
    int i, j, aux;
    for(i=0; i<n; i++){
        printf("---------------------------------------\n");
        for(j=0; j<(n-1)-i; j++){
            printf("%.2d > %.2d", V[j], V[j+1]);
            if(V[j] > V[j+1]){
              aux = V[j];
              V[j] = V[j+1];
              V[j+1] = aux;
              printf("\t\t(Troca) \t");
              exibir(V, 5);
            }else{
              printf("\t\t(Manter)\t");
              exibir(V, 5);
            }
        }
    }
}

//////////////////////////////////////////////////////////

int main(void) {
  
  int i;

  printf("\nAntes da Ordenação: \n");
  for(i=0; i<5; i++){
      printf("%d ", sorteio[i]);
  }

  printf("\n\nExibir as trocas da ordenação:\n");
  sortear(sorteio, 5);

  printf("\n\nDepois da Ordenação: \n");
  for(i=0; i<5; i++){
      printf("%.2d ", sorteio[i]);
  }

  return 0;
}

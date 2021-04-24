#include <stdio.h>
#include <time.h>

int sorteio[100] = {25, 40, 91, 71, 21, 41, 64, 45, 36, 54, 50, 39, 38, 35, 44, 1, 2, 77, 79, 8, 83, 43, 14, 31, 89, 22, 32, 61, 42, 53, 58, 97, 98, 47, 33, 27, 80, 11, 6, 12, 65, 17, 94, 7, 76, 20, 78, 52, 48, 96, 81, 92, 93, 26, 04, 13, 15, 75, 72, 9, 84, 60, 63, 56, 18, 16, 59, 88, 37, 69, 86, 67, 99, 24, 87, 28, 82, 100, 5, 55, 29, 34, 66, 10, 62, 30, 23, 46, 74, 95, 68, 73, 90, 57, 70, 85, 51, 19, 3, 49};

//ANTES DA ORDENAÇÃO
void exibir(int V[], int n){
    int i;
    for(i=0; i<100; i++){
      printf("%.2d ", V[i]);
    }
    printf("\n");
}

//TROCAS E COMPARAÇÕES
void sortear(int V[], int n){
    int i, j, aux, trocas = 0, compara = 0;
    
    for(i=0; i<n; i++){
        printf("---------------------------------------\n");

        for(j=0; j<(n-1)-i; j++){
            printf("%.2d > %.2d", V[j], V[j+1]);
            
            //PARA CRESCENTE OU DECRESCENTE, MUDAR O <>
            if(V[j] > V[j+1]){
              aux = V[j];
              V[j] = V[j+1];
              V[j+1] = aux;
              printf("\t\t(Troca) \t");
              exibir(V, 5);
              trocas++;
            }else{
              printf("\t\t(Manter)\t");
              exibir(V, 5);
            }
            compara++;
        }
    }

  printf("\nTotal de Trocas: ");
  printf("%.2d \n", trocas);

  printf("\nTotal de Comparações: ");
  printf("%.2d \n", compara);
}

//////////////////////////////////////////////////////////

int main(void) {
  
  int i, trocas = 0;

  printf("\nAntes da Ordenação: \n");
  for(i=0; i<100; i++){
      printf("%d ", sorteio[i]);
  }

  clock_t begin=clock(); //INICIO
  printf("\n\nExibir as trocas da ordenação:\n");
  sortear(sorteio, 100);
  clock_t end=clock(); //FINAL

  printf("\nDepois da Ordenação: \n");
  for(i=0; i<100; i++){
      printf("%.2d ", sorteio[i]);
  }

  //TEMPO DE EXECUÇÃO
  printf("\n\n");
  printf("Tempo: %lf Segundos",(double)(end-begin) / CLOCKS_PER_SEC);

  return 0;
}

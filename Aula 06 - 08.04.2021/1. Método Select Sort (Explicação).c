#include <stdio.h>

int sorteio[5] = {19, 27, 2, 43, 12}; //{0, 1, 2, 3, 4}

void exibir(int V[], int n){
    int i;
    for(i=0; i<5; i++){
      printf("%.2d ", V[i]);
    }
    printf("\n");
}

void ordenar_selecao(int V[], int n){
    int i, j, aux, min;

    for(i=0; i<n-1; i++){
        printf("\n---------------------------------------\n");
        min = i; 

        for(j=i+1; j<n; j++){
            printf("%.2d > %.2d", V[j], V[j+1]);
            if(V[j] < V[min]){
                min = j;
                printf(" Min (indice) = %d\n", min);
            }else{
                printf(" Min (indice) = %d\n", min);
            }
        }

        if(V[i] != V[min]){
            aux = V[i];
            V[i] = V[min];
            V[min] = aux;

            printf("(Status: Trocar)\n");
        }else{
          printf("(Status: Manter)\n");
        }
    }
}

//////////////////////////////////////////////////////////////////

int main(void) {
  
    int i;

    printf("\nAntes da Ordenação: \n");
    for(i=0; i<5; i++){
        printf("%d ", sorteio[i]);
    }

    printf("\n\nExibir as trocas da ordenação:\n");
    ordenar_selecao(sorteio, 5);

    printf("\nDepois da Ordenação: \n");
    for(i=0; i<5; i++){
        printf("%.2d ", sorteio[i]);
    }

    return 0;
}

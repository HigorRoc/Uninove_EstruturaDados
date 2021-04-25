#include <stdio.h>
#include <time.h>
#define GREEN "\x1B[32m"
#define WHITE "\033[0m"

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
void ordenar_insertion(int V[], int n){
    int i, j, aux, trocas=0, compara=0;

    for(i=1; i<n; i++){
        j = i;
        compara++;

        //PARA CRESCENTE: <
        //PARA DECRESCENTE: >
        while(j > 0 && V[j] < V[j-1]){
          if (V[j - 1] > V[j]){
              compara++;
            }

            aux = V[j];
            V[j] = V[j-1];
            V[j-1] = aux;
            j--;
            trocas++;
        }
    }

    printf("%s", GREEN);
    printf("\nTotal de Trocas: ");
    printf("%.2d \n", trocas);

    printf("Total de Comparações: ");
    printf("%.2d \n", compara);
    printf("%s", WHITE);
}

//METODO MAIN
int main(void) {
    int i;

    printf("\nAntes da Ordenação: \n");
    for(i=0; i<100; i++){
        printf("%.2d ", sorteio[i]);
    }

    clock_t begin=clock(); //INICIO
    printf("\n\nExibir as trocas da ordenação:\n");
    ordenar_insertion(sorteio, 100);
    clock_t end=clock(); //FINAL

    printf("\nDepois da Ordenação: \n");
    for(i=0; i<100; i++){
        printf("%.2d ", sorteio[i]);
    }

    //TEMPO DE EXECUÇÃO
    printf("\n\n");
    printf("%s", GREEN);
    printf("Tempo: %lf Segundos",(double)(end-begin) / CLOCKS_PER_SEC);
    printf("%s", WHITE);

    return 0;
}

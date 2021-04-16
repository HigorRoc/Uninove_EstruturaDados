#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50

int sorteio[N];

int repeat(int V[], int n, int numberSort){
    int i;
    for(i=0; i<N; i++){
        //printf("n=%d == V[%d]=%d\n",  numberSort, i, V[i]);
        if(numberSort == V[i]){
            break;
            return 1;
        }   
    }
    return 0;

    /*
    x = (rand() % 60) + 1;
        V[i] = x;
        value = repeat(sorteio, N, x);

        printf("V[%d] = %d (%d)\n", i, V[i], value);
        if(value == 0){
            //printf("%d ", value);
        }
    */
}


//Primeiro Void
void createValues(int V[], int n){
    int i, x, value;
    int numbers[61] = {};

    srand(time(NULL));

    for(i=0; i<n; i++){
        
        //example
        x = (rand() % 60) + 1;
        if(numbers[x] == 0){
            numbers[x] = 1;
            V[i] = x;
        }else{
          i--;
        }
    } 
}

//Segundo Void
void exibir(int V[], int n){
    int i;
    for(i=0; i<5; i++){
        printf("%.2d ", V[i]);
    }
    printf("\n");
}

//Terceiro Void
void ordenar_insertion(int V[], int n){
    int i, j, aux;

    for(i=1; i<n; i++){
        j = i;
        while(j > 0 && V[j] < V[j-1]){
            aux = V[j];
            V[j] = V[j-1];
            V[j-1] = aux;
            j--;
        }
    }
}

//////////////////////////////////////////////////////////////////

int main(void) {
  
    int i;

    //Criar o Vetor
    createValues(sorteio, N);

    printf("\nAntes da Ordenação: \n");
    for(i=0; i<N; i++){
        printf("%.2d ", sorteio[i]);
    }

    printf("\n\nExibir as trocas da ordenação:\n");
    ordenar_insertion(sorteio, N);

    printf("\nDepois da Ordenação: \n");
    for(i=0; i<N; i++){
        printf("%.2d ", sorteio[i]);
    }

    return 0;
}

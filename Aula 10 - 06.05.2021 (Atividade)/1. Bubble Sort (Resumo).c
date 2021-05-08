#include <stdio.h>
#include <time.h>
#define GREEN "\x1B[32m"
#define WHITE "\033[0m"
 
int valores[5] = {25, 40, 91, 71, 23};
 
//ANTES DA ORDENAÇÃO
void exibir(int V[], int n){
   int i;
   for(i=0; i<5; i++){
     printf("%.2d ", V[i]);
   }
   printf("\n");
}
 
//TROCAS E COMPARAÇÕES
void trocas(int V[], int n){
   int i, j, aux, trocas = 0, compara = 0;
  
   for(i=0; i<n; i++){
       printf("------------------------------------------------------\n");
 
       for(j=0; j<(n-1)-i; j++){
           printf("%.2d > %.2d", V[j], V[j+1]);
          
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
 
 printf("%s", GREEN);
 printf("\nTotal de Trocas: ");
 printf("%.2d \n", trocas);
 
 printf("Total de Comparações: ");
 printf("%.2d \n", compara);
 printf("%s", WHITE);
}
 
int main(void) {
  int i;
 
 printf("\nAntes da Ordenação: \n");
 for(i=0; i<5; i++){
     printf("%d ", valores[i]);
 }
 
 printf("\n\n Trocas e Comparações:\n");
 trocas(valores, 5);
 
 printf("\nDepois da Ordenação: \n");
 for(i=0; i<5; i++){
     printf("%.2d ", valores[i]);
 }
 
 return 0;
}

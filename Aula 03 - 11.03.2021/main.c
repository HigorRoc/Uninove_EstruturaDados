#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHA 10
#define COLUNA 4

int main(void) {
  
  float notas[LINHA][COLUNA]={}, media, bonus, mediaCurso;
  int i, j;

  system("clear");
  srand(time(NULL));
  printf("Quantos pontos bonus deseja adicionar aos alunos (AV1): ");
  scanf("%f", &bonus);
  printf("Informe a média desejada: ");
  scanf("%f", &mediaCurso);

//1° PARTE DO CÓDIGO: PRIMEIRA EXIBIÇÃO DA TABELA
  //Título
  printf("\nCOD\t\tRA\t\t\t AV1\t\t AV2\t\t MEDIA\t\tSTATUS\n");

  //COD
  for(i=0; i<LINHA; i++){
      printf("%02d\t\t", i+1);

      for(j=0; j<COLUNA; j++){
        //RA
        if(j==0)
          notas[i][j] = 210000 + rand() % 10000;

        //AV1 + BONUS
        if(j==1)
          notas[i][j] = (rand() % 11) + bonus;
        if(notas[i][1] > 10.0)
          notas[i][j] = 10.0;

        //AV2
        if(j==2)
          notas[i][j] = (rand() % 11);

        //MEDIA
        if(j==3)
          notas[i][j] = (notas[i][1] + notas[i][2]) / 2.0;

        //IMPRESSAO FINAL
        if(j==0)
          printf("%4.0f\t\t", notas[i][j]);
        else
          printf("%4.1f\t\t", notas[i][j]);

        //STATUS
        if(j==3){
          if(notas[i][3] >= mediaCurso)
            printf("A");
          else 
            printf("R");
        }
      }
      printf("\n");
  }



//2° PARTE DO CÓDIGO: SOLICITANDO A NOTA BONUS
  int add_bonus, encontrado = 0;
  float ra_escolhido, ponto_bonus;

  printf("\n\nDeseja adicionar bonus na AV1 para um aluno especifico?\nSIM (1)  NAO (0):   ");
  scanf("%d", &add_bonus);

  if(add_bonus){
    //PEDINDO RA
    printf("Informe o RA do Aluno: ");
    scanf("%f", &ra_escolhido);

    for(i=0; i<LINHA; i++){
      //MOSTRANDO NOTA ATUAL
      if(notas[i][0] == ra_escolhido){
        printf("Nota Atual (AV1): %.1f\n", notas[i][1]);

        //PEDINDO NOTA BONUS
        printf("Informe a Nota Bonus: ");
        scanf("%f", &ponto_bonus);
        notas[i][1] += ponto_bonus;

        if(notas[i][1] > 10.0)
          notas[i][1] = 10.0;

        //NOTA ADICIONADA
        printf("\nNota Adicionada!\n");
        encontrado = 1; //
        break;
      }
    }



//3° PARTE DO CÓDIO: NOVA EXIBIÇÃO (com Cor)
  //Título
  printf("\nCOD\t\tRA\t\t\t AV1\t\t AV2\t\t MEDIA\t\tSTATUS\n");

  //COD
  for(i=0; i<LINHA; i++){
      printf("%02d\t\t", i+1);

      for(j=0; j<COLUNA; j++){
        //NOVA MEDIA
        if(j==3)
          notas[i][3] = (notas[i][1] + notas[i][2]) / 2.0;

        //COLORIR
        if(notas[i][0] == ra_escolhido)
          printf("\033[1;32;40m");

        //EXIBIR
        if(j==0)
          printf("%4.0f\t\t", notas[i][j]);
        else
          printf("%4.1f\t\t", notas[i][j]);

        //STATUS
        if(j==3){
          if(notas[i][3] >= mediaCurso)
            printf("A");
          else 
            printf("R");
        }

        //VOLTANDO A COR
        if(notas[i][0] == ra_escolhido)
          printf("\033[0m");

      }
      printf("\n");
  }
  }

  return 0;
}

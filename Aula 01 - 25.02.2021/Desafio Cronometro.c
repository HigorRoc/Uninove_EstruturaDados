#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Revisão 02
int main(void) {

  //Quantos minutos deseja contar?
  //00:00 (2 minutos = 02:00)
  //Sleep(1)

  int total, ciclos=0, seg=0, min=0;

  printf("Insira os minutos: ");
  scanf("%d", &total);

  total = total*60;

  while(ciclos <= total){
    printf("%02d:%02d\n", min, seg);
    seg++;

      if(seg % 60 == 0){
        min++;
        seg=0;
      }

    sleep(1);
    ciclos++;
    system("clear");
  }
  printf("Tempo Encerrado!!\n");

  return 0;
}

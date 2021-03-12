#include <stdio.h>

int main(void) {

  //Com valores fixos
  int notas[5]={7,5,8,9,3};
  int i;

  for(i=0; i<5; i++){
   printf("notas[%d] = %d\n", i, notas[i]);
  }

  return 0;
}

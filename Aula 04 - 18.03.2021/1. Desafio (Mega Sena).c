#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define Sorteios 10

int main (){

int freq[60], freq2[60][2], freq3[3];
int Jogo_Gerado[Sorteios][6], Jogo_Oficial[Sorteios][6], Linha, Indice1, Indice2, Ordenar, UltimoJogo[60], Duplas[60][60], Duplas1[3600][3];
int Apostador, JogoApostador[6];
char ja_consta, Nome[100], CPF[13];


//Gerando numeros totalmente aleatórios.
for (Linha=0; Linha<60; Linha++){
    freq[Linha] = 0;
  //Formula para as duplas.
  for(Indice1=0; Indice1<60; Indice1++)
		Duplas[Linha][Indice1] = 0;
}

srand (time(NULL));

//Frequência de cada Número.
for (Linha=0; Linha<Sorteios; Linha++){ 
  for (Indice1=0; Indice1<6; Indice1++){

    do{
      Jogo_Gerado[Linha][Indice1] = rand() % 60 + 1;
      ja_consta = 'N';

      for (Indice2=0; Indice2<Indice1; Indice2++)
      if (Jogo_Gerado[Linha][Indice1] == Jogo_Gerado[Linha][Indice2])
      ja_consta = 'S';

      }while 
      (ja_consta == 'S'); 
      Jogo_Oficial[Linha][Indice1] = Jogo_Gerado[Linha][Indice1];
      freq[Jogo_Gerado[Linha][Indice1]-1]++;
  }
}


//Colocando os numeros em ordem crescente.
for(Linha=0; Linha<Sorteios; Linha++){
  for(Indice1=0; Indice1<6; Indice1++){
    for(Indice2=Indice1; Indice2<6; Indice2++){
               
      if(Jogo_Oficial[Linha][Indice2] < Jogo_Oficial[Linha][Indice1]){
                   
         Ordenar = Jogo_Oficial[Linha][Indice1];
         Jogo_Oficial[Linha][Indice1] = Jogo_Oficial[Linha][Indice2];
         Jogo_Oficial[Linha][Indice2] = Ordenar;
      }
    }
  }
}



/*********PRONTO************/
//Formula para sorteas
printf("\n\nSorteios:\n\n");

for(Linha=0; Linha<Sorteios; Linha++){ 
    printf("Jogo %.4d:   ", Linha+1);

for(Indice1=0; Indice1<6; Indice1++)
    printf("%02d ", Jogo_Gerado[Linha][Indice1]);
    printf(" (");
for(Indice1=0; Indice1<6; Indice1++)
    printf("%02d ", Jogo_Oficial[Linha][Indice1]);
    printf(")\n");}



/*********PRONTO************/
//Aqui mostrando a frequência dos 60 numeros.
printf("\n\nFrequência de cada número:\n\n");

for (Linha=0; Linha<60; Linha++){
{printf("Número %02d = %02d vezes.\n", Linha+1, freq[Linha]);}
freq2[Linha][0] = Linha;
freq2[Linha][1] = freq[Linha];
}



//Guardando valores e ordenando para mostrar as duplas e os 15 mais sorteados.
for(Linha=0; Linha<60; Linha++){   
  for(Indice1=Linha; Indice1<60; Indice1++){   

if(freq2[Linha][1] < freq2[Indice1][1]){
   freq3[0] =  freq2[Linha][0];
   freq3[1] =  freq2[Linha][1];
	 freq2[Linha][0] = freq2[Indice1][0];
	 freq2[Linha][1] = freq2[Indice1][1];
   freq2[Indice1][0] = freq3[0];
   freq2[Indice1][1] = freq3[1];
    }
  }
}


//Define as duplas que mais sairam nos sorteios.
for(Linha=0; Linha<Sorteios; Linha++){
	for(Indice1= 0; Indice1< 60; Indice1++){
		for(Indice2= 0; Indice2< 60; Indice2++){
			if(Jogo_Oficial[Linha][Indice1] == (Indice1+1) && Jogo_Oficial[Linha][Indice2] == Indice2+1 && Indice1 != Indice2){
				Duplas[Indice1][Indice2]++;	
			}		
		}
	}
}		
	


//Copia as Duplas e salva elas.
Linha = 0;
for(Indice2=0; Indice2<60; Indice2++){
	for(Indice1 = 0; Indice1 < 60; Indice1++){	
		Duplas1[Linha][0] = Indice2;
		Duplas1[Linha][1] = Indice1;
		Duplas1[Linha][2] = Duplas[Indice2][Indice1];
		Linha++; 
	}
}



//Ordena as Duplas
Linha = 0;
for(Indice2=0; Indice2<3600; Indice2++){
	for(Indice1 = Indice2; Indice1 < 3600; Indice1++){
		if(Duplas1[Indice2][2] < Duplas1[Indice1][2]){
			freq3[0] = Duplas1[Indice2][0];
			freq3[1] = Duplas1[Indice2][1];
			freq3[2] = Duplas1[Indice2][2];
			Duplas1[Indice2][0] = Duplas1[Indice1][0];
			Duplas1[Indice2][1] = Duplas1[Indice1][1];
			Duplas1[Indice2][2] = Duplas1[Indice1][2];
			Duplas1[Indice1][0] = freq3[0];
			Duplas1[Indice1][1] = freq3[1];
			Duplas1[Indice1][2] = freq3[2];
		}   	
	}
}
	


/*********PRONTO************/
//Mostrando as 15 Duplas que mais sairam nos sorteios.
printf("\n\nAs 15 duplas que mais sairam:\n\n");

Indice1 = 1;
for(Indice2=0; Indice2<30; Indice2++){
	if((Indice2%2) == 0){
		printf("Números %02d e %02d = %02d vezes.\n", Duplas1[Indice2][0]+1, Duplas1[Indice2][1]+1, Duplas1[Indice2][2]);	
	}	
}



/*********PRONTO************/
//Os 15 numeros mais sorteados e a sua frequencia.
printf("\n\nOs 15 números que mais sairam:\n\n");

for(Linha=0; Linha<15; Linha++){
printf("Número %02d = %02d vezes.\n", freq2[Linha][0]+1, freq2[Linha][1]);}



/*********PRONTO************/
//Mostrando a quantos jogos respectivo numero nao é sorteado.
printf("\n\nUltima vez sorteado:\n\n");

ja_consta = 'N';

for(Linha=1; Linha<=60; Linha++){   
for(Indice1=Sorteios-1; Indice1>=0; Indice1--){
for(Indice2=0; Indice2<6; Indice2++){
    
  if(Linha == Jogo_Oficial[Indice1][Indice2]){
    UltimoJogo[Linha-1] = Sorteios - Indice1;
    ja_consta = 'S';
  break;}
}
  if(ja_consta == 'S') break;}
    ja_consta = 'N';}

for(Linha=0; Linha<60; Linha++)

{if
  (UltimoJogo[Linha] == 0){
  printf("Número %02d = saiu no ultimo sorteio.\n", Linha+1);}  
else
  {printf("Número %02d =  nao sai a %02d sorteio(s) seguidos.\n", Linha+1, UltimoJogo[Linha]-1);}
}



/*********PRONTO************/
//Fazendo as jogadas os 3 usuarios e mostrando seus acertos.
printf("\n\nFaça a sua aposta:\n\n");

for(Apostador=0; Apostador<3; Apostador++){
  printf("Apostador %d\n", Apostador+1);

    {printf("Digite seu Nome: ");
    scanf("%s", Nome);}

    {printf("Digite seu CPF: ");
    scanf("%s", CPF);}

  printf("Digite seu jogo de 6 Números: ");
  scanf("%d %d %d %d %d %d", &JogoApostador[0], &JogoApostador[1], &JogoApostador[2], &JogoApostador[3],&JogoApostador[4],&JogoApostador[5]);


if(JogoApostador[0] == JogoApostador[1] ||
   JogoApostador[0] == JogoApostador[2] || 
   JogoApostador[0] == JogoApostador[3] || 
   JogoApostador[0] == JogoApostador[4] || 
   JogoApostador[0] == JogoApostador[5] || 
   JogoApostador[1] == JogoApostador[2] || 
   JogoApostador[1] == JogoApostador[3] || 
   JogoApostador[1] == JogoApostador[4] || 
   JogoApostador[1] == JogoApostador[5] || 
   JogoApostador[2] == JogoApostador[3] || 
   JogoApostador[2] == JogoApostador[4] || 
   JogoApostador[2] == JogoApostador[5] || 
   JogoApostador[3] == JogoApostador[4] || 
   JogoApostador[3] == JogoApostador[5] || 
   JogoApostador[4] == JogoApostador[5] ||
   JogoApostador[0] == 0 ||
   JogoApostador[1] == 0 ||
   JogoApostador[2] == 0 ||
   JogoApostador[3] == 0 ||
   JogoApostador[4] == 0 ||
   JogoApostador[5] == 0){

  printf("\nNúmeros inválidos ou repetidos, digite novamente:\n\n");
  printf("Digite seu jogo de 6 Números: ");
scanf("%d %d %d %d %d %d", &JogoApostador[0], &JogoApostador[1], &JogoApostador[2], &JogoApostador[3],&JogoApostador[4],&JogoApostador[5]);
}


int Acertos = 0;
int SorteioAp = rand() % Sorteios + 1;

  for(Indice1=0; Indice1<6; Indice1++){
    for(Indice2= 0; Indice2<6; Indice2++){
    
    if(Jogo_Oficial[SorteioAp][Indice1] == JogoApostador[Indice2]){
      Acertos++;}	
    }
  }{
    if(Acertos > 0){
      printf("\nParabéns %s, você acertou %d número(s)! Sorteio [%d].\n\n\n\n", Nome, Acertos, SorteioAp+1);
    }else{
      printf("\nNão foi dessa vez %s, não acertou nenhum número! Sorteio [%d].\n\n\n\n", Nome, SorteioAp+1);}
  }
  }
  
  return 0;
}

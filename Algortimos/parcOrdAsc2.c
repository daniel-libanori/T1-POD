/*
  Programa que utiliza versão modificada de quick sort para ordenar
  parcialmente dados da entrada.
  Parâmetro <fator> usado para controlar quando parar a ordenação.
  Fatores baixos (ex. 2) geram saída quase ordenada.

*/
#include <stdio.h>
#include <stdlib.h>

void imprime(int *vetor, int tam){
  int cont;
  for(cont=0; cont<tam; cont++)
	printf("%d\n", vetor[cont]);
  return;
}

int partition(int *vet, int lo, int hi){
  int pivo, i, j, aux;
  pivo = vet[lo];
  i=lo-1;
  j=hi+1;

  while(1){
	do{
	  j--;
	} while(vet[j] > pivo);

	do{
		i++;
	} while(vet[i] < pivo);

	if(i<j){
		aux = vet[i];
		vet[i] = vet[j];
		vet[j] = aux;
	} else {
		return j;
	}
  }
}

int *quickSort(int *vet, int lo, int hi, int fator){
  int p;
  if(lo<hi){
	p = partition(vet, lo, hi);
	if((hi-lo) > fator){ 
	  quickSort(vet, lo, p, fator);
	  quickSort(vet, p+1, hi, fator);
	}
  }
  return vet;
}



main(int argc, char *argv[]){
  int  i;
  int *vet;
  char linha[16];
  int tamVet;
  struct timespec t0, t1;

  if(argc < 3){
    printf("Uso: %s <n. de elementos a ordenar parcialmente> <fator parcial>\n", argv[0]);
    exit(0);
  }
  tamVet = atoi(argv[1]);
  vet = (int *) malloc(sizeof(int) * tamVet);

  for(i=0; i<tamVet; i++){
	fgets(linha, 16, stdin);
	sscanf(linha, "%d", &vet[i]);
  }

  quickSort(vet, 0, tamVet-1, atoi(argv[2]));
  imprime(vet,tamVet);

  exit(0);
}


#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]){
  int i, val;
  if(argc == 2){
    val = atoi(argv[1]);
    for(i=0; i<val; i++)
	printf("%u\n", (unsigned int) random()%val);
  } else {
    printf("Uso: geraN <numero de valores a serem gerados>\n");
  }
  exit(0);
}

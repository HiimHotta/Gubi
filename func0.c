#include <stdio.h>
#include <stdlib.h>
#include "func0.h"

// funcçao collatz do ep1, como vcs pdm perceber ha um ponteiro para
// funcoes do tipo FUNC no caso esse ponteiro pd ser usado
// para diferentes funcoes. Aqui temos duas funcoes, cada qual retornando o
// resultado adequado qd a variavel do tipo teste for par ou impar,
// logo a variavel fcollatz que é um ponteiro para funcoes aponta para uma
// outra assim realizando a devida operacao necessaria. teste é um tipo
// que possui um campo do tipo int. Esta servindo aqui como se fosse o
// elemento dado no trabalho do gubi.

//Compilar >  gcc -wall func.c -o func

int collatzPar(teste *x){
  x->n = (x->n)/2;
  return(x->n);
}

int collarzImpar(teste *x){
  x->n = 3*(x->n) +1;
  return(x->n);
}

int main(){
    teste *e = malloc(sizeof(teste));
    int n;
    scanf("%d",&n);
    e->n = n;
    func fcollatz;
    while(e->n != 1){
      if((e->n) % 2 == 0)
        fcollatz = collatzPar;
      else
        fcollatz = collarzImpar;
      printf("%d\n", fcollatz(e));
    }
    teste *e2 = e;
    if (e == e2)
      printf ("AHAAAE\n");
    free(e);
}

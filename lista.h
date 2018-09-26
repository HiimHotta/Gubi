# include " elemento .h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  Elo * cabec ;
} Lista ;

Lista cria ();

void destroi(Lista l);

//
Lista insere(Lista l, Elemento* val);

/*Busca pela lista inteira, enquanto houver p.prox continua procurando
//se nao tiver, retorna NULL                                          */
Elemento* busca(Lista l, char* n);

//busca recursiva
Elemento* buscaR (Lista l, char* n);

//retirar o elemento val da lista, sem tirar da memoria?
Elemento* retira(Lista l, Elemento* val);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Lista criaL () {
  Lista tmp;
  tmp.cabec = malloc (sizeof (Elo));
  tmp.cabec->val = NULL;
  tmp.cabec->next = NULL;
  //tmp.cabec = NULL;
  return tmp;
}

//considera q esta passando a referencia da cabeca
Boolean endList (Lista l) {
  if (l.cabec->next == NULL)
    return True;
  return False;
}

void* peek (Lista l) {
  return l.cabec->val;
}

void destroiL (Lista l) {
  if (!endList (l)) {
    Elo *lixo = l.cabec->next;
    while (lixo != NULL) {
      l.cabec->next = lixo->next;
      free (lixo);
      lixo = l.cabec->next;
    }
  }
  free (l.cabec);
  l.cabec = NULL;
}

Lista insereL (Lista l, void* val) {
  Lista aux = l;
  Elo *tmp = malloc (sizeof (Elo));
  tmp->val = val; tmp->next = NULL;

  while (aux.cabec->next != NULL)
    aux.cabec = aux.cabec->next;

  aux.cabec->next = tmp;

  return aux;
}

void* retiraL (Lista ant, Lista atual) {
  void *aux = atual.cabec->val;

  ant.cabec->next = atual.cabec->next;
  free (atual.cabec);

  return aux;
}


ElementoAntigo* buscaElementoAntigo (Lista l, ElementoAntigo *val) {
  Lista aux = l;

  //se tah olhando pra cabeca, tem q olhar pro prox
  if (aux.cabec->val == NULL && (aux.cabec->next)->val != NULL)
    aux.cabec = aux.cabec->next;

  while (aux.cabec != NULL) {
    if (compareElementoAntigo (aux.cabec->val, val) == 1)
      return aux.cabec->val;
    aux.cabec = aux.cabec->next;
  }
  return NULL;
}

ElementoAntigo* retiraElementoAntigo (Lista l, ElementoAntigo *nome) {
  ElementoAntigo *aux = NULL;
  Elo *p, *q;
  p = l.cabec;
  q = l.cabec->next;
  while (q != NULL && q->val != nome) {
    p = q;
    q = q->next;
  }
  if (q != NULL) {
    aux = q->val;
    p->next = q->next;
    free (q);
  }
  return aux;
}


void testeL () {
  Lista aux = criaL ();

  ElementoAntigo *E = malloc (sizeof (ElementoAntigo));
  strcpy (E->n, "gatinhos_mortos");
  ElementoAntigo *E2 = malloc (sizeof (ElementoAntigo));
  strcpy (E2->n, "haha");

  //teste insere
  aux = insereL (aux, E);
  insereL (aux, E2);

  //teste ateh o fim da lista
  int i = 0; Lista tmp = aux;
  while (tmp.cabec != NULL){
    printf ("Elemento %d: %s\n", i, nameAntigo (tmp.cabec->val));
    tmp.cabec = tmp.cabec->next;
    i++;
  }

  //Teste busca
  printf ("\nBusca 1: %s\n", nameAntigo (buscaElementoAntigo (aux, E)));
  printf ("Busca 2: %s\n\n", nameAntigo (buscaElementoAntigo (aux, E2)));

  //teste retiraElemento
  printf ("Retira: %s\n\n", nameAntigo (retiraElementoAntigo (aux, E2)));

  i = 0; tmp = aux;
  while (tmp.cabec != NULL){
    printf ("Elemento %d: %s\n", i, nameAntigo (tmp.cabec->val));
    tmp.cabec = tmp.cabec->next;
    i++;
  }

  destroiL (aux);
  free  (E); free (E2);
}

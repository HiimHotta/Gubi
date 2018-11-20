#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

char* name (Elemento *elemento) {
  return elemento->nome;
}

Boolean ehLugar (Elemento *ele) {
  if (ele->t == lugar)
    return True;
  return False;
}

Boolean getBoolAtributo (Elemento *ele, char *key) {
  Atributo *atr = buscaTS (ele->d.obj.atributo, key);
  return atr->bool;
}

void setBoolAtributo (Elemento *ele, Boolean bool, char *key) {
  Atributo *atr = buscaTS (ele->d.obj.atributo, key);
  atr->bool = bool;
}


int compareElemento (Elemento *elemento1, Elemento *elemento2) {
  if (strcmp (elemento1->nome, elemento2->nome) == 0)
    return 1;
  return 0;
}

void* buscaElemento (Lista l, Elemento* val) {
  Lista aux = l;

  //se tah olhando pra cabeca, tem q olhar pro prox
  if (aux.cabec->val == NULL && aux.cabec->val != NULL)
    aux.cabec = aux.cabec->next;

  while (aux.cabec != NULL) {
    if (compareElemento (aux.cabec->val, val) == 1)
      return aux.cabec->val;
    aux.cabec = aux.cabec->next;
  }
  return NULL;
}

Elemento* retiraElemento (Lista l, Elemento* nome) {
  Elemento *aux = NULL;
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

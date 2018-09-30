  /* Caso haja alguma falha de compilacao com tmp->val tente substituir por
// tmp.val, ou seja, alternar de . para "->" e o inverso.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h" //nao lembro se eh esse msm
//#include "elemento.h"

Lista cria () {
  Lista tmp;
  tmp.cabec = malloc(sizeof(Elo));
  tmp.cabec->val = malloc(sizeof(Elemento));
  tmp.cabec->next = NULL;
  return tmp;
  /*Lista* novo = (Lista*) malloc(sizeof(Lista));
  return *novo;*/
}

void destroi(Lista l) {
  if(l.cabec->next != NULL){
    Elo* lixo;
    lixo = l.cabec->next;
    while(lixo != NULL){
      l.cabec->next = lixo->next;
      free(lixo->val);
      free(lixo);
      lixo = l.cabec->next;
    }
  }
  free(l.cabec->val);
  free(l.cabec);
}
  /*Lista p = l;
  while (p.cabec->next != NULL) {
    Lista* t = p->prox;
    free(p);
    p = t;
  }
}*/

/*inserção no início: retorna a lista atualizada */
Lista insere(Lista l, Elemento* val) {
  Lista novo = cria();
  novo.cabec->val = val;
  if(l.cabec->val == NULL){
    l = novo;
  }
  else{
    novo.cabec->next = l.cabec;
  }
  return novo;
}

/*Busca pela lista inteira, enquanto houver p.prox continua procurando
//se nao tiver, retorna NULL                                          */
Elemento* busca(Lista l, char* n) {
  /*Lista p = l; int i = 0;
  while (p != NULL && i < 80) {
    if (p->val.n[i] != n[i++]) {
      p = p->next;
      i = 0;
    }
  }
  return p.val.n;*/
}

Elemento* buscaR (Lista l, char* n) {
  /*if (l == NULL) return NULL;
  while (l->val.n[i] == n[i++])
  if (i == 80) return l->val.n;
  return buscaR (l->prox, n);*/
}

Elemento* retira(Lista l, Elemento* val) {

}

int main () {
  //Lista aux = cria ();
  //aux.cabec->val = malloc (sizeof (Elemento));
  //aux.cabec->val->n[0] = 'a';
  //aux.cabec->val->n[1] = 'b';
  Elemento E;
  char str1[80] = "gatinhos_voadores";
  strcpy(E.n,str1);
  Lista aux = NULL;
  aux = insere(aux, &E);
  //printf ("%c %c \n", aux.cabec->val->n[0], aux.cabec->val->n[1);
  printf("%s",E.n);
  destroi(aux);
  return 0;
}

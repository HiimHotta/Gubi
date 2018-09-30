/* Caso haja alguma falha de compilacao com tmp->val tente substituir por
// tmp.val, ou seja, alternar de . para "->" e o inverso.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h" //nao lembro se eh esse msm

Lista cria () {
  Lista tmp = malloc sizeof (Elo);
  tmp->next = NULL;
  return tmp;
}

void destroi(Lista l) {
  Lista p = l;
  while (p != NULL) {

  }
}

Lista insere(Lista l, Elemento* val) {
  Lista aux = l, tmp = cria ();
  tmp->val = val;
  while (l->next != NULL) {

  }
}

/*Busca pela lista inteira, enquanto houver p.prox continua procurando
//se nao tiver, retorna NULL                                          */
Elemento* busca(Lista l, char* n) {
  Lista p = l; int i = 0;
  while (p != NULL && i < 80) {
    if (p->val.n[i] != n[i++]) {
      p = p->next;
      i = 0;
    }
  }
  return p.val.n;
}

Elemento* buscaR (Lista l, char* n) {
  if (l == NULL) return NULL;
  while (l->val.n[i] == n[i++])
  if (i == 80) return l->val.n;
  return buscaR (l->prox, n);
}

Elemento* retira(Lista l, Elemento* val) {

}

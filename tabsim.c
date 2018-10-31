#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabsim.h"

unsigned convert (char* s, int tam) {
   unsigned h = 0;
   for (int i = 0; s[i] != '\0'; i++) 
      h = (h * 256 + s[i]) % tam;
   return h;
}

TabSim cria (int tam) {
  TabSim tmp;
  tmp.tab = malloc (tam * sizeof (Cell));
  tmp.tam = tam;
  for (int i = 0; i < tam; i++) {
  	tmp.tab[i].key = NULL;
  }
  return tmp;
}

int insere(TabSim t, char *n, Elemento *val) {
  unsigned index = convert (n, t.tam);
  if (t.tab[index].key == NULL) {
    t.tab[index].key = n;
    t.tab[index].val = val;
  	return 1;
  }
  return 0;
}

void destroi (TabSim t) {
  free (t.tab);
  t.tab = NULL;
  //t.tam = NULL;
}

Elemento* busca(TabSim t, char *n) {
  unsigned index = convert (n, t.tam);
  if (t.tab[index].key != NULL) 
  	if (strcmp (t.tab[index].key, n) == 0)
  		return t.tab[index].val;
  return NULL;
}

int retira(TabSim t, char *n) {
  unsigned index = convert (n, t.tam);
  if (t.tab[index].key != NULL) 
  	if (strcmp (t.tab[index].key, n) == 0) {
      t.tab[index].key = NULL;
      t.tab[index].val = NULL;
  		return 1;
    }
  return 0;
}

int main () {
  TabSim tab = cria (10);
  Elemento* ele;
  ele = malloc (sizeof (Elemento));
  ele->n[0] = 'a';
  printf("%s\n", ele->n);

  //teste insere
  int x = insere (tab, "haha", ele);
  if (x != 0)
    printf ("%s\n", tab.tab[7].val);

  //teste busca
  Elemento *tmp = busca (tab, "haha");
  printf ("B:%s\n", tmp->n);

  //teste retira
  int y = retira (tab, "haha");
  //se descomentar vai dar falha de segmentacao
  //pq nao há nada na posicao 7
  //printf ("%s\n", tab.tab[7].val);

  destroi (tab);
  free (ele);

  /* Aventure-se a fazer um teste melhor HAHA */

  //while (insere (tab, "hahaha", ele) != 0) {
  //	printf ("debug2");
  //	Elemento* tmp = busca (tab, "hahaha");
  //	printf ("%s\n", tmp->n);
  //}
  return 0;
}

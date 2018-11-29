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

TabSim criaTS (int tam) {
  TabSim tmp;
  tmp.tab = malloc (tam * sizeof (Cell));
  tmp.tam = tam;
  for (int i = 0; i < tam; i++) {
    tmp.tab[i].key = criaL ();
    tmp.tab[i].val = criaL ();
  }
  return tmp;
}

int insereTS (TabSim t, char *n, void *val) {
  unsigned index = convert (n, t.tam);

  insereL (t.tab[index].key, n);
  insereL (t.tab[index].val, val);
  /*
  Lista aux = t.tab[index].key;
  Lista auxVal = t.tab[index].val;

  while (endList (aux) == False) {
    aux.cabec = aux.cabec->next;
    auxVal.cabec = auxVal.cabec->next;
  }

  (aux.cabec->next)->val = n;
  (auxVal.cabec->next)->val = val;
  */
  return 1;
}

void destroiTS (TabSim t) {
  for (int i = 0; i < t.tam; i++)
    if (!endList (t.tab[i].key)) {
      destroiL (t.tab[i].val);
      destroiL (t.tab[i].key);
    }
  free (t.tab);
  t.tab = NULL;
}

void* buscaTS (TabSim t, char *n) {
  unsigned index = convert (n, t.tam);
  Lista auxKey = t.tab[index].key;
  Lista auxVal = t.tab[index].val;

  auxKey.cabec = auxKey.cabec->next;
  auxVal.cabec = auxVal.cabec->next;

  while (endList(auxKey) == False && strcmp (peek (auxKey), n) != 0) {
    printf ("K");
    auxKey.cabec = auxKey.cabec->next;
    auxVal.cabec = auxVal.cabec->next;
  }

  return auxVal.cabec->val;
}

int retiraTS (TabSim t, char *n) {
  unsigned index = convert (n, t.tam);
  Lista auxKey = t.tab[index].key; Lista auxKeyProx = t.tab[index].key;
  Lista auxVal = t.tab[index].val;
  while (endList (auxKeyProx) == False) {
    if (strcmp (peek (auxKeyProx), n) == 0) {
      retiraL (auxKey.cabec, auxKeyProx.cabec);
      retiraL (auxVal.cabec, auxVal.cabec->next);
      return 1;
    }
    auxKey.cabec = auxKeyProx.cabec;
    auxKeyProx.cabec = auxKeyProx.cabec->next;
    auxVal.cabec = auxVal.cabec->next;
  }
  return 0;
}

void testeTS () {
  TabSim tab = criaTS (10);
  ElementoAntigo* ele = malloc (sizeof (ElementoAntigo));
  strcpy (ele->n, "teste");

  //teste insere
  printf ("Insere: %d\n", insereTS (tab, "hahaha", ele));

  //teste busca
  printf ("Busca: %s\n", nameAntigo (buscaTS (tab, "hahaha")));

  //teste retira
  printf ("Retira: %d\n", retiraTS (tab, "hahaha"));

  printf ("Busca: %s\n", buscaTS (tab, "hahaha"));

  free (ele);

  destroiTS (tab);
}

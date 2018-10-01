#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elemento.h"

typedef struct {
  char* key;
  Elemento* val;
} Cell;

typedef struct {
  Cell* tab;
  int tam;
} TabSim;

//converte para int a string, ideia : agilizar a busca
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
  return tmp;
}

/*se a posicao estiver vazia, pode inserir, se */
/*nao tiver, retorna falso                     */
int insere(TabSim t, char *n, Elemento *val) {
  unsigned index = convert (n, t.tam);
  if (t.tab[index].key == NULL) {
  	strcpy (t.tab[index].key, n);
  	return 1;
  }
  return 0;
}

//destroi tabela t
void destroi (TabSim t) {
  free (t.tab);
  t.tab = NULL;
  t.tam = 0;
}

Elemento* busca(TabSim t, char *n) {
  unsigned index = convert (n, t.tam);
  if (t.tab[index].key != NULL) 
  	if (strcmp (t.tab[index].key, n) == 0)
  		return t.tab[index].val;
  return NULL;
}

/*se a posicao estiver vazia, pode inserir, se */
/*nao tiver, retorna falso (0)                 */
int retira(TabSim t, char *n) {
  unsigned index = convert (n, t.tam);
  if (t.tab[index].key != NULL) 
  	if (strcmp (t.tab[index].key, n) == 0)
  		return 1;
  return 0;
}

int main () {
  TabSim tab = cria (10);
  Elemento ele;
  ele.n = "teste";
  while (insere (tab, "hahaha", ele.n) != 0) {
  	Elemento* tmp = busca (tab, i);
  	printf ("%s\n", tmp->n);
  }
  return 0;
}

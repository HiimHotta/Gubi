#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char* key;
  Elemento* val;
} Cell;

typedef struct {
  Cell* TabSim;
}

TabSim cria (int tam) {
  TabSim tmp = malloc (tam * sizeof (Cell));
  return tmp;
}


int insere(TabSim t, char *n, Elemento *val) {
  
  for (int i = 0; i < MAXSTRING; i++) {
  	
  }
}

//destroi tabela t
void destroi (TabSim t) {

}

Elemento* busca(TabSim t, char *n) {

}

int retira(TabSim t, char *n) {

}

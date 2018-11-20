#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *nome;
  Elemento *local;
  int MAXInventario;
  Elemento **inventario;
  TabSim acoes;
} Player;

void criaP (Player *p, char *nome, int MAXInventario, int TabAcoes, Elemento *local);

void moveP (Player *p, Elemento *local);

int adicionaInventario (Player *p, Elemento *ele);

Elemento* retiraInventario (Player *p, Elemento *ele);

void destroiP (Player *p);
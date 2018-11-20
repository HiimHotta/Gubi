#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

void criaP (Player *p, char *nome, int MAXInventario, int TabAcoes, Elemento *local) {
  strcpy (p->nome, nome);
  p->MAXInventario = MAXInventario;
  p->inventario = malloc (MAXInventario * sizeof (Elemento*));
  p->acoes = criaTS (TabAcoes);

  if (ehLugar (local))
    p->local = local;
  else 
  	printf ("Erro ao escolher lugar do player \n"); 
}

void moveP (Player *p, Elemento *local) {
  if (ehLugar (local))
    p->local = local;

  else 
  	printf ("Erro ao mudar de local\n");
}

int adicionaInventario (Player *p, Elemento *ele) {
  if (!ehLugar (ele)) { 
  	//iterador
  	i = 0;
  	while (i < p->MAXInventario && p->inventario[i] != NULL && p->inventario[i] == ele)
  	  i++;
    
    if (i < p) {
      p->inventario[i] = ele;
      return 1;
    }

    else {
      printf ("Inventário Cheio!!!");
      return -1;
    }
  }
}

Elemento* retiraInventario (Player *p, Elemento *ele) {
  int i = 0;
  while (i < p->MAXInventario && p->inventario[i] != NULL && p->inventario[i] == ele)
  	i++;

  if (i < p) 
  	return p->inventario[i];

  else 
  	return NULL;
}

void destroiP (Player *p) {
  destroiTS (p->acoes);
  free (p->inventario);
  free (p);
}
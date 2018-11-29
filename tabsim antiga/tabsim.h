#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elemento.h"

typedef struct {
  char *key;
  void *val;
} Cell;

typedef struct {
  Cell *tab;
  int tam;
} TabSim;

//converte para int a string, ideia : agilizar a busca
unsigned convert (char* s, int tam);

//cria n Cell
TabSim cria (int tam);

/*se a posicao estiver vazia, pode inserir, se */
/*nao tiver, retorna falso                     */
int insere(TabSim t, char *n, void *val);

//destroi tabela t
void destroi (TabSim t);

/*busca pela chave n, se achar retorna o elemento */
/* senao, retorna NULL                            */
void* busca(TabSim t, char *n);

/*se a posicao estiver vazia, pode tirar, se */
/*nao tiver, retorna falso (0)                 */
int retira(TabSim t, char *n);

//int main ();
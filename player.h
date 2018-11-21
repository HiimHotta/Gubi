#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//EM CONSTRUCAO PRA FASE 3

typedef struct {
  char *nome;             //nome do player
  Elemento *local;        //local que o player se encontra
  int MAXInventario;      //quant max de itens no inventario, se tiver uma bolsa pode aumentar
  Elemento **inventario;  //vetor de ponteiros dos itens (elementos)
  TabSim acoes;           //acoes que o player pode executar
} Player;

//cria o Player, setar o basico, memoria, nome, etc
void criaP (Player *p, char *nome, int MAXInventario, int TabAcoes, Elemento *local);

//muda o lugar que o player se encontra
void moveP (Player *p, Elemento *local);

//adiciona um item no inventario, pela referencia do elemento
int adicionaInventario (Player *p, Elemento *ele);

//retorna o elemento retirado, se precisarmos destrui-lo por exemplo
Elemento* retiraInventario (Player *p, Elemento *ele);

//destroi o player
void destroiP (Player *p);

//teste que serah utilizado para testar as funcoes do player
void testeP ();
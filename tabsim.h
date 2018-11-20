#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "lista.h"

typedef struct {
  Lista key;
  Lista val;
} Cell;

typedef struct {
  Cell *tab;
  int tam;
} TabSim;

//converte para int a string (modulo tamanho da tabela), ideia : agilizar a busca
//e insercao, quando usados numeros primos menores a chance de colisoes na tabela
//e listas "GIGANTES"
unsigned convert (char* s, int tam);

//cria n Cell's
TabSim criaTS (int tam);

// Insere na Lista ligada de CHAVES (KEY) o valor n e na lista de VALORES (VAL)
//insere val.
int insereTS (TabSim t, char *n, void *val);

//destroi tabela t, mas NAO ELIMINA OS ELEMENTOS NELA
void destroiTS (TabSim t);

//Busca na posicao convert (n) ateh o final da lista, se nao achar retorna NULL
void* buscaTS (TabSim t, char *n);

//Busca e retira o elemento com CHAVE(KEY) n
int retiraTS (TabSim t, char *n);

//Teste da funcao, output:
//Insere: 1
//Busca: testeTS
//Retira: 1
//Busca: (null)
void testeTS ();

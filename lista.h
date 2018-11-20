#include <stdio.h>
#include <stdlib.h>

typedef struct elo {
  struct elo* next;
  void *val;
} Elo;

typedef struct {
  Elo* cabec;
} Lista;

// Funcoes que sempre vai usar: endList() e peek(). usamos void* pra representar
//um ponteiro generico

// Cria uma lista com cabeça VAZIA, cabeça eh uma referencia para o comeco da
//lista e nao serah preenchida
Lista criaL ();

//destroi SOMENTE A LISTA, SEM eliminar(free) os ELEMENTOS
void destroiL (Lista l);

//insere na ULTIMA posicao da lista e retorna uma referencia para essa posicao
Lista insereL (Lista l, void *val);

// retorna o valor nesse Elo da lista
void* peek (Lista l);

// checa se vc estah no final da lista
Boolean endList (Lista l);

// O void* de atual.cabec e preenche os ponteiros. anterior->prox vai apontar pro
//atual->prox. Como uma Lista ligada normal.
void* retiraL (Lista ant, Lista atual);

/*Busca pela lista inteira, enquanto houver p.prox continua procurando
//se nao tiver, retorna NULL                                          */
ElementoAntigo* buscaElementoAntigo (Lista l, ElementoAntigo *val);

//retirar o elemento val da lista, sem tirar da memoria?
ElementoAntigo* retiraElementoAntigo (Lista l, ElementoAntigo *val);

//testa as funcoes basicas da lista. Output:
//Elemento 0: (null)
//Elemento 1: gatinhos_mortos
//Elemento 2: haha

//Busca 1: gatinhos_mortos
//Busca 2: haha

//Retira: haha

//Elemento 0: (null)
//Elemento 1: gatinhos_mortos
void testeL ();

#include <stdio.h>
#include <stdlib.h>

typedef int (*func) (void *e1, void *e2);

typedef enum {
  lugar = 0, objeto,
} tipo;

typedef union {
  char *name;
  int num;
  Boolean bool;
} Atributo;

typedef struct {
  TabSim atributo;
} Objeto;

typedef struct l{
  struct l *norte;
  struct l *sul;
  struct l *leste;
  struct l *oeste;
  struct l *outros;
} Lugar;

typedef union {
  Objeto obj;
  Lugar l;
} Detalhe;

typedef struct {
  char *nome;             //nome :nome padrao do Elemento (string).
  char *curta;            //curta :descricao curta (string).
  char *longa;            //longa : descricao detalhada (string).
  Boolean ativo;        //indicador se o Elemento esta ativo no jogo.
  Boolean visivel;      //indicador se o Elemento esta visivel.
  Boolean conhecido;    //indicador s o Elemento ja e conhecido do aventureiro
  TabSim conteudo;
  TabSim acoes;
  func *animacao;
  tipo t;
  Detalhe d;
} Elemento;

char* name (Elemento *elemento);

Boolean ehLugar (Elemento *ele);

Boolean getBoolAtributo (Elemento *ele, char *key);

void setBoolAtributo (Elemento *ele, Boolean bool, char *key);

int compareElemento (Elemento *elemento1, Elemento *elemento2);

/*Busca pela lista inteira, enquanto houver p.prox continua procurando
//se nao tiver, retorna NULL                                          */
void* buscaElemento (Lista l, Elemento *val);

//retirar o elemento val da lista, sem tirar da memoria?
Elemento* retiraElemento (Lista l, Elemento* val);

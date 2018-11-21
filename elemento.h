#include <stdio.h>
#include <stdlib.h>

typedef int (*func) (void *e1, void *e2);

typedef enum {
  lugar = 0, objeto,  //diferenciar entre lugar e objeto
} tipo;

typedef union {
  char *name;     //nome do atributo, ex: frase secreta. etc
  int num;        //int pra atributo extra, talvez senha/cohdigo
  Boolean bool;   //bool, o que mais usamos na verdade
} Atributo;

typedef struct {
  TabSim atributo;  //Atributos extras e especiais conforme solicitado
} Objeto;

typedef struct l{
  struct l *norte; //referencia para as direcoes cardinais
  struct l *sul;
  struct l *leste;
  struct l *oeste;
  struct l *outros; //referencias extras
} Lugar;

typedef union {
  Objeto obj;       //atributos especiais que diferenciam obj e lugar
  Lugar l;          
} Detalhe;

typedef struct {
  char *nome;           //nome :nome padrao do Elemento (string).
  char *curta;          //curta :descricao curta (string).
  char *longa;          //longa : descricao detalhada (string).
  Boolean ativo;        //indicador se o Elemento esta ativo no jogo.
  Boolean visivel;      //indicador se o Elemento esta visivel.
  Boolean conhecido;    //indicador s o Elemento ja e conhecido do aventureiro
  TabSim conteudo;      //Elementos extras contidos no Elemento
  TabSim acoes;         //Acoes possiveis de serem executadas com o ELemento
  func *animacao;       //animacao que ocorrera apos um tempo? tipo degradacao?
  tipo t;               //t ajuda a diferenciar se eh um obj ou lugar
  Detalhe d;            //detalhe de lugar OU obj
} Elemento;

//retorna o nome do objeto
char* name (Elemento *elemento);

//retorna se eh um lugar;
Boolean ehLugar (Elemento *ele);

//retorna o bool que teria em atributo, conforme a chave
Boolean getBoolAtributo (Elemento *ele, char *key);

//seta o bool que teria em atributo, conforme a chave
void setBoolAtributo (Elemento *ele, Boolean bool, char *key);

//percebemos que eh inutil, pois podemos sim-plemente comparar as referencias
int compareElemento (Elemento *elemento1, Elemento *elemento2);

//Busca pela lista inteira, enquanto houver p.prox continua procurando
//se nao tiver, retorna NULL, por ser generico, talvez seja inutil agora                                         
void* buscaElemento (Lista l, Elemento *val);

//retirar o elemento val da lista, sem tirar da memoria?
Elemento* retiraElemento (Lista l, Elemento* val);

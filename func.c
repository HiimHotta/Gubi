#include <stdio.h>
#include <stdlib.h>

//AÇÕES
//CRITERIO DE POSSIBILIDADE DE UMA ACAO:  eh se o elemento estah VISIVEL

//Por definicao, todos os Elementos tem acao ANALISAR
int analisar (Elemento *e1, Elemento *e2) {
  if (e1 != NULL && e2 == NULL)
    if (e1->visivel) {
      if (!e1->conhecido)
        e1->conhecido;
      printf ("%s: %s", e1->nome, e1->longa);
      return 1;
    }

  return -1;
}

int locomover (Elemento *e1, Elemento *e2) {
  if (e1 != NULL && e2 == NULL) {
    if (e1->visivel && ehLugar (e1) && buscaTS (e1->acoes, "LOCOMOVER") != NULL){
      e1->ativo = True;
      //movePlayer ()
      return 0;
    }
  }
  return -1;
}

int pegar (Elemento *e1, Elemento *e2) {
  if (e1 != NULL && e2 == NULL) {
    if (buscaTS (e1->acoes, "PEGAR") != NULL && e1->visivel == True) {
      //e1->ativo = False;
      e1->visivel = False;
      //colocaInvetario (player, e1)
      return 1;
    }
  }
  return -1;
}

int abrir (Elemento *e1, Elemento *e2) {
  if (e1 != NULL && e2 == NULL) {
    if (!ehLugar (e1) && e1->visivel && buscaTS (e1->acoes, "ABRIR")) {
      if (!getBoolAtributo (e1, "ABERTO"))
        setBoolAtributo (e1, True, "ABERTO");
      else
        printf ("Jah estah aberto");
      return 1;
    }
    return -1;
  }
}

int fechar (Elemento *e1, Elemento *e2) {
  if (e1 != NULL && e2 == NULL) {
    if (!ehLugar (e1) && e1->visivel && buscaTS (e1->acoes, "FECHAR")) {
      if(getBoolAtributo (e1, "ABERTO"))
        setBoolAtributo (e1, False, "ABERTO");
      else
        printf ("Jah estah fechado");
      return 1;
    }
    return -1;
  }
}

int quebrar (Elemento *e1, Elemento *e2) {
  if (e1 != NULL && e2 == NULL)
    if (!ehLugar (e1) && e1->visivel && buscaTS (e1->acoes, "QUEBRAR")) {
      e1->ativo = False;
      e1->visivel = False;
      return 1;
    }
  return -1;
}

void testeFunc (){
  /*
  printf("COMPUTADOR\n");
  Elemento *e1 = malloc(sizeof(Elemento));
  e1->nome = "COMPUTADOR";
  e1->ativo = True;
  e1->visivel = True;
  */
}

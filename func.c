#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include "tabsim.h"

//Globais
TabSim inventario;
Elemento *Posic    = (Elemento *) 0; /* Posição atual */

/* Macros para testar propriedades comuns */
#define Ativo(x) (x)->Det.obj.ativo
#define Visivel(x) (x)->Det.obj.visivel

//AÇÕES
//CRITERIO DE POSSIBILIDADE DE UMA ACAO:  eh se o elemento estah VISIVEL



//*********************************************************************************
/* Transfere um elemento para o inventário */
void Pegar(Elemento *o1, TabSim sala) {
  if (o1->t == 2) {
	puts("Impossível realizar vossa solicitação");
	return;
  }

  if (Ativo(o1)) {
	if (Visivel(o1)) {
    if(buscaTS(inventario,o1->nome)){
      printf("Você já está com %s!\n", o1->nome);
		  return;
    }
    if(buscaTS(sala,o1->nome)){ 
		/* retira do local */
      retiraTS(sala,o1->nome);

		/* insere no inventário */
		insereTS(inventario,o1->nome,o1);
		printf("Peguei %s\n", o1->nome);
		return;
    }
		printf("Não há %s aqui!\n", o1->nome);
		return;
	  }
	printf("Não consigo ver nenhum %s!\n", o1->nome);
  return;
	}
	printf("Não existe %s!!!!\n", o1->nome);
  return;
}



/* Descreve um Elemento em detalhes */
void Examinar(Elemento *o1, Elemento *o2) {
  symrec *ptr;

  /* o default é descrever o local atual */
  if (o1 == NULL || o1 == Posic) {
	puts(Posic->longa);
	puts("Aqui tem:");
	for (ptr = Posic->cont; ptr != (symrec *) 0;
		 ptr = (symrec *)ptr->next) {
	  /* como a lista contém tods os nomes, precisamos filtrar */
	  if (ptr->tipo == OBJ) {
		Elemento *oo = (Elemento *)ptr->value;
		if (Visivel(oo)  && Ativo(oo))
		  printf("\t%s\n", oo->nome);
	  }
	}
	return;
  }
  if (o1->tipo == OBJ)
	if (Ativo(o1) && Visivel(o1))
	  puts(o1->longa);
	else puts("Oi?");
  else
	puts("Não tenho como responder neste momento");
}


















//tentativa anterior
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
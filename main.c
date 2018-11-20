#include <stdio.h>
#include <stdlib.h>
//#include "elemento.h"
#include "elementoAntigo.c"
#include "lista.c"
#include "tabsim.c"
//#include "elementoAntigo.c"


  /*Cria um vetor com os comandos de teste e depois disso, temos um laco que executa o
  seguinte pseudo-codigo:
  (a) Apresenta a descricao da sala, se ela ainda nao foi visitada. Use um atributo para
  indicar a visita.
  (b) Relaciona o conteudo visıvel da sala.
  (c) Manda executar cada um dos comandos, que atualizara os objetos e salas de acordo.
  (d) Faz as atualizacoes automaticas dos Elementos animados (isto e, que contenham
  uma funcao de animacao). */


int main () {
  printf ("\nTESTE LISTA LIGADA\n\n");
  testeL ();

  printf ("\nTESTE TABELA DE SIMBOLOS\n\n");
  testeTS();
  return 0;
}

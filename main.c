#include <stdio.h>
#include "symrec.h"

int yyparse();
symrec* init_table();
int timer = 180;
int Life = 200;
int flag = 0;
int main()
{
  /* Monta o mundo */
  sym_table = init_table(sym_table);

  /* Descrição inicial */
  printf("\n\nVocê acorda em sua suíte presidencial, mas algo está errado, muito errado.\n"
         "Existe   qualquer   coisa   de   anti-natural  e  desumano  em  despertar  por\n"
         "iniciativa  própria, e  não  pelo  quarteto de cordas  executando  uma peça de\n"
         "Mozart  precisamente  às  08:00. E  onde  estão  o chef para apresentar o menu\n"
         "matinal, e Jarbas com os jornais do dia?\n\n");

  printf ("A  urgência  está o incomodando e a premonição de que algo terrível está para\n"
          "acontecer  não o abandona. Você sente que é uma questão de vida ou morte sair\n"
          "deste local em 3 horas. Você precisa sair, pois você está muito nervoso e com fome. \n\n");

  printf ("Tempo restante: 3h : 00min \n\n");

  /* Que comece o jogo */
  while (yyparse() && timer > 0 && Life > 0 ) {
    timer -= 5;
    Life  -= 5;
    if(!getsym(sym_table,"pudim") && flag == 0){
      Life += 80;
      flag = 1;
    }
    if (timer == 120)
      printf ("Apresse-se, não temos muito tempo!""Sua fome esta aumentando !!!"
              "Tempo restante: 2h : 00min \n\n");

    else if (timer == 60)
      printf ("Agora temos somente 1hora!!!"
              "Tempo restante: 1h : 00min \n\n");

    else if (timer == 30)
      printf ("Não quero nem ver o que vai acontecer!!! (Brincadeira, só tô aqui pra isso)"
              "Tempo restante: 0h : 30min \n\n");
    else
      printf ("Tempo restante: %dh : %dmin | VIDA : %d \n\n", timer / 60, timer % 60, Life);

  }

  if (timer <= 0) {
    printf ("OOOH, NÃO!!! Você não conseguiu sair para comprar seu croissant para o café\n "
            "da manhã!!! Mas que dia horrendo, com certeza um dia que você daria de tudo\n"
            "para  apagá-lo  de sua memória! O seu ritual diário quebrado, a sensação de\n"
            "satisfação  desse  alimento, que  que  meros  plebeus  não  podem desfrutar "
            "cotidianamente  como  você nunca mais será a mesma. Esse arrependimento que"
            "irá  continuar  a  perseguí-lo  até  que os seus dias se acabem! Ó que dor!\n"
            "Ó que angústia!!!\n");
  }

  printf ("FIM!!!\n");
  return 0;
}

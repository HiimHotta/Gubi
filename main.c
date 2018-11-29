#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elementoAntigo.c"
#include "lista.c"
#include "tabsim.c"
#include "elemento.c"
#include "func.c"


  /*Cria um vetor com os comandos de teste e depois disso, temos um laco que executa o
  seguinte pseudo-codigo:
  (a) Apresenta a descricao da sala, se ela ainda nao foi visitada. Use um atributo para
  indicar a visita.
  (b) Relaciona o conteudo visıvel da sala.
  (c) Manda executar cada um dos comandos, que atualizara os objetos e salas de acordo.
  (d) Faz as atualizacoes automaticas dos Elementos animados (isto e, que contenham
  uma funcao de animacao). */


int main () {
  func an = analisar;
  func lo = locomover;
  func pe = pegar;
  func ab = abrir;
  func fe = fechar;
  func queb = quebrar;

  
  TabSim lugares = criaTS(5);

  //QUARTO
  Elemento* local = malloc (sizeof (Elemento));
  local->nome = "Quarto";
  local->curta = "Seu habitáculo. Na parede sul há uma CAMA king-size e uma MESA DE CABECEIRA com um ABAJUR e a assistente ALEXA. Na parede norte há uma TELEVISÃO e a saída para o hall. A parede oeste tem a porta do banheiro.";
  local->longa = "Você acorda em sua suíte presidencial, mas algo está errado, muito errado. Existe qualquer coisa de anti-natural e desumano em despertar por iniciativa própria, e não pelo quarteto de cordas executando uma peça de Mozart precisamente às 08:00. E onde estão o chef para apresentar o menu matinal, e Jarbas com os jornais do dia? Na parede oposta há uma TELEVISÃO, desligada. Ao seu lado está a MESA DE CABECEIRA, com um ABAJUR em forma de cifrão e ALEXA, essa companheira de todas as horas. Há uma porta a oeste que leva ao banheiro e uma porta ao norte que conduz ao hall."; 
  local->ativo = False;
  local->visivel = False;
  local->conhecido = False;
  local->t = lugar;

  Elemento* ele1 = malloc (sizeof (Elemento));
  ele1->nome = "TV";
  ele1->curta = "Imagem 4K em 60 polegadas de uma tela preta";
  ele1->longa = "Essa tela deveria estar exibindo o Manhattan Connection. Por algum estranho motivo, isso não está acontecendo.";
  ele1->ativo = False;
  ele1->visivel = True;
  ele1->conhecido = False;
  insereTS (ele1->acoes, "ANALISAR", an);
  insereTS(local->conteudo, "TV", ele1);

  Elemento* ele2 = malloc (sizeof (Elemento));
  ele2->nome = "Mesa";
  ele2->curta = "Uma mesa com gaveta feita sob medida";
  ele2->longa = "Mesa de design sueco, corpo em jacarandá com acabamento em mogno. Gaveta feita sob medida com fundo falso para guardar documentos importantes. Sem o fundo falso cabe uma garrafa de uísque de pé, o que também é conveniente";
  ele2->ativo = False;
  ele2->visivel = True;
  ele2->conhecido = False;
  insereTS (ele2->acoes, "ANALISAR", an);
  insereTS (ele2->acoes, "ABRIR", ab);
  insereTS(local->conteudo, "Mesa", ele2);

  Elemento* ele3 = malloc (sizeof (Elemento));
  ele3->nome = "Controle";
  ele3->curta = "Um instrumento que os plebeus utilizam para alterar o estado das coisas";
  ele3->longa = "Qual o propósito de todos esses botões? A perspectiva de manipular diretamente um aparelho é intimidadora. Por sorte, o curso de leitura dinâmica seguindo a técnica da NASA finalmente faz por merecer, e você identifica rapidamente a tecla LIGA/DESLIGA";
  ele3->ativo = False;
  ele3->visivel = False;
  ele3->conhecido = False;
  insereTS (ele3->acoes, "ANALISAR", an);
  insereTS (ele3->acoes, "PEGAR", pe);
  insereTS(local->conteudo, "Controle", ele3);

  Elemento* ele4 = malloc (sizeof (Elemento));
  ele4->nome = "Alexa";
  ele4->curta = "A senhora das respostas, enfim derrotada. Impossível pesquisar a localização da chave.";
  ele4->longa = "A incansável Alexa, noite após noite acatando o pedido para tocar Despacito. Sua voz robótica é a radiação de fundo do próprio Universo.";
  ele4->ativo = False;
  ele4->visivel = True;
  ele4->conhecido = False;
  insereTS (ele4->acoes, "ANALISAR", an);
  insereTS(local->conteudo, "Alexa", ele4);

  Elemento* ele5 = malloc (sizeof (Elemento));
  ele5->nome = "Abajur";
  ele5->curta = "Não é atribuição sua desligar o abajur, mas essa lâmpada acesa está desperdiçando dinheiro";
  ele5->longa = "Sua fonte de luz noturna é um delicado envoltório de seda chinesa em formato de cifrão - um singelo memento para que, ao tomar os comprimidos para dormir, você se recorde de que há coisas pelas quais vale a pena acordar novamente. Curiosamente, ele ainda está ligado, da mesma forma que você deixou na noite anterior";
  ele5->ativo = True;
  ele5->visivel = True;
  ele5->conhecido = False;
  insereTS (ele5->acoes, "ANALISAR", an);
  insereTS (ele5->acoes, "ABRIR", ab);
  insereTS(local->conteudo, "Abajur", ele5);

  Elemento* ele6 = malloc (sizeof (Elemento));
  ele6->nome = "Cama";
  ele6->curta = "Não adianta voltar pra cama, vá explorar o resto da casa!";
  ele6->longa = "A visão da cama desarrumada é desconcertante, mas não há o que se fazer a respeito.";
  ele6->ativo = False;
  ele6->visivel = True;
  ele6->conhecido = False;
  insereTS (ele6->acoes, "ANALISAR", an);
  insereTS(local->conteudo, "Cama", ele6);


  insereTS(lugares, "Quarto", local);

  //BANHEIRO
  Elemento *local2 = malloc (sizeof (Elemento));
  local2->nome = "Banheiro";
  local2->curta = "Esquece o resto, tem um remedinho ali, vamos ver isso";
  local2->longa = "Um modesto espaço de 150 metros quadrados devidamente equipado com duchas, banheiras em diferentes temperaturas, sauna romana e parque aquático. A leste está a porta para o quarto. Logo ao lado há uma pia com um TARJA PRETA."; 
  local2->ativo = False;
  local2->visivel = False;
  local2->conhecido = False;
  local2->t = lugar;

  Elemento* ele7 = malloc (sizeof (Elemento));
  ele7->nome = "TarjaPreta";
  ele7->curta = "Medicação obtida estritamente dentro dos limites da lei";
  ele7->longa = "A claridade do Sol alojada em pequenos comprimidos para ser consumida religiosamente no início de cada dia";
  ele7->ativo = False;
  ele7->visivel = True;
  ele7->conhecido = False;
  insereTS (ele7->acoes, "ANALISAR", an);
  insereTS (ele7->acoes, "PEGAR", pe);
  insereTS(local2->conteudo, "TarjaPreta", ele7);

  insereTS(lugares, "Banheiro", local2);
  //HALL
  Elemento* local3 = malloc (sizeof (Elemento));
  local3->nome = "Hall";
  local3->curta = "A porta de saída da casa está ao norte. A sala tem uma armadura segurando uma ESPADA BASTARDA e também uma MINI-ESTUFA. À leste está a biblioteca, e à oeste a cozinha.";
  local3->longa = "O saguão central dessa modesta residência. As paredes estão decoradas com um brasão que definitivamente não é da sua família, seu avô era sapateiro em Várzea Grande, mas isso não importa agora. Em uma das paredes há uma armadura medieval repousando as mãos sobre uma ESPADA BASTARDA. Sob o relógio-cuco suíço há uma MINI-ESTUFA com uma flor. Ao norte está a pesada porta que dá para o jardim externo. À leste está a biblioteca, e à oeste a cozinha. Ao sul está o corredor que volta para o quarto."; 
  local3->ativo = False;
  local3->visivel = False;
  local3->conhecido = False;
  local3->t = lugar;

  Elemento* ele8 = malloc (sizeof (Elemento));
  ele8->nome = "Espada";
  ele8->curta = "Parece pesada. A lâmina ainda conserva o fio";
  ele8->longa = "Em excepcional estado de conservação, este artefato teria sido empunhado na época da sexta crusada por um vassalo de Frederico II.";
  ele8->ativo = False;
  ele8->visivel = True;
  ele8->conhecido = False;
  insereTS (ele8->acoes, "ANALISAR", an);
  insereTS(local3->conteudo, "Espada", ele8);

  Elemento* ele9 = malloc (sizeof (Elemento));
  ele9->nome = "Estufa";
  ele9->curta = "Estimado Barão. Que Deus o tenha! Talvez o último espírito romântico de nossa era.";
  ele9->longa = "Dentro da estufa está a orquídea rara trazida pelo Barão von Trapp em uma de suas breves estadias na mansão, logo antes de partir para Macapá para juntar-se à expedição russa naquela que viria a ser sua derradeira aventura.";
  ele9->ativo = False;
  ele9->visivel = True;
  ele9->conhecido = False;
  insereTS (ele9->acoes, "ANALISAR", an);
  insereTS(local3->conteudo, "Estufa", ele9);

  insereTS(lugares, "Hall", local3);

  //BIBLIOTECA
  Elemento* local4 = malloc (sizeof (Elemento));
  local4->nome = "Biblioteca";
  local4->curta = "No centro da sala há uma escrivaninha com um LIVRO aberto. Ao lado há uma ESTÁTUA. As paredes são cobertas de ESTANTES. A leste está a porta do Hall.";
  local4->longa = "As paredes são preenchidas, do chão ao teto, com ESTANTES cheias de livros. Entre eles existem algumas primeiras edições de autores famosos, e algumas destas estão assinadas pelos próprios autores. Não que você saiba dizer quais, evidentemente - nunca leu um livro na vida. Mas a existência de uma biblioteca bem estocada é exigência de primeira ordem na construção de uma mansão de calibre, e existem serviços especializados em reunir exemplares com aparência de grande antiguidade e valor. Você examina, com certa curiosidade, essa terra incognita. Há uma escrivaninha com um LIVRO aberto, e uma ESTÁTUA grega em um canto. A leste está a porta de volta para o Hall."; 
  local4->ativo = False;
  local4->visivel = False;
  local4->conhecido = False;
  local4->t = lugar;

  Elemento* ele10 = malloc (sizeof (Elemento));
  ele10->nome = "Estantes";
  ele10->curta = "Mais livros do que um acadêmico sério lerá na vida";
  ele10->longa = "Centenas de livros! Ou milhares! Qual a diferença? Impossível saber onde está qualquer coisa aí no meio";
  ele10->ativo = False;
  ele10->visivel = True;
  ele10->conhecido = False;
  insereTS (ele10->acoes, "ANALISAR", an);
  insereTS(local4->conteudo, "Estantes", ele10);

  Elemento* ele11 = malloc (sizeof (Elemento));
  ele11->nome = "Estátua";
  ele11->curta = "Hermes-Afrodite";
  ele11->longa = "Alguma deusa, ou rainha de algum lugar. Na verdade, olhando bem, pode ser que seja um homem.";
  ele11->ativo = False;
  ele11->visivel = True;
  ele11->conhecido = False;
  insereTS (ele11->acoes, "ANALISAR", an);
  insereTS(local4->conteudo, "Estátua", ele11);

  Elemento* ele12 = malloc (sizeof (Elemento));
  ele12->nome = "Livro";
  ele12->curta = "O catálogo da biblioteca";
  ele12->longa = "Convenientemente, esse livro aberto parece ser um catálogo de todas as obras na biblioteca, indicando estante e prateleira de cada obra";
  ele12->ativo = False;
  ele12->visivel = True;
  ele12->conhecido = False;
  insereTS (ele12->acoes, "ANALISAR", an);
  insereTS(local4->conteudo, "Livro", ele12);

  insereTS(lugares, "Biblioteca", local4);


  //COZINHA
  Elemento* local5 = malloc (sizeof (Elemento));
  local5->nome = "Cozinha";
  local5->curta = "No balcão da cozinha estão um PUDIM DE CACTO e uma PEIXEIRA. A leste está a porta do hall.";
  local5->longa = "O coração inescrutável da residência. Então é este seu aspecto! Fascinante! Infelizmente, encontra-se tão deserta quanto o resto da casa. Os muitos armários e ganchos nas paredes perfilam os artefatos incompreensíveis necessários para conjurar as cornucópias da gastronomia internacional que abastecem diariamente a mansão. A organização do ambiente é impecável, com uma exceção: o PUDIM DE CACTO que arrematou a ceia da noite anterior ainda se encontra sobre o balcão. Ali também há uma PEIXEIRA. A leste fica a porta de volta para o hall."; 
  local5->ativo = False;
  local5->visivel = False;
  local5->conhecido = False;
  local5->t = lugar;

  Elemento* ele13 = malloc (sizeof (Elemento));
  ele13->nome = "Pudim";
  ele13->curta = "Asqueroso! Mas extremamente rico em ômega 3";
  ele13->longa = "As virtudes fitoterápicas do pudim de cacto foram muitíssimo celebradas pelo Comendador Braga em certo jantar beneficente, e desde então passaram a integrar o cardápio regular da mansão. Este pudim foi servido na noite anterior, mas está praticamente intacto";
  ele13->ativo = False;
  ele13->visivel = True;
  ele13->conhecido = False;
  insereTS (ele13->acoes, "ANALISAR", an);
  insereTS (ele13->acoes, "PEGAR", pe);
  insereTS(local5->conteudo, "Pudim", ele13);

  Elemento* ele14 = malloc (sizeof (Elemento));
  ele14->nome = "Faca";
  ele14->curta = "Uma faca dessas corta qualquer coisa com facilidade. Qualquer coisa";
  ele14->longa = "Uma faca de grande porte, pontiaguda e afiada. É a isso que chegamos, então? É este o fim?";
  ele14->ativo = False;
  ele14->visivel = True;
  ele14->conhecido = False;
  insereTS (ele14->acoes, "ANALISAR", an);
  insereTS (ele14->acoes, "PEGAR", pe);
  insereTS(local5->conteudo, "Faca", ele14);

  insereTS(lugares, "Cozinha", local5);

  printf ("Busca: %s\n", buscaTS (lugares, "Banheiro"));

  free (ele1);
  return 0;
}
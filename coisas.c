#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symrec.h"
#include "coisas.h"
#include "avent.tab.h"

/* Variáveis globais */
symrec *sym_table  = (symrec *) 0; /* Tabela de símbolos global */
symrec *inventario = (symrec *) 0; /* material com o aventureiro */
Elemento *Posic    = (Elemento *) 0; /* Posição atual */
Elemento **invent;

//Objetos
//QUARTO
Elemento quarto = {"Quarto", "Seu habitáculo. Na parede sul há uma CAMA king-size e uma MESA DE CABECEIRA com um ABAJUR e a assistente ALEXA. Na parede norte há uma TELEVISÃO e a saída para o hall. A parede oeste tem a porta do banheiro.",
                  "Você acorda em sua suíte presidencial, mas algo está errado, muito errado. Existe qualquer coisa de anti-natural e desumano em despertar por iniciativa própria, e não pelo quarteto de cordas executando uma peça de Mozart precisamente às 08:00. E onde estão o chef para apresentar o menu matinal, e Jarbas com os jornais do dia? Na parede oposta há uma TELEVISÃO, desligada. Ao seu lado está a MESA DE CABECEIRA, com um ABAJUR em forma de cifrão e ALEXA, essa companheira de todas as horas. Há uma porta a oeste que leva ao banheiro e uma porta ao norte que conduz ao hall.",
                  NULL, NULL, LUGAR, .Det.lug.Saidas =  {NULL, NULL, NULL, NULL, NULL,NULL}, 1};

//OBJETOS QUARTO
Elemento tv = {"tv", "Imagem 4K em 60 polegadas de uma tela preta", "Essa tela deveria estar exibindo o Manhattan Connection. Por algum estranho motivo, isso não está acontecendo.",
               NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};


Elemento mesa = {"mesa", "Uma mesa com gaveta feita sob medida", "Mesa de design sueco, corpo em jacarandá com acabamento em mogno. Gaveta feita sob medida com fundo falso para guardar documentos importantes. Sem o fundo falso cabe uma garrafa de uísque de pé, o que também é conveniente",
               NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};

Elemento controle = {"controle",  "Um instrumento que os plebeus utilizam para alterar o estado das coisas",
                    "Qual o propósito de todos esses botões? A perspectiva de manipular diretamente um aparelho é intimidadora. Por sorte, o curso de leitura dinâmica seguindo a técnica da NASA finalmente faz por merecer, e você identifica rapidamente a tecla LIGA/DESLIGA",
                     NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};

Elemento Alexa = {"Alexa", "A senhora das respostas, enfim derrotada. Impossível pesquisar a localização da chave.",
                 "A incansável Alexa, noite após noite acatando o pedido para tocar Despacito. Sua voz robótica é a radiação de fundo do próprio Universo.",
                  NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};

Elemento abajur = {"abajur", "Não é atribuição sua desligar o abajur, mas essa lâmpada acesa está desperdiçando dinheiro",
                  "Sua fonte de luz noturna é um delicado envoltório de seda chinesa em formato de cifrão - um singelo memento para que, ao tomar os comprimidos para dormir, você se recorde de que há coisas pelas quais vale a pena acordar novamente. Curiosamente, ele ainda está ligado, da mesma forma que você deixou na noite anterior",
                  NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};

Elemento cama = {"cama", "Não adianta voltar pra cama, vá explorar o resto da casa!","A visão da cama desarrumada é desconcertante, mas não há o que se fazer a respeito.",
                 NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};


//BANHEIRO
Elemento banheiro = {"Banheiro", "Esquece o resto, tem um remedinho ali, vamos ver isso",
                    "Um modesto espaço de 150 metros quadrados devidamente equipado com duchas, banheiras em diferentes temperaturas, sauna romana e parque aquático. A leste está a porta para o quarto. Logo ao lado há uma pia com um TARJA PRETA.",
                     NULL, NULL, LUGAR, .Det.lug.Saidas =  {NULL, NULL, NULL, NULL, NULL,NULL}, 1};

//OBJETOS BANHEIRO
Elemento tarjapreta = {"tarjapreta", "Medicação obtida estritamente dentro dos limites da lei",
                     "A claridade do Sol alojada em pequenos comprimidos para ser consumida religiosamente no início de cada dia",
                      NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};



//HALL
Elemento hall = {"Hall", "A porta de saída da casa está ao norte. A sala tem uma armadura segurando uma ESPADA BASTARDA e também uma MINI-ESTUFA. À leste está a biblioteca, e à oeste a cozinha.",
                 "O saguão central dessa modesta residência. As paredes estão decoradas com um brasão que definitivamente não é da sua família, seu avô era sapateiro em Várzea Grande, mas isso não importa agora. Em uma das paredes há uma armadura medieval repousando as mãos sobre uma ESPADA BASTARDA. Sob o relógio-cuco suíço há uma MINI-ESTUFA com uma flor. Ao norte está a pesada porta que dá para o jardim externo. À leste está a biblioteca, e à oeste a cozinha. Ao sul está o corredor que volta para o quarto.",
                 NULL, NULL, LUGAR, .Det.lug.Saidas =  {NULL, NULL, NULL, NULL, NULL,NULL}, 1};

//OBJETOS HALL
Elemento espada = {"espada", "Parece pesada. A lâmina ainda conserva o fio",
                  "Em excepcional estado de conservação, este artefato teria sido empunhado na época da sexta crusada por um vassalo de Frederico II.",
                   NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};

Elemento estufa = {"estufa", "Estimado Barão. Que Deus o tenha! Talvez o último espírito romântico de nossa era.",
                  "Dentro da estufa está a orquídea rara trazida pelo Barão von Trapp em uma de suas breves estadias na mansão, logo antes de partir para Macapá para juntar-se à expedição russa naquela que viria a ser sua derradeira aventura.",
                  NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};


//BIBLIOTECA
Elemento biblioteca = {"Biblioteca", "No centro da sala há uma escrivaninha com um LIVRO aberto. Ao lado há uma ESTÁTUA. As paredes são cobertas de ESTANTES. A oeste está a porta do Hall.",
                      "As paredes são preenchidas, do chão ao teto, com ESTANTES cheias de livros. Entre eles existem algumas primeiras edições de autores famosos, e algumas destas estão assinadas pelos próprios autores. Não que você saiba dizer quais, evidentemente - nunca leu um livro na vida. Mas a existência de uma biblioteca bem estocada é exigência de primeira ordem na construção de uma mansão de calibre, e existem serviços especializados em reunir exemplares com aparência de grande antiguidade e valor. Você examina, com certa curiosidade, essa terra incognita. Há uma escrivaninha com um LIVRO aberto, e uma ESTÁTUA grega em um canto. A leste está a porta de volta para o Hall.",
                      NULL, NULL, LUGAR, .Det.lug.Saidas =  {NULL, NULL, NULL, NULL, NULL,NULL}, 1};

//OBJETOS BIBLIOTECA
Elemento estante = {"estantes", "Mais livros do que um acadêmico sério lerá na vida",
                   "Centenas de livros! Ou milhares! Qual a diferença? Impossível saber onde está qualquer coisa aí no meio",
                   NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};

Elemento estatua = {"estátua", "Hermes-Afrodite","Alguma deusa, ou rainha de algum lugar. Na verdade, olhando bem, pode ser que seja um homem.",
                   NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};

Elemento livro = {"livro", "O catálogo da biblioteca", "Convenientemente, esse livro aberto parece ser um catálogo de todas as obras na biblioteca, indicando estante e prateleira de cada obra",
                 NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};


//COZINHA
Elemento cozinha  = {"Cozinha", "No balcão da cozinha estão um PUDIM DE CACTO e uma PEIXEIRA. A leste está a porta do hall.", "O coração inescrutável da residência. Então é este seu aspecto! Fascinante! Infelizmente, encontra-se tão deserta quanto o resto da casa. Os muitos armários e ganchos nas paredes perfilam os artefatos incompreensíveis necessários para conjurar as cornucópias da gastronomia internacional que abastecem diariamente a mansão. A organização do ambiente é impecável, com uma exceção: o PUDIM DE CACTO que arrematou a ceia da noite anterior ainda se encontra sobre o balcão. Ali também há uma PEIXEIRA. A leste fica a porta de volta para o hall.",
                    NULL, NULL, LUGAR, .Det.lug.Saidas =  {NULL, NULL, NULL, NULL, NULL,NULL}, 1};

//OBJETOS COZINHA
Elemento pudim = {"pudim", "Asqueroso! Mas extremamente rico em ômega 3", "As virtudes fitoterápicas do pudim de cacto foram muitíssimo celebradas pelo Comendador Braga em certo jantar beneficente, e desde então passaram a integrar o cardápio regular da mansão. Este pudim foi servido na noite anterior, mas está praticamente intacto",
                 NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};

Elemento faca = {"faca", "Uma faca dessas corta qualquer coisa com facilidade. Qualquer coisa", "Uma faca de grande porte, pontiaguda e afiada. É a isso que chegamos, então? É este o fim?",
                NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};


/* Objetos  */
Elemento fogo    = {"fogo",   "É uma chama quente e bruxuleante", "uma chama", NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};
Elemento gelo    = {"gelo",   "É um pedaço de gelo bem frio", "uma pedra de gelo", NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};
Elemento vapor   = {"vapor",   "Parece fumaça, dança ao vento", "simplesmente vapor", NULL, NULL, OBJ, .Det.obj = {0,0}, 1};
Elemento lepre   = {"leprechaum", "Um leprechaum perdido, vindo da Irlanda, seu nome é Kirkpatrick", "um homenzinho mal encarado", NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};
Elemento caneta  = {"caneta", "Uma caneta vermelha, ótima para corrigir provas", "uma caneta vermelha", NULL, NULL, OBJ, .Det.obj = {0,0}, 1};
Elemento lapis   = {"lapis",  "Um lápis azul, não serve para muitas coisas", "um lapis azul", NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};
Elemento hamster = {"hamster","Um roedor bonitinho, parece muito assustado.", "um hamster fofinho", NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};
Elemento prova   = {"prova",  "Uma prova cheia de garranchos e de escrita insegura", "uma prova escrabosa", NULL, NULL, OBJ, .Det.obj = {1, NULL}, 1};

// adjetivos

Elemento quente = {"quente", "adjetivo de medida de temperatura relativo", "sinônimo de presença de calor", NULL, NULL, ADJETIVO, .Det.adj = "quente", 1};


//
// Funções auxiliares
//

/* verifica se um objeto está presente e visível */
/* retorna 1 se no local, 2 se no inventário, 0 se não existir*/
int presente (char *nome) {
  /* inventário? */
  if (getsym (inventario, nome)) return 2;
  if (getsym (Posic->cont, nome)) return 1;
  return 0;
}

/* Implementações dos verbos */

/* Macros para testar propriedades comuns */
#define Ativo(x) (x)->Det.obj.ativo
#define Visivel(x) (x)->visivel


/* FUNCOES NOVAS*/
//Seta Saidas
void SetLugar () {
  quarto.Det.lug.Saidas[0] = &hall;
  quarto.Det.lug.Saidas[3] = &banheiro;

  banheiro.Det.lug.Saidas[2] = &quarto;

  hall.Det.lug.Saidas[1] = &quarto;
  hall.Det.lug.Saidas[3] = &cozinha;
  hall.Det.lug.Saidas[2] = &biblioteca;

  cozinha.Det.lug.Saidas[2] = &hall;

  biblioteca.Det.lug.Saidas[3] = &hall;
}

//Preenche conteudos nos lugares
void SetObj () {

  // Coloca os objetos nos lugares (GUBI)
  quarto.cont = putsym (quarto.cont, "fogo",       OBJ, &fogo);
  quarto.cont = putsym (quarto.cont, "gelo",       OBJ, &gelo);
  quarto.cont = putsym (quarto.cont, "leprechaum", OBJ, &lepre);
  quarto.cont = putsym (quarto.cont, "lapis",     OBJ, &lapis);
  quarto.cont = putsym (quarto.cont, "caneta",    OBJ, &caneta);
  hall.cont = putsym (hall.cont, "prova",   OBJ, &prova);
  hall.cont = putsym (hall.cont, "hamster", OBJ, &hamster);


  //Quarto
  quarto.cont = putsym (quarto.cont,    "tv"   , OBJ,     &tv   );
  quarto.cont = putsym (quarto.cont,   "mesa"  , OBJ,    &mesa  );
  quarto.cont = putsym (quarto.cont, "controle", OBJ,  &controle);
  quarto.cont = putsym (quarto.cont,  "Alexa"  , OBJ,   &Alexa  );
  quarto.cont = putsym (quarto.cont,  "abajur" , OBJ,   &abajur );
  quarto.cont = putsym (quarto.cont,   "cama"  , OBJ,    &cama  );

  //Banheiro
  banheiro.cont = putsym (banheiro.cont, "tarjapreta", OBJ, &tarjapreta);

  //hall
  hall.cont = putsym (hall.cont, "espada", OBJ, &espada);
  hall.cont = putsym (hall.cont, "estufa", OBJ, &estufa);

  //COZINHA
  cozinha.cont = putsym (cozinha.cont, "pudim", OBJ, &pudim);
  cozinha.cont = putsym (cozinha.cont, "faca", OBJ, &faca);

  //BIBLIOTECA
  biblioteca.cont = putsym (biblioteca.cont, "estante", OBJ, &estante);
  biblioteca.cont = putsym (biblioteca.cont, "estatua", OBJ, &estatua);
  biblioteca.cont = putsym (biblioteca.cont, "livro", OBJ, &livro);
}

void comer (Elemento *o1, Elemento *o2) {

  if (presente ("pudim") == 2) {
	if (getsym (inventario, "pudim")) {
	  inventario = popsym (inventario, "pudim");
	  Posic->cont = popsym (Posic->cont, "pudim");/* Posição atual */

    pudim.Det.obj.ativo = 0;
    pudim.visivel = 0;
    popsym(sym_table, "pudim");
	  puts ("Sua Fome Passou");
	  return;
	}
	else {
	  puts ("BRRRrr, que fome, mas eu aguento");
	}
  }
  else{
    puts ("comer o que ?");
  }
}


void Dicionario (Elemento *o1, Elemento *o2) {
  if (o1 == NULL) {
    printf ("Tá de brincadeira?\n");
    return;
  }

  if (o1->tipo == LUGAR) {
    printf ("Parece que você está se referindo a um SUBSTANTIVO\n");
    return;
  }

  else if (o1->tipo == OBJ) {
    printf ("Parece que você está se referindo a um SUBSTANTIVO\n");
    return;
  }
  else if (o1->tipo == VERBO) {
    printf ("Parece que você está se referindo a um VERBO\n");
    return;
  }
  else if (o1->tipo == ADJETIVO) {
    printf ("Parece que você está se referindo a um ADJETIVO\n");
    return;
  }
  else
    return;
}



void PlayDespacito (Elemento *o1, Elemento *o2) {
  if (o1 == NULL) {
    printf ("Play é exclusivo da ALEXA!!!\n");
    return;
  }
  else if (strcmp (o1->nome, "Alexa") == 0) {
    //ACAO
  }
  else {
    printf ("Play é exclusivo da ALEXA!!!\n");
  }
}



//FIM NOVOS

/* Transfere um elemento para o inventário */
void Pegar (Elemento *o1, Elemento *o2) {
  if (o1 == NULL) {
    printf ("Pegar o que???\n");
    return;
  }
  if (o1->tipo == LUGAR) {
	  puts ("Não dá para pegar um lugar!");
	  return;
  }

  if (o2 != NULL)
    if (o2->tipo != ADJETIVO) {
      printf ("Só consigo pegar uma coisa de cada vez!");
      return;
    }

  if (Ativo(o1)) {
	  if (Visivel (o1)) {
	    int r = presente (o1->nome);
	    switch (r) {
	      case 2:
		      printf ("Você já está com %s!\n", o1->nome);
		      return;
	      case 1:
    		  /* retira do local */
	      	Posic->cont = popsym (Posic->cont, o1->nome);
	      	/* insere no inventário */
    	  	inventario = putsym (inventario, o1->nome, OBJ, o1);
       		printf ("Peguei %s\n", o1->nome);
    	  	return;
	      default:
		      printf ("Não há %s aqui!\n", o1->nome);
		      return;
	    }
	  }
	  printf ("Não consigo ver nenhum %s!\n", o1->nome);
  }

  else
	  printf ("Não existe %s!!!!\n", o1->nome);
}

/* Transfere do inventário para o local atual */
void Largar (Elemento *o1, Elemento *o2) {
  if (o1->tipo == LUGAR) {
	puts ("Largue a mão de ser besta!");
	return;
  }
  if (getsym (inventario, o1->nome)) {
	/* retira do inventario */
	inventario = popsym (inventario, o1->nome);

	/* insere no local */
	Posic->cont = putsym (Posic->cont, o1->nome, OBJ,o1);
	return;
  }
  else {
	/* Em inglês for fun */
	puts ("You don't have it");
  }
}

/* Descreve um Elemento em detalhes */
void Examinar (Elemento *o1, Elemento *o2) {
  symrec *ptr;

  /* o default é descrever o local atual */
  if (o1 == NULL || o1 == Posic) {
	puts (Posic->longa);
	puts ("Aqui tem:");
	for (ptr = Posic->cont; ptr != (symrec *) 0;
		 ptr = (symrec *)ptr->next) {
	  /* como a lista contém tods os nomes, precisamos filtrar */
	  if (ptr->tipo == OBJ) {
		Elemento *oo = (Elemento *)ptr->value;
		if (Visivel(oo)  && Ativo(oo))
		  printf ("\t%s\n", oo->nome);
	  }
	}
	return;
  }
  if (o1->tipo == OBJ)
	if (Ativo(o1) && Visivel(o1))
	  puts (o1->longa);
	else puts ("Oi?");
  else
	puts ("Não tenho como responder neste momento");
}

/* descrição curta de um elemento, está incompleta */
void Olhar (Elemento *o1, Elemento *o2) {
  if (o1)
	  puts (o1->curta);
  else
	  puts (Posic->curta);
}

void Gritar (Elemento *o1, Elemento *o2){
  puts ("YEEAAAAAOOOOOWWWGRRUWL");
}

/* Estas duas funções são mais sofisticadas, pois alteram outros elementos */
void PegarGelo (Elemento *o1, Elemento *o2) {
  if (presente ("gelo")) {
	if (getsym (inventario, "fogo")) {
	  inventario = popsym (inventario, "fogo");
	  Posic->cont = popsym (Posic->cont, "gelo");
	  Posic->cont = putsym (Posic->cont, "vapor", OBJ, &vapor);
	  vapor.Det.obj = (Objeto) {1, NULL};
	  puts ("O gelo e o fogo se fundiram...");
	  return;
	}
	else {
	  puts ("BRRRrr, que frio, mas eu aguento");
	}
  }
  Pegar (&gelo, NULL);
}

void PegarFogo (Elemento *o1, Elemento *o2) {
  if (o2 != NULL && o2->tipo != ADJETIVO) {
    printf ("Só consigo pegar uma coisa de cada vez!\n");
    return;
  }
  if (presente ("fogo")) {
	  if (getsym (inventario, "gelo")) {
	    inventario = popsym (inventario, "gelo");
	    Posic->cont = popsym (Posic->cont, "fogo");
	    Posic->cont = putsym (Posic->cont, "vapor", OBJ, &vapor);
	    vapor.Det.obj = (Objeto) {1, NULL};
	    puts ("O fogo e o gelo se fundiram...");
	    return;
	  }
	  else
	    puts ("UAU! AII! ARRGGHH! Que quente, mas eu aguento");
  }
  Pegar (&fogo, NULL);
}

/* exemplo comportamento especial */
void PegarVapor (Elemento *o1, Elemento *o2) {
  if (Visivel(o1))
	puts ("Não dá! É muito etéreo...");
  else
	Pegar (&vapor,NULL);
}

/* Libera mais um elemento */
void JogarLeprechaum (Elemento *o1, Elemento *o2) {
  puts ("Kirkpatrick emite umas palavras impronunciáveis num jogo de respeito\n"
	   "Algo como @!#$@!&");
  if (!Ativo(&caneta)) {
	caneta.Det.obj = (Objeto) {1, NULL};
	puts ("Ele deixou cair alguma coisa!");
  }
  Largar (&lepre, NULL);
}

/* outro comportamento especial */
void JogarHamster (Elemento *o1, Elemento *o2) {
  printf ("O %s se agarra desesperadamente a você e é impossível largá-lo!\n", o1->nome);
}

void Corrigir (Elemento *o1, Elemento *o2) {
  int r;
  if ((r = presente (o1->nome)))
	puts ("Dei-lhe uma dura!");
  else printf ("Corrigir o quê? Não vejo %s\n", o1->nome);
}

void CorrigirProva(Elemento *o1, Elemento *o2) {
  if (!getsym (inventario, "prova"))
	puts ("Não estou com a prova...");
  else if (!getsym (inventario, "caneta"))
	puts ("preciso da ferramenta correta para  a correção!");
  else {
	puts ("Pronto! Missão cumprida!\n"
		 "A prova está corrigida, mas é melhor você não saber o resultado...\n"
		 "*** FIM ***");
	exit(0);
  }
}

/* comportamento especial que depende do lugar */
void GritaQuarto (Elemento *o1, Elemento *o2) {
  puts ("Psiuuuu!!!\nIsto é um quarto!!!!");
}


/* Para inicializar as funções, copiei da calculadora */
struct initfunc {
  char *fname;
  Fptr fnct;
};

/* Lista de verbos */
struct initfunc lfunc[] = {
  {"pegue", Pegar},
  {"cate", Pegar},
  {"largue", Largar },
  {"solte", Largar },
  {"jogue", Largar },
  {"examine", Examinar },
  {"olhe", Olhar },
  {"veja", Olhar },
  { "grite", Gritar },
  {  "berre",    Gritar },
  {  "corrija", Corrigir },
  {"dicionario", Dicionario},
  {"coma",comer},
  {0, 0}
};

/* Para objetos */
struct initobj {
  char *name;
  Elemento *obj;
};

/* Lista de objetos */
struct initobj lobjs[] = {
  {"fogo",  &fogo},
  {"gelo",  &gelo},
  {"leprechaum", &lepre},
  {"Kirkpatrick", &lepre},
  {"lapis", &lapis},
  {"caneta", &caneta},
  {"hamster", &hamster},
  {"prova", &prova},
  {"vapor", &vapor},
  {    "tv"   ,      &tv     },
  {   "mesa"  ,     &mesa    },
  { "controle",   &controle  },
  {  "Alexa"  ,    &Alexa    },
  {  "abajur" ,    &abajur   },
  {   "cama"  ,     &cama    },
  {   "espada" ,   &espada   },
  {  "estufa"  ,   &estufa   },
  {   "pudim"  ,   &pudim    },
  {    "faca"  ,    &faca    },
  {   "livro"  ,    &livro   },
  {   "estante",   &estante  },
  {   "estatua",   &estatua  },
  {"tarjapreta",  &tarjapreta},
  { 0, 0}
};

/* Para lugares */
struct initlug {
  char *name;
  Elemento *lug;
};

/* Lista de lugares */
struct initlug llugs[] = {
  {  "quarto"  ,   &quarto  },
  {   "hall"   ,    &hall   },
  { "banheiro" ,  &banheiro },
  { "cozinha"  ,  &cozinha  },
  {"biblioteca", &biblioteca},
  { 0, 0}
};

// Para adjetivos
struct initAdj {
  char *name;
  Elemento *adj;
};

struct initAdj lAdj[] = {
  {"quente", &quente},
  //{"frio",   &gelo},
  {0, 0}
};

//Preenche os verbos nas acoes dos objetos, atencao, tem q ficar no final
//pq tem q declarar os verbos antes
void SetVerbo () {
  gelo.cont    = putsym (gelo.cont,    "pegue",   VERBO, PegarGelo);
  fogo.cont    = putsym (fogo.cont,    "pegue",   VERBO, PegarFogo);
  lepre.cont   = putsym (lepre.cont,   "jogue",   VERBO, JogarLeprechaum);
  hamster.cont = putsym (hamster.cont, "jogue",   VERBO, JogarHamster);
  quarto.cont  = putsym (quarto.cont,  "grite",   VERBO, GritaQuarto);
  vapor.cont   = putsym (vapor.cont,   "pegue",   VERBO, PegarVapor);
  prova.cont   = putsym (prova.cont,   "corrija", VERBO, CorrigirProva);
  cama.cont    = putsym (cama.cont,   "pegue", VERBO, Pegar);

  espada.cont  = putsym (espada.cont  ,       "pegue",   VERBO, Pegar);
  estufa.cont  = putsym (estufa.cont  ,       "pegue",   VERBO, Pegar);
  faca.cont    = putsym (faca.cont    ,       "pegue",   VERBO, Pegar);
  livro.cont   = putsym (livro.cont   ,       "pegue",   VERBO, Pegar);
  estante.cont = putsym (estante.cont ,       "olhe",    VERBO, Olhar );
  pudim.cont   = putsym (pudim.cont   ,       "pegue",   VERBO, Pegar);
  pudim.cont   = putsym (pudim.cont   ,       "coma",    VERBO, comer);
  estatua.cont = putsym (estatua.cont ,       "olhe",    VERBO, Olhar );
  tarjapreta.cont = putsym (tarjapreta.cont,  "pegue",   VERBO, Pegar);
  //Alexa.cont = putsym (Alexa.cont ,    "",    VERBO, );
}

/* Inicializa a tabela de símbolos passada como argumento */
symrec*  init_table (symrec *sym_table) {
  int i;
  symrec *ptr = sym_table;		/* cabeça da lista */

  /* Lista de verbos */
  for (i = 0; lfunc[i].fname != 0; i++) {
	  /* insere */
    ptr = putsym (ptr, lfunc[i].fname, VERBO, lfunc[i].fnct);
	  /* completa os dados */
    ptr->value = lfunc[i].fnct;
  }

  /* Lista de objetos */
  for (i = 0; lobjs[i].name != 0; i++) {
	  Elemento *oo = lobjs[i].obj;
	  /* insere */
    ptr = putsym (ptr, lobjs[i].name, OBJ, oo);
	  oo->cont = NULL;
  }

  /* Lista de lugares */
  for (i = 0; llugs[i].name != 0; i++)
    ptr = putsym (ptr, llugs[i].name, LUGAR, llugs[i].lug);

    /* Lista de adjetivos */
  for (i = 0; lAdj[i].name != 0; i++)
      ptr = putsym (ptr, lAdj[i].name, ADJETIVO, lAdj[i].adj);

  SetLugar ();

  SetObj ();

  SetVerbo ();

  /* Ajustes finais */ // Subtstituir pelo SetVerbo ()
  Posic = &quarto;
  /* retorna a nova cabeça da lista */
  return ptr;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elementoAntigo.c"
#include "lista.c"
#include "tabsim.c"
#include "elemento.c"
#include "func.c"


//QUARTO
Elemento quarto = {"Quarto", "Seu habitáculo. Na parede sul há uma CAMA king-size e uma MESA DE CABECEIRA com um ABAJUR e a assistente ALEXA. Na parede norte há uma TELEVISÃO e a saída para o hall. A parede oeste tem a porta do banheiro.",
                  "Você acorda em sua suíte presidencial, mas algo está errado, muito errado. Existe qualquer coisa de anti-natural e desumano em despertar por iniciativa própria, e não pelo quarteto de cordas executando uma peça de Mozart precisamente às 08:00. E onde estão o chef para apresentar o menu matinal, e Jarbas com os jornais do dia? Na parede oposta há uma TELEVISÃO, desligada. Ao seu lado está a MESA DE CABECEIRA, com um ABAJUR em forma de cifrão e ALEXA, essa companheira de todas as horas. Há uma porta a oeste que leva ao banheiro e uma porta ao norte que conduz ao hall.",
                  False, False, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, lugar, .d.lug.norte = NULL};

//OBJETOS QUARTO
Elemento tv = {"TV", "Imagem 4K em 60 polegadas de uma tela preta", "Essa tela deveria estar exibindo o Manhattan Connection. Por algum estranho motivo, isso não está acontecendo.",
               False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};


Elemento mesa = {"Mesa", "Uma mesa com gaveta feita sob medida", "Mesa de design sueco, corpo em jacarandá com acabamento em mogno. Gaveta feita sob medida com fundo falso para guardar documentos importantes. Sem o fundo falso cabe uma garrafa de uísque de pé, o que também é conveniente",
               False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

Elemento controle = {"Controle",  "Um instrumento que os plebeus utilizam para alterar o estado das coisas",
                    "Qual o propósito de todos esses botões? A perspectiva de manipular diretamente um aparelho é intimidadora. Por sorte, o curso de leitura dinâmica seguindo a técnica da NASA finalmente faz por merecer, e você identifica rapidamente a tecla LIGA/DESLIGA",
                     False, False, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

Elemento alexa = {"Alexa", "A senhora das respostas, enfim derrotada. Impossível pesquisar a localização da chave.",
                 "A incansável Alexa, noite após noite acatando o pedido para tocar Despacito. Sua voz robótica é a radiação de fundo do próprio Universo.",
                  False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

Elemento abajur = {"Abajur", "Não é atribuição sua desligar o abajur, mas essa lâmpada acesa está desperdiçando dinheiro",
                  "Sua fonte de luz noturna é um delicado envoltório de seda chinesa em formato de cifrão - um singelo memento para que, ao tomar os comprimidos para dormir, você se recorde de que há coisas pelas quais vale a pena acordar novamente. Curiosamente, ele ainda está ligado, da mesma forma que você deixou na noite anterior",
                  True, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};


Elemento cama = {"Cama", "Não adianta voltar pra cama, vá explorar o resto da casa!","A visão da cama desarrumada é desconcertante, mas não há o que se fazer a respeito.",
                 False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

//BANHEIRO
Elemento banheiro = {"Banheiro", "Esquece o resto, tem um remedinho ali, vamos ver isso",
                    "Um modesto espaço de 150 metros quadrados devidamente equipado com duchas, banheiras em diferentes temperaturas, sauna romana e parque aquático. A leste está a porta para o quarto. Logo ao lado há uma pia com um TARJA PRETA.",
                     False, False, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, lugar, .d.lug.norte = NULL};

//OBJETOS BANHEIRO
Elemento tarjapreta = {"TarjaPreta", "Medicação obtida estritamente dentro dos limites da lei",
                     "A claridade do Sol alojada em pequenos comprimidos para ser consumida religiosamente no início de cada dia",
                      False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

//HALL
Elemento hall = {"Hall", "A porta de saída da casa está ao norte. A sala tem uma armadura segurando uma ESPADA BASTARDA e também uma MINI-ESTUFA. À leste está a biblioteca, e à oeste a cozinha.",
                 "O saguão central dessa modesta residência. As paredes estão decoradas com um brasão que definitivamente não é da sua família, seu avô era sapateiro em Várzea Grande, mas isso não importa agora. Em uma das paredes há uma armadura medieval repousando as mãos sobre uma ESPADA BASTARDA. Sob o relógio-cuco suíço há uma MINI-ESTUFA com uma flor. Ao norte está a pesada porta que dá para o jardim externo. À leste está a biblioteca, e à oeste a cozinha. Ao sul está o corredor que volta para o quarto.",
                 False, False, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, lugar, .d.lug.norte = NULL};

//OBJETOS HALL
Elemento espada = {"Espada", "Parece pesada. A lâmina ainda conserva o fio",
                  "Em excepcional estado de conservação, este artefato teria sido empunhado na época da sexta crusada por um vassalo de Frederico II.",
                   False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

Elemento estufa = {"Estufa", "Estimado Barão. Que Deus o tenha! Talvez o último espírito romântico de nossa era.",
                  "Dentro da estufa está a orquídea rara trazida pelo Barão von Trapp em uma de suas breves estadias na mansão, logo antes de partir para Macapá para juntar-se à expedição russa naquela que viria a ser sua derradeira aventura.",
                  False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};


//BIBLIOTECA
Elemento biblioteca = {"Biblioteca", "No centro da sala há uma escrivaninha com um LIVRO aberto. Ao lado há uma ESTÁTUA. As paredes são cobertas de ESTANTES. A leste está a porta do Hall.",
"As paredes são preenchidas, do chão ao teto, com ESTANTES cheias de livros. Entre eles existem algumas primeiras edições de autores famosos, e algumas destas estão assinadas pelos próprios autores. Não que você saiba dizer quais, evidentemente - nunca leu um livro na vida. Mas a existência de uma biblioteca bem estocada é exigência de primeira ordem na construção de uma mansão de calibre, e existem serviços especializados em reunir exemplares com aparência de grande antiguidade e valor. Você examina, com certa curiosidade, essa terra incognita. Há uma escrivaninha com um LIVRO aberto, e uma ESTÁTUA grega em um canto. A leste está a porta de volta para o Hall.",
False, False, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, lugar, .d.lug.norte = NULL};

//OBJETOS BIBLIOTECA
Elemento estante = {"Estantes", "Mais livros do que um acadêmico sério lerá na vida",
"Centenas de livros! Ou milhares! Qual a diferença? Impossível saber onde está qualquer coisa aí no meio",
False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

Elemento estatua = {"Estátua", "Hermes-Afrodite",
"Alguma deusa, ou rainha de algum lugar. Na verdade, olhando bem, pode ser que seja um homem.",
False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

Elemento livro = {"Livro", "O catálogo da biblioteca",
"Convenientemente, esse livro aberto parece ser um catálogo de todas as obras na biblioteca, indicando estante e prateleira de cada obra",
False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

//COZINHA
Elemento cozinha  = {"Cozinha",
"No balcão da cozinha estão um PUDIM DE CACTO e uma PEIXEIRA. A leste está a porta do hall.",
"O coração inescrutável da residência. Então é este seu aspecto! Fascinante! Infelizmente, encontra-se tão deserta quanto o resto da casa. Os muitos armários e ganchos nas paredes perfilam os artefatos incompreensíveis necessários para conjurar as cornucópias da gastronomia internacional que abastecem diariamente a mansão. A organização do ambiente é impecável, com uma exceção: o PUDIM DE CACTO que arrematou a ceia da noite anterior ainda se encontra sobre o balcão. Ali também há uma PEIXEIRA. A leste fica a porta de volta para o hall.",
False, False, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

//OBJETOS COZINHA
Elemento pudim = {"Pudim", "Asqueroso! Mas extremamente rico em ômega 3",
"As virtudes fitoterápicas do pudim de cacto foram muitíssimo celebradas pelo Comendador Braga em certo jantar beneficente, e desde então passaram a integrar o cardápio regular da mansão. Este pudim foi servido na noite anterior, mas está praticamente intacto",
False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};

Elemento faca = {"Faca", "Uma faca dessas corta qualquer coisa com facilidade. Qualquer coisa",
"Uma faca de grande porte, pontiaguda e afiada. É a isso que chegamos, então? É este o fim?", False, True, False, .conteudo.tam = 0, .acoes.tam = 0, .animacao.tam = 0, objeto, .d.obj.atributo.tam = 0};


//Simplesmente para mortais que tem preguica de inicializar tabela de simbolos na mao
void InicializaTS (Elemento *ele, int n) {
  ele->conteudo = criaTS (n);
  ele->acoes    = criaTS (n);
  ele->animacao = criaTS (n);
}


int main () {
  func an = analisar;
  func lo = locomover;
  func pe = pegar;
  func ab = abrir;
  func fe = fechar;
  func queb = quebrar;

  TabSim lugares = criaTS (5);

  //Inicialização dos objetos do quarto
  InicializaTS (&tv, 5);
  insereTS (tv.acoes, "ANALISAR", an);

  InicializaTS (&mesa, 5);
  insereTS (mesa.acoes, "ANALISAR", an);
  insereTS (mesa.acoes, "ABRIR", ab);

  InicializaTS (&controle, 5);
  insereTS (controle.acoes, "ANALISAR", an);
  insereTS (controle.acoes, "PEGAR", ab);

  InicializaTS (&alexa, 5);
  insereTS (alexa.acoes, "ANALISAR", an);

  InicializaTS (&abajur, 5);
  insereTS (abajur.acoes, "ANALISAR", an);
  insereTS (abajur.acoes, "ABRIR", ab);

  InicializaTS (&cama, 5);
  insereTS (cama.acoes, "ANALISAR", an);

  //configura quarto
  InicializaTS (&quarto, 5);
  insereTS (quarto.conteudo, "TV",   &tv);
  insereTS (quarto.conteudo, "MESA", &mesa);
  insereTS (quarto.conteudo, "CONTROLE", &controle);
  insereTS (quarto.conteudo, "ALEXA", &alexa);
  insereTS (quarto.conteudo, "ABAJUR", &abajur);
  insereTS (quarto.conteudo, "CAMA", &cama);
  insereTS(lugares, "Quarto", &quarto);

  //Inicialização dos objetos do banheiro
  InicializaTS (&tarjapreta, 5);
  insereTS (tarjapreta.acoes, "ANALISAR", an);
  insereTS (tarjapreta.acoes, "PEGAR", pe);

  //configura banheiro
  InicializaTS (&banheiro, 5);
  insereTS (banheiro.conteudo, "TARJAPRETA", &tarjapreta);
  insereTS(lugares, "Banheiro", &banheiro);

  //Inicialização dos objetos do hall
  InicializaTS (&espada, 5);
  insereTS (espada.acoes, "ANALISAR", an);
  insereTS (espada.acoes, "PEGAR", pe);

  InicializaTS (&estufa, 5);
  insereTS (estufa.acoes, "ANALISAR", an);
  insereTS (estufa.acoes, "ABRIR", ab);

  //configura hall
  InicializaTS (&hall, 5);
  insereTS (hall.conteudo, "ESPADA",   &espada);
  insereTS (hall.conteudo, "ESTUFA", &estufa);
  insereTS(lugares, "Hall", &hall);

  //Inicialização dos objetos da biblioteca
  InicializaTS (&estante, 5);
  insereTS (estante.acoes, "ANALISAR", an);

  InicializaTS (&estatua, 5);
  insereTS (estatua.acoes, "ANALISAR", an);

  InicializaTS (&livro, 5);
  insereTS (livro.acoes, "ANALISAR", an);

  //configura biblioteca
  InicializaTS (&biblioteca, 5);
  insereTS (biblioteca.conteudo, "ESTANTE",   &estante);
  insereTS (biblioteca.conteudo, "ESTATUA", &estatua);
  insereTS (biblioteca.conteudo, "LIVRO", &livro);
  insereTS(lugares, "Biblioteca", &biblioteca);

  printf ("%s\n", name (buscaTS (quarto.conteudo, "MESA")));
  printf ("Busca: %s\n", name (buscaTS (lugares, "Quarto")));
  return 0;
}

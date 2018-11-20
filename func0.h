#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int n;
}teste;

// func retorna um tipo int e recebe um ponteiro do tipo teste.
typedef int (*func) (teste *e1);

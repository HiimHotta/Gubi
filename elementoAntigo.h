#include <stdio.h>
#include <stdlib.h>
#define MAXSTRING 80

typedef struct {
char n [80];
} ElementoAntigo;

typedef enum {
  False, True,
} Boolean;

char* nameAntigo (ElementoAntigo *elemento);

int compareElementoAntigo (ElementoAntigo *elemento1, ElementoAntigo *elemento2);

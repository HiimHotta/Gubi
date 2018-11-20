#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elementoAntigo.h"

char* nameAntigo (ElementoAntigo *elemento) {
  return elemento->n;
}

int compareElementoAntigo (ElementoAntigo *elemento1, ElementoAntigo *elemento2) {
  if (strcmp (elemento1->n, elemento2->n) == 0)
    return 1;
  return 0;
}

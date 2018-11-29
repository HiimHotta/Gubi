
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int a;
  int b; } Caca;

typedef struct{
  Caca v[10];
  int i; } TIPO;

void swap(int *el1, int *el2, TIPO *gp) {
    int temp;
    temp = *el1;
    *el1 = *el2;
    *el2 = temp;
    int i =0;
    while(i<=10){
      gp[i].v[i].a = i+10;
      gp[i].v[i].b = i+20;
      i++;
    }
}
//A chamada à função deve passar os endereços das variáveis, como em
int main() {
    int a = 10, b = 20;
    TIPO * gp = malloc( a * sizeof (TIPO));
    swap( &a, &b ,gp);

    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b,gp);
    for ( int i = 0; i <= 10; i++){
      printf("gp[%d].v[%d]a: %d\n", i, i, gp[i].v[i].a );
      printf("gp[%d].v[%d]b: %d\n", i, i, gp[i].v[i].b );
    }
    free(gp);
}

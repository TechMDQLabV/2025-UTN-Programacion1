#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define DIM 100

int main()
{
    int *a = NULL;

    creaArreglo(&a, DIM);

    printf("Hello world!\n");
    return 0;
}

void creaArreglo(int **a, int dim){
    *a = (int *) malloc(sizeof(int)*dim);
}

void muestraArregloDinamico(int *a, int v){
    for(int i=0;i<v;i++){
        printf("\n %d", a[i]);
    }
}

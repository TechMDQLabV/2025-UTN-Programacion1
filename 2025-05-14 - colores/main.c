#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.h"

int main()
{
    printf("\n <<<<< Colores >>>>> \n");
    for(int i=0;i<256; i++){
        color(i);
        printf("\n Color: %d", i);
    }
    system("pause");

    return 0;
}

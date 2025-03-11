#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\t\t<<< Tabla de Caracteres ASCII >>>\n");
    for(int i=0;i<256;i++){
        printf("nro: %d - %c | ", i,i);
        if(i%5==0){
            printf("\n");
        }
    }
    system("pause");
    return 0;
}

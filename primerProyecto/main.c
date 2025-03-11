#include <stdio.h>
#include <stdlib.h>

int main()
{
    char opcion;

    do{
        printf("\n\t\t\t Menu de Opciones\n");
        printf("\n1 - Tabla ASCII");
        printf("\n2 - Mostrar dir");
        printf("\n3 - Ejercicio 2");
        printf("\n4 - Ejercicio 3");
        printf("\nESC para salir ...");

        opcion = getch();

        switch(opcion){
            case 27:
                printf("\n Bye Bye");
                break;
            case 49:
                printf("\t\t<<< Tabla de Caracteres ASCII >>>\n");
                for(int i=0;i<256;i++){
                    printf("nro: %d - %c | ", i,i);
                    if(i%5==0){
                        printf("\n");
                    }
                }
                break;
            case 50:
                printf("\t\t\t Archivos de la carpeta actual");
                system("dir");
        }
        system("pause");
        system("cls");
    }while(opcion!=27);





    system("pause");
    return 0;
}

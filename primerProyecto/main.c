#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char opcion;

    do{
        opcionesMenu();

        opcion = getch();

        switch(opcion){
            case 27:
                printf("\n Bye Bye");
                break;
            case 49:
                codigoAscii();
                break;
            case 50:
                printf("\t\t\t Archivos de la carpeta actual");
                system("dir");
        }
        Sleep(1500);
        system("cls");
    }while(opcion!=27);

    return 0;
}

void opcionesMenu(){
    printf("\n\t\t\t Menu de Opciones\n");
    printf("\n1 - Tabla ASCII");
    printf("\n2 - Mostrar dir");
    printf("\n3 - Ejercicio 2");
    printf("\n4 - Ejercicio 3");
    printf("\nESC para salir ...");
}

int suma(int uno, int dos){
    return uno + dos;
}

void codigoAscii(){
    printf("\t\t<<< Tabla de Caracteres ASCII >>>\n");
    for(int i=0;i<256;i++){
        printf("nro: %d - %c | ", i,i);
        if(i%5==0){
            printf("\n");
        }
    }
}

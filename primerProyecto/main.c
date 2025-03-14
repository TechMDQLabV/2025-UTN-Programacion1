#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

void opcionesMenu();


int main()
{
    Pila dada;
    Pila volcom;
    inicpila(&dada);
    inicpila(&volcom);

    cargaPilaRandom(&dada);
    muestraPila(&dada);
    copiaPila(dada, &volcom);
    mostrar(&dada);
    mostrar(&volcom);
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

void copiaPila(Pila origen, Pila *destino){
    while(!pilavacia(&origen)){
        apilar(destino,desapilar(&origen));
    }
    printf("\nPila origen dentro de la funcion despues del while");
    mostrar(&origen);
}

void cargaPilaRandom(Pila *pila){
    for(int i=0;i < 20;i++){
        apilar(pila, rand()%100);
    }
}

void muestraPila(Pila origen){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&origen)){
        printf("%d\n", tope(&origen));
        apilar(&aux, desapilar(&origen));
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

void opcionesMenu();
int suma(int uno, int dos);
void codigoAscii();
void copiaPila(Pila origen, Pila *destino);
void cargaPilaRandom(Pila *pila);
void muestraPila(Pila origen);
void cargaPila(Pila *p, char log[]);

int main()
{
    srand(time(NULL));
    Pila dada;
    Pila volcom;
    inicpila(&dada);
    inicpila(&volcom);

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
                break;
            case 51:
                printf("\n<< Cargando pila de forma aleatoria >>");
                cargaPilaRandom(&dada);
                break;
            case 52:
                printf("\n<< Cargando pila  >>");
                cargaPila(&dada, "Ingrese una edad: ");
                break;
            case 53:
                printf("\n<<< Listado de edades >>>");
                muestraPila(dada);
                break;
            case 54:
                printf("\n<<< Pasa pila de origen a destino >>>");
                //pasaPila(&dada, &volcom);
                pasaPilaEnOrden(&dada, &volcom);
                printf("\n<<< Pila dada >>>");
                muestraPila(dada);
                printf("\n<<< Pila volcom >>>");
                muestraPila(volcom);
                break;
            case 55:
                if(!pilavacia(&dada)){
                    printf("\n El menor es: %d", buscaMenor(&dada));
                }else{
                    printf("\n La pila esta vacia");
                }
        }
        //Sleep(1500);
        system("pause");
        system("cls");
    }while(opcion!=27);

    return 0;
}

void opcionesMenu(){
    printf("\n\t\t\t Menu de Opciones\n");
    printf("\n1 - Tabla ASCII");
    printf("\n2 - Mostrar dir");
    printf("\n3 - Carga pila random");
    printf("\n4 - Carga pila");
    printf("\n5 - Muestra pila");
    printf("\n6 - Pasa pila");
    printf("\n7 - Busca menor");
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
}

void cargaPilaRandom(Pila *pila){
    for(int i=0;i < 20;i++){
        apilar(pila, rand()%100);
    }
}

void muestraPila(Pila origen){
    Pila aux;
    inicpila(&aux);
    int cont = 0;
    while(!pilavacia(&origen)){
        if(cont % 7 == 0){
            printf("\n");
        }
        printf("%4d | ", tope(&origen));
        apilar(&aux, desapilar(&origen));
        cont++;
    }
    printf("\n");
}

void cargaPila(Pila *p, char log[]){
    int nro;
    char cont;

    do{
        printf("\n %s", log);
        scanf("%d", &nro);
        apilar(p, nro);
        printf("\n\nESC para salir o cualquier tecla para continuar ....");
        cont=getch();
        system("cls");
    }while(cont != ESC); /// cont != 27
}

void pasaPila(Pila *origen, Pila *destino){
    while(!pilavacia(origen)){
        apilar(destino, desapilar(origen));
    }
}

void pasaPilaEnOrden(Pila *origen, Pila *destino){
    Pila aux;
    inicpila(&aux);
    pasaPila(origen,&aux);
    pasaPila(&aux, destino);
}

int buscaMenor(Pila *p){
    int menor;
    Pila aux;
    inicpila(&aux);
    if(!pilavacia(p)){
        menor = desapilar(p);
        while(!pilavacia(p)){
            if(tope(p) < menor){
                apilar(&aux, menor);
                menor = desapilar(p);
            }else{
                apilar(&aux, desapilar(p));
            }
        }
        pasaPila(&aux, p);
    }

    return menor;
}

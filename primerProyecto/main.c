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
void pasaPila(Pila *origen, Pila *destino);
void pasaPilaEnOrden(Pila *origen, Pila *destino);
int buscaMenor(Pila *p);
void ordenaPilaPorSeleccion(Pila *origen, Pila *ordenada);
void ordenaPilaPorSeleccion1(Pila *origen);
int buscaElementoEnPila(Pila origen, int aBuscar);
int buscaElementoEnPila1(Pila origen, int aBuscar);
void insertaEnOrden(Pila *ordenada, int dato){;
void ordenaPilaPorInsercion(Pila *des);

int main() {
    srand(time(NULL));
    Pila dada;
    Pila volcom;
    inicpila(&dada);
    inicpila(&volcom);
    int encontrado;

    //printf("\n La cantidad de digitos es: %d", cuentaDigitos(1110));

    char opcion;

    do {
        opcionesMenu();
        opcion = getch();

        switch(opcion) {
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
            if(!pilavacia(&dada)) {
                printf("\n El menor es: %d", buscaMenor(&dada));
            } else {
                printf("\n La pila esta vacia");
            }
            break;
        case 56:
            printf("\n<<< Ordena pila por seleccion >>>");
            //ordenaPilaPorSeleccion(&dada, &volcom);
            ordenaPilaPorSeleccion1(&dada);
            printf("\n<<< Pila dada >>>");
            muestraPila(dada);
            printf("\n<<< Pila volcom >>>");
            muestraPila(volcom);
            break;
        case 57: // case '9';
            printf("\n<<< Busca un elemento en una pila >>>");
            apilar(&dada, 10);
            encontrado = buscaElementoEnPila(dada, 10);
            muestraPila(dada);
            if(encontrado) { /// es igual a if(encontrado == 1)
                printf("El nro 10 se encuentra en la Pila");
            } else {
                printf("El nro 10 NO se encuentra en la pila");
            }
            break;
        case 97: // case 'a'
            printf("\n<<< Inserta en una pila ordenada >>>");
            printf("\n<<< Pila dada antes de insertar >>>");
            muestraPila(dada);
            insertaEnOrden(&dada, 6);
            printf("\n<<< Pila dada con el dato insertado >>>");
            muestraPila(dada);
            break;
        case 98:
            printf("\n<<< Ordena una pila por insercion >>>");
            printf("\n<<< Pila dada antes de ordenar >>>");
            muestraPila(dada);
            ordenaPilaPorInsercion(&dada);
            printf("\n<<< Pila dada ordenada >>>");
            muestraPila(dada);
        }
        //Sleep(1500);
        printf("\n");
        system("pause");
        system("cls");
    } while(opcion!=27);

    return 0;
}

void opcionesMenu() {
    printf("\n\t\t\t Menu de Opciones\n");
    printf("\n1 - Tabla ASCII");
    printf("\n2 - Mostrar dir");
    printf("\n3 - Carga pila random");
    printf("\n4 - Carga pila");
    printf("\n5 - Muestra pila");
    printf("\n6 - Pasa pila");
    printf("\n7 - Busca menor");
    printf("\n8 - Ordena pila por seleccion");
    printf("\n9 - Busca un elemento en una pila");
    printf("\na - Inserta en orden");
    printf("\nb - Ordena por insercion");
    printf("\nESC para salir ...");
}

int suma(int uno, int dos) {
    return uno + dos;
}

void codigoAscii() {
    printf("\t\t<<< Tabla de Caracteres ASCII >>>\n");
    for(int i=0; i<256; i++) {
        printf("nro: %d - %c | ", i,i);
        if(i%5==0) {
            printf("\n");
        }
    }
}

void copiaPila(Pila origen, Pila *destino) {
    while(!pilavacia(&origen)) {
        apilar(destino,desapilar(&origen));
    }
}

void cargaPilaRandom(Pila *pila) {
    for(int i=0; i < 20; i++) {
        apilar(pila, rand()%100);
    }
}

void muestraPila(Pila origen) {
    Pila aux;
    inicpila(&aux);
    int cont = 0;
    while(!pilavacia(&origen)) {
        if(cont % 7 == 0) {
            printf("\n");
        }
        printf("%4d | ", tope(&origen));
        apilar(&aux, desapilar(&origen));
        cont++;
    }
    printf("\n");
}

void cargaPila(Pila *p, char log[]) {
    int nro;
    char cont;

    do {
        printf("\n %s", log);
        scanf("%d", &nro);
        apilar(p, nro);
        printf("\n\nESC para salir o cualquier tecla para continuar ....");
        cont=getch();
        system("cls");
    } while(cont != ESC); /// cont != 27
}

void pasaPila(Pila *origen, Pila *destino) {
    while(!pilavacia(origen)) {
        apilar(destino, desapilar(origen));
    }
}

void pasaPilaEnOrden(Pila *origen, Pila *destino) {
    Pila aux;
    inicpila(&aux);
    pasaPila(origen,&aux);
    pasaPila(&aux, destino);
}

int buscaMenor(Pila *p) {
    int menor;
    Pila aux;
    inicpila(&aux);
    if(!pilavacia(p)) {
        menor = desapilar(p);
        while(!pilavacia(p)) {
            if(tope(p) < menor) {
                apilar(&aux, menor);
                menor = desapilar(p);
            } else {
                apilar(&aux, desapilar(p));
            }
        }
        pasaPila(&aux, p);
    }

    return menor;
}

void ordenaPilaPorSeleccion(Pila *origen, Pila *ordenada) {
    while(!pilavacia(origen)) {
        apilar(ordenada, buscaMenor(origen));
    }
}

void ordenaPilaPorSeleccion1(Pila *origen) {
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(origen)) {
        apilar(&aux, buscaMenor(origen));
    }
    pasaPila(&aux, origen);
}

int buscaElementoEnPila(Pila origen, int aBuscar) {
    Pila aux;
    inicpila(&aux);
    int encontrado = 0;
    while(!pilavacia(&origen) && encontrado == 0) {
        if(tope(&origen) == aBuscar) {
            encontrado = 1;
        }
        apilar(&aux, desapilar(&origen));
    }
    return encontrado;
}

int buscaElementoEnPila1(Pila origen, int aBuscar) {
    Pila aux;
    inicpila(&aux);
    int encontrado;
    while(!pilavacia(&origen) && tope(&origen) != aBuscar) {
        apilar(&aux, desapilar(&origen));
    }
    if(pilavacia(&origen)) {
        encontrado = 0;
    } else {
        encontrado = 1;
    }
    return encontrado;
}

void insertaEnOrden(Pila *ordenada, int dato){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(ordenada) && tope(ordenada) < dato){
        apilar(&aux, desapilar(ordenada));
    }

    apilar(ordenada, dato);
    pasaPila(&aux, ordenada);
}

void ordenaPilaPorInsercion(Pila *des){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(des)){
        insertaEnOrden(&aux, desapilar(des));
    }
    pasaPila(&aux, des);
}

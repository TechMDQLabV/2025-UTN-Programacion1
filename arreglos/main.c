#include <stdio.h>
#include <stdlib.h>

void menu();
int cargaArregloRandom(int a[], int dim);
int cargaArreglo(int a[], int v, int dim);
void muestraArreglo(int a[], int v);
void intercambio(int* a, int* b);
int buscaPosMenor(int a[], int v, int inicio);
void ordenacionPorSeleccionInt(int a[], int v);
int insertaEnArregloOrdenadoInt(int a[], int v, int dim, int dato);
void insertaEnArregloOrdenadoInt2(int a[], int v, int dato);
void ordenaPorInsercion(int a[], int v);

#define ESC 27
#define DIM 100

int main()
{
    char opcion;
    int notas[DIM];
    int vNotas = 0;
    int posMenor;

    do{
        menu();
        opcion = getch();

        switch(opcion){
            case '1':
                printf("\n <<< Carga arreglo random >>>");
                vNotas = cargaArregloRandom(notas, DIM);
                break;
            case 50:
                printf("\n <<< Carga arreglo >>>");
                vNotas = cargaArreglo(notas, vNotas, DIM);
                break;
            case 51:
                printf("\n <<< Muestra arreglo >>>");
                muestraArreglo(notas, vNotas);
                break;
            case 52:
                printf("\n <<< Limpia arreglo >>>");
                vNotas = 0;
                break;
            case 53:
                printf("\n <<< Busca Menor >>>");
                posMenor = buscaPosMenor(notas, vNotas, 0);
                printf("\n El menor es: %d", notas[posMenor]);
                break;
            case 54:
                printf("\n <<< Ordenacion por seleccion >>>");
                ordenacionPorSeleccionInt(notas, vNotas);
                break;
            case 55:
                printf("\n <<< Inserta en arreglo ordenado >>>");
                vNotas=insertaEnArregloOrdenadoInt(notas, vNotas, DIM, 0);
                break;
            case 56:
                printf("\n <<< Ordenacion por insercion >>>");
                ordenaPorInsercion(notas, vNotas);
                break;
        }
        getch();
        system("cls");
    }while(opcion != ESC);
    return 0;
}

void menu(){
    printf("\n\t\t\t <<< TP Arreglos >>>");
    printf("\n\n 1.- Carga arreglo random");
    printf("\n\n 2.- Carga arreglo");
    printf("\n\n 3.- Muestra arreglo");
    printf("\n\n 4.- Limpia arreglo");
    printf("\n\n 5.- Busca menor");
    printf("\n\n 6.- Ordenacion por Seleccion");
    printf("\n\n 7.- Inserta en arreglo ordenado");
    printf("\n\n 8.- Ordenacion por Insercion");
    printf("\n\n\tESC para salir");
}

int cargaArregloRandom(int a[], int dim){
    int i;
    for(i=0;i<dim-1;i++){
        a[i]=rand()%10+1;
    }
    return i;
}

int cargaArreglo(int a[], int v, int dim){
    char opcion = 0;

    while(v<dim && opcion != ESC){
        printf("\n Ingrese una nota: ");
        scanf("%d",&a[v]);
        v++;
        printf("\n ESC para salir o cualquier tecla para continuar ... ");
        opcion = getch();
        system("cls");
    }
    return v;
}

void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%13==0){
            printf("\n");
        }
        printf("%3d", a[i]);
    }
}

void intercambio(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int buscaPosMenor(int a[], int v, int inicio){
    int posMenor = -1;
    if(v > 0){
        posMenor = inicio;
    }

    for(int i = inicio; i<v; i++){
        if(a[i]<a[posMenor]){
            posMenor=i;
        }
    }

    return posMenor;
}

void ordenacionPorSeleccionInt(int a[], int v){
    int posMenor;
    for(int i=0;i<v-1;i++){
        posMenor = buscaPosMenor(a, v, i);
        intercambio(&a[i],&a[posMenor]);
    }
}

int insertaEnArregloOrdenadoInt(int a[], int v, int dim, int dato){
    int validos = -1;
    int i = v - 1;
    if(v < dim){
        while(i>=0 && dato < a[i]){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = dato;
        validos = v + 1;
    }

    return validos;
}


void insertaEnArregloOrdenadoInt2(int a[], int v, int dato){
    int i = v - 1;
    while(i>=0 && dato < a[i]){
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = dato;
}

void ordenaPorInsercion(int a[], int v){
    for(int i=0;i<v-1;i++){
        insertaEnArregloOrdenadoInt2(a, i, a[i+1]);
    }
}

int randomRango(int min, int max){
    rerturn rand()%(max-min)+min;
}

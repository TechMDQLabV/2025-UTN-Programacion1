#include <stdio.h>
#include <stdlib.h>

void menu();
int cargaArregloRandom(int a[], int dim);
int cargaArreglo(int a[], int v, int dim);
void muestraArreglo(int a[], int v);

#define ESC 27
#define DIM 100

int main()
{
    char opcion;
    int notas[DIM];
    int vNotas = 0;

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
    printf("\n\n\tESC para salir");
}

int cargaArregloRandom(int a[], int dim){
    int i;
    for(i=0;i<dim;i++){
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

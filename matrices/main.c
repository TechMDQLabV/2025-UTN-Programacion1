#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ESC 27
#define DIM 100

int main()
{
    srand(time(NULL));
    char opcion;
    int fil = 3;
    int col = 3;
    int matrix[fil][col];

    char nombres[DIM][30];
    int vNombres = 0;
    do{
        menuDeOpciones();
        opcion = getch();

        switch(opcion){
            case 49:
                printf("\n <<<< Carga matriz random >>>> ");
                cargaMatrizRandom(fil, col, matrix);
                break;
            case 50:
                printf("\n <<<< Muestra matriz >>>> \n");
                muestraMatriz(fil, col, matrix);
                break;
            case 51:
                printf("\n <<<< Carga Nombres >>>> ");
                vNombres = cargaNombres(DIM, nombres);
                strcpy(nombres[vNombres],"Juanito");
                vNombres++;
                break;
            case 52:
                printf("\n <<<< Muestra Nombres >>>> \n");
                muestraNombres(DIM, nombres, vNombres);
                break;
        }
        getch();
        system("cls");
    }while(opcion != ESC);

    return 0;
}

void menuDeOpciones(){
    printf("\n\t\t\t <<<< Menu de Opciones >>>>");
    printf("\n\n 1. Carga matriz random");
    printf("\n 2. Muestra matriz");
    printf("\n 3. Carga nombres");
    printf("\n 4. Muestra Listado de Nombres");
}

void cargaMatrizRandom(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            m[i][j]=rand()%100+1;
        }
    }
}

void muestraMatriz(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            printf("%5d",m[i][j]);
        }
        printf("\n");
    }
}

int cargaNombres(int dim, char n[dim][30]){
    int i = 0;
    char opcion = 0;

    while(i<dim && opcion != 27){
        printf("\nIngrese un nombre: ");
        //scanf("%s", n[i]);
        gets(n[i]);
        i++;
        printf("\n\n ESC para salir o cualquier tecla para continuar...");
        opcion = getch();
        system("cls");
    }

    return i;
}

void muestraNombres(int dim, char n[dim][30], int v){
    printf("<<<< Listado de Nombres >>>>");
    for(int i=0; i<v; i++){
        printf("\n %s", n[i]);
    }
}

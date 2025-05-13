#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "mocks.h"
#include "mockAlumnos.h"
#include "stAlumno.h"

#define ESC 27
#define DIM 100

int main()
{
    int cont[11]={0};
    stAlumno alumnos[DIM];
    int vAlumnos = 0;
    vAlumnos = cargaArregloAlumnosAuto(alumnos, DIM);
    //stAlumno a = alumnos[99];
    //vAlumnos = cargaArregloAlumnos(alumnos, vAlumnos, DIM);
    printf("\n <<<< Listado de Alumnos >>>> \n");
    muestraArregloAlumnos(alumnos, vAlumnos);
    //printf("\n Alumno a");
    //mostrarUnAlumno(a);
    cuentaNotas(alumnos, vAlumnos, cont);
    printf("\n <<<<< Cantidad de notas >>>>>");
    muestraContadorDeNotas(cont);
    return 0;
}

int cargaArregloAlumnos(stAlumno a[], int v, int dim){
    char opcion = 0;
    int i = v;

    while(v < dim && opcion != ESC){
        //a[i] = cargaUnAlumno();
        cargaUnAlumnoP(&a[i]);
        i++;
        printf("\nESC para salir o cualquier tecla para continuar");
        opcion = getch();
        system("cls");
    }
    return i;
}

void muestraArregloAlumnos(stAlumno a[], int v){
    for(int i=0; i<v; i++){
        mostrarUnAlumno(a[i]);
    }
}

void cuentaNotas(stAlumno a[], int v, int cont[]){
    for(int i=0; i<v; i++){
        cont[a[i].nota]++;
    }
}

void muestraContadorDeNotas(int cont[]){
    for(int i=0; i<11; i++){
        printf("\n Nota %2d: %2d", i, cont[i]);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "mockAlumnos.h"
#include "mocks.h"

#define DIM 100
#define ARCHI_ALUMNOS "alumnos.dat"

int main()
{
    stAlumno alumnos[DIM];
    int vAlumnos=0;
    vAlumnos = cargaArregloAlumnosAuto(alumnos, DIM);
    printf("\n <<<<< Listado de Alumnos del arreglo>>>>>");
    muestraArregloAlumnos(alumnos, vAlumnos);
    arreglo2archivo(alumnos, vAlumnos, ARCHI_ALUMNOS);
    printf("\n <<<<< Listado de Alumnos del archivo >>>>>");
    leeArchivo(ARCHI_ALUMNOS);
    return 0;
}

void arreglo2archivo(stAlumno a[], int v, char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi){  /// if(archi!=NULL)
        for(int i=0; i<v; i++){
            fwrite(&a[i], sizeof(stAlumno), 1, archi);
        }
        fclose(archi);
    }
}

void leeArchivo(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "rb");
    stAlumno alumno;
    if(archi){
        while(fread(&alumno, sizeof(stAlumno), 1, archi)>0){
            mostrarUnAlumno(alumno);
        }
        fclose(archi);
    }
}

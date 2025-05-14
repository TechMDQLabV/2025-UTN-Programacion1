#include <stdio.h>
#include <stdlib.h>
#include "mockAlumnos.h"
#include "mocks.h"
#include "gotoxy.h"

#define DIM 20
#define ARCHI_ALUMNOS "alumnos.dat"

int main()
{
   /* for(int i=0;i<256; i++){
        color(i);
        printf("\n Color: %d", i);
    }
    system("pause");
    */
        stAlumno alumnos[DIM];
    int vAlumnos=0;
    vAlumnos = cargaArregloAlumnosAuto(alumnos, DIM);
    printf("\n <<<<< Listado de Alumnos del arreglo>>>>>");
    //muestraArregloAlumnos(alumnos, vAlumnos);
    arreglo2archivo(alumnos, vAlumnos, ARCHI_ALUMNOS);
    printf("\n <<<<< Listado de Alumnos del archivo >>>>> ");
    printf("\n <<<<< CAntidad de registros: %d >>>>> ", cuentaRegistros(ARCHI_ALUMNOS));
    leeArchivo(ARCHI_ALUMNOS);
    return 0;
}

void arreglo2archivo(stAlumno a[], int v, char nombreArchivo[]){
    //int contId = cuentaRegistros(nombreArchivo, sizeof(stAlumno));
    int contId = ultimoIdAlumno(nombreArchivo);
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi){  /// if(archi!=NULL)
        for(int i=0; i<v; i++){
            contId++;
            a[i].id = contId;
            fwrite(&a[i], sizeof(stAlumno), 1, archi);
        }
        fclose(archi);
    }
}

void arregloCompleto2archivo(stAlumno a[], int v, char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi){  /// if(archi!=NULL)
        fwrite(a, sizeof(stAlumno), v, archi);
        fclose(archi);
    }
}

void leeArchivo(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "rb");
    stAlumno alumno;
    if(archi){
        while(fread(&alumno, sizeof(stAlumno), 1, archi)>0){
            if(alumno.nota >= 6){
                color(15);
                printf("\n APROBADO");
            }else{
                color(4);
                printf("\n NO APROBO");
            }
            mostrarUnAlumno(alumno);
        }
        fclose(archi);
    }
}

int cuentaRegistros(char nombreArchivo[], int pesoStruct){
    FILE *archi = fopen(nombreArchivo, "rb");
    int cont = 0;
    if(archi){
        fseek(archi, 0, SEEK_END);
        cont = ftell(archi)/pesoStruct;
    }
    return cont;
}

int ultimoIdAlumno(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "rb");
    stAlumno alumno;
    int ultimoId = 0;
    if(archi){
        fseek(archi, -1 * sizeof(stAlumno), SEEK_END);
        fread(&alumno, sizeof(stAlumno), 1, archi);
        ultimoId=alumno.id;
    }
    return ultimoId;
}

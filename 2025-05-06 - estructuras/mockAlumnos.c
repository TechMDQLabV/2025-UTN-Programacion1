#include "mockAlumnos.h"

int cargaArregloAlumnosAuto(stAlumno a[], int dim){
    int i;
    for(i=0; i<dim; i++){
        a[i].id=i+1;
        cargaNombre(a[i].nombre);
        cargaApellido(a[i].apellido);
        cargaDni(a[i].dni);
        a[i].legajo=cargaLegajo();
        a[i].nota=cargaNota();
    }
    return i;
}

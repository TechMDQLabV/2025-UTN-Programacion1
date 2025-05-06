#include "stAlumno.h"

void mostrarUnAlumno(stAlumno a){
    printf("\nNombre................: %s", a.nombre);
    printf("\nApellido..............: %s", a.apellido);
    printf("\nDNI...................: %s", a.dni);
    printf("\nLegajo................: %d", a.legajo);
    printf("\n__________________________________________");
}

stAlumno cargaUnAlumno(){
    stAlumno a;
    printf("\nNombre..........: ");
    gets(a.nombre);
    printf("\nApellido........: ");
    gets(a.apellido);
    printf("\nDNI.............: ");
    gets(a.dni);
    printf("\nLegajo..........: ");
    scanf("%d", &a.legajo);
    fflush(stdin);
    return a;
}

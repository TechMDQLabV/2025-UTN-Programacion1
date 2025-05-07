#include "stAlumno.h"

void mostrarUnAlumno(stAlumno a){
    printf("\nId....................: %d", a.id);
    printf("\nNombre................: %s", a.nombre);
    printf("\nApellido..............: %s", a.apellido);
    printf("\nDNI...................: %s", a.dni);
    printf("\nLegajo................: %d", a.legajo);
    printf("\n__________________________________________");
}

stAlumno cargaUnAlumno(){
    static int id = 0;
    id++;
    stAlumno a;
    a.id=id;
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

void cargaUnAlumnoP(stAlumno *p){
    static int id = 0;
    id++;
    p->id = id;
    printf("\nNombre..........: ");
    gets(p->nombre);
    printf("\nApellido........: ");
    gets(p->apellido);
    printf("\nDNI.............: ");
    gets(p->dni);
    printf("\nLegajo..........: ");
    scanf("%d", &p->legajo);
    fflush(stdin);
}

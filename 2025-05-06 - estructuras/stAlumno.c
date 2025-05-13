#include "stAlumno.h"

void mostrarUnAlumno(stAlumno a){
    printf("\nId....................: %d", a.id);
    printf("\nNombre................: %s", a.nombre);
    printf("\nApellido..............: %s", a.apellido);
    printf("\nDNI...................: %s", a.dni);
    printf("\nLegajo................: %d", a.legajo);
    printf("\nNota..................: %d", a.nota);
    printf("\n__________________________________________");
}

/**
 * @brief Carga un alumno con intervención del usuario y lo retorna
 *
 * @param void
 * @return stAlumno.
 *
 * @author Juan Pérez
 * @date 2025/06/05
 * @version 1.0
 *
 * @pre no hay
 * @post La estructura se retorna con un id autoincremental y el resto de los datos ingresados por el usuario.
 *
 * @code
 * stAlumno alumno = cargaUnAlumno();
 * @endcode
 */
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
    printf("\nNota............: ");
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
    printf("\nNota............: ");
    scanf("%d", &p->nota);
    fflush(stdin);
}

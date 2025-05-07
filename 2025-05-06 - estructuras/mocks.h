#ifndef MOCKS_H_INCLUDED
#define MOCKS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stAlumno.h"

void cargaNombre(char nombre[]);
void cargaApellido(char apellido[]);
void cargaDni(char dni[]);
int cargaLegajo();
int cargaArregloAlumnosAuto(stAlumno a[], int dim);

#endif // MOCKS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

#define DIM 100
int esNotaValida (int nota);
int cargarArreglo (int arreglo[], int v, int dimension);
void mostrarArreglo (int arreglo[], int validos);
void pasarAprobadosDeArregloAPila (int arreglo[], int validos, Pila * pila);
void cargarArregloFloatRandom (float arreglo[], int dimension);
void mostrarArregloFloats (float arreglo[], int validos);
float suma (float arreglo[], int validos);
int buscarCaracter (char arreglo[], int validos, char letra);
int posicionMenor (int arreglo[], int validos);


int main()
{
    srand(time(NULL));
    int opcion;
    int arreglo[DIM];
    float arregloFloat[DIM];
    int validos = 0;
    int validosFloat = 0;
    char continuar = 's';
    char arregloCaracteres[] = {'p','r','o','g','a','m','a'};

    Pila pilita;
    inicpila(&pilita);

    printf("Ingrese el numero del ejercicio. \n");
    scanf("%i",&opcion);

    do
    {
        switch(opcion)
        {

            case 1:
            printf("Cargar arreglo con validación de nota: \n");
            validos = cargarArreglo(arreglo,validos,DIM);
            mostrarArreglo(arreglo,validos);
            break;
            case 2:
            printf("Pasar notas aprobadas a una pila. \n");
            validos = cargarArreglo(arreglo,validos,DIM);
            printf("Arreglo con TODAS las notas: \n");
            mostrarArreglo(arreglo,validos);
            printf("Pila vacia: \n");
            mostrar(&pilita);
            printf("Pila con los aprobados: \n");
            pasarAprobadosDeArregloAPila(arreglo,validos,&pilita);
            mostrar(&pilita);
            break;
            case 3:
            printf("Suma de elementos de un arreglo de tipo float. \n");
            cargarArregloFloatRandom(arregloFloat,DIM);
            printf("Arreglo cargado de manera random. \n");
            mostrarArregloFloats(arregloFloat,DIM);

            float sumaFloat = suma(arregloFloat,DIM);

            printf("El resultado de la suma de arreglo de flontates es: %.2f ", sumaFloat);
            break;
            case 4:
            printf("Busqueda de elemento en arreglo de caracteres. \n");

            int encontrado = buscarCaracter(arregloCaracteres,8,'k');

            if(encontrado == 1)
            {
                printf("La letra se encuentra en el arreglo. \n");
            }
            else
            {
                printf("La letra NO se encuentra en el arreglo. \n");
            }
            break;
            case 5:
            printf("Arreglo capicua. \n");
            validos = cargarArreglo(arreglo,validos,DIM);
            mostrarArreglo(arreglo,validos);

            if(esCapicua(arreglo,validos) == 1)
            {
                printf("El arreglo es capicua. \n");
            }
            else
            {
                printf("El arreglo NO es capicua. \n");
            }
            break;
            case 6:
            printf("Posicion del menor elemento de un arreglo. \n");
            validos = cargarArreglo(arreglo,validos,DIM);
            mostrarArreglo(arreglo,validos);

            int posMenor = posicionMenor(arreglo,validos);

            printf("\n \n La posicion donde se encuentra el menor elemento es: %i \n", posMenor + 1);
            break;
        }

        printf("Desea seguir viendo ejercicios? s/n. \n");
        fflush(stdin);
        scanf("%c",&continuar);

    }while(continuar == 's');

    return 0;
}
int cargarArreglo (int arreglo[], int v, int dimension)
{
    char continuar = 's';

    while(continuar == 's' && v < dimension)
    {
        do
        {
          printf("Ingrese un dato al arreglo. \n");
          scanf("%i", &arreglo[v]);

          if(esNotaValida(arreglo[v]) == 0)
          {
              printf("Ingrese una nota valida. \n");
          }

        }while(esNotaValida(arreglo[v]) == 0);

        v++;

        printf("Desea seguir cargando datos en el arreglo? s/n. \n");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    return v;
}
int esNotaValida (int nota)
{
    int flag = 0;

    if(nota > 0 && nota < 11)
    {
        flag = 1;
    }

    return flag;
}
void mostrarArreglo (int arreglo[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%5d |", arreglo[i]);
    }
}
void mostrarArregloFloats (float arreglo[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        if(i%8==0)
        {
            printf("\n");
        }
        printf("%5.2f |", arreglo[i]);
    }
}
void pasarAprobadosDeArregloAPila (int arreglo[], int validos, Pila * pila)
{
    for(int i = 0; i < validos; i++)
    {
        if(arreglo[i] >= 7)
        {
            apilar(pila,arreglo[i]);
        }
    }
}
void cargarArregloFloatRandom (float arreglo[], int dimension)
{
    for(int i = 0; i < dimension; i++)
    {
        arreglo[i] = (float)rand() / (RAND_MAX / 100.0f);
    }
}
float suma (float arreglo[], int validos)
{
    float suma = 0;

    for(int i = 0; i < validos; i++)
    {
        suma = suma + arreglo[i];
    }
    return suma;
}
int buscarCaracter (char arreglo[], int validos, char letra)
{
    int flag = 0;

    for(int i = 0; i < validos && flag == 0; i++)
    {
        if(arreglo[i] == letra)
        {
            flag = 1;
        }
    }

    return flag;
}
//Neuquen o 2112
int esCapicua (int arreglo[], int validos)
{
    int i = 0;
    int ultimo = validos - 1;
    int flag = 1;


    while(i <= ultimo && flag == 1)
    {
        if(arreglo[i] != arreglo[ultimo])
        {
            flag = 0;
        }
        i++;
        ultimo--;
    }

    return flag;
}
int posicionMenor (int arreglo[], int validos)
{
    int posMenor = 0;

    for(int i = 1; i < validos; i++)
    {
        if(arreglo[i] < arreglo[posMenor])
        {
            posMenor = i;
        }
    }
    return posMenor;
}

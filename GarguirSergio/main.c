#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

/**
Hacer una funci�n para cargar una pila de temperaturas con intervenci�n del usuario
 validando que est�n dentro del rango de valores elegido por el usuario.
  Las temperaturas deben ser de tipo entero y estar en el rango de -10 a 40.
*/

void cargaPilaUsuario(Pila *p){
    char opcion = 0;
    int temp;

    do{
        printf("\n Ingrese una temperatura (entre -10 y 40): ");
        scanf("%d",&temp);

        if(temp >= -10 && temp <= 40){
            apilar(p, temp);
        }else{
            printf("\n Dato invalido");
        }

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
        system("cls");
    }while(opcion != 27);
}

/**

Hacer una funci�n que muestre la pila de las temperaturas (sin utilizar la funci�n
mostrar() de la librer�a de pilas) Se deber�n mostrar 15 temperaturas por l�nea.
*/

void muestraPila(Pila c){
    Pila aux;
    inicpila(&c);
    int cont=0;
    while(!pilavacia(&c)){
        if(cont == 15){
            printf("\n");
            cont = 0;
        }
        printf(" %d |", tope(&c));
        apilar(&aux, desapilar(&c));
        cont++;
    }
}

/**
10 ptos.

Hacer una funci�n que copie a una pila menores las temperaturas <= 0 y
a una pila mayores el resto de las temperaturas. No se deben perder los datos de la pila original.
*/

void tempeMaxyMin(Pila origen, Pila *min, Pila *max){
    while(!pilavacia(&origen)){
        if(tope(&origen)<=0){
            apilar(min, desapilar(&origen));
        }else{
            apilar(max, desapilar(&origen));
        }
    }
}

/**
Hacer una funci�n que encuentre la temperatura m�nima en la pila y la retorne (la temperatura m�nima debe quitarse de la pila).
*/

int buscaMenor(Pila *p){
    Pila aux;
    inicpila(p);
    int menor = 0;
    if(!pilavacia(p)){
        menor = desapilar(p);
        while(!pilavacia(p)){
            if(tope(p) < menor){
                apilar(&aux, menor);
                menor = tope(p);
            }
            apilar(&aux, desapilar(p));
        }
        pasaPila(&aux, p);
    }
    return menor;
}

/**
Hacer una funci�n que cuente las temperaturas de una pila, mayores
a un valor dado y lo retorne. (el valor se recibe por par�metro).
*/
int cuantaPila(Pila c, int valor){
    Pila aux;
    inicpila(&aux);
    int cont = 0;
    while(!pilavacia(&c)){
        if(tope(&c)>valor){}
            cont ++;
        }
        apilar(&aux, desapilar(&c));
    }
    return cont;
}

int sumaPila(Pila c, int valor){
    Pila aux;
    inicpila(&aux);
    int total = 0;
    while(!pilavacia(&c)){
        if(tope(&c)>valor){}
            total+=tope(&c);
        }
        apilar(&aux, desapilar(&c));
    }
    return total;
}

int cargaArreglo(Pila c, int a[], int dim){
    int i = 0;
    while(!pilavacia(&c)){
        a[i] = buscaMenor(&c);
        i++;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ESC 27
#define DIM 100

int main()
{
    srand(time(NULL));
    char opcion;
    int fil = 3;
    int col = 3;
    int matrix[fil][col];
    char nombre[30];

    char nombres[DIM][30];
    char apellidos[DIM][30];
    int legajos[DIM];
    int notas[DIM];
    int vParalelos=0;
    int vNombres = 0;
    do{
        menuDeOpciones();
        opcion = getch();

        switch(opcion){
            case 49:
                printf("\n <<<< Carga matriz random >>>> ");
                cargaMatrizRandom(fil, col, matrix);
                break;
            case 50:
                printf("\n <<<< Muestra matriz >>>> \n");
                muestraMatriz(fil, col, matrix);
                break;
            case 51:
                printf("\n <<<< Carga Nombres >>>> ");
                vNombres = cargaNombres(DIM, nombres);
                strcpy(nombres[vNombres],"Juanito");
                vNombres++;
                break;
            case 52:
                printf("\n <<<< Muestra Nombres >>>> \n");
                muestraNombres(DIM, nombres, vNombres);
                break;
            case 53:
                printf("\n <<<< Carga Arreglo de Nombres random >>>> \n");
                vNombres=cargaArregloNombresRandom(nombres, DIM);
                break;
            case 54:
                printf("\n <<<< Ordena Nombres por Seleccion >>>> \n");
                ordenaNombresPorSeleccion(nombres, vNombres);
                break;
            case 55:
                printf("\n <<<< Carga arreglos paralelos >>>> \n");
                vParalelos = cargaParalelos(legajos, apellidos, nombres, notas, DIM);
                break;
            case 56:
                printf("\n <<<< Muestra arreglos paralelos >>>> \n");
                muestraParalelos(legajos, apellidos, nombres, notas, vParalelos);
                break;
        }
        getch();
        system("cls");
    }while(opcion != ESC);

    return 0;
}

void menuDeOpciones(){
    printf("\n\t\t\t <<<< Menu de Opciones >>>>");
    printf("\n\n 1. Carga matriz random");
    printf("\n 2. Muestra matriz");
    printf("\n 3. Carga nombres");
    printf("\n 4. Muestra Listado de Nombres");
    printf("\n 5. Carga arreglo de nombres random");
    printf("\n 6. Ordena nombres por seleccion");
    printf("\n 7. Carga arreglos paralelos");
    printf("\n 8. Muestra arreglos paralelos");
}

void cargaMatrizRandom(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            m[i][j]=rand()%100+1;
        }
    }
}

void muestraMatriz(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            printf("%5d",m[i][j]);
        }
        printf("\n");
    }
}

int cargaNombres(int dim, char n[dim][30]){
    int i = 0;
    char opcion = 0;

    while(i<dim && opcion != 27){
        printf("\nIngrese un nombre: ");
        //scanf("%s", n[i]);
        gets(n[i]);
        i++;
        printf("\n\n ESC para salir o cualquier tecla para continuar...");
        opcion = getch();
        system("cls");
    }

    return i;
}

void muestraNombres(int dim, char n[dim][30], int v){
    printf("<<<< Listado de Nombres >>>>");
    for(int i=0; i<v; i++){
        printf("\n %s", n[i]);
    }
}

void cargaNombre(char n[]){
    char nombres[][30]= {
    "Juan", "Maria", "Carlos", "Ana", "Luis", "Laura", "Pedro", "Sofia", "Jorge", "Lucia",
    "Miguel", "Valentina", "Jose", "Isabella", "David", "Camila", "Alejandro", "Paula", "Daniel", "Fernanda",
    "Andres", "Valeria", "Manuel", "Mariana", "Ricardo", "Gabriela", "Felipe", "Daniela", "Javier", "Alejandra",
    "Roberto", "Victoria", "Raul", "Juana", "Fernando", "Antonella", "Diego", "Ximena", "Arturo", "Adriana",
    "Eduardo", "Natalia", "Alberto", "Claudia", "Francisco", "Andrea", "Antonio", "Patricia", "Ruben", "Monica",
    "Sergio", "Alicia", "Enrique", "Carolina", "Óscar", "Rosa", "Pablo", "Teresa", "Hugo", "Sara",
    "Guillermo", "Elena", "Rodrigo", "Beatriz", "Salvador", "Julia", "Emilio", "Raquel", "Mario", "Diana",
    "Alfonso", "Olga", "Armando", "Angelica", "Gerardo", "Silvia", "Rafael", "Carmen", "Jaime", "Irene",
    "Ignacio", "Pilar", "Hector", "Concepcion", "Cesar", "Lourdes", "Victor", "Consuelo", "Ramon", "Eva",
    "Alfredo", "Luisa", "Julio", "Amparo", "Joaquin", "Rocio", "Gustavo", "Manuela", "Lorenzo", "Veronica", "Lorenzo", "Veronica"
    };
   /// printf("%d", sizeof(nombres)/30);

    strcpy(n, nombres[rand()%(sizeof(nombres)/30)]);
}

void cargaApellido(char apellido[30]){
    char apellidos[][30]={
        "García", "Rodríguez", "González", "Fernández", "López",
        "Martínez", "Sánchez", "Pérez", "Gómez", "Martín",
        "Jiménez", "Ruiz", "Hernández", "Díaz", "Moreno",
        "Álvarez", "Muñoz", "Romero", "Alonso", "Gutiérrez",
        "Navarro", "Torres", "Domínguez", "Vázquez", "Ramos",
        "Gil", "Ramírez", "Serrano", "Blanco", "Suárez",
        "Molina", "Morales", "Ortega", "Delgado", "Castro",
        "Ortíz", "Rubio", "Marín", "Sanz", "Iglesias",
        "Medina", "Cortés", "Garrido", "Castillo", "Santos",
        "Lozano", "Guerrero", "Cano", "Prieto", "Méndez",
        "Cruz", "Calvo", "Gallego", "Vidal", "León",
        "Herrera", "Márquez", "Peña", "Flores", "Cabrera",
        "Campos", "Vega", "Fuentes", "Carrasco", "Diez",
        "Reyes", "Caballero", "Núñez", "Aguilar", "Pascual",
        "Santana", "Herrero", "Montero", "Lorenzo", "Hidalgo",
        "Giménez", "Ibáñez", "Ferrer", "Durán", "Santiago",
        "Benítez", "Mora", "Vicente", "Vargas", "Arias",
        "Carmona", "Crespo", "Román", "Pastor", "Soto",
        "Sáez", "Velasco", "Moya", "Soler", "Parra",
        "Esteban", "Bravo", "Gallardo", "Rojas", "Pardo"
    };

    strcpy(apellido, apellidos[rand()%(sizeof(apellidos)/30)]);
}

int cargaArregloApellidosRandom(char a[][30], int dim){
    int i;
    for(i=0;i<dim;i++){
        cargaApellido(a[i]);
    }
    return i;
}

int cargaArregloNombresRandom(char n[][30], int dim){
    int i;
    for(i=0;i<dim;i++){
        cargaNombre(n[i]);
    }
    return i;
}

int cargaArregloLegajos(int l[], int dim){
    int i;
    for(i=0; i<dim; i++){
        l[i]=rand()%10000;
    }
    return i;
}

int cargaArregloNotas(int n[], int dim){
    int i;
    for(i=0; i<dim; i++){
        n[i]=rand()%10+1;
    }
    return i;
}

int buscarPosMenorNombre(char n[][30], int v){
    int posMenor = -1;

    if(v>0){
        posMenor = 0;
        for(int i=1; i<v; i++){
            if(strcmp(n[i],n[posMenor])<0){
                posMenor = i;
            }
        }
    }
    return posMenor;
}

int buscarPosMenorNombreParaOrdenacion(char n[][30], int v, int inicio){
    int posMenor = inicio;

    for(int i=inicio+1; i<v; i++){
        if(strcmp(n[i],n[posMenor])<0){
            posMenor = i;
        }
    }

    return posMenor;
}

void ordenaNombresPorSeleccion(char n[][30], int v){
    int posMenor;
    for(int i=0; i<v-1; i++){
        posMenor=buscarPosMenorNombreParaOrdenacion(n, v, i);
        intercambioNombres(n[i], n[posMenor]);
    }
}

void intercambioNombres(char n1[], char n2[]){
    char aux[30];
    strcpy(aux, n1);
    strcpy(n1, n2);
    strcpy(n2, aux);
}

int cargaParalelos(int l[], char a[][30], char n[][30], int notas[], int dim){
    int i;
    i = cargaArregloApellidosRandom(a, dim);
    cargaArregloNombresRandom(n, dim);
    cargaArregloLegajos(l, dim);
    cargaArregloNotas(notas, dim);
    return i;
}

void muestraParalelos(int l[], char a[][30], char n[][30], int notas[], int v){
    for(int i=0;i<v;i++){
        printf("\n Legajo........: %d", l[i]);
        printf("\n Apellido......: %s", a[i]);
        printf("\n Nombre........: %s", n[i]);
        printf("\n Nota..........: %d", notas[i]);
        printf("\n ______________________________________________________");
    }
}



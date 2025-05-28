#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n Factorial 5: %d", factorial(5));
    printf("\n Factorial 5: %d", factorial1(5));
    printf("\n Factorial 5: %d", factorialTernario(5));
    return 0;
}

int factorial(int x){
    int rta;
    if(x==0){
        rta=1;
    }else{
        rta = x * factorial(x-1);
    }
    return rta;
}

int factorial1(int x){
    int rta = 1;
    if(x>0){
        /// viaje de ida
        rta = x * factorial1(x-1);
        /// viaje de vuelta
    }
    return rta;
}

int factorialTernario(int x){
    return (x>0) ? x * factorialTernario(x-1) : 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define C 262
#define D 294
#define EB 311
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494

int main() {
    printf("\n Happy Birthday");
    happyBirthday();
    printf("\n Jingle Bells");
    jingleBells();
    printf("\n Electronic Music");
    electronicMusic();
    return 0;
}

void happyBirthday(){
    Beep(G, 500); Beep(G, 500);
    Beep(A, 1000); Beep(G, 1000);
    Beep(C, 1000); Beep(B, 500);

    Beep(G, 500); Beep(G, 500);
    Beep(A, 1000); Beep(G, 1000);
    Beep(D, 1000); Beep(C, 500);

    Beep(G, 500); Beep(G, 500);
    Beep(G, 1000); Beep(E, 1000);
    Beep(C, 1000); Beep(B, 500); Beep(A, 500);

    Beep(F, 500); Beep(F, 500);
    Beep(E, 1000); Beep(C, 1000);
    Beep(D, 1000); Beep(C, 500);
}

void jingleBells(){
    int tempo = 300;
    // Estrofa
    Beep(E, tempo); Beep(E, tempo); Beep(E, tempo*2);
    Beep(E, tempo); Beep(E, tempo); Beep(E, tempo*2);
    Beep(E, tempo); Beep(G, tempo); Beep(C, tempo); Beep(D, tempo);
    Beep(E, tempo*3);

    Beep(F, tempo); Beep(F, tempo); Beep(F, tempo); Beep(F, tempo);
    Beep(F, tempo); Beep(E, tempo); Beep(E, tempo); Beep(E, tempo);
    Beep(E, tempo); Beep(D, tempo); Beep(D, tempo); Beep(E, tempo);
    Beep(D, tempo*2); Beep(G, tempo*2);

    // Coro
    Beep(E, tempo); Beep(E, tempo); Beep(E, tempo*2);
    Beep(E, tempo); Beep(E, tempo); Beep(E, tempo*2);
    Beep(E, tempo); Beep(G, tempo); Beep(C, tempo); Beep(D, tempo);
    Beep(E, tempo*3);

    Beep(F, tempo); Beep(F, tempo); Beep(F, tempo); Beep(F, tempo);
    Beep(F, tempo); Beep(E, tempo); Beep(E, tempo); Beep(E, tempo);
    Beep(G, tempo); Beep(G, tempo); Beep(F, tempo); Beep(D, tempo);
    Beep(C, tempo*4);
}

void odeToJoy(){
    int tempo = 400;

    Beep(E, tempo); Beep(E, tempo); Beep(F, tempo); Beep(G, tempo);
    Beep(G, tempo); Beep(F, tempo); Beep(E, tempo); Beep(D, tempo);
    Beep(C, tempo); Beep(C, tempo); Beep(D, tempo); Beep(E, tempo);
    Beep(E, tempo*1.5); Beep(D, tempo/2); Beep(D, tempo*2);

    Beep(E, tempo); Beep(E, tempo); Beep(F, tempo); Beep(G, tempo);
    Beep(G, tempo); Beep(F, tempo); Beep(E, tempo); Beep(D, tempo);
    Beep(C, tempo); Beep(C, tempo); Beep(D, tempo); Beep(E, tempo);
    Beep(D, tempo*1.5); Beep(C, tempo/2); Beep(C, tempo*2);

    Beep(D, tempo); Beep(D, tempo); Beep(E, tempo); Beep(C, tempo);
    Beep(D, tempo); Beep(E, tempo/2); Beep(F, tempo/2); Beep(E, tempo); Beep(C, tempo);
    Beep(D, tempo); Beep(E, tempo/2); Beep(F, tempo/2); Beep(E, tempo); Beep(D, tempo);
    Beep(C, tempo); Beep(D, tempo); Beep(G, tempo*2);

    Beep(E, tempo); Beep(E, tempo); Beep(F, tempo); Beep(G, tempo);
    Beep(G, tempo); Beep(F, tempo); Beep(E, tempo); Beep(D, tempo);
    Beep(C, tempo); Beep(C, tempo); Beep(D, tempo); Beep(E, tempo);
    Beep(D, tempo*1.5); Beep(C, tempo/2); Beep(C, tempo*2);
}

void harryPotterTheme(){
    int tempo = 300;

    Beep(E, tempo*2); Beep(A, tempo); Beep(B, tempo); Beep(C, tempo*1.5); Beep(B, tempo/2);
    Beep(A, tempo); Beep(G, tempo*1.5); Beep(E, tempo/2); Beep(G, tempo); Beep(A, tempo);
    Beep(F, tempo); Beep(G, tempo*1.5); Beep(E, tempo/2); Beep(C, tempo); Beep(D, tempo);
    Beep(B, tempo*2); Beep(E, tempo*0.5); Beep(A, tempo); Beep(B, tempo); Beep(C, tempo*1.5);
    Beep(B, tempo/2); Beep(A, tempo); Beep(G, tempo*1.5); Beep(E, tempo/2); Beep(G, tempo);
    Beep(A, tempo); Beep(F, tempo); Beep(G, tempo*1.5); Beep(E, tempo/2); Beep(C, tempo);
    Beep(D, tempo); Beep(B, tempo*4);
}

void electronicMusic(){
    while(!kbhit()){
       Beep(randomRango(200,550),randomRango(200,1000));
    }
}

int randomRango(int min, int max){
    return rand()%(max-min)+min;
}

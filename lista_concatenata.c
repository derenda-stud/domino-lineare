// #include e definizioni di funzione
#include<stdio.h>
#include<stdlib.h>
#include"lista_concatenata.h"

void genera_tessere(tessera *tessere, int dimensione) {
    // Per ciascuna tessera del domino
    for(int i=0; i<dimensione; i++) {
        // Genera due numeri casuali per ciasun estremo della tessera
        tessere[i].estremo_sinistro = rand() % 6 + 1;
        tessere[i].estremo_destro = rand() % 6 + 1;
    }
}

void stampa_tessere(tessera *tessere, int dimensione) {
    printf("Le tessere assegnate sono le seguenti:\n");
    for(int i=0; i<dimensione; i++) {
        // Stampa le tessere in riga
        printf("[%d|%d] ", tessere[i].estremo_sinistro, tessere[i].estremo_destro);
    }
    printf("\n");
    for(int i=0; i<dimensione; i++) {
        // Stampa indice corrispondente a ciascuna tessera
        printf("  %d   ", i);
    }
    printf("\n");
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"lista_concatenata.h"

/* Progetto Domino Lineare di Bertoncello Nicolas, Derevytskyy Alessandro */
void stampa_combinazioni_tessere();

int main() {
    int num_tessere;
    // Inizializza la generazione dei numeri casuali
    srand(time(NULL));

    printf("Inserisci il numero di tessere con cui vuoi giocare: ");
    scanf("%d", &num_tessere);

    // Creazione delle tessere nella mano del giocatore
    tessera tessere[num_tessere];
    genera_tessere(tessere, num_tessere);
    stampa_tessere(tessere, num_tessere);

    return 0;
}

// Stampa una raffigurazione di tutte le possibili combinazioni di tessere
void stampa_combinazioni_tessere() {
    for(int i=1; i<=6; i++) {
        for(int j=i; j<=6; j++) {
            printf("[%d|%d]", i, j);
        }
        printf("\n");
    }
}
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/* Progetto Domino Lineare di Bertoncello Nicolas, Derevytskyy Alessandro */

typedef struct {
    int estremo_sinistro;
    int estremo_destro;
} tessera;

void stampa_combinazioni_tessere();
void stampa_tessere(tessera *tessere, int dimensione);
void genera_tessere(tessera *tessere, int dimensione);

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

//prova1
void genera_tessere(tessera *tessere, int dimensione) {
    // Per ciascuna tessera del domino
    for(int i=0; i<dimensione; i++) {
        // Genera due numeri casuali per ciasun estremo della tessera
        tessere[i].estremo_sinistro = rand() % 6 + 1;
        tessere[i].estremo_destro = rand() % 6 + 1;
    }
}

void stampa_tessere(tessera *tessere, int dimensione) {
    printf("Le tessere assegnate sono le seguenti: ");
    for(int i=0; i<dimensione; i++) {
        printf("[%d|%d] ", tessere[i].estremo_sinistro, tessere[i].estremo_destro);
    }
    printf("\n");
}
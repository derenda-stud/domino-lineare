#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "lista_concatenata.h"
#include "controlli.h"

/* Progetto Domino Lineare di Bertoncello Nicolas, Derevytskyy Alessandro */

// Stampa una raffigurazione di tutte le possibili combinazioni di tessere
void stampa_combinazioni_tessere();

int main() {
    // Inizializza la generazione dei numeri casuali
    srand(time(NULL));
    
    int numero_tessere = inserisci_numero_tessere();
    
    // Creazione delle tessere nella mano del giocatore
    tessera *mano_giocatore = NULL;
    tessera *piano_gioco = NULL;
    genera_tessere(&mano_giocatore, numero_tessere);
    stampa_tessere(mano_giocatore);
    
    // E' necessario calcolare la dimensione della lista
    int indice_tessera = inserisci_indice_tessera(numero_tessere);
    
    if(piano_gioco == NULL) {
        // Puntatore
        tessera *trovata = trova_tessera(mano_giocatore, indice_tessera);
        // Portati dietro solo il valore di una tessera
        tessera da_inserire;
        da_inserire.estremo_sinistro = trovata->estremo_sinistro;
        da_inserire.estremo_destro = trovata->estremo_destro;
        da_inserire.successivo = NULL;
        // Inserisci la tessera in testa al piano di gioco
        inserimento_in_testa(&piano_gioco, &da_inserire);
        // Rimuovi la tessera dalla mano del giocatore
        rimuovi_tessera(&mano_giocatore, trovata);
        stampa_tessere(mano_giocatore);
    }
    system("PAUSE");
    return 0;
}

void stampa_combinazioni_tessere() {
    for(int i=1; i<=6; i++) {
        for(int j=i; j<=6; j++) {
            printf("[%d|%d]", i, j);
        }
        printf("\n");
    }
}
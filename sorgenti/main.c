#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../librerie/lista_concatenata.h"
#include "../librerie/controlli.h"

/* Progetto Domino Lineare di Bertoncello Nicolas, Derevytskyy Alessandro */

int main() {
    // Inizializza la generazione dei numeri casuali
    srand(time(NULL));
    
    // Creazione delle tessere nella mano del giocatore
    tessera *mano_giocatore = NULL;
    // Creazione delle tessere sul piano di gioco
    tessera *piano_gioco = NULL;

    int numero_tessere = inserisci_numero_tessere();

    genera_tessere(&mano_giocatore, numero_tessere);
    stampa_tessere(mano_giocatore);
    
    // E' necessario calcolare la dimensione della lista
    int indice_tessera = inserisci_indice_tessera(numero_tessere);
    
    if(piano_gioco == NULL) {
        // Trova la tessere da prelevare dalla mano del giocatore
        tessera *trovata = trova_tessera(mano_giocatore, indice_tessera);
        rimuovi_tessera(&mano_giocatore, trovata);
        // Adesso aggiungi la tessera al piano di gioco
        inserimento_in_testa(&piano_gioco, trovata);
        // Stampa delle tessere presenti in entrambe le liste
        printf("Tessere sul piano di gioco:\n");
        stampa_tessere(piano_gioco);
        printf("Tessere nella mano del giocatore:\n");
        stampa_tessere(mano_giocatore);
    }
    return 0;
}
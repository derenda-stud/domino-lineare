#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../librerie/lista_concatenata.h"
#include "../librerie/controlli.h"
#include "../librerie/modalita_interattiva.h"

/* Progetto Domino Lineare di Bertoncello Nicolas, Derevytskyy Alessandro */

int main() {
    // Inizializza la generazione dei numeri casuali
    srand(time(NULL));
    
    // NOTA: Vengono utilizzati dei noti fantocci chiamati 'sentinelle'
    // Creazione delle tessere nella mano del giocatore
    tessera *mano_giocatore = crea_tessera(0, 0);
    // Creazione delle tessere sul piano di gioco
    tessera *piano_gioco = crea_tessera(0, 0);
    
    int numero_tessere = inserisci_numero_tessere();
    
    genera_tessere(mano_giocatore, numero_tessere);
    stampa_tessere(mano_giocatore);
    
    turno_giocatore(mano_giocatore, piano_gioco, numero_tessere);
    int punteggio = conta_punteggio(numero_tessere, piano_gioco);

    printf("hai effettuato %d punti!", punteggio);
    
    return 0;
}
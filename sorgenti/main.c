#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../librerie/controlli.h"
#include "../librerie/lista_concatenata.h"
#include "../librerie/modalita_interattiva.h"

/* Progetto Domino Lineare di Bertoncello Nicolas, Derevytskyy Alessandro */

int main() {
    // Inizializza la generazione dei numeri casuali
    srand(time(NULL));

    int numero_tessere = inserisci_numero_tessere();

    // NOTA: Vengono utilizzati dei noti fantocci chiamati 'sentinelle'
    // Creazione delle tessere nella mano del giocatore tenendo conto del numero iniziale ed attuale
    tessera *mano_giocatore = crea_tessera(numero_tessere, numero_tessere);
    // Creazione delle tessere sul piano di gioco impostando entrambi gli estremi a 0
    tessera *piano_gioco = crea_tessera(0, 0);

    genera_tessere(mano_giocatore, numero_tessere);
    stampa_tessere(mano_giocatore);

    turno_giocatore(mano_giocatore, piano_gioco);
    int punteggio = conta_punteggio(piano_gioco);

    printf("Hai effettuato %d punti!\n", punteggio);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../librerie/controlli.h"
#include "../librerie/lista_concatenata.h"
#include "../librerie/modalita_interattiva.h"
#include "../librerie/modalita_challenge.h"

/* Progetto Domino Lineare di Bertoncello Nicolas, Derevytskyy Alessandro */

int main(int argc, char *argv[]) {
    // Se vengono inseriti parametri da terminale
    if (argc > 1 && strcmp(argv[1], "--challenge") == 0) {
        // Stabilire se avviare la modalita' challenge
        tessera *mano_giocatore = inserimento_parametri();
        tessera *piano_gioco = crea_tessera(0, 0);
        // Comincia la partita seguendo un algoritmo AI
        stampa_tessere(mano_giocatore);
        return 0;
    }
    // Altrimenti procedi con la modalita' interattiva e AI

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

    stampa_turno(mano_giocatore, piano_gioco);
    int punteggio = conta_punteggio(piano_gioco);

    printf("Hai effettuato %d punti!\n", punteggio);

    return 0;
}
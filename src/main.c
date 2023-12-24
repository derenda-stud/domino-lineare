// 900983 899454

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "../lib/controlli.h"
#include "../lib/lista_concatenata.h"
#include "../lib/modalita_ai.h"
#include "../lib/modalita_challenge.h"
#include "../lib/modalita_interattiva.h"

/* Progetto Domino Lineare di Bertoncello Nicolas, Derevytskyy Alessandro */

/*
Le tessere speciali:
    * non avrebbe senso ruotarle? es. [12|21] diventa [21|12]?
    * [11|11] e [12|21] non possono essere posizionate per prime
    * [11|11] e [12|21] necessitano di funzionalita' aggiuntive
    * incrementare [0|0] in [1|1] significa perdere la sua proprieta'

Inserimento generico per le tessere:
switch(estremo) {
    case 11 -> incrementa, cambia valori
    case 12/21 -> cambia valori
    default -> se controllo non valido -> return
} // 0|0 non necessita controlli
inserisci_nel_piano

*/

int main(int argc, char *argv[]) {
    // Stabilire se avviare la modalita' challenge in presenza di parametri
    if (argc > 1 && strcmp(argv[1], "--challenge") == 0) {
        // Inserisci le tessere della mano dal terminale
        tessera *mano_giocatore = inserimento_parametri();
        // Inizializza la sentinella del piano di gioco
        tessera *piano_gioco = crea_tessera(0, 0, false);
        // Comincia la partita utilizzando il migliore algoritmo
        esegui_algoritmo(mano_giocatore, piano_gioco);
        return 0;
    }
    // Altrimenti procedi con la modalita' interattiva e AI
    // Inizializza la generazione dei numeri casuali
    srand(time(NULL));
    // Richiesta dall'utente per il numero di tessere
    int numero_tessere = inserisci_numero_tessere();
    // NOTA: Vengono utilizzati dei noti fantocci chiamati 'sentinelle'
    // Creazione delle tessere nella mano del giocatore tenendo conto del numero iniziale ed attuale
    tessera *mano_giocatore = crea_tessera(numero_tessere, numero_tessere, false);
    // Creazione delle tessere sul piano di gioco impostando entrambi gli estremi a 0
    tessera *piano_gioco = crea_tessera(0, 0, false);
    // Genera le tessere casuali nella mano del giocatore
    genera_tessere(mano_giocatore, numero_tessere);
    // Funzione per il proseguimento del gioco
    stampa_turno(mano_giocatore, piano_gioco);
    // Dopo il termine della partita conta il punteggio effettuato
    int punteggio = conta_punteggio(piano_gioco);
    printf("Hai effettuato %d punti!\n", punteggio);
    
    return 0;
}
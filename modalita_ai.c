#include "librerie/modalita_ai.h"

#include <stdio.h>
#include <stdlib.h>

tessera *first_match(tessera *mano_giocatore, tessera *piano_gioco, combinazione *risultato) {
    // Quando il piano di gioco e' vuoto
    if (piano_gioco->successivo == NULL) {
        // Posiziona la tessera in testa
        risultato->posizione = false;
        // Mantineni l'ordine invariato
        risultato->rotazione = false;
        // Ritorna la prima tessera nella mano del giocatore
        return mano_giocatore->successivo;
    }
    // Per ciascuna tessera nella mano del giocatore
    tessera *corrente = mano_giocatore->successivo;
    int corrispondenza;
    while (corrente != NULL) {
        // Confronta che il valore degli estremi corrisponda con quella in testa e in coda
        for (int posizione = 0; posizione <= 1; posizione++) {
            // Se ho trovato una corrispondenza memorizzo la rotazione
            if ((corrispondenza = mossa_legale(corrente, posizione, piano_gioco)) > 0) {
                risultato->posizione = posizione;
                risultato->rotazione = corrispondenza - 1;
                // Ritorna l'indirizzo della tessera corrente
                return corrente;
            }
        }
        // Continua con la tessera successiva
        corrente = corrente->successivo;
    }
    // Non sono state trovate corrispondenze
    return NULL;
}
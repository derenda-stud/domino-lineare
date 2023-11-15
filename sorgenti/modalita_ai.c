#include "../librerie/modalita_ai.h"

#include <stdio.h>
#include <stdlib.h>

#include "../librerie/controlli.h"

void first_match(tessera *mano_giocatore, tessera *piano_gioco) {
    // Traccia la tessera da inserire sul piano di gioco
    tessera *da_inserire;
    // Memorizza le informazioni sulla posizione e sulla rotazione 
    combinazione risultato;
    while((da_inserire = mosse_disponibili(mano_giocatore, piano_gioco, &risultato)) != NULL) {
        // Stabilisci se bisogna ruotare la tessera
        if(risultato.rotazione == true) {
            ruota_tessera(da_inserire);
        }
        // Aggiungi la tessera trovata alla posizione indicata
        aggiungi_tessera(mano_giocatore, piano_gioco, da_inserire, risultato.posizione);
    }
}

void first_match_v2(tessera *mano_giocatore, tessera *piano_gioco) {
    // Partendo dalla tessera sentinella
    tessera *corrente = mano_giocatore;
    int risultato;
    // Verifica se ho raggiunto la fine della lista
    while(corrente->successivo != NULL) {
        // Procedi con la tessera successiva
        corrente = corrente->successivo;
        // Controlla se il piano di gioco e' vuoto
        if(piano_gioco->successivo == NULL) {
            aggiungi_tessera(mano_giocatore, piano_gioco, corrente, 1);
            // Ricomincia il ciclo dalla prima tessera
            corrente = mano_giocatore;
            continue;
        }
        // Altrimenti verifica le tessere successive in testa e in coda
        for(int posizione = 1; posizione <= 2; posizione++) {
            if((risultato = mossa_legale(corrente, posizione, piano_gioco)) > 0) {
                // Stabilisci se bisogna girare la tessera
                if(risultato / 100 == 2) {
                    ruota_tessera(corrente);
                }
                // Aggiungi la tessera alla posizione con corrispondenza
                aggiungi_tessera(mano_giocatore, piano_gioco, corrente, posizione);
                // Ricomincia il ciclo dalla prima tessera
                corrente = mano_giocatore;
                // Esci dal ciclo corrente
                break;
            }
        }
    }
}
#include "../librerie/modalita_ai.h"

#include <stdio.h>

#include "../librerie/controlli.h"

void first_match(tessera *mano_giocatore, tessera *piano_gioco) {
    // Per ciascuna tessera nella mano del giocatore
    tessera *corrente = mano_giocatore->successivo;
    int risultato;
    while(mosse_disponibili(mano_giocatore, piano_gioco)) {
        // Confronta che sia possibile effettuare una mossa valida inserendo in testa o in coda
        //for 1 o 2, legale 0 -> 0. legale 1 -> [0][pos], legale 2 -> [1][pos]
        // se pos 1 e legale 1 allora return 01, altrimenti se pos 1 e legale 2 02
        for(int posizione=1; posizione<=2; posizione++) {
            int risultato = mossa_legale(corrente, posizione, piano_gioco);
            if(risultato != 0) {
                risultato * 10 + posizione;
                break;
            }
        }
        if(risultato / 10 == 2) {
            ruota_tessera(corrente);
        }
        // Inserisci la tessera alla posizione con la corrispondenza
        aggiungi_tessera(mano_giocatore, piano_gioco, corrente, risultato % 10);
        corrente = corrente->successivo;
    }
}

/*
00 non va bene
11 in testa
12 in coda
21 gira in testa
22 gira in coda
*/

void aggiungi_tessera(tessera *mano_giocatore, tessera *piano_gioco, tessera *trovata, int posizione) {
    // Rimuovi la tessere trovata dalla mano del giocatore
    rimuovi_tessera(mano_giocatore, trovata);
    // Aggiungi la tessera in base alla posizione selezionata
    switch (posizione) {
        case 1: {
            inserimento_in_testa(piano_gioco, trovata);
        } break;
        case 2: {
            inserimento_in_coda(piano_gioco, trovata);
        } break;
    }
    // Aggiorna il numero corrente di tessere su entrambe le liste
    mano_giocatore->estremo_destro--;
    piano_gioco->estremo_destro++;
}
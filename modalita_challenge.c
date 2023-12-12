#include "librerie/modalita_challenge.h"

#include <stdio.h>

#include "librerie/controlli.h"
#include "librerie/modalita_ai.h"

tessera *inserimento_parametri() {
    // Richiedi il numero di tessere con cui giocare
    int numero_tessere;
    scanf("%d", &numero_tessere);
    // Crea il nodo sentinello che tiene conto nel numero di tessere
    tessera *sentinella = crea_tessera(numero_tessere, numero_tessere);
    // Per ciascuna tessera prendi da input gli estremi
    int estremo_sinistro, estremo_destro;
    for (int i = 0; i < numero_tessere; i++) {
        scanf("%d %d", &estremo_sinistro, &estremo_destro);
        // Inseriscila in coda alla lista
        inserimento_in_coda(sentinella, crea_tessera(estremo_sinistro, estremo_destro));
    }
    // Restituisci il puntatore alla sentinella
    return sentinella;
}

void esegui_algoritmo(tessera *mano_giocatore, tessera *piano_gioco) {
    // Finche' mi restituisce una tessera valida
    tessera *da_inserire;
    combinazione risultato;
    for (int i = 0; (da_inserire = most_frequent(mano_giocatore, piano_gioco, &risultato)) != NULL; i++) {
        // Stabilisci se bisogna ruotare la tessera
        if (risultato.rotazione == true) {
            ruota_tessera(da_inserire);
        }
        // Stabilisci la mossa da stampare a schermo
        if (i == 0) {
            printf("S");
        } else if (!risultato.posizione) {
            printf("L");
        } else {
            printf("R");
        }
        // Stampa di seguito anche gli estremi della tessera inserita
        printf(" %d %d ", da_inserire->estremo_sinistro, da_inserire->estremo_destro);
        // Aggiungi la tessera trovata sul piano di gioco
        aggiungi_tessera(mano_giocatore, piano_gioco, da_inserire, risultato.posizione);
    }
}
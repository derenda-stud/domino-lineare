#include "librerie/modalita_interattiva.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "librerie/controlli.h"

void stampa_turno(tessera *mano_giocatore, tessera *piano_gioco) {
    // Continua finche' rimangono tessere in mano e siano disponibili mosse legali
    while (mosse_disponibili(mano_giocatore, piano_gioco)) {
        // Chiedi all'utente se vuole posizionare/ruotare una tessera
        printf(" - Premi 1 per posizionare una tessera\n");
        printf(" - Premi 2 per ruotare una tessera\n");
        // Inserisci la prossima mossa da effettuare
        inserisci_scelta(mano_giocatore, piano_gioco);
        // Stampa delle tessere presenti in entrambe le liste
        printf("Tessere sul piano di gioco:\n");
        stampa_tessere(piano_gioco);
        printf("Tessere nella mano del giocatore:\n");
        stampa_tessere(mano_giocatore);
    }
}

void inserisci_scelta(tessera *mano_giocatore, tessera *piano_gioco) {
    int scelta = inserisci_numero_compreso("Seleziona un'opzione", 1, 2);
    switch (scelta) {
        case 1: {
            // Inserisci la tessera presente ad un determinato indice
            seleziona_tessera(mano_giocatore, piano_gioco);
        } break;
        case 2: {
            // Ruota la tessere presente ad un determinato indice
            ruota_tessera(inserisci_indice(mano_giocatore, "ruotare"));
        } break;
    }
}

void seleziona_tessera(tessera *mano_giocatore, tessera *piano_gioco) {
    // Trova la tessere da prelevare dalla mano del giocatore
    tessera *trovata = inserisci_indice(mano_giocatore, "posizionare");
    // Se il piano di gioco e' vuoto non richiedere la posizione nell'inserimento
    if (piano_gioco->successivo == NULL) {
        // Impostiamo come predefinito l'inserimento in testa
        aggiungi_tessera(mano_giocatore, piano_gioco, trovata, 1);
        return;
    }
    // Seleziona se inserire la tessera a sinistra/destra
    int posizione = inserisci_numero_compreso("Dove vuoi inserire la tessera? (0 per sx / 1 per dx): ", 0, 1);
    // Memorizza la tessera in testa/in coda per confrontarne l'estremo
    tessera *da_confrontare = trova_tessera(piano_gioco, posizione * piano_gioco->estremo_destro - 1);
    // Controlla che la mossa effettuata sia legale
    if (mossa_legale(trovata, posizione, da_confrontare) != 1) {
        printf("Mossa non legale, prova con un'altra tessera\n");
        return;
    }
    // Aggiungi la tessera alla posizione indicata
    aggiungi_tessera(mano_giocatore, piano_gioco, trovata, posizione);
}

tessera *inserisci_indice(tessera *mano_giocatore, char *azione) {
    // Messaggio da stampare a terminale
    char messaggio[50] = "Inserisci l'indice della tessera da ";
    // Inserisci un numero compreso tra 0 e l'indice dell'ultima tessera
    int indice_tessera = inserisci_numero_compreso(strcat(messaggio, azione), 0, mano_giocatore->estremo_destro - 1);
    // Restituisci la tessera trovata all'indice indicato
    return trova_tessera(mano_giocatore, indice_tessera);
}

int conta_punteggio(tessera *piano_gioco) {
    // Calcola il punteggio partendo dalla prima tessera sul piano di gioco
    tessera *corrente = piano_gioco->successivo;
    int punteggio = 0;
    // Continua finche' non raggiungi l'ultima
    while (corrente != NULL) {
        punteggio += corrente->estremo_destro + corrente->estremo_sinistro;
        corrente = corrente->successivo;
    }
    return punteggio;
}
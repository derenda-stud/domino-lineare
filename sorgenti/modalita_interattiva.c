#include "../librerie/modalita_interattiva.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../librerie/controlli.h"

void stampa_turno(tessera *mano_giocatore, tessera *piano_gioco) {
    // Continua finche' rimangono tessere in mano e siano disponibili mosse legali
    while (mano_giocatore->successivo != NULL && mosse_disponibili(mano_giocatore, piano_gioco)) {
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
            ruota_tessera(mano_giocatore, inserisci_indice(mano_giocatore, "Seleziona l'indice della tessera da ruotare"));
        } break;
    }
}

void seleziona_tessera(tessera *mano_giocatore, tessera *piano_gioco) {
    // Trova la tessere da prelevare dalla mano del giocatore
    tessera *trovata = inserisci_indice(mano_giocatore, "Seleziona l'indice della tessera da posizionare");
    // Se il piano di gioco e' vuoto non richiedere la posizione nell'inserimento
    if(piano_gioco->successivo == NULL) {
        // Impostiamo come predefinito l'inserimento in testa
        aggiungi_tessera(mano_giocatore, piano_gioco, trovata, 1);
        return;
    }
    // Seleziona se inserire la tessera a sinistra/destra
    int posizione = inserisci_numero_compreso("Dove vuoi inserire la tessera? (1 per sx / 2 per dx): ", 1, 2);
    // Controlla che la mossa effettuata sia legale
    if (!mossa_legale(trovata, posizione, piano_gioco)) {
        printf("Mossa non legale, prova con un'altra tessera\n");
        return;
    }
    // Aggiungi la tessera alla posizione indicata
    aggiungi_tessera(mano_giocatore, piano_gioco, trovata, posizione);
}

tessera *inserisci_indice(tessera *mano_giocatore, char *messaggio) {
    int indice_tessera = inserisci_numero_compreso(messaggio, 0, mano_giocatore->estremo_destro - 1);
    return trova_tessera(mano_giocatore, indice_tessera);
}

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

int conta_punteggio(tessera *piano_gioco) {
    tessera *corrente = piano_gioco->successivo;
    int punteggio = 0;
    while (corrente != NULL) {
        punteggio += corrente->estremo_destro + corrente->estremo_sinistro;
        corrente = corrente->successivo;
    }
    return punteggio;
}
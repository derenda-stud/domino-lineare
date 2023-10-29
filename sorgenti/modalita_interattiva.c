#include <stdio.h>
#include <stdlib.h>
#include "../librerie/controlli.h"
#include "../librerie/modalita_interattiva.h"

void turno_giocatore(tessera *mano_giocatore, tessera *piano_gioco, int numero_tessere) {
    // Continua finche' non rimangono tessere in mano
    // TODO: oppure quando non sono piu' disponibili mosse legali
    while(mano_giocatore->successivo != NULL) {
        // Chiedi all'utente se vuole posizionare/ruotare una tessera
        printf(" - Premi 1 per posizionare una tessera\n");
        printf(" - Premi 2 per ruotare una tessera\n");
        int scelta, indice_tessera, posizione;
        scelta = inserisci_numero_compreso("Seleziona un'opzione", 1, 2);
        switch(scelta) {
            // Seleziona una tessera
            case 1: {
                indice_tessera = inserisci_numero_compreso("Seleziona l'indice della tessera da posizionare", 0, numero_tessere - 1);
                // Trova la tessere da prelevare dalla mano del giocatore
                tessera *trovata = trova_tessera(mano_giocatore, indice_tessera);
                posizione = inserisci_numero_compreso("Dove vuoi inserire la tessera? (1 per sx / 2 per dx): ", 1, 2);
                if(mossa_legale(trovata, posizione, piano_gioco)) {
                    rimuovi_tessera(mano_giocatore, trovata);
                    // Aggiungi la tessera in base alla posizione selezionata
                    switch(posizione) {
                        case 1: {
                            inserimento_in_testa(piano_gioco, trovata);
                        } break;
                        case 2: {
                            inserimento_in_coda(piano_gioco, trovata);
                        } break;
                    }
                } else {
                    printf("Mossa non legale, prova con un'altra tessera\n");
                }
            } break;
            // Ruota una tessera
            case 2: {
                indice_tessera = inserisci_numero_compreso("Seleziona l'indice della tessera da ruotare", 0, numero_tessere - 1);    
                // Ruota la tessere presente ad un determinato indice
            } break;
        }
        // Stampa delle tessere presenti in entrambe le liste
        printf("Tessere sul piano di gioco:\n");
        stampa_tessere(piano_gioco);
        printf("Tessere nella mano del giocatore:\n");
        stampa_tessere(mano_giocatore);
    }
}
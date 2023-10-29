#include <stdio.h>
#include <stdlib.h>
#include "../librerie/controlli.h"
#include "../librerie/modalita_interattiva.h"

void turno_giocatore(tessera *mano_giocatore, tessera *piano_gioco, int numero_tessere) {
    // Continua finche' non rimangono tessere in mano
    // TODO: oppure quando non sono piu' disponibili mosse legali
    while(mano_giocatore->successivo != NULL) {
        // Chiedi all'utente l'indice della tessera da posizionare
        int indice_tessera = inserisci_indice_tessera(numero_tessere);
        // Trova la tessere da prelevare dalla mano del giocatore
        tessera *trovata = trova_tessera(mano_giocatore, indice_tessera);
        rimuovi_tessera(mano_giocatore, trovata);
        // Adesso aggiungi la tessera al piano di gioco
        inserimento_in_testa(piano_gioco, trovata);
        // Stampa delle tessere presenti in entrambe le liste
        printf("Tessere sul piano di gioco:\n");
        stampa_tessere(piano_gioco);
        printf("Tessere nella mano del giocatore:\n");
        stampa_tessere(mano_giocatore);
    }
}
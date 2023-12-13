#include "librerie/modalita_ai.h"

#include <stdio.h>
#include <stdlib.h>

tessera *first_match(tessera *mano_giocatore, tessera *piano_gioco, combinazione *risultato) {
    // Valore dentro cui memorizzare il risultato di mossa legale
    int corrispondenza;
    // Confronta che il valore degli estremi corrisponda con quella in testa e in coda
    for (int posizione = 0; posizione <= 1; posizione++) {
        // Comincia dalla prima tessera disponibile
        tessera *corrente = mano_giocatore->successivo;
        // Trova gli estremi della tessera da confrontare in base alla posizione
        tessera *da_confrontare = trova_tessera(piano_gioco, posizione * piano_gioco->estremo_destro - 1);
        while (corrente != NULL) {
            // Se ho trovato una corrispondenza
            if ((corrispondenza = mossa_legale(corrente, posizione, da_confrontare)) > 0) {
                // Memorizzo la posizione e la rotazione
                risultato->posizione = posizione;
                risultato->rotazione = corrispondenza - 1;
                // Ritorna l'indirizzo della tessera corrente
                return corrente;
            }
            // Continua con la tessera successiva
            corrente = corrente->successivo;
        }
    }
    // Non sono state trovate corrispondenze
    return NULL;
}

tessera *most_frequent(tessera *mano_giocatore, tessera *piano_gioco, combinazione *risultato) {
    // Valore dentro cui memorizzare il risultato di mossa legale
    int corrispondenza;
    // Array dentro cui salvare le frequenze di ciascun valore
    unsigned int *frequenze = calloc(6, sizeof(unsigned int));
    // Memorizza la tessera migliore
    tessera *migliore = NULL;
    // Confronta che il valore degli estremi corrisponda con quella in coda e in testa
    for (int posizione = 1; posizione >= 0; posizione--) {
        // Comincia dalla prima tessera disponibile
        tessera *corrente = mano_giocatore->successivo;
        // Trova gli estremi della tessera da confrontare in base alla posizione
        tessera *da_confrontare = trova_tessera(piano_gioco, posizione * piano_gioco->estremo_destro - 1);
        while (corrente != NULL) {
            // Se ho trovato una corrispondenza
            if ((corrispondenza = mossa_legale(corrente, posizione, da_confrontare)) > 0) {
                /* Incrementa la frequenza dell'indice pari ad estremo destro quando:
                    - inserisci in testa mantenendo l'ordine (0/1)
                    pos 0 rot 0 corr 1 -> dx
                    - inserisci in coda ruotando la tessera (1/0)
                    pos 1 rot 1 corr 2 -> dx
                */
                if(posizione == corrispondenza - 1) frequenze[corrente->estremo_destro - 1]++;
                /* Incrementa la frequenza con indice pari ad estremo sinistro quando:
                    - inserisci in testa ruotando la tessera (0/1)
                    pos 0 rot 1 corr 2 -> sx
                    - inserisci in coda mantenendo l'ordine (1/0)
                    pos 1 rot 0 corr 1 -> sx
                */
                else frequenze[corrente->estremo_sinistro - 1]++;
                // Se la tessera migliore e' nulla inizializzala
                // oppure valuta se sostituire la migliore in base alle frequenze delle tessere
                if(migliore == NULL || sostituisci_tessera(frequenze, corrente, migliore)) {
                    // Memorizza la nuova tessera migliore
                    migliore = corrente;
                    // Memorizzo la posizione e la rotazione
                    risultato->posizione = posizione;
                    risultato->rotazione = corrispondenza - 1;
                }
            }
            // Continua con la tessera successiva
            corrente = corrente->successivo;
        }
    }
    // Stampa frequenze
    printf("\n[ ");
    for(int i=0; i<6; i++) {
        printf("%d ", frequenze[i]);
    }
    printf("]\n");
    // Libera la memoria allocata
    free(frequenze);
    // Ritorna la miglior tessera trovata
    return migliore;
}

bool sostituisci_tessera(unsigned int *frequenze, tessera *corrente, tessera *migliore) {
    int frequenza_corrente = frequenze[corrente->estremo_sinistro - 1] + frequenze[corrente->estremo_destro - 1];
    int frequenza_massima = frequenze[corrente->estremo_sinistro - 1] + frequenze[corrente->estremo_destro - 1];
    // Se la tessera che sto confrontando ha minor frequenza non considerarla
    if(frequenza_corrente < frequenza_massima) return false;
    // A parita' di frequenze, confronta i valori delle tessere
    if(frequenza_corrente == frequenza_massima && 
        corrente->estremo_sinistro + corrente->estremo_destro < migliore->estremo_sinistro + migliore->estremo_destro) {
        // In quanto il valore della tessera e' minore lascio la precedente
        return false;
    }
    // La tessera migliore puo' essere sostituita
    return true;
}
#include "../lib/controlli.h"

#include <stdio.h>

int inserisci_numero_tessere() {
    int numero_tessere;
    printf("Inserisci il numero di tessere con cui vuoi giocare: ");
    do {
        scanf("%d", &numero_tessere);
        if (numero_tessere <= 0) {
            printf("Inserisci un numero valido: ");
        }
    } while (numero_tessere <= 0);
    return numero_tessere;
}

int inserisci_numero_compreso(char *messaggio, int minimo, int massimo) {
    int numero;
    printf("%s: ", messaggio);
    do {
        scanf("%d", &numero);
        if (numero < minimo || numero > massimo) {
            printf("Inserisci un numero valido: ");
        }
    } while (numero < minimo || numero > massimo);
    return numero;
}

int mossa_legale(tessera *da_posizionare, int posizione, tessera *da_confrontare) {
    // Quando il piano di gioco e' nullo non sono necessari controlli
    if (da_confrontare == NULL) return 1;
    // Se sono in possesso di una tessera speciale posso continuare la partita
    if(da_confrontare->speciale) {
        return 1; // Posiziona la tessera mantenendo l'ordine
    }
    // Confronta la tessera da inserire con quella in testa
    if (posizione == 0) {
        return estremi_corrispondono(da_posizionare->estremo_destro, da_posizionare->estremo_sinistro, da_confrontare->estremo_sinistro);
    }
    // Confronta la tessera in coda con quella da inserire
    return estremi_corrispondono(da_posizionare->estremo_sinistro, da_posizionare->estremo_destro, da_confrontare->estremo_destro);
}

bool mosse_disponibili(tessera *mano_giocatore, tessera *piano_gioco) {
    // Se sono rimaste delle tessere e il piano di gioco e' vuoto
    if (mano_giocatore->estremo_destro && piano_gioco->successivo == NULL) {
        // Non sono necessari controlli
        return true;
    }
    // Confronta che il valore degli estremi corrisponda in testa e in coda
    for (int posizione = 0; posizione <= 1; posizione++) {
        // Per ciascuna tessera nella mano del giocatore
        tessera *corrente = mano_giocatore->successivo;
        // Trova gli estremi della tessera da confrontare in base alla posizione
        tessera *da_confrontare = trova_tessera(piano_gioco, posizione * piano_gioco->estremo_destro - 1);
        while (corrente != NULL) {
            if (mossa_legale(corrente, posizione, da_confrontare)) {
                return true;
            }
            corrente = corrente->successivo;
        }
    }
    return false;
}

int estremi_corrispondono(int primo, int secondo, int estremo_piano) {
    // Restituisci 1 se la tessera combacia mantenendo l'ordine
    if (primo == estremo_piano) return 1;
    // Restituisci 2 se la tessera combacia girando l'ordine
    if (secondo == estremo_piano) return 2;
    // Restituisci 0 se la tessera non ha corrispondenza
    return 0;
}

void funzionalita_aggiuntive(tessera *da_posizionare, int posizione, tessera *da_confrontare, tessera *piano_gioco) {
    switch (da_posizionare->estremo_sinistro) {
        case 11: {
            // Incrementa tutti gli estremi sul piano di gioco
            incrementa_estremi(piano_gioco);
            // In testa memorizza l'estremo sinistro
            if (posizione == 0) {
                da_posizionare->estremo_sinistro = da_confrontare->estremo_sinistro;
                da_posizionare->estremo_destro = da_confrontare->estremo_sinistro;
                // In coda memorizza l'estremo destro
            } else {
                da_posizionare->estremo_sinistro = da_confrontare->estremo_destro;
                da_posizionare->estremo_destro = da_confrontare->estremo_destro;
            }
            break;
        }
        case 12: case 21: {
            // Specchia gli estremi della tessera da posizionare
            da_posizionare->estremo_sinistro = da_confrontare->estremo_destro;
            da_posizionare->estremo_destro = da_confrontare->estremo_sinistro;
            break;
        }
        // Per la tessera [0|0] non sono necessari controlli
    }
}
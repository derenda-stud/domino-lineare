#include "../librerie/controlli.h"

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


int mossa_legale(tessera *da_posizionare, int posizione, tessera *piano_gioco) {
    // In base alla posizione ritorna la prima [0] o ultima [1] tessera del piano di gioco
    tessera *da_confrontare = trova_tessera(piano_gioco, posizione * piano_gioco->estremo_destro - 1);
    // Confronta la tessera da inserire con quella in testa
    if(posizione == 0) {
        return estremi_corrispondono(da_posizionare->estremo_destro, da_posizionare->estremo_sinistro, da_confrontare->estremo_sinistro);
    }
    // Confronta la tessera in coda con quella da inserire
    return estremi_corrispondono(da_posizionare->estremo_sinistro, da_posizionare->estremo_destro, da_confrontare->estremo_destro);
}

tessera* mosse_disponibili(tessera *mano_giocatore, tessera *piano_gioco, combinazione *risultato) {
    // Quando il piano di gioco e' vuoto non sono necessari controlli
    if(piano_gioco->successivo == NULL) {
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
    while(corrente != NULL) {
        // Confronta che il valore degli estremi corrisponda con quella in testa e in coda
        for(int posizione = 0; posizione <= 1; posizione++) {
            // Se ho trovato una corrispondenza memorizzo la rotazione
            if((corrispondenza = mossa_legale(corrente, posizione, piano_gioco)) > 0) {
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

int estremi_corrispondono(int primo, int secondo, int estremo_piano) {
    if(primo == estremo_piano) return 1;
    if(secondo == estremo_piano) return 2;
    return 0;
}
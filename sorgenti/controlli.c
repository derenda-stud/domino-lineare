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

// Controlla che l'estremo della tessera da inserire combaci con quello sul piano di gioco
bool mossa_legale(tessera *da_inserire, int posizione, tessera *piano_gioco) {
    // [1] Confronta la tessera da inserire con quella in testa
    if(posizione == 1) {
        return da_inserire->estremo_destro == trova_tessera(piano_gioco, 0)->estremo_sinistro;
    }
    // [2] Confronta la tessera in coda con quella da inserire
    return trova_tessera(piano_gioco, piano_gioco->estremo_destro - 1)->estremo_destro == da_inserire->estremo_sinistro;
}

bool mosse_disponibili(tessera *mano_giocatore, tessera *piano_gioco) {
    // Quando il piano di gioco e' vuoto non sono necessari controlli
    if(piano_gioco->successivo == NULL) {
        return true;
    }
    // Memorizza gli estremi delle tessere in testa e in coda
    int estremo_in_testa = trova_tessera(piano_gioco, 0)->estremo_sinistro;
    int estremo_in_coda = trova_tessera(piano_gioco, piano_gioco->estremo_destro - 1)->estremo_destro;
    // Per ciascuna tessera nella mano del giocatore
    tessera *corrente = mano_giocatore->successivo;
    while(corrente != NULL) {
        // Confronta che il valore degli estremi corrisponda con quella in testa e in coda
        if(estremi_corrispondono(corrente, estremo_in_testa) || estremi_corrispondono(corrente, estremo_in_coda)) {
            return true;
        }
        // Continua con la tessera successiva
        corrente = corrente->successivo;
    }
    // Non sono state trovate corrispondenze
    return false;
}

bool estremi_corrispondono(tessera *selezionata, int valore) {
    return (selezionata->estremo_sinistro == valore || selezionata->estremo_destro == valore);
}
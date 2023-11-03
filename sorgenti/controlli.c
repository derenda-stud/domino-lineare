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
    // Quando il piano di gioco e' vuoto non sono necessari controlli
    if(piano_gioco->successivo == NULL) {
        return true;
    }
    // [1] Confronta la tessera da interire con quella in testa
    if(posizione == 1) {
        return da_inserire->estremo_destro == trova_tessera(piano_gioco, 0)->estremo_sinistro;
    }
    // [2] Confronta la tessera in coda con quella da inserire
    return trova_tessera(piano_gioco, piano_gioco->estremo_destro - 1)->estremo_destro == da_inserire->estremo_sinistro;
}
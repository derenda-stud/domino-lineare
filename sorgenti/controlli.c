#include <stdio.h>
#include "../librerie/controlli.h"

int inserisci_numero_tessere() {
    int numero_tessere;
    printf("Inserisci il numero di tessere con cui vuoi giocare: ");
    do {
        scanf("%d", &numero_tessere);
        if(numero_tessere <= 0) {
            printf("Inserisci un numero valido: ");
        }
    } while(numero_tessere <= 0);
    return numero_tessere;
}

int inserisci_numero_compreso(char* messaggio, int minimo, int massimo) {
    int numero;
    printf("%s: ", messaggio);
    do {
        scanf("%d", &numero);
        if(numero < minimo || numero > massimo) {
            printf("Inserisci un numero valido: ");
        }
    } while(numero < minimo || numero > massimo);
    return numero;
}

bool mossa_legale(tessera *trovata, int posizione, tessera *piano_gioco) {
    /* In base alla posizione, controlla:
        - 1 (sx) --> trovata->estremo_dx = testa->estremo_sx
        - 2 (dx) --> coda->estremo_sx = trovata->estremo_sx
    */
    return true;
}
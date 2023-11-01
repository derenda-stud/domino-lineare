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

/*trovata => tessera da inserire
  posizione => [1] sx, [2] dx
  piano_gioco => lista tessere all'interno del piano di gioco.
  n_tessere_piano => numero delle tessere presenti nel piano di gioco.*/
bool mossa_legale(tessera *trovata, int posizione, tessera *piano_gioco) {
    /* In base alla posizione, controlla:
        - 1 (sx) --> trovata->estremo_dx = testa->estremo_sx
        - 2 (dx) --> coda->estremo_sx = trovata->estremo_sx
    */
    tessera *posizionata = piano_gioco->successivo;
    // Quando il piano di gioco e' vuoto non sono necessari controlli
    if(posizionata == NULL) {
        return true;
    }
    if (posizione == 1) {
        return posizionata->estremo_sinistro == trovata->estremo_destro ? true : false;
    } else {
        while (posizionata->successivo != NULL) {
            posizionata = posizionata->successivo;
        }
        return posizionata->estremo_destro == trovata->estremo_sinistro ? true : false;
    }
}
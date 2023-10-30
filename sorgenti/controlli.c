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


/*trovata => tessera da inserire
  posizione => [1] sx, [2] dx
  piano_gioco => lista tessere all'interno del piano di gioco.
  n_tessere_piano => numero delle tessere presenti nel piano di gioco.*/
bool mossa_legale(tessera *trovata, int posizione, tessera *piano_gioco, int *n_tessere_piano) {
    /* In base alla posizione, controlla:
        - 1 (sx) --> trovata->estremo_dx = testa->estremo_sx
        - 2 (dx) --> coda->estremo_sx = trovata->estremo_sx
    */
   tessera *posizionata = piano_gioco->successivo;
    if(posizione == 1 && *n_tessere_piano != 0) {
            return posizionata->estremo_sinistro == trovata->estremo_destro ? true : false;
    } else if(posizione == 2 && *n_tessere_piano != 0) {
        for(int i = 0; i < *n_tessere_piano; i++){
            posizionata = posizionata->successivo;
        }
        return posizionata->estremo_destro == trovata->estremo_sinistro ? true : false;
    } else {
        return true;
    }
}
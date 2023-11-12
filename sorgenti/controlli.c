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
    tessera da_controllare;
    if(piano_gioco->estremo_destro == 1) da_controllare = *piano_gioco->successivo;
    else{
        da_controllare.estremo_sinistro = trova_tessera(piano_gioco, 0)->estremo_sinistro;
        da_controllare.estremo_destro = trova_tessera(piano_gioco, piano_gioco->estremo_destro - 1)->estremo_destro;
    }
    tessera *corrente = mano_giocatore->successivo;
    while(corrente != NULL) {
        if(estremi_corrispondono(corrente, da_controllare) != 0) return true;
        // Continua con la tessera successiva
        corrente = corrente->successivo;
    }
    // Non sono state trovate corrispondenze
    return false;
}

/* cod -> xy    [x-> 1 testa | 2 coda]  [y-> 0 normale | 1 ruota]   [0-> nessun estremo corrisponde in alcuna combinazione]
   [1|3]   [3|6] -> 10  inserimento in testa
   [6|1]   [3|6] -> 20  inserimento in coda
   
   [3|1]   [3|6] -> 11  inserimento in testa (tessera ruotata)
   [1|6]   [3|6] -> 21  inserimento in coda (tessera ruotata)*/
int estremi_corrispondono(tessera *selezionata, tessera da_controllare) {
    if (selezionata->estremo_destro == da_controllare.estremo_sinistro) return 10;
    else if (selezionata->estremo_sinistro == da_controllare.estremo_destro) return 20;
    else if (selezionata->estremo_sinistro == da_controllare.estremo_sinistro) return 11;
    else if (selezionata->estremo_destro == da_controllare.estremo_destro) return 21;
    else return 0;
}
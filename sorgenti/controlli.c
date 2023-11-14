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
    // In base alla posizione ritorna la prima [1] o ultima [2] tessera del piano di gioco
    tessera *da_confrontare = trova_tessera(piano_gioco, (posizione - 1) * piano_gioco->estremo_destro - 1);
    switch(posizione) {
        // Confronta la tessera da inserire con quella in testa
        case 1: {
            return estremi_corrispondono(da_posizionare->estremo_destro, da_posizionare->estremo_sinistro, da_confrontare->estremo_sinistro);
        } break;
        // Confronta la tessera in coda con quella da inserire
        case 2: {
            return estremi_corrispondono(da_posizionare->estremo_sinistro, da_posizionare->estremo_destro, da_confrontare->estremo_destro);
        } break;
    }
    return 0;
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
        if(estremi_corrispondono(estremo_in_coda, estremo_in_testa, corrente->estremo_sinistro) ||
           estremi_corrispondono(estremo_in_testa, estremo_in_coda, corrente->estremo_destro)) {
            return true;
        }
        // Continua con la tessera successiva
        corrente = corrente->successivo;
    }
    // Non sono state trovate corrispondenze
    return false;
}

/*
posizione -> rotazione
combinazioni: 0 / 1 / 2
ma controllo per entrambe posizioni (6 cifre)

[3...|....|...6] piano
     [1|6]       da posizionare
in testa -> no ruotare: 6 == 3 X <-- 1 dx = primo
	        si ruotare: 1 == 3 V <-- 2 sx = secondo
				  0 altrimenti
in coda  -> no ruotare: 1 == 6 X <-- 1 sx = primo
	        si ruotare: 6 == 6 V <-- 2 dx = secondo
				  0 altrimenti
*/
int estremi_corrispondono(int primo, int secondo, int estremo_piano) {
    if(primo == estremo_piano) return 1;
    if(secondo == estremo_piano) return 2;
    return 0;
}
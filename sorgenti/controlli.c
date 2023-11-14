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
}

/*  x-> rotazione y -> posizione
                 -> 00 nessun inserimento
   [1|3]   [3|6] -> 11 inserimento in testa
   [6|1]   [3|6] -> 12 inserimento in coda
   
   [3|1]   [3|6] -> 21  inserimento in testa (tessera ruotata)
   [1|6]   [3|6] -> 22  inserimento in coda (tessera ruotata)
*/
int mosse_disponibili(tessera *mano_giocatore, tessera *piano_gioco) {
    // Quando il piano di gioco e' vuoto non sono necessari controlli
    if(piano_gioco->successivo == NULL) {
        return 01;
    }
    // Per ciascuna tessera nella mano del giocatore
    tessera *corrente = mano_giocatore->successivo;
    while(corrente != NULL) {
        // Confronta che sia possibile effettuare una mossa valida inserendo in testa o in coda
        //for 1 o 2, legale 0 -> 0. legale 1 -> [0][pos], legale 2 -> [1][pos]
        // se pos 1 e legale 1 allora return 01, altrimenti se pos 1 e legale 2 02
        for(int posizione=1; posizione<=2; posizione++) {
            int risultato = mossa_legale(corrente, posizione, piano_gioco);
            if(risultato != 0) {
                return risultato * 10 + posizione;
            }
        }
        // Continua con la tessera successiva
        corrente = corrente->successivo;
    }
    // Non sono state trovate corrispondenze
    return 0;
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
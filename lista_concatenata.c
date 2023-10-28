// #include e definizioni di funzione
#include<stdio.h>
#include<stdlib.h>
#include"lista_concatenata.h"

void genera_tessere(tessera **testa, int dimensione) {
    // Per ciascuna tessera del domino
    for(int i=0; i<dimensione; i++) {
        // Genera due numeri casuali per ciasun estremo della tessera
        int casuale_sinistro = rand() % 6 + 1;
        int casuale_destro = rand() % 6 + 1;
        printf("Ho generato %d %d\n", casuale_sinistro, casuale_destro);
        // Aggiungi una nuova tessera
        tessera* nuova = crea_tessera(casuale_sinistro, casuale_destro);
        inserimento_in_coda(testa, nuova);
        printf("Valori in testa: %d %d\n", (*testa)->estremo_sinistro, (*testa)->estremo_destro);
    }
}

tessera* crea_tessera(int estremo_sinistro, int estremo_destro) {
    // Creazione della tessera con allocazione dinamica della memoria
    tessera *nuova_tessera = malloc(sizeof(tessera));
    // Imposta come valori della tessera quelli passati dal chiamante
    nuova_tessera->estremo_sinistro = estremo_sinistro;
    nuova_tessera->estremo_destro = estremo_destro;
    // Inizializzo il valore del puntatore successivo
    nuova_tessera->successivo = NULL;
    printf("I valori salvati nella nuova tessera sono: %d %d\n", nuova_tessera->estremo_sinistro, nuova_tessera->estremo_destro);
    // Ritorna il puntatore della nuova tessera creata
    return nuova_tessera;
}

void inserimento_in_testa(tessera **testa, tessera *da_inserire) {
    // Aggiungi la tessera in testa
    da_inserire->successivo = *testa;
    // Aggiorna il puntatore della testa
    *testa = da_inserire;
    printf("Ho salvato: %d %d\n", (*testa)->estremo_sinistro, (*testa)->estremo_destro);
}

void inserimento_in_coda(tessera **testa, tessera *da_inserire) {
    // Arrivato alla fine della lista e' necessario conoscere il precedente
    tessera *precedente;
    // Scorri la lista usando il nodo corrente
    tessera *corrente = *testa;
    while(corrente != NULL) {
        precedente = corrente;
        printf("Valori in nodo precedente: %d %d\n", precedente->estremo_sinistro, precedente->estremo_destro);
        corrente = corrente->successivo;
        printf("Sono andato al successivo\n");
    }
    // Se non sono ancora presenti tessere nella lista 
    if(*testa == NULL) {
        printf("Assegno la testa\n");
        // Inserisci il nodo come testa
        *testa = da_inserire;
    } else {
        printf("Inserisco in coda\n");
        // Altrimenti inseriscilo in coda alla lista
        precedente->successivo = da_inserire;
    }
}

void stampa_tessere(tessera *testa) {
    printf("Le tessere assegnate sono le seguenti:\n");
    // Tieni traccia del nodo corrente
    tessera *corrente = testa;
    // Finche' non raggiungi la fine della lista
    while(corrente != NULL) {
        // Stampa la tessera corrente
        printf("[%d|%d] ", corrente->estremo_sinistro, corrente->estremo_destro);
        // Continua con la tessera successiva
        corrente = corrente->successivo;
    }
    printf("\n");
    // Ricomincia dalla testa per stampare gli indici
    corrente = testa;
    // Tieni traccia del numero di tessere presenti nella lista
    for(int indice_tessera=0; corrente != NULL; indice_tessera++) {
        printf("  %d   ", indice_tessera);
        // Continua con la tessera successiva
        corrente = corrente->successivo;
    }
    printf("\n");
}

/*
void stampa_tessere(tessera *tessere, int dimensione) {
    printf("Le tessere assegnate sono le seguenti:\n");
    for(int i=0; i<dimensione; i++) {
        // Stampa le tessere in riga
        printf("[%d|%d] ", tessere[i].estremo_sinistro, tessere[i].estremo_destro);
    }
    printf("\n");
    for(int i=0; i<dimensione; i++) {
        // Stampa indice corrispondente a ciascuna tessera
        printf("  %d   ", i);
    }
    printf("\n");
}
*/
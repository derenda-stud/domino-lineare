// #include e definizioni di funzione
#include <stdio.h>
#include <stdlib.h>
#include "../librerie/lista_concatenata.h"

void genera_tessere(tessera **testa, int dimensione) {
    // Per ciascuna tessera del domino
    for(int i=0; i<dimensione; i++) {
        // Genera due numeri casuali per ciasun estremo della tessera
        int casuale_sinistro = rand() % 6 + 1;
        int casuale_destro = rand() % 6 + 1;
        // Aggiungi una nuova tessera
        tessera* nuova = crea_tessera(casuale_sinistro, casuale_destro);
        inserimento_in_coda(testa, nuova);
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
    // Ritorna il puntatore della nuova tessera creata
    return nuova_tessera;
}

void inserimento_in_testa(tessera **testa, tessera *da_inserire) {
    // Aggiungi la tessera in testa
    da_inserire->successivo = *testa;
    // Aggiorna il puntatore della testa
    *testa = da_inserire;
}

void inserimento_in_coda(tessera **testa, tessera *da_inserire) {
    // Arrivato alla fine della lista e' necessario conoscere il precedente
    tessera *precedente;
    // Scorri la lista usando il nodo corrente
    tessera *corrente = *testa;
    while(corrente != NULL) {
        precedente = corrente;
        corrente = corrente->successivo;
    }
    // Se non sono ancora presenti tessere nella lista 
    if(*testa == NULL) {
        // Inserisci il nodo come testa
        *testa = da_inserire;
    } else {
        // Altrimenti inseriscilo in coda alla lista
        precedente->successivo = da_inserire;
    }
}

void stampa_tessere(tessera *testa) {
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

tessera* trova_tessera(tessera *testa, int indice_tessera){
    tessera *corrente = testa;
    for(int i = 0; i < indice_tessera; i++){
        corrente = corrente->successivo;
    }
    return corrente;
}

void rimuovi_tessera(tessera **testa, tessera *da_rimuovere) {
    // Inizializzo entrambi i puntatori alla prima tessera della lista
    tessera *precedente = *testa;
    tessera *corrente = *testa;
    while(corrente != da_rimuovere){
        precedente = corrente;
        corrente = corrente->successivo;
    }
    // Se devi rimuovere la prima tessera
    if(precedente == corrente) {
        // La testa viene spostata alla tessera successiva
        *testa = precedente->successivo;
    } else {
        // Altrimenti salta fino alla successiva
        precedente->successivo = corrente->successivo;
    }
    // La tessera da rimuovere e' ancora dentro la memoria dinamica
    // Inizializzo il suo puntatore successivo
    da_rimuovere->successivo = NULL;
}
// #include e definizioni di funzione
#include "../librerie/lista_concatenata.h"

#include <stdio.h>
#include <stdlib.h>

void genera_tessere(tessera *sentinella, int dimensione) {
    // Per ciascuna tessera del domino
    for (int i = 0; i < dimensione; i++) {
        // Genera due numeri casuali per ciasun estremo della tessera
        int casuale_sinistro = rand() % 6 + 1;
        int casuale_destro = rand() % 6 + 1;
        // Aggiungi una nuova tessera
        tessera *nuova = crea_tessera(casuale_sinistro, casuale_destro);
        inserimento_in_coda(sentinella, nuova);
    }
}

tessera *crea_tessera(int estremo_sinistro, int estremo_destro) {
    // Creazione della tessera con allocazione dinamica della memoria
    tessera *nuova_tessera = malloc(sizeof(tessera));
    // Imposta come valori della tessera quelli passati dal chiamante
    nuova_tessera->estremo_sinistro = estremo_sinistro;
    nuova_tessera->estremo_destro = estremo_destro;
    // Inizializzo il valore del puntatore successivo
    nuova_tessera->successivo = NULL;
    // Ritorna il puntatore della tessera appena creata
    return nuova_tessera;
}

void inserimento_in_testa(tessera *sentinella, tessera *da_inserire) {
    // Imposta il puntatore successivo alla prima tessera corrente
    da_inserire->successivo = sentinella->successivo;
    // Aggiorna la tessera in testa
    sentinella->successivo = da_inserire;
}

void inserimento_in_coda(tessera *sentinella, tessera *da_inserire) {
    // Il nodo precedente e' usato nella fase di assegnamento
    tessera *precedente = sentinella;
    // Scorri la lista usando il nodo corrente
    tessera *corrente = sentinella;
    while (corrente != NULL) {
        precedente = corrente;
        corrente = corrente->successivo;
    }
    // Inserisci la tessera in coda alla lista
    precedente->successivo = da_inserire;
}

void stampa_tessere(tessera *sentinella) {
    // Tieni traccia del nodo corrente
    tessera *corrente = sentinella->successivo;
    // Finche' non raggiungi la fine della lista
    while (corrente != NULL) {
        // Stampa la tessera corrente
        printf("[%d|%d] ", corrente->estremo_sinistro, corrente->estremo_destro);
        // Continua con la tessera successiva
        corrente = corrente->successivo;
    }
    printf("\n");
    // Ricomincia dalla testa per stampare gli indici
    corrente = sentinella->successivo;
    // Tieni traccia del numero di tessere presenti nella lista
    for (int indice_tessera = 0; corrente != NULL; indice_tessera++) {
        printf("  %d   ", indice_tessera);
        // Continua con la tessera successiva
        corrente = corrente->successivo;
    }
    printf("\n");
}

tessera *trova_tessera(tessera *sentinella, int indice_tessera) {
    // Inizializza il valore della prima tessera valida
    tessera *da_trovare = sentinella->successivo;
    // Continua finche' non raggiungi l'indice richiesto
    for (int i = 0; i < indice_tessera; i++) {
        da_trovare = da_trovare->successivo;
    }
    // Ritorna la tessera trovata
    return da_trovare;
}

void rimuovi_tessera(tessera *sentinella, tessera *da_rimuovere) {
    // Inizializzo entrambi i puntatori alla tessera sentinella
    tessera *precedente = sentinella;
    tessera *corrente = sentinella;
    // Scorri la lista finche' non raggiungi la tessera da rimuovere
    while (corrente != da_rimuovere) {
        precedente = corrente;
        corrente = corrente->successivo;
    }
    // Per rimuoverla, collega la precedente con la successiva
    precedente->successivo = corrente->successivo;
    // NOTA: La tessera da rimuovere e' ancora dentro la memoria dinamica
    // Inizializzo il suo puntatore successivo
    da_rimuovere->successivo = NULL;
}

void ruota_tessera(tessera *sentinella, tessera *da_ruotare) {
    // Scambia il valore dei due estremi della tessera
    int temp = da_ruotare->estremo_destro;
    da_ruotare->estremo_destro = da_ruotare->estremo_sinistro;
    da_ruotare->estremo_sinistro = temp;
}
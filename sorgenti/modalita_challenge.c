#include <stdio.h>

#include "../librerie/modalita_challenge.h"

tessera *inserimento_parametri() {
    // Richiedi il numero di tessere con cui giocare
    int numero_tessere;
    scanf("%d", &numero_tessere);
    // Crea il nodo sentinello che tiene conto nel numero di tessere
    tessera *sentinella = crea_tessera(numero_tessere, numero_tessere);
    // Per ciascuna tessera prendi da input gli estremi
    int estremo_sinistro, estremo_destro;
    for(int i=0; i<numero_tessere; i++) {
        scanf("%d %d", &estremo_sinistro, &estremo_destro);
        // Inseriscila in coda alla lista
        inserimento_in_coda(sentinella, crea_tessera(estremo_sinistro, estremo_destro));
    }
    // Restituisci il puntatore alla sentinella
    return sentinella;
}
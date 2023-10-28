#include <stdio.h>
#include "controlli.h"

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

int inserisci_indice_tessera(int dimensione) {
    int indice;
    printf("Seleziona l'indice della tessera da posizionare: ");
    do {
        scanf("%d", &indice);
        if(indice < 0 || indice >= dimensione) {
            printf("Seleziona un indice valido: ");
        }
    } while(indice < 0 || indice >= dimensione);
    return indice;
}
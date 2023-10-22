#ifndef lista_concatenata_h
#define lista_concatenata_h

typedef struct {
    int estremo_sinistro;
    int estremo_destro;
    struct tessera *successivo;
} tessera;

// Prototipi di funzione
void genera_tessere(tessera *tessere, int dimensione);
void stampa_tessere(tessera *tessere, int dimensione);

#endif
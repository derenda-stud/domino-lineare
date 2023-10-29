#ifndef lista_concatenata_h
#define lista_concatenata_h

typedef struct struct_tessera {
    int estremo_sinistro;
    int estremo_destro;
    struct struct_tessera *successivo;
} tessera;

// Genera delle tessere dai valori casuali dopo l'inserimento dell'utente
void genera_tessere(tessera *sentinella, int dimensione);
// Crea una nuova tessera assegnando una locazione nella memoria dinamica
tessera* crea_tessera(int estremo_sinistro, int estremo_destro);
// Inserisci una nuova tessera in testa alla lista
void inserimento_in_testa(tessera *sentinella, tessera *da_inserire);
// Inserisci una nuova tessera in coda alla lista
void inserimento_in_coda(tessera *sentinella, tessera *da_inserire);
// Stampa tutte le tessere con i corrispettivi valori
void stampa_tessere(tessera *sentinella);
// Restituisci la tessera di una lista presente ad un certo indice
tessera* trova_tessera(tessera *sentinella, int indice_tessera);
// Rimuovi una tessera dalla lista
void rimuovi_tessera(tessera *sentinella, tessera *da_rimuovere);

#endif
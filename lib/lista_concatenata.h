#ifndef lista_concatenata_h
#define lista_concatenata_h

#include <stdbool.h>

typedef struct struct_tessera {
    int estremo_sinistro;
    int estremo_destro;
    bool speciale;
    struct struct_tessera *successivo;
} tessera;

// Genera delle tessere dai valori casuali dopo l'inserimento dell'utente
void genera_tessere(tessera *sentinella, int dimensione);
// Crea una nuova tessera assegnando una locazione nella memoria dinamica
tessera *crea_tessera(int estremo_sinistro, int estremo_destro, bool speciale);
// Inserisci una nuova tessera in testa alla lista
void inserimento_in_testa(tessera *sentinella, tessera *da_inserire);
// Inserisci una nuova tessera in coda alla lista
void inserimento_in_coda(tessera *sentinella, tessera *da_inserire);
// Stampa tutte le tessere con i corrispettivi valori
void stampa_tessere(tessera *sentinella);
// Restituisci la tessera di una lista presente ad un certo indice
tessera *trova_tessera(tessera *sentinella, int indice_tessera);
// Rimuovi una tessera dalla lista
void rimuovi_tessera(tessera *sentinella, tessera *da_rimuovere);
// Ruota la tessera nella mano del giocatore
void ruota_tessera(tessera *da_ruotare);
// Preleva la tessera dalla mano del giocatore ed inseriscila nel piano di gioco
void aggiungi_tessera(tessera *mano_giocatore, tessera *piano_gioco, tessera *trovata, int posizione);
// Incrementa tutti gli estremi delle tessere presenti sul piano di gioco
void incrementa_estremi(tessera *piano_gioco);

#endif
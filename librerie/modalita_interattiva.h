#ifndef modalita_interattiva_h
#define modalita_interattiva_h

#include "lista_concatenata.h"

// Stampa delle informazioni visualizzate durante il turno del giocatore
void stampa_turno(tessera *mano_giocatore, tessera *piano_gioco);
// Menu che permette di inserire la prossima mossa da effettuare
void inserisci_scelta(tessera *mano_giocatore, tessera *piano_gioco);
// Seleziona la posizione della nuova tessera da inserire
void seleziona_tessera(tessera *mano_giocatore, tessera *piano_gioco);
// Ritorna la tessera presente ad un particolare indice
tessera *inserisci_indice(tessera *mano_giocatore, char *azione);
// Preleva la tessera dalla mano del giocatore ed inseriscila nel piano di gioco
void aggiungi_tessera(tessera *mano_giocatore, tessera *piano_gioco, tessera *trovata, int posizione);
// Calcola il punteggio alla fine della partita
int conta_punteggio(tessera *piano_gioco);

#endif
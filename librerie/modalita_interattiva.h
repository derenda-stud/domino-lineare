#ifndef modalita_interattiva_h
#define modalita_interattiva_h

#include "lista_concatenata.h"

// Menu principale per la modalita' interattiva
void turno_giocatore(tessera *mano_giocatore, tessera *piano_gioco);
// Calcola il punteggio alla fine della partita
int conta_punteggio(tessera *piano_gioco);

#endif
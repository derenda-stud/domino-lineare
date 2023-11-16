#ifndef modalita_challenge_h
#define modalita_challenge_h

#include "lista_concatenata.h"

// Inserimento delle tessere da terminale
tessera *inserimento_parametri();
// Esecuzione del migliore algoritmo AI per produrre la sequenza in uscita
void esegui_algoritmo(tessera *mano_giocatore, tessera *piano_gioco);

#endif
#ifndef modalita_interattiva_h
#define modalita_interattiva_h
#include "lista_concatenata.h"

void turno_giocatore(tessera *mano_giocatore, tessera *piano_gioco, int numero_tessere, int *n_tessere_piano);
//conta i punti effettuati dal giocatore
int conta_punteggio(int *n_tessere_piano, tessera *piano_gioco);

#endif
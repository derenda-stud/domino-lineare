#ifndef modalita_interattiva_h
#define modalita_interattiva_h
#include "lista_concatenata.h"

void turno_giocatore(tessera *mano_giocatore, tessera *piano_gioco, int numero_tessere);
//conta i punti effettuati dal giocatore
int conta_punteggio(tessera *piano_gioco);

#endif
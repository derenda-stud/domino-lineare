#ifndef modalita_ai_h
#define modalita_ai_h

#include "controlli.h"
#include "lista_concatenata.h"

// Restituisci la prima tessera con una corrispondenza
tessera *first_match(tessera *mano_giocatore, tessera *piano_gioco, combinazione *risultato);
// Restituisci la tessera i cui valori compaiono piu' volte
tessera *most_frequent(tessera *mano_giocatore, tessera *piano_gioco, combinazione *risultato);
// Confronta le frequenze di due tessere per valutare se sostituire la migliore
bool sostituisci_tessera(unsigned int *frequenze, tessera *corrente, tessera *migliore);

#endif
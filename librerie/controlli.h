#ifndef controlli_h
#define controlli_h

#include <stdbool.h>
#include "lista_concatenata.h"

// Chiedi all'utente il numero di tessere con cui vuole giocare
int inserisci_numero_tessere();
// Chiedi all'utente un numero compreso tra due estremi massimo
int inserisci_numero_compreso(char* messaggio, int minimo, int massimo);
// Controlla che sia stata selezionata una mossa legale
bool mossa_legale(tessera *trovata, int posizione, tessera *piano_gioco);

#endif
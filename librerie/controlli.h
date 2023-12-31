#ifndef controlli_h
#define controlli_h

#include <stdbool.h>

#include "lista_concatenata.h"

typedef struct struct_combinazione {
    bool posizione;
    bool rotazione;
} combinazione;

// Chiedi all'utente il numero di tessere con cui vuole giocare
int inserisci_numero_tessere();
// Chiedi all'utente un numero compreso tra due estremi massimo
int inserisci_numero_compreso(char *messaggio, int minimo, int massimo);
// Controlla che l'estremo della tessera da inserire combaci con quello sul piano di gioco
int mossa_legale(tessera *da_posizionare, int posizione, tessera *piano_gioco);
// Controlla se sono rimaste mosse disponibili
bool mosse_disponibili(tessera *mano_giocatore, tessera *piano_gioco);
// Confronta gli estremi della tessera selezionata con un determinato valore
int estremi_corrispondono(int primo, int secondo, int estremo_piano);

#endif
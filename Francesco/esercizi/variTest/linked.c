#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del nodo
typedef struct Nodo {
    int valore;
    struct Nodo* prossimo;
} Nodo;

// Funzione per creare un nuovo nodo
Nodo* creaNodo(int valore) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->valore = valore;
    nuovoNodo->prossimo = NULL;
    return nuovoNodo;
}

// Funzione per inserire un nuovo nodo in testa alla lista
void inserisciInTesta(Nodo** testa, int valore) {
    Nodo* nuovoNodo = creaNodo(valore);
    nuovoNodo->prossimo = *testa;
    *testa = nuovoNodo;
}

// Funzione per stampare la lista
void stampaLista(Nodo* testa) {
    Nodo* nodoCorrente = testa;
    while (nodoCorrente != NULL) {
        printf("%d ", nodoCorrente->valore);
        nodoCorrente = nodoCorrente->prossimo;
    }
    printf("\n");
}

int main() {
    Nodo* testa = NULL;

    inserisciInTesta(&testa, 3);
    inserisciInTesta(&testa, 7);
    inserisciInTesta(&testa, 1);

    printf("Lista: ");
    stampaLista(testa);

    return 0;
}
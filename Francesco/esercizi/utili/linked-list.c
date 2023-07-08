// Creazione di una linked list vuota.
// Chiedi all'utente di inserire una serie di numeri interi. Ogni numero inserito deve essere inserito come nuovo nodo nella linked list.
// Stampa la linked list.
// Calcola e stampa la somma di tutti i numeri presenti nella linked list.
// Calcola e stampa il valore medio dei numeri presenti nella linked list.

#include <stdio.h>
#include <stdlib.h>

// Creo la struct di come sara strutturata la linked list (listaPokemon)
typedef struct listaPokemon
{
    int idPokemon;
    // Serve per creare e inizalizzare la lista concatenata
    struct listaPokemon * next;
} listaPokemon;

// Serve per creare la nuova lista 
listaPokemon *assegnaPokemon(int idPokemon){
    // Alloca dinamicamente la variabile puntatore listaPokemon *nuovaListaPokemon
    listaPokemon *nuovaListaPokemon = (listaPokemon*)malloc(sizeof(listaPokemon));
    // Assegnazione parametri
    nuovaListaPokemon->idPokemon = idPokemon;
    nuovaListaPokemon->next = NULL;
    return nuovaListaPokemon;
}

// Inserisci il pokemon in testa alla lista
// ** doppio pointer dunque devere colelgato ad un pointer
void inserisciPokem(listaPokemon **head, int idPokemon) {
    // Si crea la lista da aggiungere in head
    listaPokemon *nuovaListaPokemon = assegnaPokemon(idPokemon);
    nuovaListaPokemon->next = *head;
    *head = nuovaListaPokemon;
}

// Funzione per stampare la lista
void stampaListaPokemon(listaPokemon *head){
    listaPokemon *position = head;

    while (position != NULL){
        printf("%d\n",position->idPokemon);
        position = position->next;
    }
}

int main(void){
    listaPokemon *head = NULL;
    int idPokemon1 = 123;
    int idPokemon2 = 234;

    inserisciPokem(&head, idPokemon1);
    inserisciPokem(&head, idPokemon2);
    
    stampaListaPokemon(head);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxNomeCognome 70
#define maxIdCliente 12
#define maxPiatti 15

typedef struct Piatto{
    char idPiatto;
    int nPorzioni;
}Piatto;

typedef struct listaPrenotazione
{
    char nomeCognome[maxNomeCognome];
    char idCliente[maxIdCliente];
    char dataOrdine;
    Piatto piatti[maxPiatti];
    struct listaPrenotazione *next;
} listaPrenotazione;

// Serve per creare la nuova lista 
listaPrenotazione *creaLista(char nomeCognome[maxNomeCognome], char idCliente[maxIdCliente], char dataOrdine,Piatto piatti[15]){
    // Alloca dinamicamente la variabile puntatore listaPokemon *nuovaListaPokemon
    listaPrenotazione *nuovaListaPrenotazione = (listaPrenotazione*)malloc(sizeof(listaPrenotazione));
    // Assegnazione parametri
    strcpy(nuovaListaPrenotazione->nomeCognome, nomeCognome);
    strcpy(nuovaListaPrenotazione->idCliente, idCliente);
    memcpy(nuovaListaPrenotazione->piatti, piatti, sizeof(Piatto) * maxPiatti);
    nuovaListaPrenotazione->dataOrdine = dataOrdine;
    nuovaListaPrenotazione->next = NULL;

    return nuovaListaPrenotazione;
}


void popolaLista(listaPrenotazione **head, char nomeCognome[maxNomeCognome], char idCliente[maxIdCliente], char dataOrdine, Piatto piatti[15]) {
    // Si crea la lista da aggiungere in head
    listaPrenotazione *nuovaListaPrenotazioni = creaLista(nomeCognome,idCliente,dataOrdine,piatti);
    nuovaListaPrenotazioni->next = *head;
    *head = nuovaListaPrenotazioni;
}


// // Funzione per stampare la lista
void stampaListaPrenotazioni(listaPrenotazione *head){
    listaPrenotazione *position = head;

    while (position != NULL){
        printf("%c\n",position->nomeCognome);
        printf("%c\n",position->idCliente);
        // printf("%d\n",position->piatti);
        printf("%c\n",position->dataOrdine);
        
        position = position->next;
    }
}

void cancellaCliente(listaPrenotazione *head, char idCliente[maxIdCliente]){
    listaPrenotazione *position = head;

    while (position != NULL){
       if (idCliente == position->idCliente)
       {
        printf("cancellare");
       }
       
        
        position = position->next;
    }
    
}


int main(void){
    listaPrenotazione* head = NULL;
    
    // Popola la lista con alcuni dati di esempio
    Piatto piatti1[maxPiatti] = { {'A', 2}, {'B', 1}, {'C', 3} };
    popolaLista(&head, "Mario Rossi", "12345",'1',piatti1);

    Piatto piatti2[maxPiatti] = { {'X', 1}, {'Y', 2}, {'Z', 2} };
    popolaLista(&head, "Luca Verdi", "67890", '2', piatti2);

    // Stampa la lista
    // stampaLista(head);

    cancellaCliente(head,"12");

    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_COGNOME 71
#define MAX_ID_CLIENTE 13
#define MAX_PIATTI 15

// Struttura per rappresentare un piatto prenotato
typedef struct {
    int idPiatto;
    int nPorzioni;
} Piatto;

// Struttura per rappresentare un ordine prenotato
typedef struct Prenotazione {
    char nomeCognome[MAX_NOME_COGNOME];
    char idCliente[MAX_ID_CLIENTE];
    Piatto prenotazione[MAX_PIATTI];
    char dataOrdine[9];
    struct Prenotazione* next; // Puntatore alla prossima prenotazione nella lista
} Prenotazione;

// Funzione per creare una nuova prenotazione
Prenotazione* creaPrenotazione() {
    Prenotazione* prenotazione = (Prenotazione*)malloc(sizeof(Prenotazione));
    prenotazione->next = NULL; // Inizializza il puntatore alla prossima prenotazione come NULL
    return prenotazione;
}

// Funzione per creare una lista di prenotazioni ordinata per idCliente crescente
Prenotazione* creaLista() {
    Prenotazione* head = NULL; // Puntatore alla testa della lista
    Prenotazione* current = NULL; // Puntatore corrente

    char risposta;

    do {
        // Crea una nuova prenotazione
        Prenotazione* newPrenotazione = creaPrenotazione();

        printf("Inserisci nome e cognome del cliente (massimo 70 caratteri): ");
        fgets(newPrenotazione->nomeCognome, MAX_NOME_COGNOME, stdin);
        printf("Inserisci numero identificativo del cliente (massimo 12 caratteri): ");
        fgets(newPrenotazione->idCliente, MAX_ID_CLIENTE, stdin);
        printf("Inserisci la data dell'ordine (formato gg/mm/aa): ");
        fgets(newPrenotazione->dataOrdine, 9, stdin);

        // Aggiungi la nuova prenotazione alla lista ordinata
        if (head == NULL || strcmp(newPrenotazione->idCliente, head->idCliente) < 0) {
            // Se la lista è vuota o la nuova prenotazione ha un idCliente più piccolo della testa, inserisce la nuova prenotazione come testa
            newPrenotazione->next = head;
            head = newPrenotazione;
        } else {
            // Altrimenti, cerca il posto appropriato nella lista e inserisce la nuova prenotazione
            current = head;
            while (current->next != NULL && strcmp(newPrenotazione->idCliente, current->next->idCliente) >= 0) {
                current = current->next;
            }
            newPrenotazione->next = current->next;
            current->next = newPrenotazione;
        }

        printf("Desideri aggiungere un'altra prenotazione? (s/n): ");
        scanf(" %c", &risposta);
        getchar();  // Consuma il carattere di invio

    } while (risposta == 's' || risposta == 'S');

    return head; // Restituisce il puntatore alla testa della lista
}

// Funzione per cercare un cliente nella lista di prenotazioni e stampare il numero totale di porzioni acquistate
void cercaCliente(Prenotazione* head, char* idCliente) {
    Prenotazione* current = head;
    int totalePorzioni = 0;

    while (current != NULL) {
        if (strcmp(current->idCliente, idCliente) == 0) {
            // Se l'idCliente corrente corrisponde all'idCliente cercato, somma il numero di porzioni della prenotazione corrente al totale
            for (int i = 0; i < MAX_PIATTI; i++) {
                totalePorzioni += current->prenotazione[i].nPorzioni;
            }
        }
        current = current->next; // Passa alla prossima prenotazione nella lista
    }

    printf("Il cliente con id %s ha acquistato %d porzioni.\n", idCliente, totalePorzioni);
}

// Funzione per cancellare un cliente dalla lista di prenotazioni
void cancellaCliente(Prenotazione** head, char* idCliente) {
    Prenotazione* current = *head;
    Prenotazione* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->idCliente, idCliente) == 0) {
            if (prev == NULL) {
                // Il cliente da cancellare è il primo della lista
                *head = current->next; // Aggiorna la testa della lista
            } else {
                prev->next = current->next; // Collega il nodo precedente al nodo successivo, saltando il nodo corrente
            }
            free(current); // Dealloca il nodo corrente
            printf("Cliente con id %s cancellato.\n", idCliente);
            return;
        }
        prev = current;
        current = current->next; // Passa al prossimo nodo nella lista
    }

    printf("Cliente con id %s non trovato.\n", idCliente);
}

int main() {
    Prenotazione* listaPrenotazioni = creaLista(); // Crea la lista di prenotazioni

    char idCliente[MAX_ID_CLIENTE];
    printf("Inserisci il numero identificativo del cliente da cercare: ");
    fgets(idCliente, MAX_ID_CLIENTE, stdin);
    cercaCliente(listaPrenotazioni, idCliente); // Cerca il cliente nella lista di prenotazioni

    printf("Inserisci il numero identificativo del cliente da cancellare: ");
    fgets(idCliente, MAX_ID_CLIENTE, stdin);
    cancellaCliente(&listaPrenotazioni, idCliente); // Cancella il cliente dalla lista di prenotazioni

    // Deallocazione della memoria occupata dalla lista
    Prenotazione* current = listaPrenotazioni;
    while (current != NULL) {
        Prenotazione* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

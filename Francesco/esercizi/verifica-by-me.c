#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creo la struct per utilizzarla all'intenro di prenotaizone
typedef struct structPiatti{
    // Uso un char perche suppongo che potrebbero essere prensentui
    char idPiatto;
    char nPorzioni;
} Piatto;

typedef struct structPrenotazione
{
    char nomeCognome[70];
    char idCliente[12];
    Piatto prenotazione[15];
    // Utilizzo un char anche per un rispoarmio di memoria dato che rispoeto un int e solo un byte e occupa meno memoria
    char data;
} Prenotazione;

// Si definisca una lista Prenotazione inizialmente vuota di prenotazione
typedef struct structListaPrenotazione
{
    Prenotazione prenotazione;
    struct structListaPrenotazione * next;
} ListaPrenotazione;

// Funzione creaLista che ordina per idCliente in modo crescente
ListaPrenotazione * creaLista()
{
    ListaPrenotazione * head = NULL;
    ListaPrenotazione * current = NULL;

    char risposta;

    do
    {
        // Creo una nuova prenotazione
        ListaPrenotazione * newPrenotazione = (ListaPrenotazione *)malloc(sizeof(ListaPrenotazione));

        printf("Inserisci nome e cognome del cliente (massimo 70 caratteri): ");
        fgets(newPrenotazione->prenotazione.nomeCognome, 70, stdin);
        printf("Inserisci numero identificativo del cliente (massimo 12 caratteri): ");
        fgets(newPrenotazione->prenotazione.idCliente, 12, stdin);
        printf("Inserisci la data dell'ordine (formato gg/mm/aa): ");
        fgets(newPrenotazione->prenotazione.data, 9, stdin);

        // Aggiungi la nuova prenotazione alla lista ordinata
        if (head == NULL || strcmp(newPrenotazione->prenotazione.idCliente, head->prenotazione.idCliente) < 0)
        {
            // Se la lista è vuota o la nuova prenotazione ha un idCliente più piccolo della testa, inserisce la nuova prenotazione come testa
            newPrenotazione->next = head;
            head = newPrenotazione;
        }
        else
        {
            // Altrimenti, cerca il posto appropriato nella lista e inserisce la nuova prenotazione
            current = head;
            while (current->next != NULL && strcmp(newPrenotazione->prenotazione.idCliente, current->next->prenotazione.idCliente) >= 0)
            {
                current = current->next;
            }
            newPrenotazione->next = current->next;
            current->next = newPrenotazione;
        }

        printf("Vuoi inserire un'altra prenotazione? (s/n) ");
        scanf("%c", &risposta);
        getchar();
    } while (risposta == 's');

    return head;
}
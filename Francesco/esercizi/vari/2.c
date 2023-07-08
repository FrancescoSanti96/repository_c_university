// Scrivi un programma in linguaggio C che legga un numero intero positivo N da tastiera e poi calcoli la somma di tutti i numeri pari compresi tra 1 e N.

// Il programma deve svolgere i seguenti passaggi:

// Leggere il numero intero positivo N da tastiera.
// Allocazione dinamica di un array di dimensione N.
// Calcolare la somma di tutti i numeri pari compresi tra 1 e N e memorizzarla nell'array.
// Stampare a video la somma calcolata.
// Requisiti aggiuntivi:

// Utilizzare una funzione separata per calcolare la somma dei numeri pari.
// Gestire il caso in cui N sia minore o uguale a 0.
// Esempio di input/output:

// Inserisci un numero intero positivo: 10
// La somma dei numeri pari compresi tra 1 e 10 è: 30

// Nota: Ricordati di gestire la liberazione della memoria allocata dinamicamente dopo aver utilizzato l'array.

#include <stdio.h>
#include <stdlib.h>

int sommaPari(int *array, int n);

int main()
{
    int n;
    int *array;
    int somma;

    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Il numero inserito non è positivo");
        return 0;
    }

    array = (int *)malloc(n * sizeof(int));

    somma = sommaPari(array, n);

    printf("La somma dei numeri pari compresi tra 1 e %d è: %d", n, somma);

    free(array);

    return 0;
}

int sommaPari(int *array, int n)
{
    int somma = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            somma += i;
        }
    }

    return somma;
}



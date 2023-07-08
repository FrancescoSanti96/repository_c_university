// Scrivere un programma che indichi se un valore inserito dall’utente è presente o meno nel
// seguente array: int valori[] = {12, 15, 1337, 19, 2022, 15}; riportando nel
// caso affermativo, l’indice

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valori[] = {12, 15, 1337, 19, 2022, 15};
    int n;
    int flag = 0;

    printf("Inserisci un numero: ");
    scanf("%d", &n);

    for (int i = 0; i < 6; i++)
    {
        if (valori[i] == n)
        {
            printf("Il numero %d e' presente nell'array all'indice %d", n, i);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("Il numero %d non e' presente nell'array", n);
    }

    return 0;
}
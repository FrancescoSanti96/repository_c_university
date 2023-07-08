// Scrivere un programma che inverta l’ordine degli elementi di un array di interi.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int temp;

    for (int i = 0; i < 5 / 2; i++)
    {
        temp = array[i];
        array[i] = array[4 - i];
        array[4 - i] = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}

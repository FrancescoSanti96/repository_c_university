// 1. Scrivere un programma che calcoli la media di 5 numeri inseriti dall’utente.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, n3, n4, n5;
    float media;

    printf("Inserisci il primo numero: ");
    scanf("%d", &n1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &n2);
    printf("Inserisci il terzo numero: ");
    scanf("%d", &n3);
    printf("Inserisci il quarto numero: ");
    scanf("%d", &n4);
    printf("Inserisci il quinto numero: ");
    scanf("%d", &n5);

    media = (n1 + n2 + n3 + n4 + n5) / 5.0;

    printf("La media dei numeri inseriti e': %f", media);

    return 0;
}
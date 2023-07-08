// Chiedere all’utente di inserire una frase. Consiglio di usare
// while ((ch=getchar()) != EOF && ch != '\n')
// al posto di fflush. Contare quanti spazi bianchi ci sono nella frase utilizzando la funzione
// isspace

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char ch;
    int spazi = 0;

    printf("Inserisci una frase: ");

    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (isspace(ch))
        {
            spazi++;
        }
    }

    printf("Ci sono %d spazi", spazi);

    return 0;
}
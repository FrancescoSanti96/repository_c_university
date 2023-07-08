// Scrivere un programma che stampi tutti i numeri primi (numero naturale maggiore di 1, divisibile
// solo per 1 e per se stesso) compresi nell’intervallo da 1 a 100

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int j;
    int flag;

    for (i = 2; i <= 101; i++)
    {
        flag = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
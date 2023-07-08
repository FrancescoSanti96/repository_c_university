// 3. Write a program in C to demonstrate the use of the &(address of)
//  and *(value at address) operators.
// #include <stdio.h>

// int main(){
//     int a = 5;
//     int *b = &a;

//     printf("Valore di a->%d, Valore di b->%d \n",a, *b);
//     printf("indirizzo di memoria di a->%d, Indirizzo di memoria b->%d",&a, b);
// }


// Esercizio 1: Scambio di valori
// Scrivi una funzione che accetta due puntatori a interi e 
// scambia i valori delle due variabili utilizzando i puntatori. 
// Testa la funzione nel main.

// #include <stdio.h>

// void scambio(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     printf("%d e %d",*a,*b);
// }

// int main(void){
//     int a = 20;
//     int b = 10;
//     scambio(&a,&b);
// }


// Esercizio: Allocazione dinamica di un array
// Scrivi un programma che esegua le seguenti operazioni:

// Chiedi all'utente di inserire la dimensione di un array.
// Utilizzando malloc, alloca dinamicamente la memoria per l'array di interi con la dimensione specificata.
// Chiedi all'utente di inserire gli elementi dell'array.
// Stampa gli elementi dell'array.
// Utilizzando free, dealloca la memoria occupata dall'array.

// #include <stdio.h>

// int main(void){
//     int dim;
//     // int a[] = {};

//     printf("Inserire la lunghezza dell'array: ");
//     scanf("%d", &dim);

//     int* array = (int*)malloc(dim * sizeof(int));

//      if (array == NULL) {
//         printf("Errore: memoria non disponibile.\n");
//         return 1;
//     }

//     printf("Inserisci gli elementi dell'array:\n");
//     for (int i = 0; i < dim; i++) {
//         scanf("%d", &array[i]);
//     }

//     printf("Elementi dell'array:\n");
//     for (int i = 0; i < dim; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     free(array);

//     return 0;
// }


// Scrivi un programma che esegua le seguenti operazioni:

// Dichiarazione e inizializzazione di un array di interi di dimensione n 
// (dove n è un valore specificato dall'utente).
// Utilizzando i puntatori, raddoppia il valore di ogni elemento dell'array.
// Creazione di una lista concatenata utilizzando i valori dell'array.
//  Ogni nodo della lista deve contenere un elemento dell'array.
// Stampa dei valori della lista concatenata.

#include <stdio.h>

int main(void){
    int a[] = {};
    int dim;

    printf("Inserisci la dimensione: ");
    scanf("%d",&dim);


    a[dim];
    

    // int b[2] = {1,2};
    // printf("%d", b[1]);
    

}

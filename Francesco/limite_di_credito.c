// Numero del conto
// Saldo allínizo del mese
// Totoale delle voci addebitater sul conto del cliente nel mese
// Totoale dei crediti applicati nel mese al conto del cliente
// Limite di credito concesso

// TODO
// 1 dichiarare le varibiali
// 2 dialogale con la tastiera per prelevare i dati 
// 3 effettuare i conti 
// 4 restituire il risultato


#include <stdio.h>

int main(){
    int numeroConto;
    int saldo;
    int addebito;
    int crediti;
    int limiteCredito;
    int saldoFinale;

    printf("Inserisci il numero del conto: ");
    scanf("%i", &numeroConto);

    printf("Inserisci il saldo: ");
    scanf("%i", &saldo);

    printf("Inserisci addebito: ");
    scanf("%i", &addebito);

    printf("Inserisci i crediti: ");
    scanf("%i", &crediti);

    printf("Inserisci il limite credito: ");
    scanf("%i", &limiteCredito);

    saldoFinale = saldo + addebito - crediti;

    printf("Conto: %i\n",numeroConto);
    printf("Limite credito: %i\n",limiteCredito);
    printf("Saldo finale: %i\n",saldoFinale);

    if (saldoFinale > limiteCredito)
    {
      printf("Limite superato");
    }
    return 0;
}    

//   int numeroConto;
//     int saldo;
//     int addebito;
//     int crediti;
//     int limiteCredito;
//     int saldoFinale;

//     printf("Inserisci il numero del conto: ");
//     scanf("%i", numeroConto);

//     printf("Inserisci il saldo: ");
//     scanf("%i", saldo);

//     printf("Inserisci addebito: ");
//     scanf("%i", addebito);

//     printf("Inserisci i crediti: ");
//     scanf("%i", crediti);

//     printf("Inserisci il limite credito: ");
//     scanf("%i", limiteCredito);

//     saldoFinale = saldo + addebito - crediti;

//     printf("Conto: $i",numeroConto);
//     printf("Limite credito: $i",limiteCredito);
//     printf("Saldo finale: $i",saldoFinale);

//     if (saldoFinale > limiteCredito)
//     {
//       printf("Limite superato");
//     }
    
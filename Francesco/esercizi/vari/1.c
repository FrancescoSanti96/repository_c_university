#include <stdio.h>

int main(void) {
  int a, b, c;
  printf("Inserisci il primo numero: ");
  scanf("%d", &a);
  printf("Inserisci il secondo numero: ");
  scanf("%d", &b);
  printf("Inserisci il terzo numero: ");
  scanf("%d", &c);
  if (a > b && a > c) {
    printf("Il numero maggiore è %d\n", a);
  } else if (b > a && b > c) {
    printf("Il numero maggiore è %d\n", b);
  } else {
    printf("Il numero maggiore è %d\n", c);
  }
  return 0;
}

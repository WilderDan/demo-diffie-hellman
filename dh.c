#include <stdio.h>
#include <stdlib.h>

int pow_modn(int base, int exponent, int n) {

  long long result = 1;

  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % n;

    exponent = exponent >> 1;
    base = (base * base) % n;
  }

  return (int) result; // n is int -> result (mod n) will be int
}

int main(int argc, char **argv) {

  int exp, prime, gen, receive, send, shared;
  
  if (argc < 2) exit(1); 

  exp = atoi(argv[1]);
  scanf("%d %d %d", &prime, &gen, &receive);

  send = pow_modn(gen, exp, prime);
  printf("%d %d %d", prime, gen, send);

  shared = pow_modn(receive, exp, prime);
  fprintf(stderr, "%d\n", shared);
  
  return 0;
}

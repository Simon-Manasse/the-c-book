#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int this_number, divisor,not_prime;
  int prev_prime, difference_between_primes;

  prev_prime=3;
  this_number=3;
  difference_between_primes=0;

  while (this_number < 10000) {
    divisor = this_number / 2;
    not_prime=0;
    while (divisor > 1) {
      if (this_number % divisor==0) {
        not_prime=1;
        divisor=0;
      }
      else {
        divisor--;
      } 
    }
    difference_between_primes = this_number - prev_prime;
    if (not_prime ==0) {
      if(difference_between_primes ==2){
        printf("prime pair found: %d %d\n", prev_prime,this_number);
      }
      prev_prime=this_number;
      }
       this_number++;
  }
  exit(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_COUNT 10

int give_back_integer(int ch[],int count){
  int i, sum;
  sum=0;
  char str[count];
  for (i=0;i<count;i++) {
    sum += (ch[i] - 48) * (int)(pow(10,(count-i-1)));
  }
  return sum;
}

int main(int argc, char *argv[])
{
  int ch, chars[ARRAY_COUNT], count, i;
  count =0;
  ch = getchar();
  while (ch != '\n' && count < ARRAY_COUNT) {
    chars[count] = ch;
    count++;
    ch = getchar();
  }
  printf("the number was: %d", give_back_integer(chars,count));
  return EXIT_SUCCESS;
}

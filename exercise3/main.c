#include <stdio.h>
#include <stdlib.h>

#define ARRAY_COUNT 10

int give_back_integer(int ch[],int count){
  int i;
  char str[count];
  for (i=0;i<count;i++) {
    str[i] = ch[i];
    printf("str: %c; ch: %d\n",str[i], ch[i]);
  }
  return atoi(str);
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

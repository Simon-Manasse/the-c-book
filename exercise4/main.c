#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_COUNT 10

int give_back_integer(char chars[],int count){
  int i, sum = 0;
  for (i = 0; i < count; i++) {
    sum = sum * 10 + (chars[i] - '0');
  }
  return sum;
}


void read_string_from_user(char chars[],int* count_ptr){
  int ch, count = 0;
  ch = getchar();

  while (ch != '\n' && count < ARRAY_COUNT -1) {
    chars[count] = (char) ch;
    count++;
    ch = getchar();
  }
  chars[count] = '\0';
  *count_ptr = count;
}

int comp(const void* a, const void* b){
  return *(int*)a - *(int*)b;
}

int main(int argc, char *argv[])
{
  char chars[ARRAY_COUNT];
  int inputed_numbers[ARRAY_COUNT];
  int count_of_numbers = 0;
  int i,n;

  for (i = 0; i < ARRAY_COUNT; i++) {
    read_string_from_user(chars,&count_of_numbers);
    inputed_numbers[i] = give_back_integer(chars,count_of_numbers);
  }
  n = sizeof(inputed_numbers)/sizeof(inputed_numbers[0]);
  qsort(inputed_numbers, n,sizeof(int), comp);

  printf("inputed numbers in order:\n");

  for (i=0;i<ARRAY_COUNT;i++) {
    printf("%d\n",inputed_numbers[i]);
  }
  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ARRAY_COUNT 10



char* parse_to_binary(int number){
  char binary[sizeof(int)*4], tmp;
  char* binaryPtr = malloc(sizeof(binary));
  int i, start =0, end;
  for (i=0;i<sizeof(binary);i++) binary[i]='0'; 
  i=0;
  while (number >=1) {
    if(number%2 ==0){
      binary[i]='0';
    }
    else {
      binary[i]='1';
      number--;
    }
    number= number/2;
    i++;
   } 
  end=strlen(binary)-1;
  while (start < end) {
    tmp = binary[start];
    binary[start] = binary[end];
    binary[end] = tmp;

    start++;
    end--;
  }
  memcpy(binaryPtr, binary,sizeof(binary)/sizeof(char));
  return binaryPtr;
}

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
  for (i=0;i < ARRAY_COUNT;i++) {
    char* binary = parse_to_binary(inputed_numbers[i]);
    printf("In binary: %s\t In decimal: %d\n",binary,inputed_numbers[i]);
    free(binary);
  }
  return EXIT_SUCCESS;
}

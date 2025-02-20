#include <stdio.h>
#include <stdlib.h>

void show_message(void);

int main(int argc, char *argv[])
{
  int count;

  count = 0;
  while (count< 10) {
    show_message();
    count++;
  }
  exit(0);
}

void show_message(){
  printf("hello\n");
}

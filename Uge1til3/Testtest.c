#include <stdio.h>

int main(void)
{
  char color = 'R';
  switch (color) {
    case 'R':
      printf("red\n");
      break;
    case 'B':
      printf("blue\n");
      break;
    case 'Y':
      printf("yellow\n");
      break;
  }
  return 0;
}


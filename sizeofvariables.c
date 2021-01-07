#include<stdio.h>

int main()
{
  int a = 545;
  int b = 245;
  int c = 56;
  int d = 5;
  int e = 2345;
  int f = 242323;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("int a value: %d and size: %lu bytes\n", b, sizeof(b));
  printf("int a value: %d and size: %lu bytes\n", c, sizeof(c));
  printf("int a value: %d and size: %lu bytes\n", d, sizeof(d));
  printf("int a value: %d and size: %lu bytes\n", e, sizeof(e));
  printf("int a value: %d and size: %lu bytes\n", f, sizeof(f));

}


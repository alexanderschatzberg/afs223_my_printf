#include "my_printf.h"

int main(int argc, char *argv[])
{
  // PRINT INTEGER TESTS
  // TODO: Add more tests
  printf("----------------------------");
  printf("\nPRINT INTEGER TESTS:\n");
  print_integer(768336, 10, ""); // Test 1
  fputc('\n', stdout);
  print_integer(-768336, 10, ""); // Test 2
  fputc('\n', stdout);
  print_integer(-768336, 10, "$"); // Test 3, etc.
  fputc('\n', stdout);

  // MY_PRINTF TESTS
  // TODO: Add more tests
  printf("----------------------------");
  printf("\nMY_PRINTF TESTS:\n");
  my_printf("768336\n");                                  // Test 1
  my_printf("My favorite number is %d!\n", 768336);       // Test 2
  my_printf("%d written in hex is %x\n", 768336, 768336); // Test 3, etc.

  return EXIT_SUCCESS;
}
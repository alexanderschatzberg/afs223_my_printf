#include "my_printf.h"

int main(int argc, char* argv[]) {
  // PRINT INTEGER TESTS
  printf("----------------------------");
  printf("\nPRINT INTEGER TESTS:\n");
  print_integer(3410, 10, ""); // should print “3410”
  fputc('\n', stdout);
  print_integer(-3410, 10, ""); // should print “ - 3410”
  fputc('\n', stdout);
  print_integer(-3410, 10, "$"); // should print “ - $3410
  fputc('\n', stdout);
  print_integer(3410, 16, ""); // should print “d52”
  fputc('\n', stdout);
  print_integer(3410, 16, "0x"); // should print “0xd52”
  fputc('\n', stdout);
  print_integer(-3410, 2, "0b"); // should print “0b11111111111111111111001010101110”
  fputc('\n', stdout);
  print_integer(3410, 2, "0b"); // should print “0b110101010010”
  fputc('\n', stdout);
  print_integer(-3410, 16, "0x"); // should print “0xfffff2ae”
  fputc('\n', stdout);
  print_integer(0, 10, ""); // should print 0
  fputc('\n', stdout);
  print_integer(-0, 10, ""); // should print 0
  fputc('\n', stdout);
  print_integer(UINT_MAX, 10, ""); // should print -1 
  fputc('\n', stdout);

  // MY_PRINTF TESTS
  // TODO: Add more tests
  // printf("----------------------------");
  // printf("\nMY_PRINTF TESTS:\n");
  // my_printf("768336\n");                                  // Test 1
  // my_printf("My favorite number is %d!\n", 768336);       // Test 2
  // my_printf("%d written in hex is %x\n", 768336, 768336); // Test 3, etc.

  return EXIT_SUCCESS;
}
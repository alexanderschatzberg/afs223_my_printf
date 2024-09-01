#include "my_printf.h"

int main(int argc, char* argv[]) {
  // PRINT INTEGER TESTS
  printf("----------------------------");
  printf("\nPRINT INTEGER TESTS:\n");

  print_integer(512, 10, "");
  fputc('\n', stdout);
  print_integer(-512, 10, "");
  fputc('\n', stdout);
  print_integer(-512, 10, "$");
  fputc('\n', stdout);
  print_integer(710, 16, "");
  fputc('\n', stdout);
  print_integer(643, 16, "0x");
  fputc('\n', stdout);
  print_integer(-423, 2, "0b");
  fputc('\n', stdout);
  print_integer(10, 2, "0b");
  fputc('\n', stdout);
  print_integer(-3410, 16, "0x");
  fputc('\n', stdout);
  print_integer(0, 10, "");
  fputc('\n', stdout);
  print_integer(-0, 10, "");
  fputc('\n', stdout);
  print_integer(UINT_MAX, 10, "");
  fputc('\n', stdout);
  print_integer(INT_MAX, 10, "");
  fputc('\n', stdout);

  for (int i = 2; i < 17; i++) {
    printf("TESTS FOR BASE %d \n", i);
    print_integer(1, i, "");
    fputc('\n', stdout);
    print_integer(-1, i, "");
    fputc('\n', stdout);
    print_integer(0, i, "");
    fputc('\n', stdout);
    fputc('\n', stdout);
  }

  // MY_PRINTF TESTS
  printf("----------------------------");
  printf("\nMY_PRINTF TESTS:\n");

  my_printf("HELLO, WORLD\n");
  my_printf("13 printed in base 10: %d!\n", 13);
  my_printf("%d in hex is %x\n", 27, 27);
  my_printf("Just a string!\n"); //should print “3410”
  my_printf("The answer to life, the universe, and everything: %d\n", 42);
  my_printf("The pass rate in 3410 is most likely not 100%%\n");
  my_printf("As long as you have a %s, they'll think %s. \n", "towel", "you have everything under control");
  my_printf("Testing all codes %%, %d, %x, %b, %s, %c:\n", 13, 13, 13, "Hello", 'k');
  my_printf("The question to life, the universe, and everything: %s\n", "How many roads must a man walk? *Mice start dancing*");
  my_printf("The ultimate answer: %d\n", (6 * 9) - 12);
  return EXIT_SUCCESS;
}
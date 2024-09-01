#include <stdarg.h>
#include "my_printf.h"

// Local function header, can't edit my_printf.h 
int x_to_n(int x, int n);
void print_str(char* str);

/*My implementation of print_integer*/
void print_integer(int n, int radix, char* prefix) {
	/*Edge Cases*/
	if (n == 0) {
		print_str(prefix);
		fputc('0', stdout);
		return;
	}

	int is_negative = 0;

	if (n < 0) {
		is_negative = 1;
		if (radix == 10) {
			fputc('-', stdout);
			n = -n;
		}
	}
	print_str(prefix);

	/*Steps to print out from left to right*/

	// 1) Find number in two's compliment form if negative
	unsigned int u_n;
	// Think of it as a layer cake. We're going n (b/c n is negative) digits into the top tier that has been removed
	if (is_negative && radix != 10) {
		u_n = (UINT_MAX + n) + 1;
	}
	else {
		u_n = (unsigned int)n;
	}

	// 2) Find correct number of digits (radix^pow)
	//This is expensive, but I can't think of a better way to do it. 
	int pow = 1;
	unsigned int temp = u_n;

	do { // Want to run at least once
		temp /= radix;
		++pow;
	} while (temp >= radix);

	// 3) For each 'place', calculate the correct val and print 
	for (int i = pow - 1; i >= 0; --i) {
		int digit = u_n / x_to_n(radix, i); // How many of the current base 'fit inside' this digit? 

		//If the digit > 10, we're going to need to print out a (10) + the num - 10
		char c = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');

		fputc(c, stdout);
		u_n %= x_to_n(radix, i); // Continue to the next most significant digit w/ whatever is left 
	}
}

// My implementation of my_printf
void my_printf(const char* format, ...) {
	// Initalize variadic counter 
	va_list args;
	va_start(args, format);

	// loop through each character until the end of the string, continuing if we don't see a %
	for (int i = 0; format[i] != '\0'; ++i) {
		if (format[i] != '%') { fputc(format[i], stdout); continue; }

		// continue to next character if we have a %
		++i;

		// Enter a switch statement for each option
		switch (format[i]) {
		case '%': // Just print a %
			fputc('%', stdout);
			break;
		case 'd':
			int d_arg = va_arg(args, int);
			print_integer(d_arg, 10, "");
			break;
		case 'x':
			int x_arg = va_arg(args, int);
			print_integer(x_arg, 16, "0x");
			break;
		case 'b':
			int b_arg = va_arg(args, int);
			print_integer(b_arg, 2, "0b");
			break;
		case 's':
			print_str(va_arg(args, char*));
			break;
		case 'c':
			char c_arg = va_arg(args, int); // Must handle as an int
			fputc(c_arg, stdout);
			break;
		default:
			print_str("<UNIDENTIFIED FORMAT CODE>");
			break;
		}
	}
	va_end(args);
}


/*HELPER FUNCTIONS*/

/*Prints out the provided string*/
void print_str(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		fputc(str[i], stdout);
	}
}

/*Calculates the power of x^n*/
int x_to_n(int x, int n) {
	int res = 1;
	for (int i = 0; i < n; ++i) {
		res *= x;
	}
	return res;
}
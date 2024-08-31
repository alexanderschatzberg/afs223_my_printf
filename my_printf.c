#include "my_printf.h"
#include <stdio.h>

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
		char c = (digit < 10) ? (digit + '0') : (digit - 10 + 'a'); //If the digit > 10, we're going to need to print out a (10) + the num - 10
		fputc(c, stdout);
		u_n %= x_to_n(radix, i);
	}
}

// TODO: Your implementation for my_printf goes here.
void my_printf(const char* format, ...) {
	return;
}

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
/*  Q1. Write a C program to read a number from the user. 
 *	Assume that a positive five-digit number is always input through the keyboard, 
 *	write a program to reverse the number. 
 */
#include <stdio.h>
#define DIGITS 5

int main() {
	int input, output = 0;
	int divisor = 10000;
	int mult = 1;

	scanf("%d", &input);
	for (int i = 0; i < DIGITS; i++) {
		output += ((input / divisor) % 10) * mult;
		divisor /= 10;
		mult *= 10;
	}

	printf("%05d", output);
	return 0;
}
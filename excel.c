#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 255

int titleToNumber(char*);
char* numberToTitle(unsigned);

int main(int argc, char *argv[]) {
	int columnNumber = 0;
	if (argc < 2) {
		printf("usage: %s [columnTitle] or %s [columnNumber]\n", argv[0], argv[0]);
		return 0;
	}

	if (columnNumber = atoi(argv[1])) {
		if (columnNumber > 0) {
			printf("%s\n", numberToTitle(columnNumber));
		}
	}
	else {
		printf("%d\n", titleToNumber(argv[1]));
	}
}

/* 1. Given a string columnTitle that represents the column title as appears in
 * an Excel sheet, return its corresponding column number.
 */

int titleToNumber(char *columnTitle) {
	unsigned columnNumber = 0, length = strlen(columnTitle);
	while (*columnTitle) { 
		char letter = *columnTitle++;
		if (letter < 'A' || letter > 'Z') {
			printf("'%c' out of bounds\n", letter); exit(-1);
		}
		unsigned number = (letter - '@');
		unsigned exponent = --length;
		unsigned multiplier = 1;
		while (exponent--) {
			multiplier *= 26;
		}
		unsigned value = number * multiplier;
		columnNumber += value;
	}
	return columnNumber;
}

/* 2. Given an integer columnNumber, return its corresponding column title as it 
 * appears in an Excel sheet.
 */

char* numberToTitle(unsigned columnNumber) {
	char *buffer = malloc(BUFFER_SIZE);
	char *start, *end;
	int number;
	char letter;
	memset(buffer, 0, BUFFER_SIZE);
	start = end = buffer;

	while (columnNumber) {
		if (end - start >= BUFFER_SIZE) { 
			printf("only supports up to 26^%d columns\n", BUFFER_SIZE - 1);
			exit(-1);
		}
		if (!(number = columnNumber % 26)) { number = 26; } // 'Z'
		columnNumber /= 26;
		letter = number + 0x40;
		*(++end) = letter;
		if (letter == 'Z') { columnNumber--; }
	}

	while (start < end) { 
		char temp = *(start); 
		*(start) = *(end); 
		*(end) = temp; 
		start++; 
		end--; 
	}     
	return buffer;
}

/* Given two binary strings a and b, return their sum as a binary string. */
#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 8 * sizeof(int)

char* addBinary(char *a, char *b) {
	int i = strtol(a, NULL, 2);
	int j = strtol(b, NULL, 2);
	int sum = i + j;
	char *bitstring = calloc(STRING_LENGTH, sizeof(char));
	char *head, *tail;
	head = tail = bitstring;
	while (sum > 0) {
		char bit = (sum & 1) ? '1' : '0';
		*(tail++) = bit;
		sum >>= 1;
	}
	while (head < --tail) { 
		char temp = *head; 
		*(head++) = *tail; 
		*tail = temp; 
	} 	
	return bitstring;	
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("usage: %s (binary string) (binary string)\n", argv[0]);
	}

	printf("%s\n", addBinary(argv[1], argv[2]));
	return 0;
}
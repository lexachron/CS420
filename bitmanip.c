#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_LENGTH 8 * sizeof(int)

char* addBinary(char *a, char *b) {
	int i = strtol(a, NULL, 2);
	int j = strtol(b, NULL, 2);
	int sum = i + j;
	char *bitstring = (char*)malloc(STRING_LENGTH);
	bitstring += STRING_LENGTH;
	while (sum > 0) {
		char bit = (sum & 1) ? '1' : '0';
		*bitstring = bit;
		sum >>= 1;
		bitstring--;
	}
	return ++bitstring;	
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("usage: %s (binary string) (binary string)\n", argv[0]);
	}

	printf("%s\n", addBinary(argv[1], argv[2]));
	return 0;
}
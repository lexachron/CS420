/* Given two integers start and goal, return the minimum number of bit flips 
 * to convert start to goal
 */
#include <stdio.h>
#include <stdlib.h>

int flippedBits(int start, int goal) {
	int bitCount = 0;
	int flipped = start ^ goal;
	while (flipped != 0) {
		bitCount += flipped & 1;
		flipped = ((unsigned)flipped >> 1);
	}
	return bitCount;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("usage: %s (start) (goal)\n", argv[0]);
		return 0;
	}
	int start = atoi(argv[1]);
	int goal = atoi(argv[2]);
	printf("%d\n", flippedBits(start, goal));
}
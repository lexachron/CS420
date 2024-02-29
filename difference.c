#include <stdio.h>

char findTheDifference(char* s, char* t) {
    char sum = 0;
    while (*t) {
        sum += *t++;
        sum -= *s++;
    }
    return sum;
}

int main(char argc, char *argv[]) {
    char diff = findTheDifference(argv[1], argv[2]);
    printf("%c\n", diff);
}
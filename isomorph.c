#include <stdbool.h>
#include <stdio.h>

bool isIsomorphic(char* s, char* t) {
    char map[128];
    for (int i = 0; i < sizeof(map); i++) {
        map[i] = -128;
    }
    int i = 0, j = 0;
    while (*(s+i)) {
        char a = *(s+i++), b = *(t+j++);
        char diff = b - a;
        if (map[a] == -128) {
            for (int k = 0; k < sizeof(map); k++) {
                if ((char)k + map[k] == b) {
                    return false;
                }
            }
            map[a] = diff;
        }
        else if (map[a] != diff) {
            return false;
        }
    }
    return true;
}

int main(char argc, char *argv[]) {
    // printf("%d\n", CHAR_MIN);
    printf("%sisomorphic\n", !isIsomorphic(argv[1], argv[2]) ? "not " : "");
}
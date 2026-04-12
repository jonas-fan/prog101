#include <stdlib.h>
#include <string.h>

static int min(int lhs, int rhs) {
    return (lhs < rhs) ? lhs : rhs;
}

char * longestCommonPrefix(char ** strs, int strsSize) {
    int size = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {
        size = min(size, strlen(strs[i]));
    }

    for (int j = 0; j < size; j++) {
        const char c = strs[0][j];

        for (int i = 1; i < strsSize; i++) {
            if (strs[i][j] != c) {
                size = j;
                break;
            }
        }
    }

    char * out = (char *)calloc(size + 1, sizeof(char));

    for (int i = 0; i < size; i++) {
        out[i] = strs[0][i];
    }

    return out;
}

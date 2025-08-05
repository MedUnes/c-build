#include "freq.h"
#include <ctype.h>

void count_frequencies(FILE *stream, int *counts) {
    if (stream == NULL || counts == NULL) {
        return;
    }

    // Initialize counts to zero
    for (int i = 0; i < 26; i++) {
        counts[i] = 0;
    }

    int c;
    while ((c = fgetc(stream)) != EOF) {
        if (isalpha(c)) {
            counts[tolower(c) - 'a']++;
        }
    }
}
// GUARD
#ifndef FREQ_H
#define FREQ_H

#include <stdio.h>

// Processes a stream and calculates the frequency of each character 'a'-'z'.
// The results are stored in the 'counts' array, which must have a size of 26.
void count_frequencies(FILE *stream, int *counts);

#endif
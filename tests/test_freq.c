#define _GNU_SOURCE // Enable GNU extensions, including fmemopen
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "freq.h"

// This is the main entry point for our test runner.
int main() {
    printf("Running tests...\n");

    // Test case 1: Simple string
    char *test_string = "Hello World! 123.";
    // Convert string to an in-memory file stream
    FILE *stream = fmemopen(test_string, strlen(test_string), "r");

    int counts[26] = {0};
    count_frequencies(stream, counts);
    fclose(stream);

    // Assertions: H=1, E=1, L=3, O=2, R=1, D=1
    assert(counts['h' - 'a'] == 1);
    assert(counts['e' - 'a'] == 1);
    assert(counts['l' - 'a'] == 3);
    assert(counts['o' - 'a'] == 2);
    assert(counts['r' - 'a'] == 1);
    assert(counts['d' - 'a'] == 1);
    // Assert a character that is not present
    assert(counts['z' - 'a'] == 0);

    printf("All tests passed!\n");
    return 0;
}
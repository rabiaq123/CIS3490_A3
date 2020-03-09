/* NAME: Rabia Qureshi
 * STUDENT ID: 1046427
 * DATE: March 9, 2020
 * ASSIGNMENT 3
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// function prototype
void badSuffixTable(char[], int[]);


/* bad-suffix table table will be used to calculate shifts for Boyer-Moore algo
 * parameter includes pointer to table (array of integers containing shifts for each letter)
 */
void badSuffixTable(char *pattern, int *table) {
    int tableSize = 128;
    int patternLen = strlen(pattern);

    // storing shift sizes in table
    for (int i = 0; i < tableSize - 1; i++) {
        table[i] = patternLen;
    }

    for (int j = 0; j <= patternLen - 2; j++) {
        table[(int)pattern[j]] = patternLen - 1 - j;
    }

    return;
}


/* prompt for pattern and find all occurrences of the pattern in the text using Boyer-Moore algo
 * display num occurrences found, num shifts required, and runtime
 */
void stringSearchBoyer(char *file) {
    char pattern[100] = {'\0'};
    int table[128] = {0}; // 128 different ASCII chars
    int fileLen = 0, patternLen = 0;
    int numCharMatches = 0, numStringMatches = 0;
    int i = 0, index1 = 0, index2 = 0;
    int patternShift = 0;

    // for program execution time
	clock_t start, finish;
	double searchTime;

    // obtain user input
    printf("Please enter a string:\n");
    printf("> ");
    scanf(" %s", pattern);
    strtok(pattern, "\n"); // remove newline from pattern

    // calculating for loop iterations
    patternLen = strlen(pattern);
    fileLen = strlen(file);

    // calculate shifts for shift table
    badSuffixTable(pattern, table);

    // calclating runtime of search (start)
    start = clock();

    // starting string search
    i = patternLen - 1;
    while (i <= fileLen - 1) {
        numCharMatches = 0;
        index1 = patternLen - 1;
        index2 = i;
        while ((numCharMatches < patternLen) && (pattern[index1] == file[index2])) {
            numCharMatches++;
            index1--;
            index2--;
        }
        // match found
        if (numCharMatches == patternLen) {
            numStringMatches++;
            i += patternLen;
        } else {
            if(((int)file[index2] >= 65 && (int)file[index2] <= 90) ||
                ((int)file[index2] >= 97 && (int)file[index2] <= 122)) {
                i += table[(int)file[index2]];
            } else {
                i += patternLen;
            }
        }
		patternShift++;
    }

    // calculating runtime of search (complete!)
    finish = clock();
    searchTime = (double)(finish - start) / CLOCKS_PER_SEC;

    // printing stats
    printf("Pattern shift: %d \n", patternShift);
    printf("Number of matches found: %d\n", numStringMatches);
    printf("Run time for search: %fs\n", searchTime);

    return;
}

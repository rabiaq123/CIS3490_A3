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
int findIndex(char[], char[]);


/* find the index at which the occurence happens 
 * return the value of the index
 */
/* int findIndex(char file[3296951], char pattern[100]) {
    int fileLen = 3296951, patternLen = 0;
    int numIterations = 0; // bufferLen - patternLen
    int numCharsMatched = 0;

    patternLen = strlen(pattern);  
    numIterations = fileLen - patternLen;

    for (int j = 0; j < numIterations; j++) {
        numCharsMatched = 0;
        while ((numCharsMatched < patternLen) && (pattern[numCharsMatched] = file[j + numCharsMatched])) {
            numCharsMatched++;
        }
        // pattern found in text
        if (numCharsMatched == patternLen) {
            return j;
        }
    }

    return -1;
}
 */

/* prompt for pattern and finds all the occurrences of the pattern in the text using brute force
 * display num occurrences found, num shifts required, and runtime
 */
void stringSearchBruteForce(char *file) { // 3296951 chars in file
    char pattern[100] = {'\0'};
    int fileLen = 0, patternLen = 0;
    int numIterations = 0; // fileLen - patternLen
    int numCharsMatched = 0, index = 0; // location at which pattern is found, if found
    int numMatches = 0;

    // for program execution time
	clock_t start, finish;
	double searchTime;

    // obtain user input
    printf("Please enter a string:\n");
    printf("> ");
    scanf(" %s", pattern);
    strtok(pattern, "\n"); // remove newline from pattern

    patternLen = strlen(pattern);  
    fileLen = strlen(file);
    numIterations = fileLen - patternLen;

//    printf("patternLen = %d, fileLen = %d, numIterations = %d\n", patternLen, fileLen, numIterations);

    // display num anagrams found (if any)
    printf("Index/indices at which pattern was found: \n");

    // shifting pattern array by 1 each time
    for (int i = 0; i <= numIterations; i++) {
        for (numCharsMatched = 0; numCharsMatched < patternLen; numCharsMatched++) {
            // checking for string match with given index i
            if (file[i + numCharsMatched] != pattern[numCharsMatched]) {
                break; 
            } 
        }
        if (numCharsMatched == patternLen) {
            printf("%d \n", i); 
            numMatches++;
        }
    }

    // printing stats
    printf("Number of matches found: %d\n", numMatches);

    return;
}

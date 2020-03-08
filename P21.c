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

/* prompt for pattern and find all occurrences of the pattern in the text using brute force
 * display num occurrences found, num shifts required, and runtime
 */
void stringSearchBruteForce(char *file) {
    char pattern[100] = {'\0'};
    int fileLen = 0, patternLen = 0;
    int numIterations = 0; // fileLen - patternLen
    int numCharsMatched = 0;
    int numMatches = 0;
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
    numIterations = fileLen - patternLen;

    // calclating runtime of search (start)
    start = clock();

    // shifting pattern array by 1 each time
    for (int i = 0; i <= numIterations; i++) {
        for (numCharsMatched = 0; numCharsMatched < patternLen; numCharsMatched++) {
            // checking for string match with current index i
            if (file[i + numCharsMatched] != pattern[numCharsMatched]) {
                patternShift++;
                break; 
            }
        }
        // string search successful
        if (numCharsMatched == patternLen) {
            numMatches++;
        }
    }
    
    // calculating runtime of search (complete!)
    finish = clock();
    searchTime = (double)(finish - start) / CLOCKS_PER_SEC;

    // printing stats
    printf("Pattern shift: %d \n", patternShift); 
    printf("Number of matches found: %d\n", numMatches);
    printf("Run time for search: %fs\n", searchTime);

    return;
}

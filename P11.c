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

// code uses data_4.txt

/* prompt for string, find anagrams of string in file using brute force algorithm
 * display num anagrams (excluding string itself) and anagrams + search time 
 */
void anagramSearchBruteForce(char file[30000][20]) {
    char userInput[20] = {'\0'}, fileBuffer[30000][20] = {'\0'};
    int inputLen = 0, bufferLen = 0; // store strlen in vars to avoid repetitive calculations
    bool isAnagram = false;
    int numAnagrams = 0;

    // for program execution time
	clock_t start, finish;
	double searchTime;

    // obtain user input
    printf("Please enter a string:\n");
    printf("> ");
    scanf(" %s", userInput);
    inputLen = strlen(userInput); 

    // calclating runtime of search (start)
    start = clock();

    // displaying results of anagrams found (if any)
    printf("Anagrams found in file: \n");

    // iterate through every string in file
    for (int i = 0; i < 30000; i++) {
        bufferLen = strlen(file[i]);
        strcpy(fileBuffer[i], file[i]); // store strings from file into temp array
        // searching for anagrams
        if (inputLen == bufferLen) { // string length must be the same to be an anagram
            // iterate through every char in user input
            for (int j = 0; j < inputLen; j++) {
                isAnagram = false; // reset to FALSE; remains TRUE when anagram is found in file
                // iterate through every char in buffer from file
                for (int k = 0; k < bufferLen; k++) { 
                    // search for each successive letter of the user input in the fileBuffer[i]
                    if (userInput[j] == fileBuffer[i][k]) {
                        fileBuffer[i][k] = '*'; // remove 1st occurrence of letter found in fileBuffer[i]
                        isAnagram = true;
                        break;
                    }
                }
                // anagram search unsuccessful; userInput[j] not found in fileBuffer[i]
                if (isAnagram == false) {
                    break;
                }
            }
            // anagram search successful; incremented to last char of user input and fileBuffer[i]
            if (isAnagram == true) {
                if (strcmp(userInput, file[i]) != 0) { // do not print same string
                    printf("%s\n", file[i]);
                    numAnagrams++;
                }
            }
        }
    }

    // calculating runtime of search (complete!)
    finish = clock();
    searchTime = (double)(finish - start) / CLOCKS_PER_SEC;

    // printing stats
    printf("Number of anagrams found: %d\n", numAnagrams);
    printf("Run time for search: %fs\n", searchTime);

    return;
}

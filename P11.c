/* NAME: Rabia Qureshi
 * STUDENT ID: 1046427
 * DATE: March 9, 2020
 * ASSIGNMENT 3
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// file uses data_4.txt

/* prompt for string, find anagrams of string in file using brute force algorithm
 * display num anagrams (excluding string itself) and anagrams + search time 
 */
int anagramSearchBruteForce(char file[30000][20]) {
    char userInput[20] = {'\0'}, fileBuffer[30000][20] = {'\0'};
    int numAnagrams = 0;
    int inputLen = 0, bufferLen[30000] = {0}; // store strlen in vars to avoid repeated calculation
    bool isAnagram = false;

    // for program execution time
	clock_t start, finish;
	double runTime;

    // obtain user inputs
    printf("Please enter a string:\n");
    printf("> ");
    scanf(" %s", userInput);
    inputLen = strlen(userInput); 

    // calclating runtime of search (start)
    start = clock();

    // displaying results of anagrams found (if any)
    printf("Anagrams found in file: \n");

    for (int i = 0; i < 30000; i++) { // iterate through every string in file
        bufferLen[i] = strlen(file[i]); 
        strcpy(fileBuffer[i], file[i]);    
        if (inputLen == bufferLen[i]) { // string length must be the same to be an anagram
            for (int j = 0; j < inputLen; j++) { // iterate through every char in user input
                isAnagram = false; // reset to FALSE to ensure flag is only set to TRUE when user input is an anagram of a string in the file 
                for (int k = 0; k < bufferLen[i]; k++) {
                    if (userInput[j] == fileBuffer[i][k]) {
                        fileBuffer[i][k] = '*'; // if search is successful, remove first occurrence of letter in the second word
                        isAnagram = true;
                        break;
                    }
                }
                if (isAnagram == false) { // search unsuccessful; could not find matching char in fileBuffer[i]
                    break;
                }
            }
            if (isAnagram == true) { // anagram search was successful; incremented to last char of user input and fileBuffer[i]
                printf("%s\n", file[i]);
                numAnagrams++;
            }
        }
    }

    // calculating runtime of search (complete!)
    finish = clock();
    runTime = (double)(finish - start) / CLOCKS_PER_SEC;

    // printing stats
    printf("Number of anagrams found: %d\n", numAnagrams);
    printf("Time taken to run program: %fs\n", runTime);

    return numAnagrams;
}

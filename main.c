/* NAME: Rabia Qureshi
 * STUDENT ID: 1046427
 * DATE: March 9, 2020
 * ASSIGNMENT 3
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// function prototypes
void anagramSearchBruteForce(char[][20]);
void anagramSearchPresorted(char[][20]);
void stringSearchBruteForce(char[]);
void stringSearchHorspool(char[]);
void stringSearchBoyer(char[]);

// code uses data_4.txt and data_5.txt

/* main menu for functions program provides
 * read and store data from both files into char arrays
 */
int main() {
    FILE *fPtr;
    int userInput = 0, numElements1 = 0, numElements2 = 0;
    char file1[30000][20]; // for Q1; 30000 strings and 20 chars per string (int -> string)
    char file2[3296951]; // for Q2; 3296951 chars in file

	// parsing data for Question 1 from data_4.txt
	fPtr = fopen("data_4.txt", "r");
	while(!feof(fPtr)) {
		fscanf(fPtr, "%s", file1[numElements1++]); // fscanf() reads up to whitespace
	}
	fclose(fPtr);

	// parsing data for Question 2 from data_5.txt
    fPtr = fopen("data_5.txt", "r");
    while (!feof(fPtr)) {
        file2[numElements2++] = fgetc(fPtr);
    }
    fclose(fPtr);


    do {
        // MAIN MENU
        printf("Select one of the below options: \n");
        printf("1. Brute Force Anagram Search\n");
        printf("2. Presorted Anagram Search\n");
        printf("3. Brute Force String Search\n");
        printf("4. Horspool String Search\n");
        printf("5. Boyer-Moore String Search\n");
        printf("0. Exit program\n");
        printf("> ");
        scanf(" %d", &userInput);

        printf("-----------------------------------------------\n");

        // display user's desired functions of program
        if (userInput == 0) {           // 0. Exit program
            printf("Exiting program.\n");
        } else if (userInput == 1) {    // 1. Brute Force Anagram Search (Q1.1)
            printf("QUESTION 1.1 - Brute Force Anagram Search\n");
            printf("Searching for anagrams of integer in file...\n");
            anagramSearchBruteForce(file1);
        } else if (userInput == 2) {    // 2. Presorted Anagram Search (Q1.2)
            printf("QUESTION 1.2 - Presorted Anagram Search\n");
            printf("Searching for anagrams of integer in file...\n");
            anagramSearchPresorted(file1);
        } else if  (userInput == 3) {    // 3. Brute Force String Search (Q2.1)
            printf("QUESTION 2.1 - Brute Force String Search\n");
            printf("Searching for user input in file...\n");
            stringSearchBruteForce(file2);
        } else if  (userInput == 4) {    // 4. Horspool String Search (Q2.2)
            printf("QUESTION 2.2 - Horspool String Search\n");
            printf("Searching for user input in file...\n");
            stringSearchHorspool(file2);
        } else if  (userInput == 5) {    // 5. Boyer-Moore String Search (Q1.2)
            printf("QUESTION 2.3 - Boyer-Moore String Search\n");
            printf("Searching for user input in file...\n");
            stringSearchBoyer(file2);
        } else {
            printf("Error: Please select one of the given options.\n");
        }
        
        printf("-----------------------------------------------\n");
    } while (userInput != 0); // error-handling

    return 0;
}

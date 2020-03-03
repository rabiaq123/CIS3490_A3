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

int anagramSearchBruteForce(int[], int);
int anagramSearchPresorted(int);
int stringSearchBruteForce(int);
int stringSearchHorspool(int);
int stringSearchBoyer(int);

int main() {
    FILE *fPtr;
    int i = 0, j = 0, k = 0, userInput = 0, numElements1 = 0, numElements2 = 0, numOccurences = 0; 
    int arr[30000], *tempArr; // for Q1
    char stringArr[44049][100]; // for Q2; 44049 lines of strings and 100 chars per string
	// for program execution time
	clock_t start, finish;
	double runTime;

	// parsing data for Question 1 from data_4.txt
	fPtr = fopen("data_4.txt", "r");
	while(!feof(fPtr)) {
		fscanf(fPtr, " %d ", &arr[i++]); // fscanf() reads up to whitespace
	}
	fclose(fPtr);

	// parsing data for Question 2 from data_5.txt
    fPtr = fopen("data_5.txt", "r");
    while (!feof(fPtr)) {
        fgets(stringArr[j++], 100, fPtr); // fgets() reads string
    }
    fclose(fPtr);

    // setting number of elements after file reading
    numElements1 = i;
    numElements2 = j;

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

        printf("-----------------------------------\n");

        // display user's desired functions of program
        if (userInput == 0 ) {          // 0. Exit program
            printf("Exiting program.\n");
        } else if (userInput == 1) {    // 1. Brute Force Anagram Search (Q1.1)
            printf("QUESTION 1.1 - Brute Force Anagram Search\n");
            start = clock();
            numOccurences = anagramSearchBruteForce(arr, numElements1 + 1);
            finish = clock();
            runTime = (double)(finish - start) / CLOCKS_PER_SEC;
        } else if (userInput == 2) {    // 2. Presorted Anagram Search (Q1.2)
            printf("QUESTION 1.2 - Presorted Anagram Search\n");
            start = clock();
            tempArr = (int *)malloc(sizeof(int) * numElements1);
            numOccurences = anagramSearchPresorted(1);
            finish = clock();
            runTime = (double)(finish - start) / CLOCKS_PER_SEC;
        } else if  (userInput == 3) {    // 3. Brute Force String Search (Q2.1)
            printf("QUESTION 2.1 - Brute Force String Search\n");
            start = clock();
            tempArr = (int *)malloc(sizeof(int) * numElements2);
            numOccurences = stringSearchBruteForce(1);
            finish = clock();
            runTime = (double)(finish - start) / CLOCKS_PER_SEC;
        } else if  (userInput == 4) {    // 4. Horspool String Search (Q2.2)
            printf("QUESTION 2.2 - Horspool String Search\n");
            start = clock();
            tempArr = (int *)malloc(sizeof(int) * numElements2);
            numOccurences = stringSearchHorspool(1);
            finish = clock();
            runTime = (double)(finish - start) / CLOCKS_PER_SEC;
        } else if  (userInput == 5) {    // 5. Boyer-Moore String Search (Q1.2)
            printf("QUESTION 2.3 - Boyer-Moore String Search\n");
            start = clock();
            tempArr = (int *)malloc(sizeof(int) * numElements2);
            numOccurences = stringSearchBoyer(1);
            finish = clock();
            runTime = (double)(finish - start) / CLOCKS_PER_SEC;
        } else {
            printf("Error: Please select one of the given options.\n");
        }
        
        // printing runtime of selected function and num occurences of anagrams or strings
        if (userInput > 0 && userInput < 6) { // if user selected 1 of the 5 algorithms to run
            printf("Time taken to run program: %fs\n", runTime);
            if (userInput == 1 || userInput == 2) {
                printf("Number of anagrams found (excluding identical string): %d\n", numOccurences);
            } else {
                printf("Number of strings found in string search: %d\n", numOccurences);
            }
        }
        printf("-----------------------------------\n");
    } while (userInput < 0 || userInput > 5); // error-handling

    return 0;
}

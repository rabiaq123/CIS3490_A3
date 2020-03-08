
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// function prototypes
void merge(int[], int[], int, int, int);
void anagramMergeSort(int[], int[], int, int);


/* split input array into smaller subarrays
 * input array will be array of integers
 */
void anagramMergeSort(int arr[], int buffer[], int left, int right) {
    int mid;

    if (right > left) {
        mid = (right + left) / 2; // split array into 2 sections
        anagramMergeSort(arr, buffer, left, mid);
        anagramMergeSort(arr, buffer, mid + 1, right);
        merge(arr, buffer, left, mid + 1, right);
    }

    return;
}

// merge 2 subarrays into one and count num additional inversions while merging
void merge(int arr[30000], int buffer[], int left, int middle, int right) {
    int i = left, j = middle, k = left; // index counters for L & R subarrays and merged array

    while ((i <= middle - 1) && (j <= right)) {
        if (arr[i] > arr[j]) {
            buffer[k++] = arr[j++];
        } else {
            buffer[k++] = arr[i++];
        }
    }

    // increment from beginning of left subarray to middle and copy into buffer
    while (i <= middle - 1) {
        buffer[k++] = arr[i++];
    }

    // continue adding to buffer by copying from right subarray into buffer
    while (j <= right) {
        buffer[k++] = arr[j++];
    }

    // copy buffer into array
    for (i = left; i <= right; i++) {
        arr[i] = buffer[i];
    }

    return;
}

/* find anagrams using presorted array of file string signatures
 */
void anagramSearchPresorted(char file[30000][20]) {
    int *numArr, strToInt = 0, bufferLen = 0;
    int tempArr[20] = {0}; // for merge sort
    char userInput[20] = {'\0'};
    int  *inputArr, inputToInt = 0, inputLen = 0, indexCount = 0;
    bool isAnagram = false;
    int numAnagrams = 0;

    // for program execution time
	clock_t startSearch, finishSearch, startSort, finishSort;
    double sortTime = 0, sortTimeInput = 0, sortTimeFile = 0, searchTime = 0;

    /*****FOR USER INPUT*****/

    // obtain user input
    while (inputToInt == 0 || inputLen < 9) { // error checking for invalid input format
        printf("Please enter a string:\n");
        printf("> ");
        scanf(" %s", userInput); // input should be an int
        inputLen = strlen(userInput);
        inputToInt = atoi(userInput);
    }
    
    // store user input in int array
    inputArr = (int *)malloc(sizeof(int) * inputLen);
    indexCount = inputLen - 1;
    while (inputToInt > 0) {
        inputArr[indexCount--] = inputToInt % 10;
        inputToInt /= 10;
    }

    // sorting user input and calculating sort time
    startSort = clock();
    anagramMergeSort(inputArr, tempArr, 0, inputLen - 1);
    finishSort = clock();
    sortTimeInput = (double)(finishSort - startSort) / CLOCKS_PER_SEC;

    /*****FOR STRINGS IN FILE*****/

    // display num anagrams found (if any)
    printf("Anagrams found in file: \n");

    for (int i = 0; i < 30000; i++) {
        bufferLen = strlen(file[i]);
        if (inputLen == bufferLen) { // may be anagrams
            // store string in int array
            numArr = (int *)malloc(sizeof(int) * bufferLen);
            indexCount = bufferLen - 1;
            strToInt = atoi(file[i]);
            while (strToInt > 0) {
                numArr[indexCount--] = strToInt % 10;
                strToInt /= 10;
            }
            // sorting string from file and calculating sort time
            memset(tempArr, 0, sizeof(tempArr)); // reset tempArr elements to 0
            startSort = clock();
            anagramMergeSort(numArr, tempArr, 0, bufferLen - 1);
            finishSort = clock();
            sortTimeFile += (double)(finishSort - startSort) / CLOCKS_PER_SEC;
            // checking for anagram
            startSearch = clock(); // calculating search time (start)
            for (int j = 0; j < bufferLen; j++) {
                if (inputArr[j] == numArr[j]) {
                    isAnagram = true;
                } else {
                    isAnagram = false;
                    break;
                }
            }
            finishSearch = clock(); // calculating search time (complete!)
            searchTime += (double)(finishSearch - startSearch) / CLOCKS_PER_SEC;
            // anagram search successful
            if (isAnagram == true) {
                if (strcmp(userInput, file[i]) != 0) { // do not print same string
                    printf("%s\n", file[i]);
                    numAnagrams++;
                }
            }
        }
    }

    sortTime = sortTimeInput + sortTimeFile;

    // printing stats
    printf("Number of anagrams found: %d\n", numAnagrams);
    printf("Time taken to sort: %fs\n", sortTime);
    printf("Time taken to search: %fs\n", searchTime);

    free(inputArr);
    free(numArr);
    inputArr = NULL;
    numArr = NULL;

    return;
}
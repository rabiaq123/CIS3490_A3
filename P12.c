
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// function prototype
void merge(int[], int[], int, int, int);
void anagramMergeSort(int[], int[], int, int);


/* split input array into smaller subarrays
 * input array can be array of strings in file OR array of characters in each string in file
  * returns sorted integer
 */
void anagramMergeSort(int arr[], int buffer[], int left, int right) {
    int mid;

    if (right > left) {
        mid = (right + left) / 2; // split array into 2 sections
        anagramMergeSort(arr, buffer, left, mid);
        anagramMergeSort(arr, buffer, mid + 1, right);
        merge(arr, buffer, left, mid + 1, right);
    }
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
}

/* find anagrams using presorted array of file string signatures
 */
void anagramSearchPresorted(char file[30000][20]) {
    int *fileBuffer, *fileArr, bufferLen = 0, counter = 0, numPossibilities = 0;
    int temp[20] = {0}; // for merge sort
    char userInput[20] = {'\0'};
    int inputLen = 0, inputToInt = 0, indexCount, *inputArr; // for user input

    int numAnagrams = 0;

    // for program execution time
	clock_t start, finish;
	double searchTime;

    /*****FOR USER INPUT*****/

    // obtain user input
    while (inputToInt == 0) { // error checking for invalid input format
        printf("Please enter a string:\n");
        printf("> ");
        scanf(" %s", userInput); // assuming user input is a number
        inputLen = strlen(userInput);
        inputToInt = atoi(userInput); // convert user input to int
    }
    inputArr = malloc(sizeof(int) * inputLen);
    indexCount = inputLen - 1;

    // storing each digit in user input into array
    while (inputToInt > 0) { // increment until all digits have been stored in array
        inputArr[indexCount--] = inputToInt % 10;
        inputToInt /= 10;
    }

    // sorting user input
    anagramMergeSort(inputArr, temp, 0, inputLen - 1); // sort chars in each string from file





    free(inputArr);
    free(fileArr);
    inputArr = NULL;
    fileArr = NULL;
}
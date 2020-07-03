/*
 *  Assignment:     C.S.P0003
 *  Requirement:    Program to insert new element into an existing array.
 *  Author:         Dat Tran (HE140517)
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *  Function 1.1
 *  Prompt user to enter the number of elements in the array
 */
void getSizeOfArray(int **array, int *arraySize) {
    short isValid;
    char enterChar;

    // get the number of elements while checking validity of input
    while (1) {
        printf("Please enter size of array:");
        isValid = scanf("%d%c", arraySize, &enterChar);
        fflush(stdin);

        // if user did not enter an integer, then throw an alert
        // then force them to enter again.
        if (isValid != 2 || *arraySize < 0 || enterChar != '\n')
            printf("Invalid input. Please enter a positive interger.\n");
        else
            break;
    }

    *array = (int *) calloc(*arraySize, sizeof(int));
    if (*array == NULL)
    {
        fprintf(stderr, "Memory allocation failed for array in getSizeOfArray()\n");
        exit(-2);
    }
}

/*
 *  Function 1.2
 *  Get the value of each element in the array
 */
void getEachElementVal(int *array, int arraySize) {
    short isValid;
    int i;
    char enterChar;

    for (i = 0; i < arraySize; i++) {
        while (1) {
            printf("Enter element[%d]:", i);
            isValid = scanf("%d%c", &array[i], &enterChar);
            fflush(stdin);

            // check input validity
            // user must enter an integer
            // and finish each value with enter character
            if (isValid != 2 || enterChar != '\n')
                printf("Invalid input. Please enter an integer.\n");
            else
                break;
        }
    }
}

/*
 *  Function 2
 *  Sorting array in optional order:
 *  If sortOption is equal to 1 then sort in ascending order, otherwise (0) in descending
 *  By implementing QuickSort Algorithm.
 */
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int *array, int arraySize) {
    int i, j;
    for (i = 0; i < arraySize - 1; i++)
        for (j = 0; j < arraySize - i - 1; j++)
            // sort in ascending order
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}

/*
 *  Function 3:
 *  Prompt user to get new element value then add it to the exist array
 */
void insertNewElement(int *array, int arraySize, int newElementVal) {
    array[arraySize-1] = newElementVal;
}

void getNewElement(int **array, int *arraySize) {
    short isValid;
    int newElementVal;
    char enterChar;

    while (1) {
        printf("Please enter new value:");
        isValid = scanf("%d%c", &newElementVal, &enterChar);
        fflush(stdin);

        if (isValid != 2 || enterChar != '\n')
            printf("Invalid input. Please enter an integer.");
        else
            break;
    }

    *array = (int *) realloc(*array, sizeof(int) * (++*arraySize));
    if (*array == NULL)
    {
        fprintf(stderr, "Memory reallocation failed for array in getNewElement()\n");
        exit(-2);
    }

    insertNewElement(*array, *arraySize, newElementVal);
}

/*
 *  Function 4:
 *  Display array into the screen following options
 *  showOption is equal to 1 for array before inserting
 *  otherwise for after one.
 */
void showArray(int *array, int arraySize, int showOptions) {
    int i;

    printf("%s\n", showOptions == 1 ?
    "The array after sorting" : "New array:");
    for (i = 0; i < arraySize; i++)
        printf("%d\t", array[i]);
    printf("\n");
}

int main() {
    int *array;
    int arraySize;

    // get the number of elements in this array
    getSizeOfArray(&array, &arraySize);

    // get the value of each element
    getEachElementVal(array, arraySize);

    // sort array in ascending order
    sortArray(array, arraySize);

    // print out the array to the screen
    showArray(array, arraySize, 1);

    // prompt user to enter new value which will be inserted into the array
    getNewElement(&array, &arraySize);

    // sort array in ascending order after adding new value into it
    sortArray(array, arraySize);

    // print out the array to the screen
    showArray(array, arraySize, 0);

    // free heap memory for array
    free(array);

    return 0;
}
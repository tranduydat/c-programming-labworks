#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 *  Function 1
 *  Display a screen to ask users to input a positive natural number
 */
void getUserInput(int *userInput) {
    short isValid;

    printf("Check Square Number Program\n");
    while (1) {
        printf("Enter a positive integer n = ");
        isValid = scanf("%d", &(*userInput));
        fflush(stdin);

        // check input validity
        // if user didn't enter a positive integer (natural number)
        // then throw an alert and force them to enter again
        if (isValid != 1 || *userInput < 0)
            printf("Invalid input. Making sure that you entered a positive integer.\n");
        else
            break;
    }
}

/*
 *  Function 2
 *  Check if the inputted number is square number
 *  If it is, then return its square root of 2
 *  otherwise return -1
 */
int isSquareNum(int userInput) {
    int squareRoot = sqrt(userInput);
    if (pow(squareRoot, 2) == userInput)
        return squareRoot;
    else
        return -1;
}

/*
 *  Function 3
 *  Output the result to the screen
 */
void showResult(int userInput) {
    if (isSquareNum(userInput) == -1)
        printf("%d is not a square number\n", userInput);
    else
        printf("%d is a square number\n", userInput);
}

/*
 *  Function 4
 *  Ask user either to rerun this program or not
 */
void askContinue() {
    char userChoice;

    while (1) {
        printf("Press any key then enter to continue.");
        userChoice = getchar();
        fflush(stdin);

        if (userChoice != 0) {
            fflush(stdin);
            printf("\n");
            main();
        }
        else
            printf("Invalid input. Please try again\n");
    }
}

int main() {
    int userInput;

    // prompt user to enter a positive integer, while check its validity
    getUserInput(&userInput);

    // show the result, either user input is a square number or not
    showResult(userInput);

    // to ask user to rerun program or not
    askContinue();

    return (EXIT_SUCCESS);
}
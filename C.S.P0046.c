#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

/*
 *  Function 1
 *  Prompt user to enter input, while check its validity
 */
void getUserChoice(int *userChoice) {
    printf("1-The first primes\n");
    printf("2-Fibonacci element\n");
    printf("3-Sum of digits\n");

    // get the user choice
    while (1) {
        printf("Choose an option:");
        short isValid = scanf("%d%*c", &(*userChoice));
        __fpurge(stdin);

        // Check validity of input
        // input should be a number in sets of {1, 2, 3}
        // unless showing the alert, then forcing user to input again
        if (isValid == 1 && *userChoice >= 1 && *userChoice <= 3)
            break;
        else
            printf("Invalid choice. Please enter again! (e.g: 1, 2 or 3)\n");
    }
}

/*
 *  Function 3
 *  Function to check an input number either is prime number or not
 *  Return 1 if it is, unless return 0
 */
int isPrimeNum(int num) {
    int i;

    if (num < 2)
        return 0;
    else {
        // a Fibonacci number which should be divisible by 1 and its own.
        // if the number having more than 2 divisors which was mentioned
        // implies that it is not a Fibonacci number
        for (i = 2; i <= num/2; i++)
            if (num % i == 0)
                return 0;
    }
    return 1;
}

/*
 *  Function 2
 *  Prompt user input the number of primes which they would like to have
 *  then print the n first prime numbers from user input
 */
void showFirstPrimes() {
    int numOfPrimes;

    // get and check validity of input from user
    while (1) {
        printf("Number of primes: ");
        short isValid = scanf("%d%*c", &numOfPrimes);
        __fpurge(stdin);

        // if user didn't enter an integer number,
        // or it is out of range (0, 50]
        // then show the alert and force user to enter again
        if (isValid != 1 || numOfPrimes <= 0 || numOfPrimes > 50)
            printf("Invalid input. Please enter a positive number in the range of (0, 50]\n");
        else
            break;
    }

    // to conduct calculation
    // then print out the list of n first primes
    int i = 2;
    while (numOfPrimes != 0) {
        if (isPrimeNum(i) == 1) {
            printf("%d ", i);
            numOfPrimes--;
        }
        i++;
    }
}

/*
 *  Function 4
 *  To sum of digits from user input
 *  then print it out the console
 */
void checkPrimeNum() {
    short isValid;
    int numberToCheck;

    // prompt user to enter the number which will be checked
    // while check its validity
    while (1) {
        printf("Number tested: ");
        isValid = scanf("%d%*c", &numberToCheck);
        __fpurge(stdin);

        // if user did not enter an integer number
        // then show an alert and force them to enter again
        if (isValid != 1)
            printf("Invalid input. Please enter an integer number.\n");
        else
            break;
    }

    // to print the result to the screen
    // either input number is prime number or not
    if (isPrimeNum(numberToCheck) == 1)
        printf("It's a Fibonacci term.");
    else
        printf("It's not a Fibonacci term.");
}

void sumOfDigit() {
    short isValid;
    long long int inputNumber;
    unsigned long remainder;
    unsigned long sum = 0;

    // get the number from user input
    // while check its validity
    while (1) {
        printf("Enter an integer: ");
        isValid = scanf("%lld%*c", &inputNumber);
        __fpurge(stdin);

        if (isValid != 1)
            printf("Invalid input. Please enter an integer number.\n");
        else
            break;
    }

    if (inputNumber < 0)
        inputNumber *= -1;

    while (inputNumber != 0) {
        remainder = inputNumber % 10;
        sum += remainder;
        inputNumber /= 10;
    }

    printf("Sum of it's digit: %lu\n", sum);
}

void rerunProgram() {
    __fpurge(stdin);
    printf("\n");
    main();
}

int main() {
    int userChoice;

    // prompt user to get their choices
    getUserChoice(&userChoice);

    // to implement function corresponding to userChoice
    switch (userChoice) {
        case 1:
            // Output first primes of the inputted number
            showFirstPrimes();
            break;
        case 2:
            // Check a Fibonacci number.
            checkPrimeNum();
            break;
        case 3:
            // Sum of digits in a positive natural number
            sumOfDigits();
            break;
    }

    // to rerun this program
    rerunProgram();

    return(EXIT_SUCCESS);
}
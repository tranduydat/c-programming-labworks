/*
 *  Assignment:     C.S.P0011
 *  Requirement:    Convert binary, octal and hexadecimal to decimal
 *  Author:         Dat Tran (HE140517)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define INIT_STRING_LENGTH 100  // character unit
#define FAILURE_MEMORY_ALLOC -2 // return code if memory allocation failed
#define MAX_BIN_DIGITS 64
#define MAX_HEX_DIGITS 16
#define MAX_OCT_DIGITS 22

/*
 *  Function 1.1
 *  To check either user input (as param) is in Binary format or not
 *  Return 1 if it is, otherwise return 0
 */
int checkBinFormat(char *userInput)
{
    int i;

    if (strlen(userInput) > MAX_BIN_DIGITS)
        return 0;

    // if each character in whole string userInput
    for (i = 0; i < strlen(userInput); i++)
        // in the range from 48 to 49 (corresponding to 0's and 1's in ASCII)
        if (userInput[i] == 48 || userInput[i] == 49)
            continue;
        else
            return 0;

    return 1;
}

/*
 *  Function 1.2
 *  To check either user input (as param) is in Octal format or not
 *  Return 1 if it is, otherwise return 0
 */
int checkOctFormat(char *userInput)
{
    int i;
    short count = 0;

    if (strlen(userInput) > MAX_OCT_DIGITS)
        return 0;

    // if each character in whole string userInput
    for (i = 0; i < strlen(userInput); i++)
        // in the range from 48 to 55(corresponding in the range of[0, 8] in ASCII)
        if (userInput[i] >= 48 && userInput[i] <= 55) {
            if (i != 0 && userInput[i] == 55)
                count++;
            continue;
        }
        else
            return 0;

    // the maximum value of octal in 64 bits is 1777777777777777777777
    if (userInput[0] > 49 && count == 21)
        return 0;

    return 1;
}

/*
 *  Function 1.3
 *  To check either user input (as param) is in Hexadecimal format or not
 *  Return 1 if it is, otherwise return 0
 */
int checkHexFormat(char *userInput)
{
    int i;

    if (strlen(userInput) > MAX_HEX_DIGITS)
        return 0;

    // if each character in whole string userInput
    for (i = 0; i < strlen(userInput); i++)
        // in the range from 48 to 57(0 to 9 in ASCII)
        if ((userInput[i] >= 48 && userInput[i] <= 57))
            continue;
        // or in the range from 65 to 70 (A->F in ASCII)
        else if ((userInput[i] >= 65 && userInput[i] <= 70))
            continue;
        // or in the range from 97 to 102(a->f in ASCII)
        else if ((userInput[i] >= 97 && userInput[i] <= 102))
            continue;
        else
            return 0;

    return 1;
}

/*
 *  Function 2
 *  To prompt user to get their choice, while checking its validity
 */
void getUserChoice(int *userChoice)
{
    short isValid;

    printf("\t1. Convert binary number to decimal number\n");
    printf("\t2. Convert octal number to decimal number\n");
    printf("\t3. Convert hexadecimal number to decimal number\n");
    printf("\t4. Exit\n\n");

    // get the choice from user input
    while (1)
    {
        printf("Please choose number (1 - 4): ");
        isValid = scanf("%d", &(*userChoice));
        fflush(stdin);

        // checking the validity of input
        // if user did not enter an integer in the range of 1 to 4
        // then throw an alert then force them to enter again
        if (isValid != 1 || *userChoice > 4 || *userChoice < 1)
            printf("Invalid input. Please enter a integer between 1 and 4.\n");
        else
            break;
    }
}

/*
 *  Function 3
 *  To prompt user to get number which they want to conduct converting
 *  Return string of userInput which one has been realloc
 */
char *getUserInput(int userChoice)
{
    // if user choice is 4, then skip this function to avoid memory allocation failed
    if (userChoice == 4)
        return NULL;

    short isValid = 0;

    char *userInput = (char *)malloc(INIT_STRING_LENGTH * sizeof(char));
    if (userInput == NULL)
    {
        fprintf(stderr, "Memory allocation failed for userInput in getUserInput()\n");
        exit(FAILURE_MEMORY_ALLOC);
    }

    // getting the data to be converted from user input
    // while checking its validity
    do
    {
        switch (userChoice)
        {
        case 1:
            printf("\n\tEnter binary number: ");
            // fgets(userInput, INIT_STRING_LENGTH, stdin);
            gets(userInput);
            fflush(stdin);

            isValid = checkBinFormat(userInput);
            if (isValid == 0)
                printf("\tInvalid input. Please making sure that your input is in Binary format (hint: 1's, 0's)\n");
            break;
        case 2:
            printf("\n\tEnter octal number: ");
            // fgets(userInput, INIT_STRING_LENGTH, stdin);
            gets(userInput);
            fflush(stdin);

            isValid = checkOctFormat(userInput);
            if (isValid == 0)
                printf("\tInvalid input. Please making sure that your input is in Octal format (hint: 0's -> 8's)\n");
            break;
        case 3:
            printf("\n\tEnter hexadecimal number: ");
            // fgets(userInput, INIT_STRING_LENGTH, stdin);
            gets(userInput);
            fflush(stdin);

            isValid = checkHexFormat(userInput);
            if (isValid == 0)
                printf("\tInvalid input. Please making sure that your input is in Hex format (hint: 0's to 9's, A -> F or a -> f)\n");
            break;
        }
    } while (isValid == 0);

    size_t userInputLength = strlen(userInput);
    userInput = (char *)realloc(userInput, userInputLength * sizeof(char));
    if (userInput == NULL)
    {
        fprintf(stderr, "Memory reallocation failed for userInput in getUserInput()\n");
        exit(FAILURE_MEMORY_ALLOC);
    }

    return userInput;
}

/*
 *  Function 4.1
 *  Converting current user input is in Binary format
 *  to corresponding Decimal one.
 */
void convertBinToDec(char *userInput, unsigned long long int *decimalResult)
{
    int i, j;
    long double temp;
    size_t userInputLength = strlen(userInput);

    for (i = 0, j = userInputLength - 1; i < userInputLength; i++, j--)
    {
        // to convert character '1' and '0' in string to decimal format (1's and 0's) (ASCII)
        temp = userInput[j] - 48;
        *decimalResult += temp * pow(2, i);
    }
}

/*
 *  Function 4.2
 *  Converting current user input is in Octal format
 *  to corresponding Decimal one.
 */
void convertOctToDec(char *userInput, unsigned long long int *decimalResult)
{
    int i, j;
    long double temp;
    size_t userInputLength = strlen(userInput);

    for (i = 0, j = userInputLength - 1; i < userInputLength; i++, j--)
    {
        // to convert character to decimal format (ASCII)
        temp = userInput[j] - 48;
        *decimalResult += temp * pow(8, i);
    }
}

/*
 *  Function 4.3
 *  Converting current user input is in Hexadecimal format
 *  to corresponding Decimal one.
 */
void convertHexToDec(char *userInput, unsigned long long int *decimalResult)
{
    int i, j;
    long double temp;
    size_t userInputLength = strlen(userInput);

    for (i = 0, j = userInputLength - 1; i < userInputLength ; i++, j--)
    {
        // convert digit characters to decimal value (ASCII)
        if (isdigit(userInput[j]))
            temp = userInput[j] - 48;
        // convert A, B, C,..., F to decimal value (ASCII)
        else if (isupper(userInput[j]))
            temp = userInput[j] - 55;
        // convert a, b, c,..., f to decimal value (ASCII)
        else if (islower(userInput[j]))
            temp = userInput[j] - 87;

        *decimalResult += temp * pow(16, i);
    }
}

/*
 *  Function 5
 *  To show the converted number is in decimal format to the screen
 */
void showResult(unsigned long long int decimalResult)
{
    printf("\n\tDecimal number is: %llu\n", decimalResult);
}

/*
 *  Function 6
 *  To ask user either to rerun this program or not
 */
void askContinue()
{
    char isContinue;

    while (1)
    {
        printf("\n\tPress enter to continue, otherwise to return the main menu");
        isContinue = getchar();
        fflush(stdin);

        // if user presses enter
        if (isContinue == 10)
        {
            fflush(stdin);
            printf("\n");
            main();
        }
        else
        {
            fflush(stdin);
            system("cls");
            main();
        }
    }
}

int main()
{
    int userChoice;
    char *userInput;
    unsigned long long int decimalResult = 0;

    // prompt user to get their choices
    getUserChoice(&userChoice);

    // get the corresponding data, while checking its validity
    userInput = getUserInput(userChoice);

    switch (userChoice)
    {
    case 1:
        // convert binary number to decimal one
        convertBinToDec(userInput, &decimalResult);
        break;
    case 2:
        // convert octal number to decimal one
        convertOctToDec(userInput, &decimalResult);
        break;
    case 3:
        // convert hexadecimal number to decimal one
        convertHexToDec(userInput, &decimalResult);
        break;
    case 4:
        exit(0);
    }

    // show the result to the screen
    showResult(decimalResult);

    // free heap memory for userInput
    free(userInput);

    // asking user to rerun this program or not
    askContinue();

    return 0;
}
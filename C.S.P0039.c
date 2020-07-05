#include <stdio.h>
#include <stdlib.h>

/*
 *  Function
 *  Check input year (as parameter) either is leap year or not
 *  Return 1 if it is, unless return 0
 */
int checkLeapYear(int year) {
    /* A leap year is a year that divisible by 400 or divisible by 4
     * and indivisible by 100. If it is a leap year,
     * then return 1, otherwise return 0 */
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        return 1;
    else
        return 0;
}

/*
 *  Function
 *  Get date info from user input
 *  While checking it is in valid type of date or not
 */
void getDateInfo(int *day, int *month, int *year)
{
    printf("Enter day (1 - 31): ");
    *day = getIntInput(1, 31);
    printf("Enter month (1 - 12): ");
    *month = getIntInput(1, 12);
    printf("Enter year (1 - 9999): ");
    *year = getIntInput(1, 9999);
}

/*
 *  Function
 *  Calculating that type of dat which user inputted does it exist or not
 */
void processDateInfo(int day, int month, int year) {
    char errorMsg[] = "Day, month, year you entered is invalid\n";

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day <= 31)
            printf("\n%d-%d-%d\n", day, month, year);
        else
            printf("%s", errorMsg);
    }
    else if  (month == 2)
    {
        if (checkLeapYear(year))
            if (day <= 29)
                printf("\n%d-%d-%d\n", day, month, year);
            else
                printf("%s", errorMsg);
        else
            if (day <= 28)
                printf("\n%d-%d-%d\n", day, month, year);
            else
                printf("%s", errorMsg);
    }
    else
    {
        if (day <= 30)
            printf("\n%d-%d-%d\n", day, month, year);
        else
            printf("%s", errorMsg);
    }
}

/*
 *  Function
 *  To print out the menu to the console
 */
void getUserChoice(int *userChoice) {
    printf("MENU\n-------------------------------\n\n");
    printf("1- Processing date data\n");
    printf("2- Character data\n");
    printf("3- Quit\n");
    printf("Enter your choice: ");

    *userChoice = getIntInput(1, 3);
}

/*
 *  Function
 *  To get integer input from user while check its validity
 */
int getIntInput(int max, int min) {
    int userInput;
    short isValid;
    char enterChar;

    // check validity of input
    while (1) {
        isValid = scanf("%d%c", &userInput, &enterChar);
        fflush(stdin);

        /* input should be integer number
         * and end line with enter character */
        if (isValid != 2 || enterChar != '\n')
            printf("Invalid input. Please enter an integer number in range of %d to %d", min, max);
        else
            return userInput;
    }
}

void getCharInput();

int main() {
    int userChoice;

    getUserChoice(&userChoice);
    switch (userChoice) {
        case 1:
            getDateInfo(&day, &month, &year);
            processDateForm(day, month, year);
            break;
        case 2:
    }

    return 0;
}

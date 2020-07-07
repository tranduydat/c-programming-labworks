#include <stdio.h>
#include <stdlib.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

/*
 *  Function
 *  To get integer from standard input while check its validity
 */
int getIntInput(int min, int max)
{
    int userInput;
    short isValid;
    char enterChar;

    // check validity of input
    while (1)
    {
        isValid = scanf("%d%c", &userInput, &enterChar);
        fflush(stdin);

        /* input should be integer number
         * and end line with enter character */
        if (isValid != 2 || enterChar != '\n')
            printf("Invalid input. Please enter an integer number in range of %d to %d.\nTry again: ", min, max);
        else if (userInput < min || userInput > max)
            printf("Input is Out of Range. Please enter a valid input in range of %d to %d.\nTry again: ", min, max);
        else
            return userInput;
    }
}

/*
 *  Function
 *  To get 2 characters from standard input while check its validity
 */
void getCharInput(char *c1, char *c2)
{
    short isValid;
    char enterChar;

    do
    {
        printf("Enter 2 character: ");
        isValid = scanf("%c%c%c", *(&c1), *(&c2), &enterChar);
        fflush(stdin);

        // 65 - 90 97 - 122
        if (isValid != 3 || enterChar != '\n')
            printf("Invalid input. Please enter just only 2 character.\n");
        else
            break;
    } while (isValid != 3 || enterChar != '\n');
}

/*
 *  Function
 *  Check input year (as parameter) either is leap year or not
 *  Return 1 if it is, unless return 0
 */
int checkLeapYear(int year)
{
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
void getDateInfo(Date *date)
{
    printf("Enter day (1 - 31): ");
    date->day = getIntInput(1, 31);
    printf("Enter month (1 - 12): ");
    date->month = getIntInput(1, 12);
    printf("Enter year (1 - 9999): ");
    date->year = getIntInput(1, 9999);
}

/*
 *  Function
 *  Calculating that type of dat which user inputted does it exist or not
 */
void processDateInfo(Date date)
{
    char errorMsg[] = "\nDay, month, year you entered is invalid\n";
    char successMsg[] = "\nYou entered a valid date: ";

    if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12)
    {
        if (date.day <= 31)
            printf("%s%d-%d-%d\n", successMsg, date.day, date.month, date.year);
        else
            printf("%s", errorMsg);
    }
    else if (date.month == 2)
    {
        if (checkLeapYear(date.year))
            if (date.day <= 29)
                printf("%s%d-%d-%d\n", successMsg, date.day, date.month, date.year);
            else
                printf("%s", errorMsg);
        else if (date.day <= 28)
            printf("%s%d-%d-%d\n", successMsg, date.day, date.month, date.year);
        else
            printf("%s", errorMsg);
    }
    else
    {
        if (date.day <= 30)
            printf("%s%d-%d-%d\n", successMsg, date.day, date.month, date.year);
        else
            printf("%s", errorMsg);
    }
}

/*
 *  Function
 *  To print out the menu to the console
 */
void getUserChoice(int *userChoice)
{
    printf("MENU\n---------------------------\n\n");
    printf("1- Processing date data\n");
    printf("2- Character data\n");
    printf("3- Quit\n");
    printf("Enter your choice: ");

    *userChoice = getIntInput(1, 3);
}

/*
 *  Function
 *  Printing output in descending orders of ASCII codes of all characters
 *  between the 2 inputted characters (inclusively) to standard output
 */
void printCharactersData(char c1, char c2)
{
    int i;

    printf("Converting characters to ASCII Code:\n");
    /* to print out characters and
     * its corresponding ASCII terms
     * in Descending order */
    if (c1 < c2)
        for (i = c2; i >= c1; i--)
            printf("  %c:%d\n", i, i);
    else
        for (i = c1; i >= c2; i--)
            printf("  %c:%d\n", i, i);
}

/*
 *  Function
 *  To rerun program as soon as it be invoked
 */
void rerunProgram()
{
    fflush(stdin);
    printf("\n");
    main();
}

int main()
{
    int userChoice;
    char c1, c2;
    Date date;

    // prompt user to get their choice then performing corresponding function
    getUserChoice(&userChoice);

    switch (userChoice)
    {
    case 1:
        getDateInfo(&date);
        processDateInfo(date);
        break;
    case 2:
        getCharInput(&c1, &c2);
        printCharactersData(c1, c2);
        break;
    case 3:
        exit(0);
    }

    rerunProgram();

    return 0;
}

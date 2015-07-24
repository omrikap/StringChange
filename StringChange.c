/**
 * @file StringChange.c
 * @author  Omri Kaplan
 * @date 24 Jul 2015
 *
 * @brief A string manipulator.
 *
 * @section DESCRIPTION
 * This program get a string from the user, and turn all uppercase letter into lowercase
 * letters, and all lowercase into uppercase. It changes digits between 0 and 5 to 0, and
 * larger digits, to 8. The rest of charachters remain the same.
 */
// ------------------------------ includes ------------------------------
#include <stdio.h>

// -------------------------- const definitions -------------------------
#define END_OF_STRING '\0'

/**
 * @def GET_STRING_UNTIL_RETURN_HIT "%[^\n]%*c"
 * @brief A macro to get string from the user until he\she hit return key.
 */
#define GET_STRING_UNTIL_RETURN_HIT "%[^\n]%*c"
#define CHANGE_TO_UPPERCASE(x) (x - 32)
#define CHANGE_TO_LOWERCASE(x) (x + 32)
#define NONE 0

char userInput[51];
char changedString[51];

// ------------------------------ functions -----------------------------
/**
 * @brief The main function, performs the manipulation on the string.
 * @return 0, to tell the system the program ended as expected.
 */
int main() {
    scanf(GET_STRING_UNTIL_RETURN_HIT, userInput);
    int c = 0;
    while (userInput[c] != END_OF_STRING)
    {
        char cur = userInput[c];
        if (cur >= 'A' && cur <= 'Z') // if cur is an Uppercase letter.
        {
            changedString[c] = CHANGE_TO_LOWERCASE(cur);
        } else if (cur >= 'a' && cur <= 'z') // if cur is an Lowercase letter.
        {
            changedString[c] = CHANGE_TO_UPPERCASE(cur);
        } else if (cur >= '5' && cur <= '9') // if cur is a digit between 5 and 9.
        {
            changedString[c] = '8';
        } else if (cur >= '0' && cur < '5') // if cur is a digit between 0 and 5.
        {
            changedString[c] = '0';
        } else
        {
            changedString[c] = cur;
        }
        c++;
    }
    printf("\"%s\" -> \"%s\"", userInput, changedString);
    return NONE;
}
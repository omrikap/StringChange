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
 * larger digits, to 8. The rest of characters remain the same.
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
#define THE_CHARACTER_LOWER_A 'a'
#define THE_CHARACTER_LOWER_Z 'z'
#define THE_CHARACTER_CAPITAL_A 'A'
#define THE_CHARACTER_CAPITAL_Z 'Z'
#define THE_CHARACTER_5 '5'
#define THE_CHARACTER_9 '9'
#define THE_CHARACTER_8 '8'
#define THE_CHARACTER_0 '0'

char userInput[51];
char changedString[51];

// ------------------------------ functions -----------------------------
/**
 * @brief The main function, performs the manipulation on the string.
 * @return 0, to tell the system the program ended as expected.
 */
int main()
{
    scanf(GET_STRING_UNTIL_RETURN_HIT, userInput);
    int c = 0;
    while (userInput[c] != END_OF_STRING)
    {
        char cur = userInput[c];
        if (cur >= THE_CHARACTER_CAPITAL_A && cur <= THE_CHARACTER_CAPITAL_Z)
        {
            changedString[c] = CHANGE_TO_LOWERCASE(cur);
        }
        else if (cur >= THE_CHARACTER_LOWER_A && cur <= THE_CHARACTER_LOWER_Z)
        {
            changedString[c] = CHANGE_TO_UPPERCASE(cur);
        }
        else if (cur >= THE_CHARACTER_5 && cur <= THE_CHARACTER_9)
        {
            changedString[c] = THE_CHARACTER_8;
        }
        else if (cur >= THE_CHARACTER_0 && cur < THE_CHARACTER_5)
        {
            changedString[c] = THE_CHARACTER_0;
        }
        else
        {
            changedString[c] = cur;
        }
        c++;
    }
    printf("\"%s\" -> \"%s\"\n", userInput, changedString);
    return NONE;
}
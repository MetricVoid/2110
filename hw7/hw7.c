/**
 * @file hw7.c
 * @author YOUR NAME HERE
 * @brief Command-line argument & expression parsing logic
 * @date 2020-03-xx
 */

// DO NOT MODIFY THE INCLUDE(s) LIST
#include <stdio.h>
#include "hw7.h"
#include "errcodes.h"
// #include "my_string.c"

#define FALSE 0
#define TRUE 1

// One-time defined global array of expressions
struct expression arr[MAX_NUMBER_OF_EXPRESSIONS];

/**
 * @brief Convert a string containing ASCII characters (in decimal) to an int.
 * 
 * @param str A null-terminated C string
 * @return int the corresponding decimal value of the passed in str
 */
int decimalStringToInt(const char *str)
{
    // UNUSED_PARAM(str);
    int result = 0;
    size_t i = 0;
    while (*(str + i) != 0) {
        result *= 10;
        result += (*(str+i) - '0');
        i = i + 1;
    }
    return result;
}

/**
 * @brief Convert a string containing ASCII characters (in hex) to an int.
 * 
 * @param str A null-terminated C string
 * @return int the corresponding decimal value of the passed in hexadecimal str
 */
int hexStringToInt(const char *str)
{
    int result = 0;
    size_t i = 0;
    while (*(str + i) != 0) {
        result *= 16;
        char temp = *(str+i);
        if (temp - 'A' < 0) {
            result += (temp - '0');
        } else {
            result += (temp - 'A' + 10);
        }
        i = i + 1;
    }
    return result;
}

/**
 * @brief Parser algorithm for determining the result of a basic math expression.
 * 
 * @param expression A null terminated expression retrieved as a command line arg
 * @param index Indicating the corresponding struct in the global struct array (for this expression) to be populated
 */
void parseExpression(char *expression, int index)
{
    UNUSED_PARAM(expression);
    UNUSED_PARAM(index);
    int len = 0;
    int start = 0;
    size_t i = 0;
    int flag = 0;
    int sum = 0; 
    // my_strncpy(expression, arr[].buffer, my_);
    while (*(expression + i) != 0) {
        char temp = *(expression + i);
        if (temp - '0' >= 0 && temp - '9' <= 0) {
            if (temp == '0' && *(expression + i + 1) == 'x') {
                flag = 1; 
            }
            len = len + 1;
        } else {
            char temp2[len+1];
            my_strncpy(temp2, expression + start, len);
            temp2[len] = 0;
            printf("%s",temp2);
            if (flag == 1) {
                sum = sum + hexStringToInt(temp2);
            } else {
                sum += decimalStringToInt(temp2);
            }
            start = i + 2;
        }
        if (flag == 1) {
            i = i + 2;
            start = start + 2;
        } else {
            i = i + 1;
        }

    }
    

    // TODO: Iterate through the string, parsing each sum term and adding them to a result
    
    // TODO: Initialize the struct info for this expression and write it to the struct
}

/**
 * @brief Helper method for printing out the global array struct info
 * DO NOT MODIFY THIS METHOD AS IT IS USED FOR THE LAST STEP (PIPE).
 */
void printArrayDebug(void)
{
    // Safety check
    if (sizeof(arr) / sizeof(arr[0]) != MAX_NUMBER_OF_EXPRESSIONS)
    {
        printf("ERROR: MISMATCH ARRAY LENGTH WITH MACRO: MAX_NUMBER_OF_EXPRESSIONS.\n");
        return;
    }

    for (int i = 0; i < MAX_NUMBER_OF_EXPRESSIONS; i++)
    {
        printf("\nStruct info at index %d:\n", i);
        printf("Expression: %s\n", arr[i].buffer);
        printf("Result: %d\n", arr[i].result);
        printf("ErrorCode: %u\n", arr[i].errorCode);
        printf("---------------------\n");
    }
}

/**
 * @brief Main method, responsible for parsing command line argument and populating expression structs in the global arr
 * 
 * @param argc argument count
 * @param argv argument vector (it's an array of strings)
 * @return int status code of the program termination
 */
int my_main(int argc, char const *argv[])
{
    UNUSED_FUNC(hexStringToInt);
    UNUSED_FUNC(parseExpression);
    UNUSED_FUNC(printArrayDebug);
    UNUSED_FUNC(decimalStringToInt);
    UNUSED_PARAM(argv);
    
    // Initial check: We need at least 1 math expression passed in
    // ( Yes argc can possibly be zero! But we don't worry about that too much in this hw :) )
    if (argc < 2)
    {
        printf("USAGE:   ./hw7 [-d] \"basic math expressions separated by quotation marks\"\n");
        printf("EXAMPLE: ./hw7 \"3+0x40-7+5\" \"0xA6+5000-45\"\n");
        printf("EXAMPLE FOR PRINTING OUT DEBUG INFO: ./hw7 -d \"3+0x40-7+5\" \"0xA6+5000-45\"\n");
        return 1; // Exit failure (value is implementation defined)
    }

    // Note 1: If debug flag is presented in any other location besides argv[1], it should be treated as a bad HEX value

    // Note 2: In order to protect our struct array from overflow and undefined behavior,
    // we need to make sure we don't pass in more command-line arguments than necessary.
    // Later on in the course you will learn how to dynamically allocate space for situations like this!

    return 0; // EXIT_SUCCESS
}


/**
 * @file my_string.c
 * @author YOUR NAME HERE
 * @brief Your implementation of these famous 3 string.h libraries!
 * 
 * NOTE: NO ARRAY NOTATION IS ALLOWED IN THIS FILE
 * 
 * @date 2020-03-xx
 */

// DO NOT MODIFY THE INCLUDE(s) LIST
#include <stddef.h>
#include "hw7.h"

/**
 * @brief Calculate the length of a string
 * 
 * @param s a constant C string
 * @return size_t the number of characters in the passed in string
 */
size_t my_strlen(const char *s)
{
    int len = 0;
    while (*s != 0) {
        len = len + 1;
        s = s + 1;
    }
    return len;
}

/**
 * @brief Compare two strings
 * 
 * @param s1 First string to be compared
 * @param s2 Second string to be compared
 * @param n First (at most) n bytes to be compared
 * @return int "less than, equal to, or greater than zero if s1 (or the first n bytes thereof) is found, respectively, to be less than, to match, or be greater than s2"
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;   //native unsigned int 
    while (*(s1 + i) != 0 && *(s2+i) != 0 && i < n) {
        char tmp = *(s1+i) - *(s2+i);
        if (tmp) {
            return tmp ;
        }
        i = i + 1;
    }
    return *(s1+i) - *(s2+i);
}

/**
 * @brief Copy a string
 * 
 * @param dest The destination buffer
 * @param src The source to copy from
 * @param n maximum number of bytes to copy
 * @return char* a pointer same as dest
 */
char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;
    while (*(src+i) != 0 && i<n) {
        *(dest+i) = *(src + i);
        i = i + 1;
    }
    if (i < n) {
        *(dest+i) = *(src + i); //early termination when i < n
    }
    return dest;
}

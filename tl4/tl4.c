/**
 * CS 2110 - Spring 2020 - Timed Lab #4
 *
 * @author YOUR NAME HERE
 *
 * tl4.c: Complete the functions!
 */

// Do not add ANY additional includes!!!
#include "tl4.h"

#include "string.h"

///* You should NOT have any global variables. */

/// HINT: C doesn't initialize values for you, so make sure you initialize all
/// variables yourself!

/** deep_copy
 *
 * Creates a new deep-copied list of the original list.
 *
 * If listToCopy is NULL return NULL. For any memory allocations
 * failures your code must not leak memory. This means that if any
 * memory allocation failures occur, before you return NULL, you must destroy
 * the list
 *
 * @param listToCopy A pointer to the struct list structure to make a copy of
 * @return The struct list structure created by copying the old one, or NULL on
 *         failure (includes any of the parameters being null)
 */
struct list *deep_copy(struct list *listToCopy) {
  UNUSED_PARAMETER(listToCopy);
  return NULL;
}

/** Destroy
 *
 * Destroys the entire struct list. This function removes every list node
 * and finally remove the list itself.
 *
 * HINT: remember every malloc needs a respective free
 *
 * @param listToDestroy a pointer to the struct list
 */
void destroy(struct list *listToDestroy) { UNUSED_PARAMETER(listToDestroy); }

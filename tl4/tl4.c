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
  if (!listToCopy) {
    return NULL;
  }
  struct list* nl = calloc(1, sizeof(struct list));
  if (nl) {
    struct node** ptr_nl_cur = &nl->head;
    struct node** ptr_cur = &listToCopy->head;
    while (*ptr_cur) {
      // Copy a node
      // Allocate String
      size_t slen = strlen((*ptr_cur)->data) + 1;
      char *chr = malloc(sizeof(char) * slen);
      if (!chr) {
        destroy(nl);
        return NULL;
      }
      strcpy(chr, (*ptr_cur)->data);
      // Alloc Node
      struct node* nn = calloc(1, sizeof(struct node));
      if (!nn) {
        free(chr);
        destroy(nl);
        return NULL;
      }
      nn->id = (*ptr_cur)->id;
      nn->data = chr;
      *ptr_nl_cur = nn;
      ptr_nl_cur = &(*ptr_nl_cur)->next;
      ptr_cur = &(*ptr_cur)->next;
    }
    return nl;
  }
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
void destroy(struct list *listToDestroy) {
  UNUSED_PARAMETER(listToDestroy); 
  if (listToDestroy) {
    struct node *cur = listToDestroy -> head;
    while (cur) {
      free(cur -> data);
      struct node *next = cur -> next;
      free(cur);
      cur = next;
    }
    listToDestroy-> head = NULL;
  }
  free(listToDestroy);
}

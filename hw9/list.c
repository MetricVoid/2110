/**
 * CS 2110 - Spring 2020 - Homework #9
 *
 * @author YOUR NAME HERE
 *
 * list.c: Complete the functions!
 */

/**
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!-IMPORTANT-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * For any function that must use malloc, if malloc returns NULL, the function
 * itself should return NULL if needs to return something (or return 1 if
 * the function returns a int).
 */

// Do not add ANY additional includes!!!
#include "list.h"
//
#include <stdio.h>
void print(LinkedList *list);

/* You should NOT have any global variables. */

/* The create_node function is static because this is the only file that should
   have knowledge about the nodes backing the linked List. */
static inline Node *create_node(char *data);

/** create_node
  *
  * Helper function that creates a Node by allocating memory for it on the heap.
  * Be sure to set its next pointer to NULL.
  *
  * If malloc returns NULL, you should return NULL to indicate failure.
  *
  * @param data a void pointer to data the user wants to store in List
  * @return a Node
  */
static Node* create_node(char *data)
{
    // UNUSED_PARAMETER(data);
    Node *lnode;
    lnode = malloc(sizeof(Node));
    if (lnode == NULL) {
      return NULL;
    } else if (data == NULL) {
      lnode -> data = NULL;
      lnode -> next = NULL;
      return lnode;
    }
    lnode -> data = data;
    lnode -> next = NULL;
    return lnode;
}

/** create_list
  *
  * Creates a struct linked_list by allocating memory for it on the heap.
  * Be sure to initialize size to zero and head and tail to NULL.
  *
  * If malloc returns NULL, you should return NULL to indicate failure.
  *
  * @return a pointer to a new struct list or NULL on failure
  */
LinkedList *create_list(void)
{
    // return NULL;
    LinkedList *l;
    l = malloc(sizeof(LinkedList));
    if (l == NULL) {
      return NULL;
    }
    l -> size = 0;
    l -> head = NULL;
    // l -> tail = NULL;
    return l;
}

/** push_front
  *
  * Adds the element at the front of the struct linked_list.
  *
  * @param list a pointer to the struct linked_list structure.
  * @param data the data to add to the struct linked_list.
  * @return  1 if the struct linked_list is NULL, 0 if successful,
  */
int push_front(LinkedList *list, char *data)
{
    // UNUSED_PARAMETER(list);
    // UNUSED_PARAMETER(data);
    if (list == NULL) {
      return 1;
    }
    Node *newNode = create_node(data);
    Node *head = list -> head;
    if (!head) {
      // list -> tail = newNode;
      list -> head = newNode;
    } else {
      list -> head = newNode;
      newNode -> next = head;
    }
    list -> size++;
    // if (list -> head == list -> tail || !head) {
    //   list -> tail = newNode;
    // } else {
    //   newNode -> next = head;
    // }
    // if (*list == NULL) {
    //   return 1;
    // }
    return 0;
}

/** push_back
  *
  * Adds the element to the back of the LinkedList.
  *
  * @param list a pointer to the LinkedList structure.
  * @param data the data to add to the LinkedList.
  * @return 1 if the LinkedList is NULL, 0 if successful.
  */
int push_back(LinkedList *list, char *data)
{
    // UNUSED_PARAMETER(list);
    // UNUSED_PARAMETER(data);
    if (list == NULL) {
      return 1;
    }
    Node *newNode = create_node(data);
    if (!list -> head) {
      list -> head = newNode;
      list -> size++;
      return 0;
    }
    Node *cur = list -> head;
    while (cur -> next) {
      cur ++;
    }
    if (!list -> head) {
      list -> head = newNode;
    } else {
      cur -> next = newNode;
    }
    // list -> tail = newNode;
    list -> size++;

    // if (*list == NULL) {
    //   return 1;suites/test_utils.c:19:E:test_list_add_at_index_null:test_list_a
    // }
    return 0;
}

/** add_at_index
  *
  * Add the element at the specified index in the LinkedList. This index must lie in
  * the inclusive range [0,size].
  * For example, if you have no elements in the LinkedList,
  * you should be able to add to index 0 but no further.
  * If you have two elements in the LinkedList,
  * you should be able to add to index 2 but no further.
  *
  * @param list a pointer to the LinkedList structure
  * @param index 0-based, starting from the head in the inclusive range
  *              [0,size]
  * @param data the data to add to the LinkedList
  * @return 1 if the index is out of bounds or the LinkedList is NULL
  *         (do not add the data in this case)
  *         otherwise (on success) return 0
  */
// add_at_index(l1, ((void *)0), 0) == 0
int add_at_index(LinkedList *list, char *data, int index)
{
    UNUSED_PARAMETER(list);
    UNUSED_PARAMETER(data);
    UNUSED_PARAMETER(index);
    if (list == NULL){
      // printf("ERROR\n");
      // printf("list: %d, data: %d\n", list ==NULL, data ==NULL);
      return 1;
    }
    if (data == NULL) {
      list -> head = create_node(NULL);
      list -> size ++;
      return 0;
    }
    if (index > list -> size || index <0) {
      // printf("index is %d, data is %d\n",index, *data);
      // printf("INDEX\nERROR\n");
      return 1;
    }

    // printf("index is %d, data is %d\n",index, *data);
    // print(list);
    Node *newNode = create_node(data);
    if (index == 0) {
      // return push_front(list, data);
      newNode -> next = list -> head;
      list-> head = newNode;
      list -> size++;
    } else if (index == list -> size) {
      return push_front(list, data);
    } else {
      int count = 0;
      Node *cur = list -> head;
      while (count != index - 1) {
        cur = cur -> next;
        count ++;
        // printf("index: %d, data: %d\n", count, *(cur -> data));
      }
      newNode -> next = cur -> next;
      cur -> next = newNode;
      list -> size++;
      // print(list);
      // printf("The data is %d, The index is %d, count is %d\n", *data, index, count);
      return 0;
    }
    return 0;
}

void print(LinkedList *list) {
  Node *cur = list -> head;
  int count = 0;
  printf("print list \n");
  while (cur -> next) {
    printf("index: %d, data: %d\n", count, *(cur -> data));
    cur = cur -> next;
    count ++;
  }
  printf("index: %d, data: %d\n", count, *(cur -> data));
}

/** get
  *
  * Gets the data at the specified index in the LinkedList
  *
  * @param list a pointer to the LinkedList structure
  * @param index 0-based, starting from the head.
  * @param dataOut A pointer to a pointer used to return the data from the
  *        specified index in the LinkedList or NULL on failure.
  * @return 1 if dataOut is NULL or index is out of range of the LinkedList or
  *         the LinkedList is NULL, 0 (on success) otherwise
  */
int get(LinkedList *list, int index, char **dataOut)
{
    if (dataOut ==NULL || list == NULL) {
      return 1;
    }
    if (index > list -> size - 1 || index < 0){
      return 1;
    }
    Node *cur = list -> head;
    int count = 0;
    while (count < index) {
      cur = cur -> next;
      count ++;
    }
    *dataOut = cur -> data;
    return 0;
}

/** contains
  *
  * Traverses the LinkedList, trying to see if the LinkedList contains some
  * data. We say the list contains the data if the data string of the node 
  * matches the node passed in.
  *
  * You may use the string library functions to complete this comparison
  * (see what is included in list.h)
  * 
  * If there are multiple pieces of data in the LinkedList which are equal to
  * the "data" parameter, return the one at the lowest index.
  *
  *
  * @param list a pointer to the LinkedList structure
  * @param data The data, to see if it exists in the LinkedList
  * @param dataOut A pointer to a pointer used to return the data contained in
  *                the LinkedList or NULL on failure
  * @return int    0 if dataOut is NULL, the list is NULL, or the list
  *                does not contain data, else 1
  */
int contains(LinkedList *list, char *data, char **dataOut)
{
    UNUSED_PARAMETER(list);
    UNUSED_PARAMETER(data);
    UNUSED_PARAMETER(dataOut);
    if (dataOut ==NULL || list == NULL) {
      dataOut =NULL;
      return 0;
    }
    if (list -> head == NULL){
      dataOut =NULL;
      return 0;
    }
    Node *cur = list -> head;
    int flag = 1;
    while (cur -> next && flag == 1) {
      cur = cur -> next;
      printf("flag, toCompare: %c\n", *(cur -> data));
      if (strcmp(cur -> data, (char *) data) == 0) {
        flag = 0;
        printf("data is %c, this is same: %c\n", *data, *(cur -> data));
        *dataOut = cur -> data;
        return 1;
      } else {
        printf("data is %c, this is different: %c\n", *data, *(cur -> data));
      }
    }
    printf("Not found!\n");
    dataOut=NULL;
    return 1;
}

/** pop_front
  *
  * Removes the List_node at the front of the LinkedList, and returns its data to the user.
  *
  * @param list a pointer to the LinkedList.
  * @param dataOut A pointer to a pointer used to return the data in the first
  *                List_node or NULL if the LinkedList is NULL or empty
  * @return 1 if dataOut is NULL (the LinkedList is NULL or empty), else (on success) 0
  */
int pop_front(LinkedList *list, char **dataOut)
{
    UNUSED_PARAMETER(list);
    UNUSED_PARAMETER(dataOut);
    if (list == NULL) {
      return 1;
    }
    Node *front = list -> head;
    if (front != NULL) {
      Node *head = list -> head;
      Node *next = front -> next;
      list -> head = next;
      free(front);
      list -> size--; 
      *dataOut = head -> data;
      if (!list -> size) {
        list -> head = NULL;
      }
      return 0;
    }
    return 1;
}

/** pop_back
  *
  * Removes the ListNode at the back of the LinkedList, and returns its data to the user
  *
  * @param list a pointer to the LinkedList.
  * @param dataOut A pointer to a pointer used to return the data in the last
  *                ListNode or NULL if the LinkedList is NULL or empty
  * @return 1 if dataOut is NULL (the LinkedList is NULL or empty), else (on success) 0
  */
int pop_back(LinkedList *list, char **dataOut)
{
    UNUSED_PARAMETER(list);
    UNUSED_PARAMETER(dataOut);
    return 0;
}


/** remove_at_index
  *
  * Remove the element at the specified index in the LinkedList.
  *
  * @param list a pointer to the LinkedList structure
  * @param index 0-based, starting from the head in the inclusive range
  *              [0,size]
  * @param data the data to remove from the LinkedList
  * @return 1 if the index is out of bounds, the LinkedList is NULL or
  *         the dataOut is NULL
  *         otherwise return 0
  */
int remove_at_index(LinkedList * list, char **dataOut, int index) 
{
    UNUSED_PARAMETER(list);
    UNUSED_PARAMETER(index);
    UNUSED_PARAMETER(dataOut);
    return 0;
}

/** empty_list
  *
  * Empties the LinkedList. After this is called, the LinkedList should be
  * empty. This does not free the LinkedList struct itself, just all nodes and
  * data within. Make sure to check that listToEmpty is not NULL before
  * using it.
  *
  * You may call free on a char pointer as well as a node struct pointer.
  *
  * @param list a pointer to the LinkedList structure
  */
void empty_list(LinkedList *list)
{
    list-> head = NULL;
    list -> size = 0;
}


/** merge_nodes
  *
  *
  * Concatenate the string data in two adjacent nodes (at index and index + 1), 
  * then remove the extra un-merged node. 
  *
  *     LinkedList *A: "CS" -> "2110" -> "Rocks" -> "!" -> NULL
  *
  *     merge_nodes(A, 0): "CS2110" -> "Rocks" -> "!" -> NULL
  *
  * @param list  LinkedList to operate on
  * @param index  Index of the first node to merge
  * @return 1 if the index is out of bounds, or the LinkedList is NULL
  *         otherwise return 0
  */
int merge_nodes(LinkedList *list, int index)
{
    UNUSED_PARAMETER(list);
    UNUSED_PARAMETER(index);
    return 0;
}



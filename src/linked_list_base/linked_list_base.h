#ifndef __LINKED_LIST_BASE_H_
#define __LINKED_LIST_BASE_H_

#include <stdlib.h> /* malloc, calloc, realloc, free */

/**
 * @struct: EmeraldsLLNode
 * @desc: A linked list node with a typed object item
 * @param item -> The typed object contained in the linked list node
 * @param next -> The next node on the linked list
 **/
struct EmeraldsLLNode {
  void *item;
  struct EmeraldsLLNode *next;
};

/**
 * @struct: EmeraldsLinkedList
 * @desc: A helper linked list helper struct containing the head node
 * @param length -> The number of elements in the linked list
 * @param head -> The head node of the list
 **/
typedef struct EmeraldsLinkedList {
  size_t length;
  struct EmeraldsLLNode *head;
} EmeraldsLinkedList;

/**
 * @func: linked_list_new
 * @desc: Creates a new linked list instance and initiates the head node
 * @return The newly created typed linked list
 **/
EmeraldsLinkedList *linked_list_new(void);

/**
 * @func: linked_list_add
 * @desc: Adds a new node in the linked list
 * @param list -> The list to append to
 * @param obj -> The node to append
 **/
void linked_list_add(EmeraldsLinkedList *list, void *obj);

/**
 * @func: linked_list_remove
 * @desc: Finds and removes a node from the list
 * @param list -> The list to remove from
 * @param obj -> The node to remove
 **/
void linked_list_remove(EmeraldsLinkedList *list, void *obj);

/**
 * @func: linked_list_free
 * @brief Frees the list structure
 * @param list -> The list to free
 */
void linked_list_free(EmeraldsLinkedList *list);

#endif

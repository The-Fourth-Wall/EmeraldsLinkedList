#include "linked_list_base.h"

EmeraldsLinkedList *linked_list_new(void) {
  EmeraldsLinkedList *list =
    (EmeraldsLinkedList *)malloc(sizeof(EmeraldsLinkedList));
  list->head   = NULL;
  list->length = 0;
  return list;
}

void linked_list_add(EmeraldsLinkedList *list, void *item) {
  struct EmeraldsLLNode **probe  = NULL;
  struct EmeraldsLLNode *newnode = NULL;

  if(list == NULL || item == NULL) {
    return;
  }

  /* Use the address to take advantage of a pointer to pointer approach */
  probe = &(list->head);

  /* Create a new node */
  newnode = (struct EmeraldsLLNode *)malloc(sizeof(struct EmeraldsLLNode));
  newnode->item = (void *)malloc(sizeof(item));
  newnode->item = item;

  /* Traverse to the end of the linked list */
  while(*probe) {
    probe = (struct EmeraldsLLNode **)&(*probe)->next;
  }

  newnode->next = (struct EmeraldsLLNode *)*probe;
  *probe        = newnode;
  list->length++;
}

/* TODO -> FIX MEMORY WHEN REMOVING */
void linked_list_remove(EmeraldsLinkedList *list, void *item) {
  struct EmeraldsLLNode **probe = NULL;

  if(list == NULL || item == NULL) {
    return;
  }

  probe = &(list->head);

  while((*probe) && (*probe)->item != list) {
    probe = (struct EmeraldsLLNode **)&(*probe)->next;
  }

  *probe = (struct EmeraldsLLNode *)((*probe)->next);
}

void linked_list_free(EmeraldsLinkedList *list) {
  struct EmeraldsLLNode **probe = NULL;
  struct EmeraldsLLNode *next   = NULL;

  if(list == NULL) {
    return;
  }

  probe = &(list->head);

  while(*probe) {
    next = (*probe)->next;
    free(*probe);
    *probe = next;
  }

  list->head   = NULL;
  list->length = 0;
}

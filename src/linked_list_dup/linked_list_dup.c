#include "linked_list_dup.h"

EmeraldsLinkedList *linked_list_dup(EmeraldsLinkedList *list) {
  struct EmeraldsLLNode **probe = NULL;
  EmeraldsLinkedList *dup       = NULL;

  if(list == NULL) {
    return NULL;
  }

  /* Use the address to take advantage of a pointer to pointer approach */
  probe = &(list->head);
  dup   = linked_list_new();

  while(*probe) {
    linked_list_add(dup, (*probe)->item);

    /* Move to the next item */
    probe = (struct EmeraldsLLNode **)&(*probe)->next;
  }

  return dup;
}

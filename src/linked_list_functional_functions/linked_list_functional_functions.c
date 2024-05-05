#include "linked_list_functional_functions.h"

EmeraldsLinkedList *
linked_list_map(EmeraldsLinkedList *list, EmeraldsLinkedListLambda1 modifier) {
  EmeraldsLinkedList *dup       = NULL;
  struct EmeraldsLLNode **probe = NULL;

  if(list == NULL || modifier == NULL) {
    return NULL;
  }

  dup = linked_list_new();

  /* Typecast and use the address to take advantage of a pointer to pointer
   * approach */
  probe = &(list->head);

  /* Dereference once */
  while(*probe) {
    void *item = (*probe)->item;
    linked_list_add(dup, modifier(item));

    /* Point probe to the next node */
    probe = (struct EmeraldsLLNode **)&(*probe)->next;
  }

  return dup;
}

EmeraldsLinkedList *
linked_list_filter(EmeraldsLinkedList *list, EmeraldsLinkedListLambda1 filter) {
  EmeraldsLinkedList *dup       = NULL;
  struct EmeraldsLLNode **probe = NULL;

  if(list == NULL || filter == NULL) {
    return NULL;
  }

  dup = linked_list_new();

  /* Typecast and use the address to take advantage of a pointer to pointer
   * approach */
  probe = &(list->head);

  /* Dereference once */
  while(*probe) {
    void *item = (*probe)->item;
    if(!filter(item)) {
      linked_list_add(dup, item);
    }

    /* Point probe to the next node */
    probe = (struct EmeraldsLLNode **)&(*probe)->next;
  }

  return dup;
}

void *
linked_list_reduce(EmeraldsLinkedList *list, EmeraldsLinkedListLambda2 fold) {
  struct EmeraldsLLNode **probe = NULL;
  void *accumulator             = NULL;

  if(list == NULL || fold == NULL) {
    return NULL;
  }

  probe = (&list->head);

  /* Get the initial value */
  /* Create the value that gets returned with the accumulation of the vector
   * elements */
  accumulator = (*probe)->item;

  /* Start counting from the next */
  probe = (struct EmeraldsLLNode **)&(*probe)->next;

  while(*probe) {
    void *current = (*probe)->item;
    accumulator   = fold(accumulator, current);
    probe         = (struct EmeraldsLLNode **)&(*probe)->next;
  }

  return accumulator;
}

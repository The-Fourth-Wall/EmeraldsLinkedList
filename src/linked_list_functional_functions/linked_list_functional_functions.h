#ifndef __LINKED_LIST_FUNCTIONAL_FUNCTIONS_H_
#define __LINKED_LIST_FUNCTIONAL_FUNCTIONS_H_

#include "../linked_list_base/linked_list_base.h"

/**
 * @func: EmeraldsLinkedListLambda
 * @desc: A generic function type used upon iterable data structures
 * @param -> An element belonging to an iterable
 * @return -> A value that satisfies the callee's purpose (map, filter, reduce)
 **/
/* The param void* can have more than 1 argument stored as a list of some sort
 */
/* Since this is completely generic we can't check for validity of arguments */
/* The validity of the function is dependent on the callee */
typedef void *(*EmeraldsLinkedListLambda1)(void *);
typedef void *(*EmeraldsLinkedListLambda2)(void *, void *);

/**
 * @func: linked_list_map
 * @desc: Maps all linked list elements in iteration using a modifier function
 *pointer
 * @param list -> The linked list to map
 * @param modifier -> The modifier function
 * @return The mapped linked list duplicate
 **/
EmeraldsLinkedList *
linked_list_map(EmeraldsLinkedList *list, EmeraldsLinkedListLambda1 modifier);

/**
 * @func: linked_list_filter
 * @desc: Filters all linked list elements in iteration using a filter function
 * @param list -> The linked list to filter
 * @param filter -> The filter functions
 * @return The filtered linked list duplicate
 **/
EmeraldsLinkedList *
linked_list_filter(EmeraldsLinkedList *list, EmeraldsLinkedListLambda1 filter);

/**
 * @func: linked_list_reduce
 * @desc: Reduces all linked list elements to some accumulated value using a
 *fold function
 * @param obj -> The linked list to reduce
 * @param fold -> The fold function
 * @return The accumulated result
 **/
void *
linked_list_reduce(EmeraldsLinkedList *list, EmeraldsLinkedListLambda2 fold);

#endif

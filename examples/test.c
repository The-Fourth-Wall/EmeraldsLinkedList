#include "../export/EmeraldsLinkedList.h" /* IWYU pragma: keep */

int double_item(int item) { return item * 2; }

int positive_filter(int item) { return item < 0; }

int adder(int accumulator, int current) { return accumulator + current; }

int main(void) {
  EmeraldsLinkedList *llist                = linked_list_new();
  EmeraldsLinkedList *double_list          = NULL;
  EmeraldsLinkedList *positive_double_list = NULL;
  long lsum;

  printf("TESTING LINKED LIST\n");
  linked_list_add(llist, (void *)-1);
  linked_list_add(llist, (void *)-2);
  linked_list_add(llist, (void *)-3);
  linked_list_add(llist, (void *)1);
  linked_list_add(llist, (void *)2);
  linked_list_add(llist, (void *)-4);
  linked_list_add(llist, (void *)-5);
  linked_list_add(llist, (void *)3);
  linked_list_add(llist, (void *)4);
  linked_list_add(llist, (void *)5);

  double_list = linked_list_map(llist, (EmeraldsLinkedListLambda1)double_item);
  positive_double_list =
    linked_list_filter(double_list, (EmeraldsLinkedListLambda1)positive_filter);
  lsum = (long
  )linked_list_reduce(positive_double_list, (EmeraldsLinkedListLambda2)adder);
  printf("LL SUM: `%ld` should be `30`\n", lsum);

  linked_list_free(llist);
  linked_list_free(double_list);
  linked_list_free(positive_double_list);

  return 0;
}

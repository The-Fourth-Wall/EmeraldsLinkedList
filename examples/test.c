#include "../export/LinkedList.h"

int double_item(int item) {
    return item * 2;
}

int positive_filter(int item) {
    return item < 0;
}

int adder(int accumulator, int current) {
    return accumulator + current;
}

int main(void) {
    linked_list *llist = linked_list_new();
    linked_list *double_list = NULL;
    linked_list *positive_double_list = NULL;
    long lsum;

    printf("TESTING LINKED LIST\n");
    linked_list_add(llist, (void*)-1);
    linked_list_add(llist, (void*)-2);
    linked_list_add(llist, (void*)-3);
    linked_list_add(llist, (void*)1);
    linked_list_add(llist, (void*)2);
    linked_list_add(llist, (void*)-4);
    linked_list_add(llist, (void*)-5);
    linked_list_add(llist, (void*)3);
    linked_list_add(llist, (void*)4);
    linked_list_add(llist, (void*)5);
    
    double_list = linked_list_map(llist, (linked_list_lambda)double_item);
    positive_double_list = linked_list_filter(double_list, (linked_list_lambda)positive_filter);
    lsum = (long)linked_list_reduce(positive_double_list, (linked_list_lambda)adder);
    printf("LL SUM: `%ld` should be `30`\n", lsum);

    linked_list_free(llist);
    linked_list_free(double_list);
    linked_list_free(positive_double_list);

    return 0;
}

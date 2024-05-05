#include "linked_list_base/linked_list_base.module.spec.h"
#include "linked_list_dup/linked_list_dup.module.spec.h"
#include "linked_list_functional_functions/linked_list_functional_functions.module.spec.h"

spec_suite({
  T_linked_list_base();
  T_linked_list_dup();
  T_linked_list_functional_functions();
});

int main(void) { run_spec_suite("all"); }

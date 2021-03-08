#include "LinkedList.spec.h"

module(T_LinkedList, {
    describe("#get_value", {
        it("returns `Hello, World!`", {
            assert_that_charptr("Hello, World!" equals to "Hello, World!");
        });
    });
});

spec_suite({
    T_LinkedList();
});

spec({
    run_spec_suite("all");
});

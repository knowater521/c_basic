#include <stdio.h>
#include "../tcut.h"

int nr_tests = 0;
int foo = 7;
int bar = 5;

static char* test_foo() {
    tcut_assert("error, foo != 7",foo == 7);
    return 0;
}
static char * test_bar() {
    tcut_assert("error, bar != 5",bar == 5);
    return 0;
}

static char * all_tests() {
    tcut_run_test(test_foo);
    tcut_run_test(test_bar);
    return 0;
}

int main(int argc, char ** argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n",result);
    } else {
        printf("All tests passed\n");
    }
    printf("Tests run: %d\n",nr_tests);
    return result != 0;
}

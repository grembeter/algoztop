#include <check.h>
#include <solution.h>
#include <stdlib.h>

#define ARRAY_COUNT(x) (sizeof(x)/sizeof(x[0]))

START_TEST(test_6)
{
    int buf[] = {1, 3, 7, 0, 5, 2, 3, 2};
    int wanted = 6;
    int total = trap_rain(buf, ARRAY_COUNT(buf));

    ck_assert_int_eq(wanted, total);
} END_TEST

Suite *test_suite(void);

Suite *test_suite()
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("rain");
    tc_core = tcase_create("core");

    tcase_add_test(tc_core, test_6);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

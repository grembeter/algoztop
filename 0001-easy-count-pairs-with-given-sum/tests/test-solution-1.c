#include <check.h>
#include <hashset.h>
#include <stdlib.h>

#define ARRAY_COUNT(x) (sizeof(x)/sizeof(x[0]))

START_TEST(test_1)
{
    struct pair *pair;
    int sum;
    int arr1[] = {6, 3, 5, 2, 1, 7};

    sum = 4;
    pair = find_2sum(sum, arr1, sizeof(arr1)/sizeof(arr1[0]));

    ck_assert_int_eq(pair->x + pair->y, sum);
} END_TEST

START_TEST(test_2)
{
    struct pair *pair;
    int sum;
    int arr2[] = {60, 30, 50, 20, 10, 70};

    sum = 400;
    pair = find_2sum(sum, arr2, sizeof(arr2)/sizeof(arr2[0]));

    ck_assert_int_eq(pair->x + pair->y, sum);
} END_TEST

Suite *test_suite(void);

Suite *test_suite()
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("rain");
    tc_core = tcase_create("core");

    tcase_add_test(tc_core, test_1);
    tcase_add_test(tc_core, test_2);
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

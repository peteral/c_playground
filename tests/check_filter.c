#include <check.h>
#include "../src/filter.h"

START_TEST (isphone_validnumber_returns_true)
{
  ck_assert(isphone('+'));
  ck_assert(isphone('0'));
  ck_assert(isphone('1'));
  ck_assert(isphone('2'));
  ck_assert(isphone('3'));
  ck_assert(isphone('4'));
  ck_assert(isphone('5'));
  ck_assert(isphone('6'));
  ck_assert(isphone('7'));
  ck_assert(isphone('8'));
  ck_assert(isphone('9'));
}
END_TEST

void setup(void)
{
}

void teardown(void)
{
}

Suite * filter_suite(void)
{
    Suite *s;
    TCase *tc_isphone;

    s = suite_create("Filter");

    tc_isphone = tcase_create("Is Phone");

    tcase_add_checked_fixture(tc_isphone, setup, teardown);
    tcase_add_test(tc_isphone, isphone_validnumber_returns_true);
    suite_add_tcase(s, tc_isphone);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = filter_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : -1;
}
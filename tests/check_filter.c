#include <check.h>
#include "../src/filter.h"

FILE * input;
FILE * output;

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

START_TEST (isphone_invalidnumber_returns_false)
{
  ck_assert(!isphone(' '));
  ck_assert(!isphone('x'));
  ck_assert(!isphone('!'));
}
END_TEST

START_TEST(assert_valid_argument_no_arguments_returns_false)
{
  ck_assert(!assert_valid_argument(0, NULL, output));
}
END_TEST

START_TEST(assert_valid_argument_no_arguments_prints_error)
{
  assert_valid_argument(0, NULL, output);

  rewind(output);
  char buffer[512];
  fgets(buffer, sizeof(buffer), output);
  ck_assert_str_eq(buffer, "Syntax: filter PATTERN < seznam.txt\n");
}
END_TEST

void setup(void)
{
  input = tmpfile();
  output = tmpfile();
}

void teardown(void)
{
  fclose(input);
  fclose(output);
}

TCase * isphone_case(void)
{
    TCase *testcase = tcase_create("isphone");

    tcase_add_checked_fixture(testcase, setup, teardown);
    tcase_add_test(testcase, isphone_validnumber_returns_true);
    tcase_add_test(testcase, isphone_invalidnumber_returns_false);
    return testcase;
}

TCase * assert_valid_argument_case(void)
{
    TCase *testcase = tcase_create("assert_valid_argument");

    tcase_add_checked_fixture(testcase, setup, teardown);
    tcase_add_test(testcase, assert_valid_argument_no_arguments_returns_false);
    tcase_add_test(testcase, assert_valid_argument_no_arguments_prints_error);
    return testcase;
}

Suite * filter_suite(void)
{
    Suite *s = suite_create("Filter");

    suite_add_tcase(s, isphone_case());
    suite_add_tcase(s, assert_valid_argument_case());

    return s;
}

int main(void)
{
    Suite *s = filter_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : -1;
}
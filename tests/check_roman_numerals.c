#include <config.h>
#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "../src/roman_numerals.h"

void setup(void)
{

}

void teardown(void)
{

}

START_TEST(converts_to_arabic)
{
    ck_assert_int_eq(to_arabic("I"), 1);
    ck_assert_int_eq(to_arabic("V"), 5);
    ck_assert_int_eq(to_arabic("X"), 10);
    ck_assert_int_eq(to_arabic("L"), 50);
    ck_assert_int_eq(to_arabic("C"), 100);
    ck_assert_int_eq(to_arabic("D"), 500);
    ck_assert_int_eq(to_arabic("M"), 1000);

    ck_assert_int_eq(to_arabic("II"), 2);
    ck_assert_int_eq(to_arabic("IV"), 4);
}
END_TEST

START_TEST(converts_to_roman)
{
    ck_assert_str_eq(to_roman(1), "I");
    ck_assert_str_eq(to_roman(2), "II");
    ck_assert_str_eq(to_roman(4), "IV");
}
END_TEST

Suite * roman_numerals_suite(void)
{
    Suite *s;
    TCase *tcase_converts_to_arabic;
    TCase *tcase_converts_to_roman;

    s = suite_create("Roman Numerals");

    tcase_converts_to_arabic = tcase_create("Converts to Arabic");
    tcase_add_checked_fixture(tcase_converts_to_arabic, setup, teardown);
    tcase_add_test(tcase_converts_to_arabic, converts_to_arabic);
    suite_add_tcase(s, tcase_converts_to_arabic);

    tcase_converts_to_roman = tcase_create("Converts to Roman");
    tcase_add_checked_fixture(tcase_converts_to_roman, setup, teardown);
    tcase_add_test(tcase_converts_to_roman, converts_to_roman);
    suite_add_tcase(s, tcase_converts_to_roman);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_numerals_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

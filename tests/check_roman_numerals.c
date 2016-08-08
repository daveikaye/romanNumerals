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
    ck_assert_int_eq(to_arabic("VI"), 6);
    ck_assert_int_eq(to_arabic("IV"), 4);
    ck_assert_int_eq(to_arabic("MMMCMXCIX"), 3999);


    //Check error conditions
    ck_assert_int_eq(to_arabic("MMMCMXCX"), -1);
    ck_assert_int_eq(to_arabic(""), -1);
    ck_assert_int_eq(to_arabic(NULL), -1);
}
END_TEST

START_TEST(converts_to_roman)
    {
        ck_assert_str_eq(to_roman(1), "I");
        ck_assert_str_eq(to_roman(2), "II");
        ck_assert_str_eq(to_roman(4), "IV");
        ck_assert_str_eq(to_roman(5), "V");
        ck_assert_str_eq(to_roman(9), "IX");
        ck_assert_str_eq(to_roman(10), "X");
        ck_assert_str_eq(to_roman(40), "XL");
        ck_assert_str_eq(to_roman(50), "L");
        ck_assert_str_eq(to_roman(90), "XC");
        ck_assert_str_eq(to_roman(100), "C");
        ck_assert_str_eq(to_roman(400), "CD");
        ck_assert_str_eq(to_roman(500), "D");
        ck_assert_str_eq(to_roman(900), "CM");
        ck_assert_str_eq(to_roman(1000), "M");
        ck_assert_str_eq(to_roman(3999), "MMMCMXCIX");

        //Check error conditions
        ck_assert_ptr_eq(to_roman(-1), NULL);
        ck_assert_ptr_eq(to_roman(-0), NULL);
        ck_assert_ptr_eq(to_roman(4000), NULL);
    }
END_TEST

START_TEST(adds)
    {
        ck_assert_str_eq(add("IV", "V"), "IX");

        //Check error conditions
        ck_assert_ptr_eq(add("MMMCMXCIX", "I"), NULL);
        ck_assert_ptr_eq(add("MMMCMXCIX", NULL), NULL);
        ck_assert_ptr_eq(add(NULL, "I"), NULL);
        ck_assert_ptr_eq(add(NULL, NULL), NULL);
    }
END_TEST

START_TEST(subtracts)
    {
        ck_assert_str_eq(subtract("V", "IV"), "I");

        //Check error conditions
    }
END_TEST

Suite * money_suite(void)
{
    Suite *s;
    TCase *tcase_converts_to_arabic;
    TCase *tcase_converts_to_roman;
    TCase *tcase_adds;
    TCase *tcase_subtracts;

    s = suite_create("Roman Numerals");

    tcase_converts_to_arabic = tcase_create("Converts to Arabic");
    tcase_add_checked_fixture(tcase_converts_to_arabic, setup, teardown);
    tcase_add_test(tcase_converts_to_arabic, converts_to_arabic);
    suite_add_tcase(s, tcase_converts_to_arabic);

    tcase_converts_to_roman = tcase_create("Converts to Roman");
    tcase_add_checked_fixture(tcase_converts_to_roman, setup, teardown);
    tcase_add_test(tcase_converts_to_roman, converts_to_roman);
    suite_add_tcase(s, tcase_converts_to_roman);

    tcase_adds = tcase_create("Adds");
    tcase_add_checked_fixture(tcase_adds, setup, teardown);
    tcase_add_test(tcase_adds, adds);
    suite_add_tcase(s, tcase_adds);

    tcase_subtracts = tcase_create("Subtracts");
    tcase_add_checked_fixture(tcase_subtracts, setup, teardown);
    tcase_add_test(tcase_subtracts, subtracts);
    suite_add_tcase(s, tcase_subtracts);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = money_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

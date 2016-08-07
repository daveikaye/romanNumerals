#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int roman_letter_to_arabic_number(char roman_letter) {

    switch(roman_letter) {

        case 'I'  :
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default :
            return -1;
    }

}

int to_arabic(char *roman)
{
    int i = 0;
    int arabic = 0;
    int roman_length = strlen(roman);
    while(i < roman_length) {
        char letter = roman[i];
        int number = roman_letter_to_arabic_number(letter);

        i++;

        if (i == roman_length) {
            arabic += number;
        } else {
            int nextNumber = roman_letter_to_arabic_number(roman[i]);
            if (nextNumber > number) {
                arabic += nextNumber - number;
                i++;
            } else {
                arabic += number;
            }
        }
    }

    return arabic;
}

char* concat_strings(char* target, char* source) {
    target = realloc(target, sizeof(source));
    strcat(target, source);

    return target;
}

char* to_roman(int arabic) {
    const int numbers[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    const char* letters[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };


    char *roman = NULL;
    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++) {
        while (arabic >= numbers[i]) {
            roman = concat_strings(roman, letters[i]);
            arabic -= numbers[i];
        }
    }

    return roman;
}

char* add(char* number1, char* number2) {

    return to_roman(to_arabic(number1) + to_arabic(number2));
}

char* subtract(char* number1, char* number2) {

    return to_roman(to_arabic(number1) - to_arabic(number2));
}

main()
{
    printf("%s\n", add("IX", "X"));
    printf("%s\n", subtract("X", "IX"));
}
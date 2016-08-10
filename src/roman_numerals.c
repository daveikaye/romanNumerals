#include <string.h>
#include <stdlib.h>

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

int roman_digit_to_arabic(char *roman, int* i_ptr, int roman_length) {
    int number = roman_letter_to_arabic_number(roman[*i_ptr]);
    (*i_ptr)++;

    if (*i_ptr < roman_length) {
        int nextNumber = roman_letter_to_arabic_number(roman[*i_ptr]);
        if (nextNumber > number) {
            number = nextNumber - number;
            (*i_ptr)++;
        }
    }

    return number;
}

int to_arabic(char *roman)
{
    int i = 0;
    int arabic = 0;
    int roman_length = strlen(roman);
    while(i < roman_length) {
        arabic += roman_digit_to_arabic(roman, &i, roman_length);
    }

    return arabic;
}

char* concat_strings(char* target, char* source) {
    target = target == NULL ? malloc(sizeof(source)+1) : realloc(target, sizeof(source)+sizeof(target)+1);

    strcat(target, source);

    return target;
}

char *to_roman(int arabic) {
    const int numbers[] = { 5, 4, 1 };
    const char* letters[] = { "V", "IV", "I" };

    char *roman = NULL;

    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++) {
        while (arabic >= numbers[i]) {
            roman = concat_strings(roman, letters[i]);
            arabic -= numbers[i];
        }
    }

    return roman;
}
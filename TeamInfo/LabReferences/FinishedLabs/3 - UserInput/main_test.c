//
//  main_test.c
//  Week 3 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "min_unit.h"
#include "core.h"

static char * test_string_compare() {
    mu_begin_case("string_compare");
    
    mu_assert_i("string_compare(\"Hello\", \"Hello\") should return TRUE", 1, string_compare("Hello", "Hello"));
    mu_assert_i("string_compare(\"!@#$%^&*()_+\", \"!@#$%^&*()_+\") should return TRUE", 1, string_compare("!@#$%^&*()_+", "!@#$%^&*()_+"));
    mu_assert_i("string_compare(\"\", \"\") should return TRUE", 1, string_compare("", ""));
    mu_assert_i("string_compare(NULL, NULL) should return TRUE", 1, string_compare(NULL, NULL));
    
    mu_assert_i("string_compare(\"Hello\", \"World\") should return FALSE", 0, string_compare("Hello", "World"));
    mu_assert_i("string_compare(\"Hi\", \"Hello\") should return FALSE", 0, string_compare("Hi", "Hello"));
    mu_assert_i("string_compare(\"Hello\", \"Hi\") should return FALSE", 0, string_compare("Hello", "Hi"));
    mu_assert_i("string_compare(\"!@#$%^&*()_+\", \"+_)(*&^%$#@!)\") should return FALSE", 0, string_compare("!@#$%^&*()_+", "+_)(*&^%$#@!)"));
    mu_assert_i("string_compare(NULL, \"\") should return FALSE", 0, string_compare(NULL, ""));


    mu_end_case("string_compare");
    return 0;
}

static char * test_string_length() {
    mu_begin_case("string_length");

    mu_assert_i("string_length(\"CS308\") should return 5", 5, string_length("CS308"));
    mu_assert_i("string_length(\"Hello World\") should return 11", 11, string_length("Hello World"));
    mu_assert_i("string_length(\"!@#$%^&*()_+\") should return 12", 12, string_length("!@#$%^&*()_+"));
    mu_assert_i("string_length(\"\") should return 0", 0, string_length(""));
    mu_assert_i("string_length(NULL) should return 0", 0, string_length(NULL));

    mu_end_case("string_length");
    return 0;
}

static char * test_string_is_palindrome() {
    mu_begin_case("string_is_palindrome");

    mu_assert_i("string_is_palindrome(\"\") should return TRUE", 1, string_is_palindrome("", 0));
    mu_assert_i("string_is_palindrome(\"A\") should return TRUE", 1, string_is_palindrome("A", 1));
    mu_assert_i("string_is_palindrome(\"AA\") should return TRUE", 1, string_is_palindrome("AA", 2));
    mu_assert_i("string_is_palindrome(\"kayak\") should return TRUE", 1, string_is_palindrome("kayak", 5));
    mu_assert_i("string_is_palindrome(\"racecar\") should return TRUE", 1, string_is_palindrome("racecar", 7));
    mu_assert_i("string_is_palindrome(\"tenet\") should return TRUE", 1, string_is_palindrome("tenet", 5));
    mu_assert_i("string_is_palindrome(\"noon\") should return TRUE", 1, string_is_palindrome("noon", 4));
    mu_assert_i("string_is_palindrome(\"rotor\") should return TRUE", 1, string_is_palindrome("rotor", 5));
    mu_assert_i("string_is_palindrome(\"step on no pets\") should return TRUE", 1, string_is_palindrome("step on no pets", 15));

    mu_assert_i("string_is_palindrome(NULL) should return FALSE", 0, string_is_palindrome(NULL, 0));
    mu_assert_i("string_is_palindrome(\"AB\") should return FALSE", 0, string_is_palindrome("AB", 2));
    mu_assert_i("string_is_palindrome(\"airplanes\") should return FALSE", 0, string_is_palindrome("airplanes", 9));
    mu_assert_i("string_is_palindrome(\"not a palindrome\") should return FALSE", 0, string_is_palindrome("not a palindrome", 16));

    mu_end_case("string_is_palindrome");
    return 0;
}

static char * all_tests() {
    test_string_compare();
    test_string_length();
    test_string_is_palindrome();
    return 0;
}

#ifdef TEST
int main(int argc, char **argv) {
    mu_run(all_tests);
    
    return 0;
}
#endif


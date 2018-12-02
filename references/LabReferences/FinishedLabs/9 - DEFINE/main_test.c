//
//  main_test.c
//  Project 3 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "min_unit.h"

#include "core.h"

static char * test_alloc() {
    mu_begin_case("ALLOC", 3);

    {
        int * point = ALLOC(int, 5);
        mu_assert_not_null("Verify pointer has value", point);
        
        if (point != NULL) {
            free(point);
        }
    }

    {
        char * point = ALLOC(char, 5);
        mu_assert_not_null("Verify pointer has value", point);
        
        if (point != NULL) {
            free(point);
        }
    }

    {
        double * point = ALLOC(double, 5);
        mu_assert_not_null("Verify pointer has value", point);
        
        if (point != NULL) {
            free(point);
        }
    }

    mu_end_case("ALLOC");
    return 0;
}

static char * test_set_array() {

    mu_begin_case("SET_ARRAY", 17);

    {
        int * items = calloc(5, sizeof(int));

        SET_ARRAY(items, 2, 5);
    
        for (int i = 0; i < 5; i++) {
            mu_assert_i("Verify array item was set to 2", 2, items[i]);
        }

        free(items);
    } 

    {
        int * items = calloc(12, sizeof(int));

        SET_ARRAY(items, 7, 12);
    
        for (int i = 0; i < 12; i++) {
            mu_assert_i("Verify array item was set to 2", 7, items[i]);
        }

        free(items);
    } 

    mu_end_case("SET_ARRAY");
    return 0;
}

static char * test_swap() {

    mu_begin_case("SWAP", 6);

    {
        int a = 5;
        int b = 10;

        SWAP(int, a, b);

        mu_assert_i("Verify a is 10", 10, a);
        mu_assert_i("Verify b is 5", 5, b);
    } 

    {
        char a = 'a';
        char b = 'b';

        SWAP(char, a, b);

        mu_assert_c("Verify a is 'b'", 'b', a);
        mu_assert_c("Verify b is 'a'", 'a', b);
    } 

    {
        char * a = "Hello";
        char * b = "World";

        SWAP(char *, a, b);

        mu_assert_s("Verify a is World", "World", a);
        mu_assert_s("Verify b is Hello", "Hello", b);
    } 
    mu_end_case("SWAP");
    return 0;
}

static char * test_square() {

    mu_begin_case("SQUARE", 3);

    {
        int result = SQUARE(2);
        mu_assert_i("Verify 2 squared is 4", 4, result);
    } 

    {
        int result = SQUARE(2 + 2);
        mu_assert_i("Verify 2 + 2 squared is 16", 16, result);
    } 

    {
        int result = 2 * SQUARE(3);
        mu_assert_i("Verify 2 times 2 squared is 18", 18, result);
    } 

    mu_end_case("SQUARE");
    return 0;
}

static char * all_tests() {
    test_alloc();
    test_set_array();
    test_swap();
    test_square();
    return 0;
}

#ifdef TEST
int main(int argc, char **argv) {
    mu_run(all_tests);
    return 0;
}
#endif


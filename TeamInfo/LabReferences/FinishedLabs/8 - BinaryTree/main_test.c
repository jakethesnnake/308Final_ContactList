//
//  main_test.c
//  Week 8 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "min_unit.h"
#include "core.h"
#include "binary_tree.h"

void clear_stack_tree(BinaryTree * t) {
    t->value = 0;
    t->left = NULL;
    t->right = NULL;
}

void murder_stack(){
    BinaryTree b;
    clear_stack_tree(&b);
    BinaryTree b1;
    clear_stack_tree(&b1);
    BinaryTree b2;
    clear_stack_tree(&b2);
    BinaryTree b3;
    clear_stack_tree(&b3);
}

static char * test_binary_tree_h_created() {
    mu_begin_case("binary_tree.h file needs to be created");

    {
        FILE * fp = fopen("binary_tree.h", "r");
        mu_assert_not_null("Verify binary_tree.h was created", fp);
        fclose(fp);
    }

    mu_end_case("binary_tree.h file needs to be created");
    return 0;
}

static char * test_binary_tree_c_created() {
    mu_begin_case("binary_tree.c file needs to be created");

    {
        FILE * fp = fopen("binary_tree.c", "r");
        mu_assert_not_null("Verify binary_tree.c was created", fp);
        fclose(fp);
    }

    mu_end_case("binary_tree.c file needs to be created");
    return 0;
}

static char * test_binary_tree_make() {
    mu_begin_case("BinaryTree_make()");

    {
        BinaryTree * t = BinaryTree_make(5, BinaryTree_make(3, BinaryTree_make(2, NULL, NULL), NULL), BinaryTree_make(5, NULL, NULL));
        murder_stack();
        murder_stack();
        murder_stack();
        murder_stack();
        murder_stack();
        mu_assert_i("Verify tree make", 2, t->left->left->value);
    }

    {
        BinaryTree * t = BinaryTree_make(5, BinaryTree_make(5, NULL, NULL), BinaryTree_make(3, BinaryTree_make(7, NULL, NULL), NULL));
        murder_stack();
        murder_stack();
        murder_stack();
        murder_stack();
        murder_stack();
        mu_assert_i("Verify tree make", 7, t->right->left->value);
    }

    mu_end_case("BinaryTree_make()");
    return 0;
}

static char * test_binary_tree_free() {
    mu_begin_case("BinaryTree_free()");

    {
        BinaryTree_free(NULL);
    }

    {
        BinaryTree * t = BinaryTree_make(5, BinaryTree_make(3, BinaryTree_make(2, NULL, NULL), NULL), BinaryTree_make(5, NULL, NULL));
        BinaryTree_free(t);
    }

    {
        BinaryTree * t = BinaryTree_make(5, BinaryTree_make(5, NULL, NULL), BinaryTree_make(3, BinaryTree_make(7, NULL, NULL), NULL));
        BinaryTree_free(t);
    }

    mu_end_case("BinaryTree_free()");
    return 0;
}

static char * all_tests() {
    test_binary_tree_h_created();
    test_binary_tree_c_created();
    test_binary_tree_make();
    test_binary_tree_free();
    return 0;
}

#ifdef TEST
int main(int argc, char **argv) {
    mu_run(all_tests);
    return 0;
}
#endif


//
//  ast.h
//  Project 3 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef login_h
#define login_h

#include "types.h" // maybe unnecessary
//#include "token.h"

typedef struct AST {
    //Token * value;
    struct AST * left;
    struct AST * right;
} AST;

void free_tree(AST *);

#endif /* linked_list_h */

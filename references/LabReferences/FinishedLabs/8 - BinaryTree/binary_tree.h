//
//  types.h
//  Week 8 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

typedef struct BinaryTree
{
	int value;
	struct BinaryTree * left;
	struct BinaryTree * right;
} BinaryTree;

BinaryTree* BinaryTree_make(int num, BinaryTree*, BinaryTree*);
void BinaryTree_free(BinaryTree*);

#endif /* binary_tree_h */


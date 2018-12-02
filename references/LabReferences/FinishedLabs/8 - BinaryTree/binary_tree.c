//#include <studio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "core.h"

BinaryTree* BinaryTree_make(int num, BinaryTree * left, BinaryTree * right)
{
	BinaryTree * temp = malloc(sizeof(BinaryTree));
	temp->value = num;
	temp->left = left;
	temp->right = right;
	
}
void BinaryTree_free(BinaryTree * tree)
{
	if(tree == NULL) free(tree);
	else
	{
		BinaryTree_free(tree->left);
		BinaryTree_free(tree->right);
	}
}

/*
 * DISCUSSION:
 *
 * Normally, I give descriptions of all the function above the given function but for this lab you actually
 * have to create a two new files binary_tree.h and binary_tree.c. Therefore you will have to actually create
 * the functions and their prototypes for this lab. So I am going to give the descriptions here and leave it 
 * for you to move them over.
 *
 * The binary_tree.h file needs the following things
 * 1. A defination for a binary tree. Here is the shape of that
 *     1.1 typdef'd struct called "BinaryTree"
 *     1.2 int value 
 *     1.3 BinaryTree * left
 *     1.4 BinaryTree * right
 *
 * 2. Function prototypes for the following functions (NOTE: Order of the parameters matters, and must match)
 *     2.1 a function called "BinaryTree_make" that takes an "int", and two "BinaryTree *" and returns a "BinaryTree *"
 *     2.2 a function called "BinaryTree_free" that takes a "BinaryTree *" and returns void
 *
 *
 * The binary_tree.c file needs the following things
 * 3. An include for "binary_tree.h"
 * 4. The implementation for the function noted in 2.1
 *     4.1 Hints on this function
 *         4.1.1 Do *NOT* check for NULL here. We want to allow NULL for "empty" children
 *         4.1.2 Call malloc to crate the pointer
 *         4.1.3 This function is responsible for creating a BinaryTree, setting the value, and assinging the left and right children
 *         4.1.4 The first BinaryTree * is the left child, the second is the right
 * 5. The implementation for the function noted in 2.2
 *     5.1 Hints on this function
 *         5.1.1 Recursively free all the children of the tree *before* freeing the parent
 *         5.1.2 You only need to check if the parent is null
 *         5.1.3 Make sure to call free()
 *
 */
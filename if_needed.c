//
//  token.c
//  Project 3
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"
#include "types.h"

bool is_digit(char c) {
    return (c <= '9' && c >= '0');
}

bool is_whitespace(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

Token * copy_token(Token * token) {
    if (token == NULL) {
        return NULL;
    }
    Token * t = malloc(sizeof(Token));
    memcpy(t, token, sizeof(Token));
    return t;
}

Token * make_add_token() 
{
    Token * t = malloc(sizeof(Token));
    t->type = ADD;
    return t;
}

Token * make_subtract_token() {
    Token * t = malloc(sizeof(Token));
    t->type = SUBTRACT;
    return t;
}

Token * make_multiply_token() {
    Token * t = malloc(sizeof(Token));
    t->type = MULTIPLY;
    return t;
}

Token * make_integer_token(int value) {
    Token * t = malloc(sizeof(Token));
    t->type = INTEGER;
    t->value = value;
    return t;
}

// The tokenize function takes a string and a converts
// it into the appropriate token. 
// 
// For example:
//     "+" creates a "ADD" token
//     "123" creates a "INTEGER" token with the value 123
//
// Helper functions have been provided to create the individual tokens. 
// Those functions are listed above
//
// Hints
//   For TODO #1
//      Write a switch statement that looks at the first characters of str.
//      If the first character is '*', '+', or '-' increase the characters_read value
//      and return the correct token using the make functions from above
//
//  For TODO #2
//      Once here we either have a integer or we have an invalid token 
//      Check if the first character is a digit (using is_digit). If so
//          1. Count the number of digit and assign that to characters_read
//          2. return make_integer_token() with the correct integer (will need to use atoi)
Token * tokenize(char * str, int * characters_read) {
    if (characters_read == NULL) {
        return NULL;
    }
    
    *characters_read = 0;
    
    if (str == NULL) {
        return NULL;
    }
    
    while (is_whitespace(*str)) {
        (*characters_read)++;
        str++;
    }
    
	char s = *str;
	switch(s)
	{// TODO #1
		case '*':
			(*characters_read)++;
			return make_multiply_token();
		case '+':
			(*characters_read)++;
			return make_add_token();
		case '-':
			(*characters_read)++;
			return make_subtract_token();
	}
	if(is_digit(s)) 
	{
		int count = 0;
		Token * tok = make_integer_token(atoi(str)); // assignment
		while(str != NULL && *str != '\0'&& *str != ' ')
		{
			++count;
			++str;
		}
		*characters_read += count; // increment
		return tok;
	}
	*characters_read = 0;
	return NULL;
}


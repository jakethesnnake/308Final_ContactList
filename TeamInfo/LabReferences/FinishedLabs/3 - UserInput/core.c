//
//  core.c
//  Week 3 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>

#include "core.h"

void print_usage() {
    printf("Usage:\n");
    printf("./main \"string1 to analyze\" \"string2 to analyze\"\n");
}

void analyze_string(const char * s) {
    printf("Analyzing \"%s\"\n", s);
    
    int length = string_length(s);
    printf("\tCharacter count: %d\n", length);
    printf("\tIs palendrome: %s\n\n", string_is_palindrome(s, length) ? "YES" : "NO");
}

// This function should determine if two strings are equal.
// if they are return TRUE
// otherwise return FALSE
//
// When implementing this function, use recursion.
//
// HINTS: 
//     - The end of a string is denoted by '\0'
//     - If you are getting a segmentation fault then you should probably 
//         check if s1 or s2 are NULL
//     - 'char c1 = *s1;' will give you the first character in s1
int string_compare(const char * s1, const char * s2) 
{
	if((s1 == NULL) && (s2 == NULL)) {return TRUE;}
	if((s1 == NULL) || (s2 == NULL)) {return FALSE;}
	char c1 = *s1;
	char c2 = *s2;
	if((c1 == '\0') && (c2 == '\0')) {return TRUE;}
	if((c1 == '\0') || (c2 == '\0')) {return FALSE;}
	if(c1 == c2) 
	{
		return string_compare(++s1,++s2);
	}
	else return FALSE;
}

// This function should return the number of characters in a string
//
// Example:
//     "Hello" -> 5
//     "" -> 0
//
// When implementing this function, use recursion.
// 
// HINT:
//     - If you are getting a segmentation fault, consider the NULL case
//
int string_length(const char * s) {
	if(s == NULL) {return 0;}
	char c = *s;
	if(c == '\0') {return 0;}
	return 1 + string_length(++s);
}

// This function should return if a string is a palindrome
//
// Example:
//     "noon" -> TRUE
//     NULL -> FALSE
//     "" -> TRUE
//     "A" -> TRUE
//     "cat" -> FALSE
//
// When implementing this function, use recursion.
// 
// HINT: 
//     - 'char last = *(s + length - 1);' will give you the last character
//           in a string
//
int string_is_palindrome(const char * s, int length) {
    if(s == NULL) return FALSE;
	char c = *s;
	if(c == '\0') return TRUE;
	char last = *(s + length - 1);
	if(length == 1)	return TRUE;
	if(c == last)
	{
		if(length == 2)	{return TRUE};
		--length;
		return string_is_palindrome(++s, --length);
	} else {return FALSE;}
	// return int
}

// This function is called when "./main" is ran
// For this function there aren't any tests but all
// you need to do it pull in the values passed in from the cli
// Example:
//     if you run "./main hello world" then
//         string1 should be set to "hello"
//         string2 should be set to "world"
//
//     if you run "./main" or "./main hello" then 
//         print_usage() should be called 
//         and then 1 should be returned (signaling an error to linux)
//
int core_main(int argc, const char * argv[]) {
    if(argc != 3)
	{
		print_usage();
		return 1;
	}
	const char * string1 = argv[1];
	const char * string2 = argv[2];
	
    // DON'T EDIT BELOW THIS LINE

    analyze_string(string1);
    analyze_string(string2);

    printf("\"%s\" == \"%s\": %s\n", string1, string2, string_compare(string1, string2) ? "YES" : "NO");

    return 0;
}

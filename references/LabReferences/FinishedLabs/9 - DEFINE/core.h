//
//  core.h
//  Project 3 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef core_h
#define core_h

#include <stdio.h>

#define ALLOC(type, count) malloc(sizeof(type)*(count)) 

#define SET_ARRAY(array, value, length) \
	for(int i = 0; i < (length); i++) {array[i] = value;}

#define SWAP(T, a, b) T temp = a; a = b; b = temp

#define SQUARE(a) ((a) * (a))

int core_main(int argc, const char * argv[]);

#endif /* core_h */
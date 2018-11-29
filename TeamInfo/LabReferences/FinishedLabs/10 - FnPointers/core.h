//
//  core.h
//  Week 10 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef core_h
#define core_h

#include <stdio.h>


/*
typedef float (* multi) (float, float)
{	
	// instances
	mutli x;
	multi u;
}

// funPoint def -- much better
void apply(int x, multi func)
{
	func(x);
}
*/

// TODO: typedef a function pointer called "int_application_function" that 
//       takes an int parameter and returns an int

// TODO: typedef a function pointer called "change_string_function" that 
//       takes a char parameter and returns a char 

typedef int (*int_application_function) (int);
typedef char (*change_string_function) (char);

int apply_twice(int value, int_application_function func);
void change_string(char * str, change_string_function func);

int core_main(int argc, const char * argv[]);

#endif /* core_h */

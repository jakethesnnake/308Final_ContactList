// FINAL PROJECT: CONTACT APPLICATION
// Jake Willson, Victor Ramos, Kevin Merwin
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "core.h"
#include "types.h"

int core_main(int argc, const char * argv[])
{
	
	// **parse user input
	// **find if user wants to createAccount(0) or login(1)
	// **enforce valid input (loops)
	
	int choice = 1;
	char * uname = "John";
	char * psw = "Doe";
	
	// start of while loop
	if(choice == 1) // login attempt
	{
		if(tryLogin(uname, psw)) printf("Welcome back!\n");
		else printf("Invalid login attempt\n");
    }
	else if(choice == 0) // create account attempt
	{
		int b = tryCreateAccount(uname,psw);
		if(b == TRUE) printf("new!\n"); else printf("--old\n");
	}
	else printf("Invalid Input");
	// end of while loop
	
	return TRUE;
}
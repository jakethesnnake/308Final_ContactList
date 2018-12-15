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
	printf("\nWelcome to ContactHub\nSelect an option:\n\t (1) login\n\t (2) Sign-up\n : ");
	Account a; // ACCOUNT
		char inp[MAX]; 
		fgets(inp, MAX, stdin);
		int choice = atoi(inp);	// exception handling later
		char uname[MAX];
		char psw[MAX];
	int b = 0;
	while(b == 0)
	{
		if(choice == 1) // login
		{
			
			printf("\nLOGIN\n");
			
			printf("\tusername: ");
				fgets(uname, MAX, stdin);
				size_t n_ln = strlen(uname)-1;
				uname[n_ln] = '\0';
			
			printf("\tpassword: ");
				fgets(psw, MAX, stdin);
				size_t p_ln = strlen(psw)-1;
				psw[p_ln] = '\0';
				
			if(tryLogin(uname, psw)) {
				printf("Welcome back!\n");
				b = 1;
			} else printf("Invalid credentials\n");
		}
		else if(choice == 2) // create account
		{
			printf("\nCREATE ACCOUNT\n");
			
			printf("\tusername: ");
				fgets(uname, MAX, stdin);
				size_t n_ln = strlen(uname)-1;
				uname[n_ln] = '\0';
			
			printf("\tpassword: ");
				fgets(psw, MAX, stdin);
				size_t p_ln = strlen(psw)-1;
				psw[p_ln] = '\0';
				
			if(tryCreateAccount(uname,psw)) {printf("Registration successful!\n"); b = 1; }
			else printf("ERROR: username associated with a pre-existing acccount\n");
		}
		else printf("Invalid Input");
	}
}
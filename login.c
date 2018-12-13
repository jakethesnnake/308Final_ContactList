//  login.c
//  Authentication, initialization, encryption and file I/O

#include <stdlib.h>
#include "login.h"
#define MAX 100

// Parses
Account read_one_account(char * line)
{
	Account a;
	if(line == NULL) return a;
	const char delim[2] = "~";
	char * token = strtok(line, delim);
	a.username = token;
	token = strtok(NULL, delim);
	a.password = token;
	return a;
}

// Evaluates equality iteratively through file
Account tryLogin(char * uname, char * psw)
{
	FILE * reader = fopen("AllLoginData.txt", "r");
	Account AccArr[100];
	char line[10000];
	for(int i = 0; fscanf(reader, "%s\n", line) != EOF; i++)
	{
		AccArr[i] = read_one_account(line);
		if(strcmp(uname,AccArr[i].username) == 0 && strcmp(psw,AccArr[i].password) == 0) 
		{
			fclose(reader);
			return AccArr[i];
		}
	}
	fclose(reader);
	Account a;
	return a;
}

// May creates account upon successful equality testing (referential)
Account tryCreateAccount(char * uname, char * psw)
{
	FILE * reader = fopen("AllLoginData.txt", "w");
	Account AccArr[100];
	char line[10000];
	for(int i = 0; fscanf(reader, "%s\n", line) != EOF; i++)
	{
		AccArr[i] = read_one_account(line);
		if(strcmp(uname,AccArr[i].username) == 0) 
		{
			fclose(reader);
			Account a;
			return a;
		}
	}
	Account a;
	a.username = uname;
	a.password = psw;
	fprintf("%s~%s", uname, psw);
	fclose(reader);
	return a;
}

Account userIO()
{
	printf("\nWelcome to ContactHub\nSelect an option:\n\t (1) login\n\t (2) Sign-up\n : ");
	
	Account a; // ACCOUNT
		char inp[MAX]; 
		fgets(inp, MAX, stdin);
		int choice = atoi(inp);	// exception handling later
		char uname[MAX];
		char psw[MAX];
	while(strlen(a.username) < 1)
	{
		if(choice == 1) // login
		{
			printf("\tusername: ");
				fgets(uname, MAX, stdin);
				size_t n_ln = strlen(uname)-1;
				uname[n_ln] = '\0';
			
			printf("\tpassword: ");
				fgets(psw, MAX, stdin);
				size_t p_ln = strlen(psw)-1;
				psw[p_ln] = '\0';
				
			a = tryLogin(uname, psw); 
			if(strlen(a.username) > 0) {printf("Welcome back!\n"); return a;}
			else printf("Invalid login attempt\n");
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

			a = tryCreateAccount(uname,psw); // INSTANCE
			if(strlen(a.username) > 0) {printf("Register successful!\n"); return a;}
			else printf("ERROR: username associated with a pre-existing acccount\n");
		}
		else printf("Invalid Input");
	}
	return a;
}

void encrypt_one_password(char * psw)
{
	
}

void decrypt_one_password(char * psw)
{
	
}

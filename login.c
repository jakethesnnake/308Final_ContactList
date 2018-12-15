//  login.c
//  Authentication, initialization, encryption and file I/O

#include <stdlib.h>
#include "login.h"

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
int tryLogin(char * uname, char * psw)
{
	FILE * reader = fopen("AllLoginData.txt", "r");
	Account AccArr[100];
	char line[10000];
	for(int i = 0; fscanf(reader, "%s\n", line) != EOF; i++)
	{
		AccArr[i] = read_one_account(line);
		//printf("%s~%s\n",AccArr[i].username, AccArr[i].password);
		//printf("%s~%s\n",uname, psw);
		if(strcmp(uname,AccArr[i].username) == 0 && strcmp(psw,AccArr[i].password) == 0) 
		{
			fclose(reader);
			return TRUE;
		}
	}
	fclose(reader);
	return FALSE;
}

// May creates account upon successful equality testing (referential)
int tryCreateAccount(char * uname, char * psw)
{
	FILE * reader = fopen("AllLoginData.txt", "r+");
	Account AccArr[100];
	char line[10000];
	const char delim[2] = "\n";
	for(int i = 0; fscanf(reader, "%s\n", line) != EOF; i++)
	{
		AccArr[i] = read_one_account(line);
		if(strcmp(uname,AccArr[i].username) == 0) 
		{
			fclose(reader);
			return FALSE;
		}
	}
	fprintf(reader, "%s~%s\n", uname, psw);
	fclose(reader);
	//printf("%s~%s\n", uname, psw);
	return TRUE;
}

void encrypt_one_password(char * psw)
{
	
}

void decrypt_one_password(char * psw)
{
	
}
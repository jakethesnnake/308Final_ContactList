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
	const char delim[2] = "\n";
	for(int i = 0; fscanf(reader, "%s\n", line) != EOF; i++)
	{
		AccArr[i] = read_one_account(line);
		
		size_t n_ln = strlen(AccArr[i].username)-1;
		size_t p_ln = strlen(AccArr[i].password)-1;
		if (AccArr[i].username[n_ln] == '\n') AccArr[i].username[n_ln] = '\0';
		if (AccArr[i].username[p_ln] == '\n') AccArr[i].password[p_ln] = '\0';
		
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
	if(tryLogin(uname,psw)) return FALSE;
	Account a;
	a.username = uname;
	a.password = psw;
	const char c[2] = ",";
	FILE * reader = fopen("AllLoginData.txt", "a+"); // appending
	fprintf(reader, "%s~%s\n", uname, psw);
	fclose(reader);
	return TRUE;
}

void encrypt_one_password(char * psw)
{
	
}

void decrypt_one_password(char * psw)
{
	
}
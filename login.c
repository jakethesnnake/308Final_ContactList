//  login.c
//  Authenticate, Create Account, File Writing/Reading

#include <stdlib.h>
#include "login.h"

// Run when program begins
Account * read_all_accounts(FILE * fp)
{
	Account * acctArr;
	char * uname;
	char * psw;
	//FILE * f_in = fopen(argv[1],"r");
	//FILE * f_out = fopen(argv[2], "w");
	if(fp == NULL) return NULL;
	while(fscanf(fp , "%s %s\n", uname, psw) != EOF) // EOF = end of file (.hasNextLine())
	{
		Account a;
		a.username = uname;
		a.password = psw;
		*acctArr = a;
		++acctArr;
	}
	fclose(fp);
	return acctArr;
}
/*Account read_account(char * line)
{
	
}*/
/*int read_board(Board * board, FILE * fp)
{
	char temp[10000];
	char arr[10000];
	if(fp == NULL) return FALSE;
	int w = fscanf(fp, "%d", &board->width);
	int h = fscanf(fp, "%d\n", &board->height);	// height
	if(w < 1 || h < 1) return FALSE;
	int i = 0;
	int a = 0, b = 0;
	while(i <= ((board->width) * board->height)) // eliminates new line character
	{
		fgets(temp,2,fp);
		if(*temp == '\n') 
		{ 
			fgets(temp,2,fp);
			if(*temp == '\n') break;
		}
		arr[i] = *temp; 
		i++; 
	}
	int z = 0;
	while(arr[z] != '\0')
	{
		if(arr[z] == '*') {board->board[a][b] = 1; b++;}
		else if(arr[z] == '.') {board->board[a][b] = 0; b++;}
		if(b == board->width) {a++; b = 0;}
		z++;
	}
	fclose(fp);
    return TRUE;
}*/

// Run when program ends
int write_all_accounts(FILE * fp, Account * accts)
{
	return TRUE;
}
char * encrypt_account(Account a)
{
	return NULL;
}

// Authentication
Account create_account(char * uname, char * psw)
{
	Account temp;
	temp.username = uname;
	temp.password = psw;
	return temp;
}

// Initializes file reading
// 1 = PASS, 0 = FAIL
int login(char * uname, char * psw)
{
	return TRUE;
}

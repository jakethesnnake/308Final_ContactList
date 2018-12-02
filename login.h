// login.h
#ifndef login_h
#define login_h
#include <stdio.h>
#include <string.h>
#include "types.h"

// Run when program begins
Account * read_all_accounts(FILE *);
//Account read_account(char *);

// Run when program ends
int write_all_accounts(FILE *, Account *);
char * encrypt_account(Account);

// Authentication
Account create_account(char *, char *);
int login(char *, char *);

#endif /* login.h */

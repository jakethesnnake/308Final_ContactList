// login.h
#ifndef login_h
#define login_h
#include <stdio.h>
#include <string.h>
#include "types.h"

Account read_one_account(char * line);
Account tryLogin(char * uname, char * psw);
Account tryCreateAccount(char * uname, char * psw);
Account userIO();

#endif /* login.h */

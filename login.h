// login.h
#ifndef login_h
#define login_h
#include <stdio.h>
#include <string.h>
#include "types.h"

int tryLogin(char * uname, char * psw);
int tryCreateAccount(char * uname, char * psw);

#endif /* login.h */
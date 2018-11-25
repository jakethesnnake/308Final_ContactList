/* core.h */

// methods, definitions and libraries
#ifndef core_h
#define core_h
#include <stdio.h>
#include "types.h"

#define TRUE 1
#define FALSE 0

int core_main(int argc, const char * argv[]);
int search_contacts(Command * board); 
int commit_changes(FILE * my_contacts, FILE * all_logins);
int add_contact(Contact c, FILE * fp);
int add_login(FILE * login_fp);
int login(char * username, char * password);

#endif
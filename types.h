/* types_h */

// Both LinkedLists can be changed into dynamic arrays
// VCARD has not been implemented

// 1 

#ifndef types_h
#define types_h
#define max 100

typedef struct Contact
{
	char * f_name;
	char * l_name;
	char * email;
	long * phone_num;
	char * address;
} Contact;

typedef struct Account
{
	char * username;
	char * password;
} Account;

typedef struct Command
{
	enum { ADD, FIND, VCARD, CHANGE, REMOVE} type;
	union { long phone_num; char * string; } search; // string is all else
} Command;

typedef enum {ACCT_SETUP, LOGIN, ACTION, QUIT} State; // Session runtime state

#endif 

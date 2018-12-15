/* types_h */

// Array approach

#ifndef types_h
#define types_h
#define MAX 100
#define max 100
#define TRUE 1
#define FALSE 0

typedef struct
{
	char  f_name[75];
	char  l_name[75];
	char  email[75];
	double phone_num;
	char  address[110];
} Contact;

typedef struct Account
{
	char * username;
	char * password;
	Contact cons[20];
} Account;

typedef struct Command
{
	enum { ADD, FIND, VCARD, CHANGE, REMOVE, VIEW, LOGOUT} type;
	enum {DOUBLE, STRING} valuetype;
	union { double phone_num; char * string; } search; // string is all else
} Command;

typedef enum {ACCT_SETUP, LOGIN, ACTION, QUIT} State; // Session runtime state

#endif

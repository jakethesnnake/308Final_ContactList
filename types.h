/* types_h */

// Both LinkedLists can be changed into dynamic arrays
// VCARD has not been implemented
#ifndef types_h
#define types_h
#define max 100

typedef struct Contact
{
	struct Contact * next; // LinkedList -- can change
	char * f_name;
	char * l_name;
	char * email;
	long * phone_num;
} Contact;

typedef struct Account
{
	struct Account * next;	// LinkedList -- can change
	char * username;
	char * password;
} Account;

typedef struct Command
{
	enum { ADD, FIND, DISPLAY, CHANGE, REMOVE} type;
	union {long phone_num; char * string;} search; // string is all else
} Command;

typedef enum {LOGIN, ACTION, QUIT} State; // Session runtime state

#endif 
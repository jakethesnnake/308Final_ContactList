#ifndef system_h
#define system_h

#include <stdio.h>
#include "types.h"
#include "contacts.h"
#include "login.h"

///Used a guide to make a dynamic array. https://stackoverflow.com/questions/3536153/c-dynamically-growing-array.
///All credit to original creator.

typedef struct
{
	Account *array;
	int used;
	int size;
}AccountArray;

void initAccountArray(AccountArray *a, int initialsize);
void insertAccountArray(AccountArray * a, Account element);
void freeAccountArray(AccountArray *a);

typedef struct
{
	Contact *array;
	int used;
	int size;
} ContactArray;

int sys(Account * acc, State state);
void initContactArray(ContactArray *a, int initialsize);
void insertContactArray(ContactArray *a, Contact element);
void freeContactArray(ContactArray *a);
int getContacts(FILE *stream,ContactArray *a);
int set_command(char *command, char *contact, Command * c);
int execute_command(Command * c,ContactArray *a);
int add_contactsystem(Command *c, ContactArray *a);
int find_contacts(Command *c,ContactArray *database, ContactArray *found);
int change_contact(Command *cmd, ContactArray * c);
int remove_contact(Command *cmd, ContactArray *c);
int search_array(ContactArray *a, char *string);
int iterateArray(ContactArray *a);
int remove_element(ContactArray *a, int index, int arraylength);
int removeandresize(ContactArray *a, int index, int arrayLength);
int printContacts(Account * a, ContactArray * c);
int printVCard(Command *c, ContactArray * a, FILE * fp);

#endif

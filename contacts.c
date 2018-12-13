// contacts.c

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contacts.h"
#include "types.h"

void initialize(Account a)
{
	// **after login complete, login.c invokes this method?
	// **and this class handles user input?
}

int printContacts(Account a){ // Contact[] is a property of Account so only 1 parameter necessary
	FILE *fp;
	char *filename = (strcat(a.username, "_Contacts.txt"));
	fp = fopen(filename, "w");
	fprintf(fp, "%ld\n", sizeof(Contact));
	for(int i = 0; i < sizeof(Contact); i++){

		if (a.cons[i].address == NULL) a.cons[i].address = "*";
		if (a.cons[i].email == NULL) a.cons[i].email = "*";
		if (a.cons[i].f_name == NULL || a.cons[i].l_name == NULL || a.cons[i].phone_num == NULL) {
			return printf("error");
		}
		fprintf(fp, "%s, ", a.cons[i].f_name);
		fprintf(fp, "%s, ", a.cons[i].l_name);
		fprintf(fp, "%ln, ", a.cons[i].phone_num);
		fprintf(fp, "%s, ", a.cons[i].address);
		fprintf(fp, "%s\n", a.cons[i].email);
	}
	fclose(fp);
}


void printVCard(Contact cont) {
	FILE *fp;
	char *filename = (strcat(cont.f_name, "_vCard.txt"));
	fp = fopen(filename, "w");

	if (cont.address == NULL || cont.address == "*") cont.address = "N/A";
	if (cont.email == NULL || cont.email == "*") cont.email = "N/A";
	if (cont.f_name == NULL || cont.l_name == NULL || cont.phone_num == NULL) {
		printf("error");
	}
	fprintf(fp, "NAME: %s ", cont.f_name);
	fprintf(fp, "%s\n", cont.l_name);
	fprintf(fp, "NUMBER: %ln\n", cont.phone_num);
	fprintf(fp, "ADDRESS: %s\n", cont.address);
	fprintf(fp, "EMAIL: %s\n", cont.email);
	fclose(fp);
}


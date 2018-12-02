//
//  linked_list.c
//  Project 3
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contacts.h"
#include "types.h"

LinkedList * append(LinkedList * head) {
    /*LinkedList * new = malloc(sizeof(LinkedList));
    new->value = token;
    new->next = NULL;
    
    if (head == NULL) {
        return new;
    }
    
    LinkedList * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = new;*/
    
    return head;
}

LinkedList * advance_list(LinkedList * list, int steps) {
   /* while (list != NULL && steps > 0) {
        list = list->next;
        steps--;
    }*/
    
    return list;
}

void free_list(LinkedList * list) {
   /* while (list != NULL) {
        LinkedList * next = list->next;
        free(list->value);
        free(list);
        list = next;
    }*/
}


int printContacts(Contact cont[], Account acc){
	FILE *fp;
	int i;
	char *filename = (strcat(acc.username, "_Contacts.txt"));
	fp = fopen(filename, "w");
	fprintf(fp, "%ld\n", sizeof(cont));
	for(i = 0; i < sizeof(cont); i++){

		if (cont[i].address == NULL) cont[i].address = "*";
		//if (contacts[i]->home_phone == NULL) contacts[i]->home_phone = "*";
		if (cont[i].email == NULL) cont[i].email = "*";
		if (cont[i].f_name == NULL || cont[i].l_name == NULL || cont[i].phone_num == NULL) {
			return printf("error");
		}
		fprintf(fp, "%s, ", cont[i].f_name);
		fprintf(fp, "%s, ", cont[i].l_name);
		fprintf(fp, "%ln, ", cont[i].phone_num);
		fprintf(fp, "%s, ", cont[i].address);
		//fprintf(fp, "%d, ", cont[i]->home_phone);
		fprintf(fp, "%s\n", cont[i].email);
	}
	fclose(fp);
	//return TRUE;
}


void printVCard(Contact cont) {
	FILE *fp;
	char *filename = (strcat(cont.f_name, "_vCard.txt"));
	fp = fopen(filename, "w");

	if (cont.address == NULL || cont.address == "*") cont.address = "N/A";
	//if (cont->home_phone == NULL|| cont->home_phone == "*") cont->home_phone = "N/A";
	if (cont.email == NULL || cont.email == "*") cont.email = "N/A";
	if (cont.f_name == NULL || cont.l_name == NULL || cont.phone_num == NULL) {
		printf("error");
	}
	fprintf(fp, "NAME: %s ", cont.f_name);
	fprintf(fp, "%s\n", cont.l_name);
	fprintf(fp, "NUMBER: %ln\n", cont.phone_num);
	fprintf(fp, "ADDRESS: %s\n", cont.address);
	//fprintf(fp, "HOME PHONE: %d\n", cont->home_phone);
	fprintf(fp, "EMAIL: %s\n", cont.email);
	fclose(fp);
}


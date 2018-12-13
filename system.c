#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "core.h"
#include "types.h"
#include "system.h"
///main
int main(Account * acc, State state){
    char src[50], dest[50];
    strcpy(src, "_Contacts.txt");
    strcpy(dest, "Joy");
    state = ACTION;
    strcat(dest, src);
    printf("Filename: %s\n", dest);
    FILE * fp = fopen(dest, "r");
    ContactArray a;
    int gc = getContacts(fp,&a);
    if(gc == FALSE){
      printf("No data found.\n");
      initContactArray(&a, 5);
    }
    if(gc == 2){
      printf("File is empty\n");
      initContactArray(&a, 5);
    }
    while(state == ACTION){
        printf("**************************************************\n");
        printf("These are the available commands:\n");
        printf("Add [Contact First Name]\n");
        printf("Find [Contact Name]\n");
        printf("VCARD [Contact First Name]\n");
        printf("Change [Contact First Name]\n");
        printf("Remove [Contact First Name]\n");
        printf("Logout Now\n");
        printf("If you would like to search via number please add N before the command, i.e. NAdd 1234567890\n");
        Command cmd;
        char command[20];
        char contact[50];
        int number;
        scanf("%s %s",command,contact);
        int x = set_command(command, contact, &cmd);
        if(x == FALSE)printf("Unknown command, please enter a valid command.\n");
        else if(cmd.type == LOGOUT){
          state = QUIT;
          iterateArray(&a);
          printContacts(acc, &a);
        }
        else{
            execute_command(&cmd,&a);
        }
    }
    printf("Array freed\n");
    freeContactArray(&a);
    return TRUE;
}

///Gets the contacts from the file.
int getContacts(FILE * stream,ContactArray *a){
    if(stream == NULL)return FALSE;
    fseek(stream,0,SEEK_END);
    if(ftell(stream) == 0)return 2;
    fseek(stream,0,SEEK_SET);
    int arraysize;
    fscanf(stream,"%d",&arraysize);
    initContactArray(a,arraysize);
    char str[100], firstname[50], lastname[50],address[100],email[50],phonenumber[15];
    while(fscanf(stream,"%s %s %s %s %s", firstname, lastname,phonenumber,email,address) != EOF){
        Contact c;
        strcpy(c.f_name, firstname);
        strcpy(c.l_name, lastname);
        double phone;
        sscanf(phonenumber,"%lf", &phone);
        c.phone_num = phone;
        if(strcmp(address, "*") == 0){
          strcpy(c.address,"*");
        }
        else{
            strcpy(c.address, address);
        }
        if(strcmp(email,"*") == 0){
          strcpy(c.email,"*");
        }
        else{
            strcpy(c.email,email);
        }
        insertContactArray(a, c);
    }
    fclose(stream);
    return TRUE;
}
///Sets the command to whatever value is needed
int set_command(char *command, char *contact, Command * c){
    if(strcmp(command,"Add")== 0){
        c->type = ADD;
        c->valuetype = STRING;
        c->search.string = contact;
        return TRUE;
    }
    if(strcmp(command,"NAdd")==0){
        c->type = ADD;
        c->valuetype = DOUBLE;
        double phone;
        sscanf(contact,"%lf", &phone);
        c->search.phone_num = phone;
        return TRUE;
    }
    if(strcmp(command,"Find")==0){
        c->type = FIND;
        c->valuetype = STRING;
        c->search.string = contact;
        return TRUE;
    }
    if(strcmp(command,"NFind")==0){
        c->type = FIND;
        c->valuetype = DOUBLE;
        double phone;
        sscanf(contact,"%lf", &phone);
        c->search.phone_num = phone;
        return TRUE;
    }
    if(strcmp(command,"VCARD")==0){
        c->type = VCARD;
        c->valuetype = STRING;
        c->search.string = contact;
        return TRUE;
    }
    if(strcmp(command,"NVCARD")==0){
        c->type = VCARD;
        c->valuetype = DOUBLE;
        double phone;
        sscanf(contact,"%lf", &phone);
        c->search.phone_num = phone;
        return TRUE;
    }
    if(strcmp(command,"Change")==0){
        c->type = CHANGE;
        c->valuetype = STRING;
        c->search.string = contact;
        return TRUE;
    }
    if(strcmp(command,"NChange")==0){
        c->type = CHANGE;
        c->valuetype = DOUBLE;
        double phone;
        sscanf(contact,"%lf", &phone);
        c->search.phone_num = phone;
        return TRUE;
    }
    if(strcmp(command,"Remove")==0){
        c->type = REMOVE;
        c->valuetype = STRING;
        c->search.string = contact;
        return TRUE;
    }
    if(strcmp(command,"NRemove")==0){
        c->type = REMOVE;
        c->valuetype = DOUBLE;
        double phone;
        sscanf(contact,"%lf", &phone);
        c->search.phone_num = phone;
        return TRUE;
    }
    if(strcmp(command,"Logout")==0){
        c->type = LOGOUT;
        return TRUE;
    }
    return FALSE;
}
///Control
int execute_command(Command *c,ContactArray *a){
  if(c->type == ADD){
    add_contactsystem(c,a);
  }
  if(c->type == FIND){
    ContactArray found;
    initContactArray(&found,10);
    int x = find_contacts(c,a,&found);
    if(x == FALSE)printf("Sorry no contact was found\n");
    freeContactArray(&found);
  }
  if(c->type == VCARD){
    FILE *fp;
    int x = printVCard(c, a, fp);
    fclose(fp);
    if(x==FALSE)printf("No accoutn for VCARD\n");
  }
  if(c->type == CHANGE){
    int x = change_contact(c,a);
    if(x == FALSE)printf("No contact found to edit\n");
  }
  if(c->type == REMOVE){
    int x = remove_contact(c,a);
    if(x == FALSE)printf("Removeal unsuccessful\n");
    else if(x==2)printf("No contact found with those credentials\n");
    else{
      printf("Removal was successful\n");
      for(int i = 0; i < a->used; i++){
        printf("%s\n", a->array[i].f_name);
        printf("%s\n", a->array[i].l_name);
        printf("%.0lf\n", a->array[i].phone_num);
        printf("%s\n", a->array[i].address);
        printf("%s\n", a->array[i].email);
        printf("**************************************************\n");
      }
    }
  }
}

int add_contactsystem(Command *c, ContactArray *a){
    Contact cont;
    if(c->valuetype == STRING){
      strcpy(cont.f_name, c->search.string);
      printf("Please enter: lastname phonenumber address email\n");
      printf("If you do not want to enter an address or email place a * in its place \n");
      char lastname[50], address[100],email[50],phonenumber[15];
      scanf("%s %s %s %s",lastname,phonenumber,address,email);
      strcpy(cont.l_name,lastname);
      double phone;
      sscanf(phonenumber,"%lf", &phone);
      cont.phone_num = phone;
      if(strcmp(address,"*") == 0)strcpy(cont.address,"*");
      else strcpy(cont.address,address);
      if(strcmp(email,"*") == 0)strcpy(cont.email,"*");
      else strcpy(cont.email,email);
      insertContactArray(a, cont);
      return TRUE;
    }
    if(c->valuetype == DOUBLE){
      cont.phone_num = c->search.phone_num;
      printf("Please enter: firstname lastname address email\n");
      printf("If you do not want to enter an address or email place a * in its place \n");
      char lastname[50], address[100],email[50], firstname[50];
      scanf("%s %s %s %s",firstname,lastname,address,email);
      strcpy(cont.f_name, firstname);
      strcpy(cont.l_name,lastname);
      if(strcmp(address,"*")==0)strcpy(cont.address,"*");
      else strcpy(cont.address,address);
      if(strcmp(email,"*")==0)strcpy(cont.email,"*");
      else strcpy(cont.email,email);
      insertContactArray(a, cont);
      return TRUE;
    }
    return FALSE;
}
int find_contacts(Command *c,ContactArray *database, ContactArray *found){
  if(c->valuetype == STRING){
      for(int i = 0;i < database->used;i++){
        if(strstr(database->array[i].f_name,c->search.string)!= NULL){
          insertContactArray(found,database->array[i]);
        }
      }
      if(found->used == 0)return FALSE;
      iterateArray(found);
      return TRUE;
  }
  if(c->valuetype == DOUBLE){
    for(int i = 0;i < database->used;i++){
      if(database->array[i].phone_num == c->search.phone_num){
        insertContactArray(found,database->array[i]);
      }
    }
    if(found->used == 0)return FALSE;
    iterateArray(found);
    return TRUE;
  }
  return FALSE;
}

int change_contact(Command *cmd, ContactArray * c){
  if(cmd->valuetype == STRING){
    for(int i = 0;i < c->used;i++){
      if(strcmp(c->array[i].f_name,cmd->search.string)== 0){
        printf("You are editing: \n");
        printf("%s\n", c->array[i].f_name);
        printf("%s\n", c->array[i].l_name);
        printf("%.0lf\n", c->array[i].phone_num);
        printf("%s\n", c->array[i].address);
        printf("%s\n", c->array[i].email);
        printf("**************************************************\n");
        int j = 1;
        while(j){
          char choice[20], firstname[50], lastname[50],address[100],email[50],phonenumber[15];
          printf("Please enter which value you would like to edit:\n");
          printf("FirstName, LastName, Phonenumber, Email, Address, or Quit\n");
          scanf("%s",choice);
          if(strcmp(choice,"FirstName") == 0){
              printf("Enter new first name\n");
              scanf("%s", firstname);
              strcpy(c->array[i].f_name, firstname);
          }
          else if(strcmp(choice,"LastName") == 0){
              printf("Enter new last name\n");
              scanf("%s", lastname);
              strcpy(c->array[i].l_name, lastname);
          }
          else if(strcmp(choice,"Phonenumber") == 0){
              printf("Enter new phone number\n");
              scanf("%s", phonenumber);
              double phone;
              sscanf(phonenumber,"%lf", &phone);
              c->array[i].phone_num = phone;
          }
          else if(strcmp(choice,"Email") == 0){
              printf("Enter new email\n");
              scanf("%s", email);
              strcpy(c->array[i].email, email);
          }
          else if(strcmp(choice,"Address") == 0){
              printf("Enter new address\n");
              scanf("%s", address);
              strcpy(c->array[i].address, address);
          }
          else if(strcmp(choice,"Quit") == 0){
              printf("Changes saved\n");
              printf("%s\n", c->array[i].f_name);
              printf("%s\n", c->array[i].l_name);
              printf("%.0lf\n", c->array[i].phone_num);
              printf("%s\n", c->array[i].address);
              printf("%s\n", c->array[i].email);
              printf("**************************************************\n");
              return TRUE;
          }
          else{
            printf("Please choose a valid option\n");
          }
        }
      }
    }
    return FALSE;
  }
  if(cmd->valuetype == DOUBLE){
    for(int i = 0;i < c->used;i++){
      if(c->array[i].phone_num == cmd->search.phone_num){
        printf("You are editing: \n");
        printf("%s\n", c->array[i].f_name);
        printf("%s\n", c->array[i].l_name);
        printf("%.0lf\n", c->array[i].phone_num);
        printf("%s\n", c->array[i].address);
        printf("%s\n", c->array[i].email);
        printf("\n");
        int j = 1;
        while(j){
          char choice[20], firstname[50], lastname[50],address[100],email[50],phonenumber[15];
          printf("Please enter which value you would like to edit:\n");
          printf("FirstName, LastName, Phonenumber, Email, Address, or Quit\n");
          scanf("%s",choice);
          if(strcmp(choice,"FirstName") == 0){
              printf("Enter new first name\n");
              scanf("%s", firstname);
              strcpy(c->array[i].f_name, firstname);
          }
          else if(strcmp(choice,"LastName") == 0){
              printf("Enter new last name\n");
              scanf("%s", lastname);
              strcpy(c->array[i].l_name, lastname);
          }
          else if(strcmp(choice,"Phonenumber") == 0){
              printf("Enter new phone number\n");
              scanf("%s", phonenumber);
              double phone;
              sscanf(phonenumber,"%lf", &phone);
              c->array[i].phone_num = phone;
          }
          else if(strcmp(choice,"Email") == 0){
              printf("Enter new email\n");
              scanf("%s", email);
              strcpy(c->array[i].email, email);
          }
          else if(strcmp(choice,"Address") == 0){
              printf("Enter new address\n");
              scanf("%s", address);
              strcpy(c->array[i].address, address);
          }
          else if(strcmp(choice,"Quit") == 0){
              printf("Changes saved\n");
              printf("%s\n", c->array[i].f_name);
              printf("%s\n", c->array[i].l_name);
              printf("%.0lf\n", c->array[i].phone_num);
              printf("%s\n", c->array[i].address);
              printf("%s\n", c->array[i].email);
              printf("\n");
              return TRUE;
          }
          else{
            printf("Please choose a valid option\n");
          }
        }
      }
    }
    return FALSE;
  }
  return FALSE;
}
int remove_contact(Command *cmd, ContactArray *c){
  if(cmd->valuetype == STRING){
    for(int i = 0;i < c->used;i++){
      if(strcmp(c->array[i].f_name,cmd->search.string)== 0){
          return remove_element(c,i, c->size);
      }
    }
    return 2;
  }
  if(cmd->valuetype == DOUBLE){
    for(int i = 0;i < c->used;i++){
      if(c->array[i].phone_num == cmd->search.phone_num){
        return remove_element(c, i, c->size);
      }
    }
  }
  return 2;
}
int iterateArray(ContactArray *a){
  for(int i = 0;i < a->used;i++){
    printf("%s\n", a->array[i].f_name);
    printf("%s\n", a->array[i].l_name);
    printf("%.0lf\n", a->array[i].phone_num);
    printf("%s\n", a->array[i].address);
    printf("%s\n", a->array[i].email);
    printf("**************************************************\n");
  }
  return TRUE;
}
int remove_element(ContactArray *a, int index, int arraylength){
  int size = a->size;
  int used = a->used;
  Contact * temp = realloc(a->array, (arraylength)*sizeof(Contact));
    memmove(
      temp,
      a->array,
      (index+1)*sizeof(Contact));
    memmove(
      temp+index,
      a->array+(index+1),
      (arraylength - index)*sizeof(Contact));
    free(a->array);
    a->array = temp;
    a->size = size - 1;
    a->used = used - 1;
    return TRUE;
}
int printContacts(Account * a, ContactArray * c){ // Contact[] is a property of Account so only 1 parameter necessary
	FILE *fp;
	char filename[100];
  strcpy(filename, "Joy");
  strcat(filename, "_Contacts.txt");
  printf("%s\n",filename);
  printf("%d\n", c->used);
	fp = fopen(filename, "w+");
	fprintf(fp, "%d\n", c->used);
	for(int i = 0; i < c->used; i++){
    char fname[120], lname[120], address[175],email[120];
    double phonenum;
    strcpy(fname, c->array[i].f_name);
		fprintf(fp, "%s ",fname);
    strcpy(lname, c->array[i].l_name);
		fprintf(fp, "%s ", lname);
    phonenum = c->array[i].phone_num;
		fprintf(fp, "%.0lf ", phonenum);
    strcpy(address, c->array[i].address);
		fprintf(fp, "%s ", address);
    strcpy(email,  c->array[i].email);
		fprintf(fp, "%s\n", email);
	}
	fclose(fp);
  return TRUE;
}

int printVCard(Command *c, ContactArray * a, FILE * fp) {
  if(fp == NULL)return FALSE;
  if(c->valuetype == STRING){
    for(int i = 0;i < a->used;i++){
      if(strstr(a->array[i].f_name,c->search.string)!= NULL){
        printf("I'm alive\n");
        char filename[100];
        strcpy(filename,a->array[i].f_name);
      	strcat(filename, "_vCard.txt");
      	fp = fopen(filename, "w");
        printf("File opens\n");
      	fprintf(fp, "NAME: %s ", a->array[i].f_name);
      	fprintf(fp, "%s\n", a->array[i].l_name);
      	fprintf(fp, "NUMBER: %.0lf\n", a->array[i].phone_num);
      	fprintf(fp, "ADDRESS: %s\n", a->array[i].address);
        fflush(fp);
      	fprintf(fp, "EMAIL: %s\n", a->array[i].email);
        fflush(fp);
        printf("File opens 7\n");
        printf("File close\n");
        printf("VCARD created successfully\n");
        return TRUE;
      }
    }
  }
  if(c->valuetype == DOUBLE){
    for(int i = 0;i < a->used;i++){
      if(a->array[i].phone_num == c->search.phone_num){
        FILE *fp;
        printf("I'm alive\n");
      	char *filename = (strcat(a->array[i].f_name, "_vCard.txt"));
      	fp = fopen(filename, "w");
        printf("File opens\n");
      	fprintf(fp, "NAME: %s ", a->array[i].f_name);
        printf("File opens 2\n");
      	fprintf(fp, "%s\n", a->array[i].l_name);
      	fprintf(fp, "NUMBER: %f\n", a->array[i].phone_num);
      	fprintf(fp, "ADDRESS: %s\n", a->array[i].address);
      	fprintf(fp, "EMAIL: %s\n", a->array[i].email);
      	fclose(fp);
        printf("File close\n");
        printf("VCARD created successfully\n");
        return TRUE;
      }
    }
  }
  return FALSE;
}
///Used a guide to make a dynamic array. https://stackoverflow.com/questions/3536153/c-dynamically-growing-array.
///All credit to original creator.
///Dynamic Array is not being used
///Initializes the array
void initAccountArray(AccountArray *a, int initialsize){
	a->array = (Account *)calloc(initialsize, sizeof(Account));
	a->used = 0;
	a->size = initialsize;
}
///Enters element into the array
void insertAccountArray(AccountArray * a, Account element){
	if(a->used == a->size){
		a->size = a->size * 2;
		a->array = (Account *)realloc(a->array, a->size * sizeof(Account));
	}
	a->array[a->used++] = element;
}
///When array is done. Frees array memory
void freeAccountArray(AccountArray *a){
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;
}
///Same as above but using a Contact


///Initializes the array
void initContactArray(ContactArray *a, int initialsize){
  a->array = (Contact *)malloc(initialsize * sizeof(Contact));
	a->used = 0;
	a->size = initialsize;
}
///Enters element into the array
void insertContactArray(ContactArray *a, Contact element){
	if(a->used == a->size){
		a->size *= 2;
		a->array = (Contact *)realloc(a->array, a->size);
	}
	a->array[a->used++] = element;
}
///When array is done. Frees array memory
void freeContactArray(ContactArray * a){
	a->array = NULL;
	a->used = a->size = 0;
}

// Structs with function pointers

typedef struct Person Person;
typedef void (* print_function) (Person *);

struct Person // definition of person
{
	char * f_name;
	char * l_name;
	print_function Print; // field declaration
}

typedef struct Employee
{
	Person base; // uses a person from the person struct
	char * job;
	int salary;
} Employee;

/*******************************/

Person * p = new_person();	//  initialize
p->Print(p);	// uses function as a field!

// if returns " Employee* "
Employee * e = new_employee();	// initialize
e->base.Print((Person *)e) // person = field of employee

Person * p2 = new_employee();		
p2->Print(p2);	// if Person* is returned, we would print person

/*********************************/

Employee * e = ...
Person * p = (Person *)e;	// typecast
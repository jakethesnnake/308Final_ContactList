struct Location
{
	double longitude;
	double latitude;
}

typedef struct Location Location // eliminates struct reference when calling
Location 11;


void find(Location L)
{ 	/**/	}

struct Student
{
	char name[100];
	char grade;
} Student;	// gives alias

Student s; // shortcut

strcpy(s.name , "some name");
s.grade = 'B';

Student * s_p = &s
Student * s_p_1 = *s_p;

Struct * s = ...
char c3 = s->grade;
// best

// self referential structs
typedef struct EmptyLS
{
	struct EmptyLS * next;	// must create a pointer for it to be referential
} EmptyLS
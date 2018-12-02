// Enumeration - good for iteration - basically arrays (0-index)

enum bool {FALSE, TRUE};
enum Direction {N , S, E, W};
enum Day {M,Tu,W,Th,F,Sa,Su}

// assignments to instances
enum bool is_true = TRUE;
enum Day today = Tu;
if(today == F) {...}

typedef enum Direction Direction;
Direction d = N;

enum Day {M,Tu,W,Th,F,Sa,Su} Day;	// alias
printf("",Sa) // prints 5

typedef enum Place {First = 1, Second, Third, Tenth = 10} Place; // assigning indices

typedef enum bool {FALSE, TRUE} bool;

// Enums in structs
typedef enum {January = 1, February...} Month;
typedef struct 
{
	Month m;	// enum
	Day d_name;	// enum
	int d_num;
	int year;
} Date;

/*
	Unions (single var that has multiple types)
	1. Typepunning
	2. Saving memory
	3. Making "generic" functions
*/
/*
	Struct - values for all its members
	Union - holds one value
*/

union money {double dollars; int yen;};
union money m;
m.yen = 100;

typedef union money money;
money * m2 = /*	*/
m2->dollars = 1.23;

typedef struct money
{
	enum {DollarT, YenT} type;
	union {double dollars; int yen;} value;
} money;

money m = /*...*/
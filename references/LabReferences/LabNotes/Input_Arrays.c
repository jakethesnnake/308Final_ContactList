// best solution to calling function before it's defined

void print_hello();
int main() {print_hello();}
void print_hello() { ... }

int factorial(int n)
{
	if(n<0) return -1;	// base case 1
	if(n<2) return 1;	// base case 2*
	return n * factorial(n-1);	// induction
}

/*	Arrays	*/

type name[size]
int scores[10];
int bad[var];	// cannot compile with variable as length. Must be constant

int scores[10];
int scores[3] = {1, 2, 3};	// can initialize new size legally

// 2D
int matrix[5][5];

char  str[] = "Hello";
char  str [6] = {’H’, ’e’, ’l’, ’l’, ’o’, ’\0’};
// DO NOT  FORGET  ABOUT  THE \0 (NULL) BYTE

#include  <string.h>	// use later
char  str1[] = "Hello";
char * str2 = "Hello";	// pointer : points to location in memory (same as array variable)

/*	User Input	*/
int  main(int argc , const  char * argv [])
{
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
}
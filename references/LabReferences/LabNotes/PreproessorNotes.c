// Pointers to Pointers //

void expand(char ** c)
{
	if(c == NULL) return;
	char * code = *c;
	if(strcmp(code, "MO") == 0) *c = "Missouri";
	else if(strcmp(code, "KS") == 0) *c = "Kansas";
}
int main()
{
	char * s = "KS";
	expand(&s);
	printf("%s\n", s);	// prints "Kansas"
}

///////////////////////////////////

void substring(char ** c, int front)
{
	char * new = *c;
	new += front;
	*c = new;
}
int main()
{
	char * s = "Kansas";
	expand(&s, 3);
	printf("%s\n", s);	// prints "sas"	
}

// Preprocessor directives begin with #
#define TRUE 1
#define PI 3.14

if(TRUE) float pi = PI;
if(1) float pi = 3.14;

// Adding parameters to define is called Macro
#define ADD(a, b, c) a + b + c
int x = ADD(1, 2, 3);

// Lots of silly irritating parenthesis (to specify)
#define ADD(a,b) ((a) + (b))
#define MULTIPLY(a,b) ((a) * (b))

int x = MULTIPLY(1 + 2, 2 + 3);
int y = 2 * ADD(2,3);

// Metaprogramming: writing code that writes code
#define DEFINE_VECTOR(type) \
	typedef struct type##Vector {\
		type a; \
		type b; \
	} type##Vector;
	
DEFINE_VECTOR(int);
DEFINE_VECTOR(char);
DEFINE_VECTOR(charVector);

int main()
{
	charVector cv;
	intVector iv;
	charVectorVector cvv;
}

Generic functions (any type)

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
// works for (int, float, char, double)
// anything that can be tested for numeric inequality

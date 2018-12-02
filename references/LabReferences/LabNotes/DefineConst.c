
int count = 1;
float distance = 2.34;
double latitude = 2.123456789;
char letter = 'Z';
// no boolean typede

/*	LEFT OFF SLIDE 6	*/

if (0) {printf("1\n");}
if (7) {printf("2\n");}
if (1) {printf("3\n");}
if (0 == 0) {printf("4\n");}	// only one that is false

// This is how we  define a ’constant ’
#define  TRUE 1
#define  FALSE 0
int  should_print_answer = TRUE;
if (should_print_answer) {printf("Answer\n");}

printf("%d\n",<int>);
printf("%f\n",<float>);
printf("%lf\n",<double>);
printf("%c\n",<char>);
printf("%s\n",<*string*>);

float  percent = 80.298;
printf("Two  decimal  percent: %.2f\n", percent);	// %.2f

#define  NORTH 0
#define  SOUTH 1
#define  EAST  2
#define  WEST  3
int  direction =/* ... */;

switch (direction) 
{
	case  NORTH:
	printf("Heading  north\n");
	break;	//... continue
}

break;	// exits nearest for loop (or switch statement)
continue;	// next iteration
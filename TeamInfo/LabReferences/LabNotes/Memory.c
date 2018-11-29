Defining modules
- header file (.h) - public code
- source file (.c) - implementation

# is from pre-processor and precedes compilation

#ifnef draw_h
#define draw_h
#endif

Dynamic memory
-powerful
-dangerous b/c no memory management built in

After C program is run, we must free memory

free(pointer)

// DYNAMIC MEMORY
int * j = malloc(sizeof(int))
int * j = malloc(10 * sizeof(int))
j[9] = 9

malloc - reserves space for array but can be garbage
calloc - writes 0s into each spot in array

int * i calloc(10,sizeof(int))
int * temp = realloc(i, (15 * sizeof(int)));
if(temp != NULL) i = temp;	// I can hold 15
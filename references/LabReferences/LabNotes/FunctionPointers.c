typedef function_pointer_signature;
{ // definition
}

typedef float (* multi) (float, float)
{	
	// instances
	mutli x;
	multi u;
}

// funPoint def -- much better
void apply(int x, multi func)
{
	func(x);
}

int add(int a, int b) {return a + b;}
int sub(int a, int b) {return a - b;}
typedef int (* operator) (int, int);
int main()
{
	operator o; // function object
	o = add; // always convert to pointer
	int x = o(1,2); // always dereference pointer
}
#include <stdio.h>

void main()
{
	int* Ptr;
	int A;
	Ptr = &A;

	A = 10;
	printf("\n\n\n\n");
	printf("\t %d\n", *Ptr);
	
	return;
}

#include <stdio.h>

void main()
{
	int* Ptr;
	int A;
	Ptr = &A;

	printf("\n\n");

	A = 10;
	printf(" A 초기값 : %d \n", A);
	
	*Ptr = 15;	// 할당된 메모리 주소에 해당하는 메모리 값에 15를 저장

	printf("   포인터값에 값을 저장해서 메모리값 바꾼 값 : %d\n", *Ptr);
	printf("   변수 A에 저장된 값 : %d \n", A);
	
	return;
}
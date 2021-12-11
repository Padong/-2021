#include <stdio.h>

void double_f(int* input, int* output)
{
	*output = *input * 2;
	return;
}

void main()
{
	int A = 10;
	int result;

	double_f(&A, &result);	//사용자정의 함수에서 주소값을 입력받으므로 변수의 주소를 입력해야함.
	printf("\n\n\n\n");
	printf("\t result 의 값 : %d\n", result);

	return;
}
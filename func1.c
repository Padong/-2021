#include <stdio.h>

 

int bigNum(int num01, int num02) // 함수의 정의

{

    if (num01 >= num02)

    {

        return num01;

    }

    else

    {

        return num02;

    }

}

 

int main(void)

{

    int result;  

 

    result = bigNum(3, 5); // 함수의 호출

    printf("두 수 중 더 큰수는 %d입니다.\n", result);

    result = bigNum(3, 1); // 함수의 호출

    printf("두 수 중 더 큰수는 %d입니다.\n", result);

    result = bigNum(7, 5); // 함수의 호출

    printf("두 수 중 더 큰수는 %d입니다.\n", result);

    return 0;

}  
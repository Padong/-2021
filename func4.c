#include <stdio.h>
// 두 수(파라미터)를 입력받아 더한 후 결과를 반환하는 함수
int add(int a, int b)
{
    int c;
 
    c = a + b; //a, b를 인수(Argument)로 전달 받아 더하기
 
    return c;
}
 
int main(void)
{
    int a, b;
    int result;
 
    a = 10;
    b = 20;
 
    result = add(a, b);         //add() 함수를 호출하여 add()함수가 반환한 결과를 result 변수에 저장(대입)
    printf("result = %d\n", result);  //result 변수에 저장된 값을 출력
 
    result = add(a + 5, b + 10);    //add() 함수 호출, 재사용
    printf("result = %d\n", result);
 
    printf("result = %d\n", add(20, 30)); //add() 함수 호출 재사용
 
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1
 
#include <stdio.h>
#include <string.h>
 
//정수를 입력받는 함수
int get_int(void)
{
    int a;
 
    scanf("%d", &a);
 
    return a;
}
 
//두 수 중 큰 수를 반환하는 함수
int get_max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
 
//두 수를 더하는 함수
int add(int a, int b)
{
    return a + b;
}
 
//두 수를 곱하는 함수
int mul(int a, int b)
{
    return a * b;
}
 
//전체경로에서 파일명만 잘라내는 함수
char* get_filename(char* path)
{
    //char path[256] = "c:\\test\\tistory.com\\codes.txt";
    static char filename[256] = "";
    char* ptr = NULL;
 
    ptr = strrchr(path, '\\');
 
    if (ptr == NULL)
        strcpy(filename, path);
    else
        strcpy(filename, ptr + 1);
 
    return filename;
}
 
 
int main(void)
{
    int x, y;
    int result;
    char path[256] = "c:\\test\\tistory.com\\mainCodes.txt";
    char filename[100];
 
    x = get_int();
    y = get_int();
 
    result = get_max(x, y);
    printf(">> 두 수 중 큰 수 : %d\n", result);
 
    result = add(x, y);
    printf(">> add 함수 호출 결과(덧셈) : %d\n", result);
 
    result = mul(x, y);
    printf(">> mul 함수 호출 결과(곱셈) : %d\n", result);
 
    printf("\n>> 입력한 전체 경로: %s\n", path);
    strcpy(filename, get_filename(path));
    printf(">> 추출한 파일명 : %s\n", filename);
 
    return 0;
}

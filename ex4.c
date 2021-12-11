#include <stdio.h>
#include <Windows.h>
 
int* StrLength(char *s);
 
 
void main()
{
    char c;
    char s[100] = { 0 };
    int count = 0;
    int *len;
 
    printf("Enter the Sentence : ");
 
    for (; (c = getchar()) != '\n';) // 엔터가 입력될 때까지 문자열을 입력받는다
    {
        s[count] = c;
        count++;
    }
 
 
    printf("\n");
 
    Sleep(500);
    printf("[*] WAIT, StrCpySelfMade function is running...\n");
    Sleep(2000);
 
    printf("\n");
 
 
 
    len = StrLength(s);        // 문자열의 길이를 StrLength로 구한 후 포인터로 받습니다
 
    printf("Length of sentence is [ %d ]\nLength of sentence is (without Space) [ %d ]\n\n", len[0],len[1]);
 
 
}
 
int* StrLength(char *s)                // 배열을 리턴하기 위해 int* 를 사용합니다
{
    static int len[2] = { 0 };        // static으로 지정해줘야 리턴할 때 len의 값이 소멸되지 않습니다
    int i = 0;
    int isSpace = 0;
 
    for (i = 0; s[i] != '\0'; i++)
    {
        len[0]++;
        if (isspace(s[i]))   // 빈칸이 있으면 isSpace++ 를 합니다
            isSpace++;
    }
 
    len[1] = len[0] - isSpace;
 
    return len;
 
}
#include <stdio.h>
#include <Windows.h>
 
void StrCatSelfMade(char* s1, const char* s2);
 
void main()
{
    char s1[100] = { 0 };
    char s2[100] = { 0 };
    char c;
    int count = 0;
 
    // s1을 입력하고
    printf("( s1 ) : ");
    for (; (c = getchar()) != '\n';)
    {
        s1[count] = c;
        count++;
    }
    printf("\n");
    count = 0;
 
    // s2를 입력한 다음
    printf("( s2 ) : ");
    for (; (c = getchar()) != '\n';)
    {
        s2[count] = c;
        count++;
    }
 
 
 
    printf("\n");
    Sleep(500);
    printf("[*] WAIT, StrCatSelfMade function is running...\n");
    Sleep(2000);
    printf("\n");
 
 
    // 두 문자열을 합칩니다
    StrCatSelfMade(s1, s2);
 
    printf("[ %s ] \n\n", s1);
 
 
}
 
 
void StrCatSelfMade(char* s1, const char* s2)
{
    int i = 0;
    int j = 0;
    
 
    // s1의 문자열 끝까지 i 값을 증가시키고
    for (i = 0; s1[i] != '\0';)
        i++;
    
    
    // s2의 문자열이 끝날 때까지 s1에 뒷부분에 붙입니다
    for (; s2[j] != '\0';j++)
    {
        s1[i] = s2[j];
        i++;
    }
    
 
    // s2[j] = '\0'
    // s1의 마지막에 '\0'을 입력해서 문자열의 끝을 알립니다
    s1[i] = s2[j];
 
}
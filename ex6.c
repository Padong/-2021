#include <stdio.h>
#include <Windows.h>
 
int StrNCmpSelfMade(const char* s1, const char* s2, int N);
 
void main()
{
    char s1[100] = { 0 };
    char s2[100] = { 0 };
    char c;
    int count = 0;
    int len = 0;
 
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
 
    // 비교할 길이를 선택합니다
    printf("\n");
    printf("determine length please : ");
    scanf_s("%d", &len, 100);
 
 
    // 길이가 문자열보다 길면 에러납니다
    if (len > strlen(s1) || len > strlen(s2))
    {
        printf("\n");
        printf("length is too long\n");
        Sleep(1000);
        exit(0);
    }
 
    printf("\n");
    Sleep(500);
    printf("[*] WAIT, StrCatSelfMade function is running...\n");
    Sleep(2000);
 
 
 
    printf("\n");
 
    // 비교 구문입니다
    if (StrNCmpSelfMade(s1, s2, len) > 0)
        printf("s2 is before than s1 (just %d word(s) compared)\n\n", len);
    else if (StrNCmpSelfMade(s1, s2, len) < 0)
        printf("s1 is before than s2 (just %d word(s) compared)\n\n", len);
    else if (StrNCmpSelfMade(s1, s2, len) == 0)
        printf("[ s1 is same with s2 ] (just %d word(s) compared)\n\n", len);
 
}
 
int StrNCmpSelfMade(const char* s1, const char* s2, int N)
{
    int i = 0;
 
    for (; i != N; i++)     // 사용자가 입력한 길이까지 i 값을 증가시켜가면서 s1과 s2를 비교합니다
    {
        // 둘 다 알파벳만 비교
        if (isalpha(s1[i]) && isalpha(s2[i]))
        {
            if (s1[i] > s2[i])
                return -1;
            else if (s1[i] < s2[i])
                return 1;
            else if (s1[i] == s2[i])
                continue;
        }
 
        // 둘 중 하나는 숫자이고 하나는 알파벳일 때 
        else if ((isalpha(s1[i]) && isdigit(s2[i])) || (isdigit(s1[i]) && isalpha(s2[i])))
        {
            printf("[-] Cannot compare with digit and string\n\n");
            exit(0);
        }
        
        // 둘 다 숫자가 포함되어 있을 때는 거꾸로 리턴 값을 정해줘야 정확한 비교가 됩니다
        // ASCII 코드를 보시면 바로 알 수 있습니다
        else
        {
            if (s1[i] > s2[i])
                return 1;
            else if (s1[i] < s2[i])
                return -1;
            else if (s1[i] == s2[i])
                continue;
        }
 
    }
    return 0;
 
 
}
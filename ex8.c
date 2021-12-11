#include <stdio.h>
#include <conio.h>
#include <Windows.h>
 
void main()
{
    char c;
    int count = 0;
    int alphabetCounter[100] = { 0 };
    int alphabetCounter2[100] = { 0 };
 
 
    printf("Enter the word you want : ");
    // EOF (ctrl + Z) or (ctrl + C) 가 눌릴 때까지 입력합니다
    while ((c = getchar()) != EOF)
    {
 
        // 대문자일 경우 아스키코드를 보면서
        // alphabetCounter1,2[0~26] 까지 쌓는다
        if (isupper(c))
        {
            alphabetCounter[c - 65] = c;
            alphabetCounter2[c - 65] += 1;
        }
 
        // 소문자일 경우
        // alphabetCounter1,2[27~51] 까지 쌓는다
        else if (islower(c))
        {
            alphabetCounter[c - 71] = c;
            alphabetCounter2[c - 71] += 1;
        }
 
        // 숫자일 경우
        // alphabetCounter1,2[52~61] 까지 쌓는다
        else if (isdigit(c))
        {
            alphabetCounter[c + 4] = c;
            alphabetCounter2[c + 4] += 1;
        }
 
        // 특수문자일 경우
        // alphabetCounter1,2[62~90] 까지 쌓는다
        else if (c >= 33 && c <= 47)
        {
            alphabetCounter[c + 29] = c;
            alphabetCounter2[c + 29] += 1;
        }
        // 특수문자일 경우
        else if (c >= 60 && c <= 64)
        {
            alphabetCounter[c + 17] = c;
            alphabetCounter2[c + 17] += 1;
        }
        // 특수문자일 경우
        else if (c >= 91 && c <= 96)
        {
            alphabetCounter[c - 9] = c;
            alphabetCounter2[c - 9] += 1;
        }
        // 특수문자일 경우
        else if (c >= 123 && c <= 125)
        {
            alphabetCounter[c - 35] = c;
            alphabetCounter2[c - 35] += 1;
        }
    }

    for (count = 0; count < sizeof(alphabetCounter)/sizeof(int) ; count++)
    {
        if (alphabetCounter[count] != 0)
        {
            printf("[ %c ] : [ %d ]\n", alphabetCounter[count], alphabetCounter2[count]);
        }
    }
 
 
}
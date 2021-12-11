#include <stdio.h>
#include <conio.h>
#include <Windows.h>
 
void main()
{
    char c;
    int count = 0;
    int isAlreadyUse[26] = { 0 };
 
 
    
    // EOF (ctrl + Z) 가 눌릴 때까지 입력합니다
    while ((c = _getch()) != 26)
    {
        if (c >= 'A' && c <= 'Z')
        {
 
            // 대문자가 입력되면 isAlreadyUse에 값을 추가시키면서 중복을 방지합니다
            // ex) 'A'는 아스키코드로 65이므로 isAlreadyUse[0]의 값이 증가합니다
            if (isAlreadyUse[c - 65] == 0)
            {
                printf("%c ", c);
                isAlreadyUse[c - 65]++;
            }
            else
                continue;
        }
        else
            continue;
    }
 
 
}
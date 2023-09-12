#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

int main()
{

    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t김가을의 행복한 VC++\n");
    Sleep(3000);
    system("cls");
    char w;

    printf("ex>\n");
    while (1) {
        printf("command> ");
        w = _getch();

        if (w == 27) {
            printf("ESC\n");
            break;
        }

        switch (w) {
        case 'q':
            printf("q\nqwer 화이팅\n");
            break;
        case 'w':
            printf("w\n과제 너무 좋다.\n");
            break;
        case 'e':
            printf("e\n담주부턴 과제량 3배다\n");
            break;
        case 'r':
            printf("r\n행복합니다\n");
            break;
        default:
            printf("오류. 재 입력을 요구합니다.\n");
            break;
        }
    }
    return 0;
}

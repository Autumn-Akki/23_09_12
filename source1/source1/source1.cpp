﻿#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t김가을의 행복한 VC++\n");
    Sleep(3000);
    system("cls");
    char c;
    char buffer[100]; // 입력을 저장할 버퍼

    while (1) {
        printf("command> ");
        int i = 0;

        while (1) {
            c = _getch();

            if (c == 27) {
                return 0;
            }
            else if (c == 13) { // Enter 키를 눌렀을 때
                buffer[i] = '\0'; // 문자열을 종료
                break;
            }
            else {
                // 입력된 문자를 버퍼에 저장하고 화면에 출력
                buffer[i] = c;
                putchar(c);
                i++;
            }
        }

        // 명령어 처리
        if (strcmp(buffer, "q") == 0) {
            printf("\nq\nqwer 화이팅\n");
        }
        else if (strcmp(buffer, "w") == 0) {
            printf("\nw\n과제 너무 좋다\n");
        }
        else if (strcmp(buffer, "e") == 0) {
            printf("\ne\n담주부턴 과제량 3배다\n");
        }
        else if (strcmp(buffer, "r") == 0) {
            printf("\nr\n행복합니다.\n");
        }
        else {
            printf("\n잘못된 명령입니다.\n");
        }
    }

    return 0;
}
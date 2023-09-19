#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h> // 불안정하지만, 제일 쓰기 편한 Sleep을 사용하기 위해

int main()
{
    int bein = 0; // before input, 이전 입력한 키를 저장
    int noin = 0; // now input, 현재 입력되어진 키를 저장
    char key;

        while (1) {
            Sleep(150); // 0.15초 지연시간 줌 
            key = _getch();
            if (key == 75) {
                bein = key; // 입력한 키에 좌측 화살표의 아스키코드값을 넣어준다
                printf("←");
            }
            else if (key == 77) {
                if (bein == 75) {
                    noin = 1; // 아따따뚜겐 기술 발현이 가능해진 상태
                }
                else if (bein == 80) {
                    noin = 2; // 아도겐 기술 발동이 가능
                }
                else {
                    bein = key; // 기술 발동이 불가능하다면, 입력한 키 초기화
                }
                printf("→");
            }
            else if (key == 72) {
                if (bein == 77) {
                    noin = 3; // 오류겐 기술 발동이 가능
                }
                else {
                    bein = key; // 기술 발동이 불가능하다면, 입력한 키 초기화
                }
                printf("↑");
            }
            else if (key == 80) {
                bein = key; // 발동 가능한 기술이 없으므로 입력한 키만 초기화
                printf("↓");
            }
            else if (key == 97) {
                if (noin == 1) {
                    printf("a \t [아따따뚜겐!] <-> <-> <-> \n"); // 첫 번째 기술 발동 
                }
                else if (noin == 2) {
                    printf("a \t [아도겐!] =o \n"); // 두 번째 기술 발동 
                }
                else if (noin == 3) {
                    printf("a \t [오류겐!] _9↑↑ \n"); // 세 번째 기술 발동
                }
                else if (bein == 80) {
                    printf("a \t [짠손!] _o \n"); // 평타 기술 하나쯤은 있어야죠
                }
                else {
                    printf("a \t[평타!] ==@ \n"); // 위의 상황 모두와 안맞을 경우 기본 평타가 나감
                }
                noin = 0;
                bein = 0; // 이후 사용된 모든 전 입력 키들은 초기화
            }
            else {
                if (key == -32) {
                    continue;
                }
                else if (key == 27) {
                    break; // ESC키 입력시 종료됨
                }
                else {
                    putchar(key);
                    noin = 0;
                    bein = 0;
                    continue;
                }
            }
        }
}  // 원작자 김가을 202007001

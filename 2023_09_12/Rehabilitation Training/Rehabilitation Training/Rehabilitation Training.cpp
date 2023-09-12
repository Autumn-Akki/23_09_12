#include <stdio.h>
#include <iostream>
#include <conio.h>

int main()
{

    printf("12312314\n");
    printf("김가을님의\n");
    printf("Application\n");
    char w;
    while (1) {

        printf("command> ");
        w = _getch();

        if (w == 27) {
            printf("ESC\n과제는 이클래스가 아닌 GIT에 올리자");
            break;
        }

        switch (w) {
        case 'p':
            printf("p\n나는 과제를 겁나 잘하는 학생이다.\n");
            break;
        case 'f':
            printf("f\n나는 과제가 너무 즐겁다.\n");
            break;
        case 'j':
            printf("j\n교수님 과제 더 내주세요.\n");
            break;
        default:
            printf("잘못된 명령\n");
            break;
        }
    }
    return 0;
}

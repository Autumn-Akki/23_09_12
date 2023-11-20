#include "Stack.h"
#include <iostream>
using namespace std;

// 스택 클래스의 생성자
SStack::SStack() {
    top = nullptr; // 초기화 시 top은 null
}

// 스택 클래스의 소멸자
SStack::~SStack() {
    while (!isEmpty()) {
        pop(); // 스택이 비어있지 않으면 모든 요소 제거
    }
}

// 스택에 데이터를 추가
void SStack::push(int data) {
    Nod* newNod = new Nod(data); // 새 노드 생성
    newNod->next = top; // 새 노드의 next를 현재 top으로 설정
    top = newNod; // 새 노드를 새로운 top으로 설정
}

// 스택에서 데이터를 제거하고 반환
int SStack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else {
        Nod* temp = top; // 현재 top 노드를 임시 저장
        top = top->next; // top을 다음 노드로 이동
        int poppedData = temp->data; // 제거될 데이터 저장
        delete temp; // 노드 메모리 해제
        return poppedData; // 제거된 데이터 반환
    }
}

// 스택의 맨 위 데이터를 조회
int SStack::peek() {
    if (isEmpty()) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else {
        return top->data; // top 데이터 반환
    }
}

// 스택이 비어 있는지 확인
bool SStack::isEmpty() {
    return top == nullptr; // top이 null이면 스택은 비어 있는 것
}


int main() {
    SStack s;     
    s.push(10);     
    s.push(20);  
    s.push(30);    
    s.push(40);    
    s.push(50);   
    s.push(60);   
    s.push(70);     


    
    for (int i = 0; i < 7; i++) {
        cout << s.pop() << " 스텍에서 제거됨 \n";
        cout << "현재 Top은 " << s.peek() << "입니다.\n\n" << endl;
    }

    return 0;
}
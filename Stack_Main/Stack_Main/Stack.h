#pragma once 


class Nod {
public:
    int data;     
    Nod* next;  

    Nod(int data) : data(data), next(nullptr) {} 
};

class SStack {
private:
    Nod* top;

public:
    SStack();    
    ~SStack();   
    void push(int data); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
};
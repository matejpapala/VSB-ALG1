#include <iostream>
using namespace std;


class Stack{
    private:
        int index;
        int capacity;
        int *data;
    public:
        void pop();
        void push(int value);
        void top();
        Stack();
};
Stack::Stack(){
    capacity = 10;
    data = new int[capacity];
    index = -1;
}

void Stack::pop(){
    if(index == -1) {
        cout << "Stack is empty" << endl;
        return;
    }else {
        index--;
    }
}

void Stack::push(int value) {
    if(index == capacity) {
        cout << "Stack full" << endl;
        return;
    }else {
        index++;
        data[index] = value;
    }
}

void Stack::top() {
    if(index == -1) {
        cout << "Stack is empty" << endl;
        return;
    }else {
        cout << data[index] << endl;
    }
}

int main() {
    Stack *stack = new Stack();
    stack->push(1);
    stack->push(5);
    stack->push(10);
    stack->pop();
    stack->top();
    return 0;
}


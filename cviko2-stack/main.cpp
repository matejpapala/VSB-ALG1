#include <iostream>
#include <climits>
#include <string>
using namespace std;


class Stack{
    private:
        int index;
        int capacity;
        int *data;
    public:
        void pop();
        void push(int value);
        int top();
        int getIndex() {
            return index;
        }
        Stack();
        ~Stack();
};
Stack::Stack(){
    capacity = 20;
    data = new int[capacity];
    index = -1;
}

Stack::~Stack(){
    delete[] data;
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

int Stack::top() {
    if(index == -1) {
        cout << "Stack is empty" << endl;
        return INT_MAX;
    }else {
        return data[index];
    }
}

bool checkParity(string str) {
    Stack *stack = new Stack();
    for(int i = 0; i< str.length();i++) {
        if(str[i] == '(') {
            stack->push(1);
        }
        if(str[i] == ')') {
            if(stack->top() == INT_MAX) {
                return false;
            }
           stack->pop();
        }
    }
    return stack->getIndex() == -1;
}

int main() {
    Stack *stack = new Stack();
    string str = "((.)(.))";
    cout << checkParity(str) << endl;

    return 0;
}


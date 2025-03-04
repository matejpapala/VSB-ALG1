#include <iostream>
#include <string>
using namespace std;

class Queue{
private:
    int capacity;
    int *data;
    int index;
public:
    Queue();
    ~Queue();
    void enqueue(int value);
    int getCapacity() {
        return capacity;
    }
    int dequeue();
};


Queue::Queue() {
    capacity = 20;
    data = new int[capacity];
    index = -1;
}

Queue::~Queue() {
    delete[] data;
}

void Queue::enqueue(int value) {
    if(index >= capacity) {
        cout << "Queue is full" << endl;
        return;
    }else {
        index++;
        data[index] = value;
    }
}

int Queue::dequeue() {
    if(index == -1) {
        cout << "Queue is empty" << endl;
        return -1;
    }else {
        int value = data[0];
        for(int j = 0; j < index;j++) {
            data[j] = data[j+1];
        }
        index--;
        return value;
    }
}


int main() {
    Queue *q = new Queue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
    return 0;
}
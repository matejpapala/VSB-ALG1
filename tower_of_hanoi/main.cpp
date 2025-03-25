#include <iostream>
#include <stack>
using namespace std;

void printTowers(stack<int> A, stack<int> B, stack<int> C, int N) {
    for(int i = N; i > 0; i--) {
        if(A.size() >= i) {
            cout << A.top() << " ";
            A.pop();
        } else {
            cout << "| ";
        }
        if(B.size() >= i) {
            cout << B.top() << " ";
            B.pop();
        } else {
            cout << "| ";
        }
        if(C.size() >= i) {
            cout << C.top() << " ";
            C.pop();
        } else {
            cout << "| ";
        }
        cout << endl;
    }
}

bool isMoveValid(const stack<int>& src,const stack<int>& dest) {
    return (!src.empty() && (dest.empty() || src.top() < dest.top()));
}

void moveDisc(stack<int>& src, stack<int>& dest) {
    if(isMoveValid(src, dest)) {
        dest.push(src.top());
        src.pop();
    }else {
        src.push(dest.top());
        dest.pop();
    }
}

void towersOfHanoi(int N, stack<int>& src, stack<int>& aux, stack<int>& dest) {
    if(N == 1) {
        moveDisc(src, dest);
        return;
    }
    towersOfHanoi(N-1, src, dest, aux);
    moveDisc(src, dest);
    towersOfHanoi(N-1, aux, src, dest);
}

int main() {
    int N = 4;
    stack<int> A, B, C;
    for(int i = N; i > 0; i--) {
        A.push(i);
    }
    
    printTowers(A, B, C, N);

    towersOfHanoi(N, A, B, C);

    cout << endl;

    printTowers(A, B, C, N);
    return 0;
}
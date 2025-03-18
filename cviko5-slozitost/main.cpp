#include <iostream>
using namespace std;

int findValue(int* arr, int N, int value) {
    for(int i = 0; i < N;i++) {
        if(arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void nonDuplicate(int* arr, int N, int* res) {
    bool* unique = new bool[N];

    for(int i = 0; i < N;i++) {
        unique[i] = true;
    }

    for(int i = 0; i < N;i++) {
        for(int j = 0; j < N;j++) {
            if(i != j && arr[i] == arr[j]) {
                unique[i] = false;
                unique[j] = false;
            }
        }
    }

    int index = 0;
    for(int i = 0; i < N;i++) {
        if(unique[i]) {
            res[index] = arr[i];
            index++;
        }
    }
    delete[] unique;
}

int fakt(int N) {
    if(N == 0) {
        return 1;
    }

    return N * fakt(N - 1);
}


int main() {

srand((int)time(nullptr));

    int N = 10;
    int* arr = new int[N];
    int* res = new int[N];
    int value = 5;
    for(int i = 0; i < N;i++) {
        arr[i] = rand()%N;
        cout << arr[i] << "\t";
    }
    cout << endl;

    //cout << "Value" << value << "found at: " << findValue(arr, N, value) << endl;
    nonDuplicate(arr, N, res);
    for(int j = 0;j < N;j++) {
        cout << res[j] << "\t";
    }
    cout << endl;

    cout << "Faktorial: " << fakt(5) << endl;
    delete[] arr;
    delete[] res;
    return 0;
}
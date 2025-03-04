#include <iostream>
#include <string>
using namespace std;

void eratosthen(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            continue;
        }
        if(arr[i] == 2) {
            arr[i] = 0;
        }
        if(arr[i] == 4) {
            arr[i] = 0;
        }
        if (arr[i] != 0) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] % arr[i] == 0) {
                    arr[j] = 0;
                }
            }
        }
    }
}

int main() {
    int n = 20;
    int arr[20] = {3, 4, 5, 6, 7, 8, 9, 10, 13, 15, 19, 21, 12, 104, 123, 439, 97, 41, 42};
    eratosthen(arr, n);
    for(int i = 0;i < n;i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

void insertionSort(int* arr, int size) {
    for(int i = 1;i < size;i++) {
        int tmp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

bool binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    while(left <= right) {
        int middle = (left + right) / 2;
        if(arr[middle] == target){
            return true;
        }
        if(arr[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return false;
}

bool isSorted(int* arr, int size) {
    for(int i = 0;i < size;i++) {
        if(arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return false;
}

int main() {

    int arr[] = {5, 2, 4, 1, 3, 9, 10, 8, 7, 6};
    int size = 10;
    cout << "Before sorting: ";
    for(int i = 0;i < size;i++) {
        cout << arr[i] << " ";
    }
    insertionSort(arr, size);
    cout << "After sorting: ";
    for(int i = 0;i < size;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << (binarySearch(arr, size, 33) ? "Found" : "Not found");
    return 0;
}
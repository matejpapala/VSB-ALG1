#include <iostream>
#include <vector>
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

enum Direction {
    left = -1,
    right = 1
};

class ArrowedInt {
public:
    int number;
    int dir = Direction::left;
    ArrowedInt(int number) {
        this->number = number;
    }
};

void printInts(vector<ArrowedInt*> aInts) {
    for (auto aInt : aInts) {
        cout << aInt->number << " ";
    }
    cout << endl;
}

void swapArrInts(ArrowedInt*& a, ArrowedInt*& b) {
    ArrowedInt* tmp = a;
    a = b;
    b = tmp;
}

void changeDirections(vector<ArrowedInt*> aInts, ArrowedInt* mobileInt) {
    for( auto aInt : aInts) {
        if(aInt->number > mobileInt->number) {
            aInt->dir *= -1;
        }
    }
}

bool isMobile(int index, vector<ArrowedInt*> aInts) {
    if(index == 0 && aInts[index]->dir == Direction::left) {
        return false;
    }

    if(index == aInts.size() - 1 && aInts[index]->dir == Direction::right) {
        return false;
    }

    int direction = aInts[index]->dir;
    if(aInts[index]->number > aInts[index + direction]->number) 
        return true;

    return false;
}

int getLargestMobileIndex(vector<ArrowedInt*> aInts) {
    int largestIndex = -1;
    int maxValue = INT_MIN;
    for(int i = 0;i < aInts.size();i++) {
        if(isMobile(i, aInts) && aInts[i]->number > maxValue) {
            maxValue = aInts[i]->number;
            largestIndex = i;
        }
    }
    return largestIndex;
}

void johnsonTrotter(int N) {
    vector<ArrowedInt*> arr;

    for(int i = 0;i < N;i++) {
        arr.push_back(new ArrowedInt(i));
    }

    printInts(arr);
    int index = getLargestMobileIndex(arr);
    while(index >= 0) {
        int direction = arr[index]->dir;
        swapArrInts(arr[index], arr[index + direction]);

        printInts(arr);
        changeDirections(arr, arr[index + direction]);
        index = getLargestMobileIndex(arr);
        
    }
}

int main() {
    int N = 4;
    
    johnsonTrotter(N);

    return 0;
}
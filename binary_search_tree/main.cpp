#include <iostream>
#include "BSTree.h"
using namespace std;
int main() {
    BSTree groot;
    groot.insert(5);
    groot.insert(3);
    groot.insert(7);
    groot.insert(2);
    groot.insert(20);
    groot.insert(40);
    groot.insert(10);
    groot.insert(23);
    groot.insert(30);
    groot.insert(52);
    groot.insert(27);
    groot.insert(25);
    //cout << groot.knotsCount(groot.getRoot()) << endl;
    groot.sortedPrint(groot.getRoot());
    return 0;
}
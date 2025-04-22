#include <iostream>
#include "BSTree.h"
using namespace std;
int main() {
    BSTree groot;
    groot.insert(10);
    groot.insert(5);
    groot.insert(30);
    groot.insert(2);
    groot.insert(7);
    groot.insert(20);
    groot.insert(40);
    groot.insert(15);
    groot.insert(25);
    // groot.insert(35);
    // groot.insert(23);
    // groot.insert(27);
    //cout << groot.knotsCount(groot.getRoot()) << endl;
    groot.sortedPrint(groot.getRoot());
    cout << endl;
    cout << "Height: " << groot.treeHeight(groot.getRoot()) << endl;
    cout << "Is balanced: " << (groot.isBalanced(groot.getRoot()) ? "Yes" : "No") << endl;
    return 0;
}
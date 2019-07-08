#include <iostream>

#include "btree.h"

using namespace std;

int main(int argc, char *argv[]) {

    cout << "Hi" << endl;

    BTree<int> b1(3, true);

    b1.insert(6);
    b1.insert(9);


    b1.print();


    cout << "\nBye" << endl;

//    system("pause");
    return EXIT_SUCCESS;
}
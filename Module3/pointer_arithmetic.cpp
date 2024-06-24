#include <iostream>

using namespace std;

int main() {
    // Initialize an integer array
    int array[6] = {1, 2, 3, 4, 5, 6};

    // Initialize a pointer to the first element of the array
    int *arrayPointer = array;

    // Access each array element using pointer arithmetic
    for (int i = 0; i < 6; i++) {
        cout << "Index " << i << ": " << *(arrayPointer + i) << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    // Declare an integer and an integer pointer
    int myInt;
    int *intPointer;

    myInt = 12;

    // Initialize the pointer using the address-of operator
    intPointer = &myInt;

    // Print the value stored in myInt by dereferencing the pointer
    cout << "Value of myInt: " << *intPointer << endl;

    return 0;
}

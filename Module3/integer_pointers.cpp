#include <iostream>

using namespace std;

int main() {
    // Declare three integer pointers
    int *pointer1;
    int *pointer2;
    int *pointer3;

    // Initialize pointers to dynamic memory
    pointer1 = new int;
    pointer2 = new int;
    pointer3 = new int;

    // Ask for user input, storing in dynamic memory
    cout << "Enter the first integer: " << endl;
    cin >> *pointer1;

    cout << "Enter the second integer: " << endl;
    cin >> *pointer2;

    cout << "Enter the third integer: " << endl;
    cin >> *pointer3;

    cout << endl;

    // Display contents of the variables using dereference operator
    cout << "Contents of first variable: " << *pointer1 << endl;
    cout << "Contents of second variable: " << *pointer2 << endl;
    cout << "Contents of third variable: " << *pointer3 << endl;

    cout << endl;

    // Display contents of the pointers using pointer names
    cout << "Contents of first pointer: " << pointer1 << endl;
    cout << "Contents of second pointer: " << pointer2 << endl;
    cout << "Contents of third pointer: " << pointer3 << endl;

    // Deallocate dynamic memory
    delete pointer1;
    delete pointer2;
    delete pointer3;

    return 0;
}

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

    return 0;
}

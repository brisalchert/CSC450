#include <iostream>

using namespace std;

int main() {
    // Declare input with length 8 characters
    char input[8];

    // Read input from user
    cout << "Enter input for character array:" << endl;
    cin >> input;

    // Print out the input
    cout << "Character array input value: " << input << endl;

    // Print value at adjacent memory location
    cout << "Adjacent memory location value: " << *(&input + 1) << endl;

    cout << endl;

    // Declare string for input
    string stringInput;

    // Read input from user
    cout << "Enter input for string: " << endl;
    cin >> stringInput;

    // Print out the input
    cout << "String input value: " << stringInput << endl;

    // Print value at adjacent memory location
    cout << "Adjacent memory location value: " << *(&stringInput + 1) << endl;

    return 0;
}

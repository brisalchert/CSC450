#include<iostream>

using namespace std;

int main() {
    // Use strings instead of character arrays to avoid buffer overflow
    string firstString;
    string secondString;

    // Get input from the user
    cout << "Enter the first string: " << endl;
    cin >> firstString;
    cout << "Enter the second string: " << endl;
    cin >> secondString;

    // Concatenate the strings by appending secondString to firstString
    firstString.append(secondString);

    // Print the results to the user
    cout << "Concatenated string: \n" + firstString << endl;

    return 0;
}

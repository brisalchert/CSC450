#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string userInput;
    fstream file;

    // Obtain input from user
    cout << "Enter a string: ";
    getline(cin, userInput);

    // Append the user input to the end of CSC450_CT5_mod5.txt
    file.open("CSC450_CT5_mod5.txt", ios::app);
    if (file.is_open()) {
        string line;
        file << userInput;
        file.close();
    }
    else {
        cout << "Unable to open file";
    }

    return 0;
}

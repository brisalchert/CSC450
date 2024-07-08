#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void createReverseFile(string filename) {
    ifstream readFile(filename);
    ofstream writeFile("CSC450-mod5-reverse.txt");

    if (readFile.is_open() && writeFile.is_open()) {
        istreambuf_iterator<char> input_start(readFile);
        istreambuf_iterator<char> input_end;
        ostreambuf_iterator<char> output_start(writeFile);
        vector<char> input_data(input_start, input_end);

        // Use reverse_copy from <algorithm>, which takes two iterators for the beginning
        // and end of the input and an iterator for the output and returns a reversed copy
        reverse_copy(input_data.begin(), input_data.end(), output_start);
        readFile.close();
        writeFile.close();

        cout << "Successfully copied reversed character data to CSC450-mod5-reverse.txt" << endl;
    }
    else {
        cout << "Unable to open read and/or write files";
    }
}

int main() {
    string userInput;
    string filename = "CSC450_CT5_mod5.txt";
    fstream file;

    // Obtain input from user
    cout << "Enter a string: ";
    getline(cin, userInput);

    cout << endl;

    // Open the existing text file
    file.open(filename, ios::app);
    if (file.is_open()) {
        // Append the user input to the end of CSC450_CT5_mod5.txt
        file << userInput;
        file.close();

        cout << "Successfully appended user input to text file" << endl;

        // Reverse the file contents and store in CSC450-mod5-reverse.txt
        createReverseFile(filename);
    }
    else {
        cout << "Unable to open file";
    }

    return 0;
}

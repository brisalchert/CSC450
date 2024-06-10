#include <iostream>

using namespace std;

int main() {
    string s("abc");
    // Attempt to access the character at index 5 using s[5]
    cout << "Character at index 5: " + s[5] << endl;

    // Attempt to access the character at index 5 using s.at(5), resulting in an exception being thrown
    try {
        cout << "Character at index 5: " + s.at(5) << endl;
    }
    catch (out_of_range) {
        cout << "Could not access character at index 5 -- index invalid." << endl;
    }

    return 0;
}

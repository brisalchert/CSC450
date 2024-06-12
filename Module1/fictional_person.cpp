#include <iostream>

using namespace std;

int main() {
    string firstName = "John",
           lastName = "Smith",
           address = "901 Main Street",
           city = "Boston",
           // Zip Code needs to be a string to preserve the leading 0
           zipCode = "02112";

    // Print personal information to the console
    cout << "PERSONAL INFORMATION" << endl;
    cout << "-----------------------------" << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Address: " << address << endl;
    cout << "City: " << city << endl;
    cout << "Zip Code: " << zipCode << endl;

    return 0;
}

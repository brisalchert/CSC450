#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Declare a mutex to use in lock_guard
mutex countMutex;

// Initialize the shared counter to 0
int counter = 0;

// Method for counting up to 20
void countUp() {
    // Set a lock using the mutex, which will automatically unlock at the end of the method
    lock_guard<mutex> lockguard(countMutex);

    cout << "Counting up to 20..." << endl;

    // Increment the counter up to twenty
    while (counter <= 20) {
        cout << "Current value: " << counter << endl;
        counter++;
    }

    cout << endl;
}

// Method for counting down to 0
void countDown() {
    // Set a lock using the mutex, which will automatically unlock at the end of the method
    lock_guard<mutex> lockguard(countMutex);

    cout << "Counting down to 0..." << endl;

    // Decrement the counter down to zero
    while (counter > 0) {
        counter--;
        cout << "Current value: " << counter << endl;
    }

    cout << endl;
}

int main() {
    // Initialize the two threads
    thread countUpThread(countUp);
    thread countDownThread(countDown);

    // Join the threads
    countUpThread.join();
    countDownThread.join();

    return 0;
}

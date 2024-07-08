#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Declare a mutex to use in lock_guard
mutex incrementMutex;

// Initialize an integer to increment
int value = 0;

void incrementHundredThousand() {
    lock_guard<mutex> lockGuard(incrementMutex);

    // Increment the value one hundred thousand times
    for (int i = 0; i < 100000; i++) {
        value++;
    }
}

void decrementFiftyThousand() {
    lock_guard<mutex> lockGuard(incrementMutex);

    // Decrement the value fifty thousand times
    for (int i = 0; i < 50000; i++) {
        value--;
    }
}

int main() {
    // Initialize several threads for executing the function
    thread thread1(incrementHundredThousand);
    thread thread2(decrementFiftyThousand);
    thread thread3(incrementHundredThousand);

    thread1.join();
    thread2.join();
    thread3.join();

    // Print the resulting value
    cout << "Resulting value: " << value << endl;

    return 0;
}

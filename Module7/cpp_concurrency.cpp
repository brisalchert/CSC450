#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// Declare a mutex to use in lock_guard and unique_lock
mutex countMutex;

// Initialize a condition variable and predicate
condition_variable cond;
bool threadOneDone = false;

// Initialize the shared counter to 0
int counter = 0;

// Method for counting up to 20
void countUp() {
    // Set a lock using the mutex, which will automatically unlock at the end of the method
    lock_guard<mutex> lockguard(countMutex);

    cout << "Counting up to 20..." << endl;

    // Print initial value
    cout << "Current value: " << counter << endl;

    // Increment the counter up to twenty
    while (counter < 20) {
        counter++;
        cout << "Current value: " << counter << endl;
    }

    cout << endl;

    // Notify the other thread to "wake up"
    threadOneDone = true;
    cond.notify_one();
}

// Method for counting down to 0
void countDown() {
    // Set a unique lock using the mutex, which will automatically unlock at the end of the method
    unique_lock<mutex> uniqueLock(countMutex);

    // Wait on the condition variable for other thread to finish
    while (!threadOneDone) {
        cond.wait(uniqueLock);
    }

    cout << "Counting down to 0..." << endl;

    // Print initial value
    cout << "Current value: " << counter << endl;

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

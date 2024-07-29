package Module8;

import java.util.concurrent.locks.ReentrantLock;

public class JavaConcurrency {
    private static int counter = 0;
    private static final ReentrantLock lock = new ReentrantLock();

    public static void incrementCounter() {
        // Lock access to the shared counter
        lock.lock();

        System.out.println("Counting up to 20...");

        // Print initial counter value
        System.out.println("Current value: " + counter);

        // Increment counter up to 20
        while (counter < 20) {
            counter++;
            System.out.println("Current value: " + counter);
        }

        System.out.println();

        // Unlock the shared counter
        lock.unlock();
    }

    public static void decrementCounter() {
        // Lock access to the shared counter
        lock.lock();

        System.out.println("Counting down to 0...");

        // Print initial counter value
        System.out.println("Current value: " + counter);

        // Decrement counter down to 0
        while (counter > 0) {
            counter--;
            System.out.println("Current value: " + counter);
        }

        System.out.println();

        // Unlock the shared counter
        lock.unlock();
    }

    public static void main(String[] args) {
        // Create the two threads
        Thread incrementThread = new Thread(new Runnable() {
            @Override
            public void run() {
                incrementCounter();
            }
        });

        Thread decrementThread = new Thread(new Runnable() {
            @Override
            public void run() {
                decrementCounter();
            }
        });

        // Start the threads
        incrementThread.start();
        decrementThread.start();
    }
}

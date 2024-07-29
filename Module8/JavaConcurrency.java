package Module8;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class JavaConcurrency {
    private static int counter = 0;
    private static final ReentrantLock lock = new ReentrantLock();
    private static final Condition counterAtMax = lock.newCondition();
    private static boolean firstThreadDone = false;

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

        // Set second thread's loop condition to true and notify
        firstThreadDone = true;
        counterAtMax.signal();

        // Unlock the shared counter
        lock.unlock();
    }

    public static void decrementCounter() {
        // Lock access to the shared counter
        lock.lock();

        try {
            // Wait until counter is at max
            while (!firstThreadDone) {
                counterAtMax.await();
            }

            System.out.println("Counting down to 0...");

            // Print initial counter value
            System.out.println("Current value: " + counter);

            // Decrement counter down to 0
            while (counter > 0) {
                counter--;
                System.out.println("Current value: " + counter);
            }
        }
        catch (InterruptedException e) {
            // Set the flag for the thread being interrupted
            Thread.currentThread().interrupt();
            System.out.println("Decrement counter thread interrupted");
        }
        finally {
            // Unlock the shared counter
            lock.unlock();
        }
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

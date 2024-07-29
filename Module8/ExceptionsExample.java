package Module8;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class ExceptionsExample {
    public static void main(String[] args) {
        // Call method that throws exception
        exceptionMethod();
    }

    public static void exceptionMethod() {
        // Use try-with-resources to automatically close resources
        // whether an exception occurs or not
        try (FileInputStream inputStream = new FileInputStream("text.txt");
             FileOutputStream outputStream = new FileOutputStream("output.txt")) {
            // This code will not execute due to FileNotFoundException occurring
            inputStream.transferTo(outputStream);
        }
        catch (FileNotFoundException e) {
            System.out.println("Error accessing files");
        } catch (IOException e) {
            System.out.println("I/O exception");
        }
    }
}

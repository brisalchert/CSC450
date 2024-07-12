package Module6;

import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.util.Base64;

public class DataSensitivity {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        // String to encrypt
        String input = "Hello World";

        // Use a key generator to create an encryption key
        SecretKey key = KeyGenerator.getInstance("AES").generateKey();

        // Generate an initialization vector
        byte[] iv = new byte[16];
        new SecureRandom().nextBytes(iv);
        IvParameterSpec initVector = new IvParameterSpec(iv);

        if (key != null) {
            // Encrypt and decrypt the string
            String encryptedString = encryptStringAES(input, key, initVector);
            String decryptedString = decryptStringAES(encryptedString, key, initVector);

            System.out.println("Encrypted String: " + encryptedString);
            System.out.println("Decrypted String: " + decryptedString);
        }
    }

    public static String encryptStringAES(String input, SecretKey key, IvParameterSpec initVector) {
        try {
            // Set the cipher algorithm
            Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");

            // Encrypt the String to a byte array
            cipher.init(Cipher.ENCRYPT_MODE, key, initVector);
            byte[] encryptedString = cipher.doFinal(input.getBytes());

            // Return the byte array as a string of Base64 characters
            return Base64.getEncoder().encodeToString(encryptedString);
        }
        catch (Exception e) {
            System.out.println("Error while encrypting string");

            return null;
        }
    }

    public static String decryptStringAES(String encryptedString, SecretKey key, IvParameterSpec initVector) {
        try {
            // Set the cipher algorithm
            Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");

            // Decrypt the string to a byte array
            cipher.init(Cipher.DECRYPT_MODE, key, initVector);
            byte[] decryptedString = cipher.doFinal(Base64.getDecoder().decode(encryptedString));

            // Return the byte array as a string
            return new String(decryptedString);
        }
        catch (Exception e) {
            System.out.println("Error while decrypting string");

            return null;
        }
    }

    public static SecretKey generateSecretKey() throws NoSuchAlgorithmException {
        try {
            KeyGenerator keyGen = KeyGenerator.getInstance("AES");
            keyGen.init(256);

            return keyGen.generateKey();
        }
        catch (NoSuchAlgorithmException e) {
            System.out.println("Error while generating secret key");

            return null;
        }
    }
}

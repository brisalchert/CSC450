package Module7;

public class ScopeExample {
    public static void main(String[] args) {
        int i = 0;

        // Print out the values 0 - 9
        while (i < 10) {
            System.out.println(i);
            i++;
        }

        // Variable "i" gets modified by other code
        if (i < 20) {
            i++;
        }

        // Attempt to print out the values 10 - 14
        while (i < 15) {
            System.out.println(i);
            i++;
        }

        System.out.println();

        //-----------------------------------------------------
        PaintColor color = new PaintColor();

        System.out.println("Current color: " + color.getColor());

        color.setColorBlue();

        System.out.println("Current color: " + color.getColor());
    }
}

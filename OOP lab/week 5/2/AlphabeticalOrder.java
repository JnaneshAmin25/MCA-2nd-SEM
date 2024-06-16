import java.util.*;

public class AlphabeticalOrder {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input a string
        System.out.print("Enter a string: ");
        String inputString = scanner.nextLine();

        // Output with case
        String outputWithCase = rearrangeAlphabet(inputString, true);
        System.out.println("Output string (with case): " + outputWithCase);

        // Output without case
        String outputWithoutCase = rearrangeAlphabet(inputString, false);
        System.out.println("Output string (without case): " + outputWithoutCase);
    }

    // Function to rearrange characters in alphabetic order
    private static String rearrangeAlphabet(String str, boolean considerCase) {
        char[] charArray = str.toCharArray();

        // Sort the characters
        if (considerCase) {
            Arrays.sort(charArray);
        }else
        {
        // Custom case-insensitive sorting
        Arrays.sort(charArray, String.CASE_INSENSITIVE_ORDER);
    }
        // Convert back to string
        return new String(charArray);
    }
}

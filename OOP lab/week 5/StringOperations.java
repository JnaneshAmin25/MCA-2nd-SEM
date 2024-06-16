import java.util.Scanner;

 class StringOperations {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the first string S1: ");
        String s1 = scanner.nextLine();
        System.out.print("Enter the second string S2: ");
        String s2 = scanner.nextLine();
        System.out.print("Input position: ");
        int n1 = scanner.nextInt();
        System.out.print("Output position: ");
        int n2 = scanner.nextInt();

        System.out.println("Upper-case of "+s1+" is: "+s1.toUpperCase());
        System.out.println("Lower-case of "+s2+" is: " + s2.toLowerCase());

        if (n1 >= 0 && n1 + n2 <= s1.length()) {
            String substring = s1.substring(n1, n1 + n2);
            System.out.println("Substring of "+ s1 +"from position "+ n1 +" with length "+n2+" = " + substring);
        } else {
            System.out.println("Invalid substring parameters.");
        }


        if (n1 >= 0 && n1 <= s1.length()) {
            StringBuffer modifiedS1 = new StringBuffer(s1);
            modifiedS1.insert(n1, s2);
            System.out.println("After inserting "+s2+" into " + s1 + " at position "+n1+" = " + modifiedS1.toString());
        } else {
            System.out.println("Invalid insertion position.");
        }


        String appendedString = s1.concat(s2);
        System.out.println("After appending "+s2+" to "+s1+" = " + appendedString);
    }
}

import java.util.Scanner;
import CToF.CelsToFahr;
import FToC.FahrToCels;

public class TemperatureConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("1. Celsius to Fahrenheit");
            System.out.println("2. Fahrenheit to Celsius");
            System.out.println("3. Quit");
            System.out.print("Enter your choice: ");
            
            int choice = scanner.nextInt();
            
            switch (choice) {
                case 1:
                    System.out.print("Enter temperature in Celsius: ");
                    double celsius = scanner.nextDouble();
                    double fahrenheit = CelsToFahr.ConvertCToF(celsius);
                    System.out.println(celsius + " Celsius is equal to " + fahrenheit + " Fahrenheit.");
                    break;
                case 2:
                    System.out.print("Enter temperature in Fahrenheit: ");
                    double fahrenheitInput = scanner.nextDouble();
                    double celsiusResult = FahrToCels.ConvertFToC(fahrenheitInput);
                    System.out.println(fahrenheitInput + " Fahrenheit is equal to " + celsiusResult + " Celsius.");
                    break;
                case 3:
                    System.out.println("Exiting program.");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        }
    }
}

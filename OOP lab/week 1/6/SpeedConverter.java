import java.util.Scanner;

public class SpeedConverter
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
         System.out.println("Choose conversion direction:");
         System.out.println("1. Kilometers per hour to Meters per second");
         System.out.println("2. Meters per second to Kilometers per hour"
         );

         int choice = scanner.nextInt();

         switch (choice)
         {
            case 1:
                System.out.print("Enter speed in Kilometers per hour: ");
				double kmph = scanner.nextDouble();
        		double mps = kmph * (1000.0 / 3600.0);
        		System.out.println("Speed in Meters per second: " + mps);
                break;
            case 2:
                System.out.print("Enter speed in Meters per second: ");
				mps = scanner.nextDouble();
				kmph = mps / (1000.0 / 3600.0);
				System.out.println("Speed in Kilometers per hour: " + kmph);
                break;
            default:
                System.out.println("Invalid choice. Please enter 1 or 2.");
        }

        scanner.close();
    }
}



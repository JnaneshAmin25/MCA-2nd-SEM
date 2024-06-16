import java.util.Scanner;

public class FuelEconomyCalculator
{

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter distance travelled (in kilometers): ");
        double distance = scanner.nextDouble();
        System.out.print("Enter quantity of fuel used (in liters): ");
        double fuelUsed = scanner.nextDouble();

        double averageFuelEconomy = distance / fuelUsed;;
        System.out.println("Average Fuel Economy: " + averageFuelEconomy + " km/l");

        System.out.println("\nChoose an option:");
        System.out.println("1. Fuel Estimation");
        System.out.println("2. Distance Estimation");
        System.out.print("Enter your choice (1 or a2): ");

        int choice = scanner.nextInt();

        switch (choice)
        {
            case 1:
                System.out.print("Enter distance for fuel estimation (in kilometers): ");
                double distanceForFuelEstimation = scanner.nextDouble();
                double estimatedFuel = distance / averageFuelEconomy;
                System.out.println("Estimated Fuel needed for " + distanceForFuelEstimation + " km: " + estimatedFuel + " liters");
                break;

            case 2:
                System.out.print("Enter fuel quantity for distance estimation (in liters): ");
                double fuelForDistanceEstimation = scanner.nextDouble();
                double estimatedDistance = fuelUsed * averageFuelEconomy;
                System.out.println("Estimated Distance for " + fuelForDistanceEstimation + " liters of fuel: " + estimatedDistance + " km");
                break;

            default:
                System.out.println("Invalid choice. Please choose either 1 or 2.");
        }

        scanner.close();
    }

}

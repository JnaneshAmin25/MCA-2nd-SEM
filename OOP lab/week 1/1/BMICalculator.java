import java.util.Scanner;
public class BMICalculator
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your weight in kilograms: ");
        double weight = scanner.nextDouble();
        System.out.print("Enter your height in centimeters: ");
        double height = scanner.nextDouble();
        double heightInMeters = height / 100.0;
        double bmi = weight / (heightInMeters * heightInMeters);
        System.out.println("Your BMI is: " + bmi);
        System.out.println("BMI Interpretation:");

        if (bmi < 18.5)
        {
            System.out.println("Underweight");
        }
        else if (bmi >= 18.5 && bmi <= 24.9)
        {
            System.out.println("Normal");
        }
        else if (bmi >= 25 && bmi <= 29.9)
        {
            System.out.println("Overweight");
        }
        else
        {
            System.out.println("Obese");
        }
        scanner.close();
    }
}

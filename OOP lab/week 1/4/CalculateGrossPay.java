import java.util.Scanner;

public class CalculateGrossPay
{
    public static void main(String[] args)
    {
		double regularPay;
        double overtimePay;

        Scanner scanner = new Scanner(System.in);
		System.out.print("Enter the number of hours worked: ");
        double hoursWorked = scanner.nextDouble();

		System.out.print("Enter the hourly rate: ");
        double hourlyRate = scanner.nextDouble();

		if (hoursWorked <= 40)
        {
		            regularPay = hoursWorked * hourlyRate;
		            overtimePay = 0;
		}
		else
		{
		            regularPay = 40 * hourlyRate;
		            overtimePay = (hoursWorked - 40) * (hourlyRate * 1.5);
		}

		double grossPay = regularPay + overtimePay;
        System.out.println("Gross Pay: " + grossPay);
        scanner.close();
    }
}









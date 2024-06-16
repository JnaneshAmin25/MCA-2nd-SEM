import java.util.Scanner;

class Employee
{
    private int empCode;
    private String empName;
    private double basic;
    private double hra;
    private double it;
    private double pf;
    private double grossSal;
    private double netSal;

    public void readData()
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Employee Code: ");
        empCode = sc.nextInt();

	sc.nextLine();
	System.out.print("Enter Employee Name: ");
        empName = sc.nextLine();

        System.out.print("Enter Basic Salary: Rs.");
        basic = sc.nextDouble();
    }

    private void calculateSalaryComponents()
    {
        hra = 0.075 * basic;
        it = 200;
        pf = 0.12 * basic;
        grossSal = basic + hra;
        netSal = grossSal - (it + pf);
    }

    public void displayData()
    {
        calculateSalaryComponents();

        System.out.println("\nEmployee Details:");
        System.out.println("Employee Code: " + empCode);
        System.out.println("Employee Name: " + empName);
        System.out.println("Basic Salary: Rs." + basic);
        System.out.println("HRA: Rs." + hra);
        System.out.println("IT: Rs." + it);
        System.out.println("PF: Rs." + pf);
        System.out.println("Gross Salary: Rs." + grossSal);
        System.out.println("Net Salary: Rs." + netSal);
    }
}

public class EmployeeMain
{
    public static void main(String[] args)
    {
        Employee emp = new Employee();
        emp.readData();
        emp.displayData();
    }
}
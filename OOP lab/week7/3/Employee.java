import java.util.Scanner;
public class Employee implements Cloneable
{
    private String name;
    private static int idCounter = 1000;
    private int id;
    private String designation;
    private double salary;

    public Employee(String name, String designation, double salary)
    {
        this.name = name;
        this.id = ++idCounter;
        this.designation = designation;
        this.salary = salary;
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public int getId()
    {
        return id;
    }

    public String getDesignation()
    {
        return designation;
    }

    public void setDesignation(String designation)
    {
        this.designation = designation;
    }

    public double getSalary()
    {
        return salary;
    }

    public void setSalary(double salary)
    {
        this.salary = salary;
    }

    @Override
    public Object clone()
    {
        try
        {
            return super.clone();
        } catch (CloneNotSupportedException e)
        {
            throw new AssertionError();
        }
    }

    public void display()
    {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("Designation: " + designation);
        System.out.println("Salary: " + salary);
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of employees: ");
        int n = scanner.nextInt();

        Employee[] employees = new Employee[n];

        for (int i = 0; i < n; i++)
        {
            scanner.nextLine();
            System.out.println("\nEnter details for employee " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.nextLine();
            System.out.print("Designation: ");
            String designation = scanner.nextLine();
            System.out.print("Salary: ");
            double salary = scanner.nextDouble();

            employees[i] = new Employee(name, designation, salary);
        }

		System.out.println("\n\nEmployee Details:\n-------------------------------------------\n");
        for (Employee employee : employees)
        {
            employee.display();
            System.out.println();
        }
    }
}

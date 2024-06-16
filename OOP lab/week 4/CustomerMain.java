import java.util.Scanner;

class Customer
{
    private int customerId;
    private String name;
    private String phoneNumber;
    private int billNumber;
    private int numberOfCalls;
    private double billAmount;

    public Customer(int customerId, String name, String phoneNumber, int billNumber, int numberOfCalls)
    {
        this.customerId = customerId;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.billNumber = billNumber;
        this.numberOfCalls = numberOfCalls;
        this.billAmount = 0.0;
    }


    public void acceptDetails()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Customer ID: ");
        customerId = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter Customer Name: ");
        name = scanner.nextLine();

        System.out.print("Enter Phone Number: ");
        phoneNumber = scanner.nextLine();

        System.out.print("Enter Bill Number: ");
        billNumber = scanner.nextInt();

        System.out.print("Enter Number of Calls: ");
        numberOfCalls = scanner.nextInt();
    }


    public void displayDetails()
    {
        System.out.println("\nCustomer ID: " + customerId);
        System.out.println("Customer Name: " + name);
        System.out.println("Phone Number: " + phoneNumber);
        System.out.println("Bill Number: " + billNumber);
        System.out.println("Number of Calls: " + numberOfCalls);
        System.out.println("Bill Amount: Rs." + billAmount);
    }


    public void calculateBillAmount()
    {
        if (numberOfCalls <= 100)
        {
            billAmount = 100.0;
        } else if (numberOfCalls <= 150)
        {
            billAmount = 100.0 + 0.60 * (numberOfCalls - 100);
        } else if (numberOfCalls <= 200)
        {
            billAmount = 100.0 + 0.60 * 50 + 0.50 * (numberOfCalls - 150);
        } else
        {
            billAmount = 100.0 + 0.60 * 50 + 0.50 * 50 + 0.40 * (numberOfCalls - 200);
        }
    }
}

public class CustomerMain
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of customers: ");
        int numberOfCustomers = scanner.nextInt();


        Customer[] cust = new Customer[numberOfCustomers];


        for (int i = 0; i < numberOfCustomers; i++)
        {
            System.out.println("\nEnter details for Customer " + (i + 1) + ":");
            System.out.println("---------------------------");
            cust[i] = new Customer(0, "", "", 0, 0);
            cust[i].acceptDetails();
            cust[i].calculateBillAmount();
        }


        System.out.println("\nCustomer Details and Bill Amounts:");
        for (int i = 0; i < numberOfCustomers; i++)
        {
            cust[i].displayDetails();
        }
    }
}

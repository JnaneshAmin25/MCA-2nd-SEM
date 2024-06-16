import java.util.Scanner;

class Shop
{
    private int itemId;
    private String itemName;
    private int quantity;
    private double unitPrice;
    private double totalBillAmount;

    public Shop(int itemId, String itemName, int quantity, double unitPrice)
    {
        this.itemId = itemId;
        this.itemName = itemName;
        this.quantity = quantity;
        this.unitPrice = unitPrice;
        this.totalBillAmount = quantity * unitPrice;
    }

    public double calculateDiscount()
    {
        if (totalBillAmount < 500)
        {
            return 0;
        } else if (totalBillAmount >= 500 && totalBillAmount <= 1000)
        {
            return 0.1 * totalBillAmount;
        } else if (totalBillAmount > 1000 && totalBillAmount <= 2000)
        {
            return 0.12 * totalBillAmount;
        } else
        {
            return 0.15 * totalBillAmount;
        }
    }

    public double getTotalBillAmount()
    {
        return totalBillAmount;
    }

    public void displayDetails()
    {
        System.out.println("Item ID: " + itemId);
        System.out.println("Item Name: " + itemName);
        System.out.println("Quantity: " + quantity);
        System.out.println("Unit Price: " + unitPrice);
        System.out.println("Total Bill Amount: " + totalBillAmount);
    }
}

public class Shopping
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Item ID: ");
        int itemId = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter Item Name: ");
        String itemName = scanner.nextLine();

        System.out.print("Enter Quantity: ");
        int quantity = scanner.nextInt();

        System.out.print("Enter Unit Price: ");
        double unitPrice = scanner.nextDouble();

        Shop objshop = new Shop(itemId, itemName, quantity, unitPrice);
        System.out.println("\n1. Display Details");
		System.out.println("2. Calculate Discount");
		System.out.println("3. Exit");
		int choice;
         do
         {


		                System.out.print("\n\nEnter your choice (1/2/3): ");
		                choice = scanner.nextInt();

		                switch (choice)
		                {
		                    case 1:
		                        objshop.displayDetails();
		                        break;
		                    case 2:
		                        double discount = objshop.calculateDiscount();
		                        System.out.println("Discount: " + discount);
		                        System.out.println("Total Payable Amount: " + (objshop.getTotalBillAmount() - discount));
		                        break;
		                    case 3:
		                        System.out.println("Exiting the program.");
		                        break;
		                    default:
		                        System.out.println("Invalid choice. Please try again.");
		                }
            } while (choice != 3);
    }
}

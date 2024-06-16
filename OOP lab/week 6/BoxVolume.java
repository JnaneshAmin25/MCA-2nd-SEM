import java.util.*;

class Box
{
    double length;
    double width;
    double height;

    public Box(double length, double width, double height)
    {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    public Box()
    {
        inputDimensions();
    }

     public void inputDimensions()
	 {
		 Scanner scanner = new Scanner(System.in);
		 boolean validDimensions = false;
         while (!validDimensions)
		 {
		            System.out.print("Enter length: ");
		            length = scanner.nextDouble();
		            System.out.print("Enter width: ");
		            width = scanner.nextDouble();
		            System.out.print("Enter height: ");
		    		height = scanner.nextDouble();

		            if (length > 0 && width > 0 && height > 0)
		            {
		                validDimensions = true;
		            } else
		            {
		                System.out.println("Error: Dimensions must be greater than zero. Please enter valid values.");
		            }
		 }
    }

    public double calculateVolume()
    {
        return length * width * height;
    }

    public void display()
    {
        System.out.println("Box Volume: " + calculateVolume());
        System.out.println("Length: " + length);
        System.out.println("Width: " + width);
        System.out.println("Height: " + height);
    }

}

class ChildBox extends Box
{
    double weight;
    String color;

    public ChildBox()
    {
		super();
        inputAttributes();
    }

    public ChildBox(double length, double width, double height, double weight, String color)
    {
        super(length, width, height);
        this.weight = weight;
        this.color = color;
    }


    public void display()
    {
        super.display();
        System.out.println("Weight: " + weight);
        System.out.println("Color: " + color);
    }

    public void inputAttributes()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter weight: ");
        weight = scanner.nextDouble();
        System.out.print("Enter color: ");
        color = scanner.next();
    }
}

public class BoxVolume
{
    public static void main(String[] args)
    {
        System.out.println("Enter dimensions for ChildBox 1:");
        ChildBox myBox1 = new ChildBox();
        System.out.println("\nEnter dimensions for ChildBox 2:");
        ChildBox myBox2 = new ChildBox();

        System.out.println("\nChildBox 1:");
        myBox1.display();

        System.out.println("\nChildBox 2:");
        myBox2.display();
    }
}

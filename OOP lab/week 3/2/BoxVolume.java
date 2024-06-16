import java.util.Scanner;

class Box
{
    private double width;
    private double height;
    private double depth;


    public Box(double width, double height, double depth)
    {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }


    public double calculateVolume()
    {
        return width * height * depth;
    }
}

public class BoxVolume
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the width of the box(in cm): ");
        double width = scanner.nextDouble();

        System.out.print("Enter the height of the box(in cm): ");
        double height = scanner.nextDouble();

        System.out.print("Enter the depth of the box(in cm): ");
        double depth = scanner.nextDouble();

        Box myBox = new Box(width, height, depth);

        double volume = myBox.calculateVolume();
        System.out.println("Volume of the box: " + volume+" cm3");
    }
}

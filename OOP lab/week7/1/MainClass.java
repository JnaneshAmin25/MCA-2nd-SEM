import java.util.Scanner;
abstract class Figure
{
    abstract double area();
}

class Rectangle extends Figure
{
    private int length;
    private int width;
    Rectangle(int length, int width)
    {
        this.length = length;
        this.width = width;
    }
    @Override
    double area()
    {
		System.out.println("\nArea of Rectangle: ");
        return length * width;
    }
}

class Triangle extends Figure
{
    private int base;
    private int height;
    Triangle(int base, int height)
    {
        this.base = base;
        this.height = height;
    }
    @Override
    double area()
    {
		System.out.println("\nArea of Triangle: ");
        return 0.5 * base * height;
    }
}

class Square extends Figure
{
    private int side;
    Square(int side)
    {
        this.side = side;
    }
    @Override
    double area()
    {
		System.out.println("\nArea of Square: ");
        return side * side;
    }
}

public class MainClass
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        Figure[] figures = new Figure[3];


        System.out.println("Enter length and width for Rectangle:");
        int length = scanner.nextInt();
        int width = scanner.nextInt();
        figures[0] = new Rectangle(length, width);


        System.out.println("Enter base and height for Triangle:");
        int base = scanner.nextInt();
        int height = scanner.nextInt();
        figures[1] = new Triangle(base, height);


        System.out.println("Enter side length for Square:");
        int side = scanner.nextInt();
        figures[2] = new Square(side);

        for (Figure figure : figures)
        {
            System.out.println(figure.area());
        }
    }
}

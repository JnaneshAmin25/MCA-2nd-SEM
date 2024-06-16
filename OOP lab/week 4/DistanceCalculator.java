import java.util.Scanner;

class Point
{
    double x;
    double y;

    public Point(double x, double y)
    {
        this.x = x;
        this.y = y;
    }


    public String toString()
    {
        return "P(" + x + ", " + y + ")";
    }
}

public class DistanceCalculator
{
    public static double calculateDistance(Point point1, Point point2)
    {
        double distance = Math.sqrt(Math.pow((point2.x - point1.x), 2) + Math.pow((point2.y - point1.y), 2));
        return distance;
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter x-coordinate for P1: ");
        double x1 = scanner.nextDouble();
        System.out.print("Enter y-coordinate for P1: ");
        double y1 = scanner.nextDouble();
        Point P1 = new Point(x1, y1);

        System.out.print("Enter x-coordinate for P2: ");
        double x2 = scanner.nextDouble();
        System.out.print("Enter y-coordinate for P2: ");
        double y2 = scanner.nextDouble();
        Point P2 = new Point(x2, y2);

        System.out.print("Enter x-coordinate for P3: ");
        double x3 = scanner.nextDouble();
        System.out.print("Enter y-coordinate for P3: ");
        double y3 = scanner.nextDouble();
        Point P3 = new Point(x3, y3);

        System.out.println("Points:");
        System.out.println("P1: " + P1);
        System.out.println("P2: " + P2);
        System.out.println("P3: " + P3);

        double distance_P1_P2 = calculateDistance(P1, P2);
        System.out.println("Distance between P1 and P2: " + distance_P1_P2);

        double distance_P1_P3 = calculateDistance(P1, P3);
        System.out.println("Distance between P1 and P3: " + distance_P1_P3);
    }
}

import java.util.Scanner;

public class Stack
{
    private static final int MAX_SIZE = 100;
    private static int top = -1;
    private static int[] elements = new int[MAX_SIZE];

    private Stack() {}

    public static void push(int value)
    {
        if (top == MAX_SIZE - 1)
        {
            System.out.println("Stack overflow! Cannot push element " + value);
        } else
        {
            top++;
            elements[top] = value;
            System.out.println("Pushed element: " + value);
        }
    }

    public static void pop()
    {
        if (top == -1)
        {
            System.out.println("Stack underflow! Cannot pop from an empty stack.");
        } else
        {
            System.out.println("Popped element: " + elements[top]);
            top--;
        }
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        while (true)
        {
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice)
            {
                case 1:
                    System.out.print("Enter the element to push: ");
                    int pushValue = scanner.nextInt();
                    push(pushValue);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    System.out.println("Exiting the program.");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please enter 1, 2, or 3.");
            }
        }
    }
}

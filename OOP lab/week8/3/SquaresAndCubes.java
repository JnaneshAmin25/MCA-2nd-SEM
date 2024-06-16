import java.util.Scanner;
class SquareThread extends Thread
{
    private int n;
    public SquareThread(int n)
    {
        this.n = n;
    }
    public void run()
    {
        for (int i = 1; i <= n; i++)
        {
            System.out.println("Square of " + i + " is " + (i * i));
            try
            {
                Thread.sleep(1000);
            } catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}

class CubeThread extends Thread
{
    private int n;
    public CubeThread(int n)
    {
        this.n = n;
    }
    public void run()
    {
        for (int i = 1; i <= n; i++)
        {
            System.out.println("Cube of " + i + " is " + (i * i * i));
            try
            {
                Thread.sleep(1000);
            } catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}

public class SquaresAndCubes
{
    public static void main(String[] args)
    {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number to display its square and cube");
        int n = sc.nextInt();

        SquareThread squareThread = new SquareThread(n);
        CubeThread cubeThread = new CubeThread(n);

        squareThread.start();
        cubeThread.start();
    }
}
import java.util.Scanner;
class RowSumThread extends Thread
{
    private int[] row;
    private int sum;

    public RowSumThread(int[] row)
    {
        this.row = row;
        this.sum = 0;
    }

    public void run()
    {
        for (int i : row)
        {
            sum += i;
            try
            {
                Thread.sleep(100);
            } catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }

    public int getSum()
    {
        return sum;
    }
}

public class MatrixRowSum
{
    public static void main(String[] args)
    {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the row and column:");
		int r = sc.nextInt();
		int c = sc.nextInt();
        int[][] matrix = new int[r][c];

        System.out.println("Enter the elements:");
        for(int i=0;i<r;i++)
        {
			for(int j=0;j<c;j++)
			{
				matrix[i][j]= sc.nextInt();
			}
		}

        RowSumThread[] threads = new RowSumThread[matrix.length];
        for (int i = 0; i < matrix.length; i++)
        {
            threads[i] = new RowSumThread(matrix[i]);
            threads[i].start();
        }

        int totalSum = 0;
        for (RowSumThread thread : threads)
        {
            try
            {
                thread.join();
                totalSum += thread.getSum();
            } catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }

        System.out.println("Total sum of all elements: " + totalSum);
    }
}
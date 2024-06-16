import java.util.Scanner;

public class FindMinMax
{
    public static void main(String[] args)
    {
		int i,j;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of rows: ");
        int rows = scanner.nextInt();
        System.out.print("Enter the number of columns: ");
        int columns = scanner.nextInt();

        int[][] array = new int[rows][columns];


        System.out.println("Enter the elements of the array:");
        for ( i = 0; i < rows; i++)
        {
            for ( j = 0; j < columns; j++)
            {
                array[i][j] = scanner.nextInt();
            }
        }

		int min = array[0][0];
		int max = array[0][0];
        int minRow = 0, minColumn = 0, maxRow = 0, maxColumn = 0;
		for ( i = 0; i < rows; i++)
		{
            for ( j = 0; j < columns; j++) {
                if (array[i][j] < min) {
                    min = array[i][j];
                    minRow = i;
                    minColumn = j;
                }

                if (array[i][j] > max) {
                    max = array[i][j];
                    maxRow = i;
                    maxColumn = j;
                }
            }
        }

        System.out.println("The largest element = " + max + ", location = (" + maxRow + ", " + maxColumn + ")");
        System.out.println("The smallest element = " + min + ", location = (" + minRow + ", " + minColumn + ")");

  }

}

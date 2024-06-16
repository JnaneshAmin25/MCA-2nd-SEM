import java.util.Scanner;

public class DisplayPairs
{
    public static void main(String[] args)
    {
		int i,j;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();
        int numbers[] = new int[n];

        System.out.println("Enter distinct numbers for the array:");
        for (i = 0; i < n; i++)
        {
            numbers[i] = scanner.nextInt();
        }
        System.out.println("entered array is:");
        for(i=0;i<n;i++)
        {
			System.out.println(numbers[i]);
		}
        System.out.println("Output:");
        for (i = 0; i < n; i++)
        {
			for (j = 0; j < n; j++)
			{
				if (numbers[i] > numbers[j])
				{
        			System.out.println("(" + numbers[i] + "," + numbers[j] + ")");
				}
			}
		}
        scanner.close();
    }
}

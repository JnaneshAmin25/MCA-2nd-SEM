import java.util.Arrays;
import java.util.Scanner;
public class ArrayReverse
{
	public static void main(String[] args)
	{
		int n,i;
		System.out.println("How many elements?  :");
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		int orgArray[] = new int[n];


		System.out.println("enter the elements:");
		for(i=0;i<n;i++)
		{
			orgArray[i] = scanner.nextInt();
		}


		System.out.println("array elements are:");
		System.out.println("Original Array:"+ Arrays.toString(orgArray));


		int revArray[] = new int[n];
		for(i=0;i<n;i++)
		{
			int revNumber = 0;
			while(orgArray[i] != 0)
			{
				int digit = orgArray[i]%10;
				revNumber = revNumber*10+digit;
				orgArray[i]/=10;
				revArray[i] = revNumber;
			}
		}
		System.out.println("Reversed Array:"+ Arrays.toString(revArray));
	}

}
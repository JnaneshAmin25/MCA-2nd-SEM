import java.util.Scanner;
public class ArrayDivision
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("enter the size of the 2 arrays (should be of same size)");
		int size = sc.nextInt();

		int[] arr1 = new int[size];
		int[] arr2 = new int[size];

		System.out.println("Enter the elements for array-1");
		for(int i=0; i<size; i++)
		{
			arr1[i] = sc.nextInt();
		}

		System.out.println("Enter the elements for array-2");
		for(int i=0; i<size; i++)
		{
			arr2[i] = sc.nextInt();
		}

		try
		{
			for(int i=0; i<size; i++)
			{
				try
				{
					System.out.println(arr1[i]+"/"+arr2[i]+"="+(arr1[i]/arr2[i]));
				}
				catch(ArithmeticException e)
				{
					System.out.println("Divide By Zero Error at index "+i);
					return;
				}
				catch(ArrayIndexOutOfBoundsException e)
				{
					System.out.println("Array out of bound exception");
				}
			}
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("Array out of bound exceptikon");
		}
	}
}
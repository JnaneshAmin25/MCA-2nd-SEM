import java.util.*;

class PalindromeChecker
{
 	private static void checkPalindrome(String str)
	{
		String rev = "";

		for (int i = str.length() - 1; i >= 0; i--)
		{
			rev = rev + str.charAt(i);
		}

		System.out.println("Reversed String is = "+rev);

		if (str.equals(rev))
			System.out.println("Entered String is a palindrome");
		else
			System.out.println("Entered String is not a palindrome");
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the string :");
		String str = sc.nextLine();
		str = str.toLowerCase();
		checkPalindrome(str);
	}
}

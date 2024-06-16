import java.util.Scanner;

class MarkOutofBoundsException extends Exception
{
	public MarkOutofBoundsException(String message)
	{
		super(message);
	}
}

public class StudentDetails
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("\nStudent name:");
		String sname = sc.nextLine();
		System.out.println("\nStudent rollnumber:");
		int rollno = 0;
		try
		{
			rollno = Integer.parseInt(sc.nextLine());
		}
		catch(NumberFormatException e)
		{
			System.out.println("invalid format of rollnumber");
			return;
		}
		System.out.println("Enter the number of subjects");
		int numSub = sc.nextInt();
		int[] marks = new int[numSub];
		for(int i=0; i<numSub; i++)
		{
			try
			{
				System.out.println("subject"+(i+1)+" marks:");
				marks[i] = sc.nextInt();
				if(marks[i]<0 || marks[i]>100)
				{
					throw new MarkOutofBoundsException("Marks should be between 0 and 100");
				}
			}
			catch(MarkOutofBoundsException e)
			{
				System.out.println(e.getMessage());
				return;
			}
			catch(NumberFormatException e)
			{
				System.out.println("invalid format");
				return;
			}
		}
		double totalMarks = 0;
		for(int i=0;i<numSub;i++)
		{
			totalMarks += marks[i];
		}
		double average = totalMarks/numSub;
		char grade;
		if (average >= 90)
		{
			grade = 'A';
		}
		else if (average >= 80)
		{
			grade = 'B';
		}
		else if (average >= 70)
		{
			grade = 'C';
		}
		else if (average >= 60)
		{
			grade = 'D';
		}
		else if (average >= 50)
		{
			grade = 'E';
		}
		else
		{
			grade = 'F';
		}

		System.out.println("\n----------STUDENT DETAILS--------------------");
		System.out.println("\nStudent Roll Number:"+rollno);
		System.out.println("Student name:"+sname);
		System.out.println("Average:"+average);
		System.out.println("Grade:"+grade);
	}
}
import java.util.Scanner;

class Student
{
    int regNumber;
    String name;
    String course;
    int semester;

    public void get_data()
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Register Number: ");
        regNumber = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter Name: ");
        name = scanner.nextLine();
        System.out.print("Enter Course: ");
        course = scanner.nextLine();
        System.out.print("Enter Semester: ");
        semester = scanner.nextInt();
    }

    public void display()
    {
        System.out.println("Register Number: " + regNumber);
        System.out.println("Name: " + name);
        System.out.println("Course: " + course);
        System.out.println("Semester: " + semester);
    }
}

class Exam extends Student
{
    int m1;
    int m2;
    int m3;

    @Override
     public void get_data()
     {
	        Scanner scanner = new Scanner(System.in);
	        boolean validMarks = false;
	        while (!validMarks)
	        {
	            super.get_data();
	            System.out.print("Enter Marks for Subject 1: ");
	            m1 = scanner.nextInt();
	            System.out.print("Enter Marks for Subject 2: ");
	            m2 = scanner.nextInt();
	            System.out.print("Enter Marks for Subject 3: ");
	            m3 = scanner.nextInt();

	            if (isValidMarks(m1) && isValidMarks(m2) && isValidMarks(m3))
	            {
	                validMarks = true;
	            } else
	            {
	                System.out.println("\nMarks should be between 0 and 100. Please enter valid marks.\n");
	            }
	        }
    }
    private boolean isValidMarks(int marks)
    {
	        return marks >= 0 && marks <= 100;
    }


    public void display()
    {
        super.display();
        System.out.println("Marks in Subject 1: " + m1);
        System.out.println("Marks in Subject 2: " + m2);
        System.out.println("Marks in Subject 3: " + m3);
    }
}

class Result extends Exam
{
    int totalMarks;
    char grade;


    public void get_data()
    {
        super.get_data();
        totalMarks = m1 + m2 + m3;

        if (totalMarks >= 240)
        {
            grade = 'A';
        } else if (totalMarks >= 180)
        {
            grade = 'B';
        } else if (totalMarks >= 120)
        {
            grade = 'C';
        } else if (totalMarks >= 60)
        {
            grade = 'D';
        } else
        {
            grade = 'F';
        }
    }


    public void display()
    {
        super.display();
        System.out.println("Total Marks: " + totalMarks);
        System.out.println("Grade: " + grade);
    }
}

public class StudentResult
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();

        Result[] students = new Result[n];

        for (int i = 0; i < n; i++)
        {
            System.out.println("\nEnter details for Student " + (i + 1) + ":");
            students[i] = new Result();
            students[i].get_data();
        }

        System.out.println("\nStudent Details:");
        for (Result student : students)
        {
            student.display();
            System.out.println();
        }
    }
}
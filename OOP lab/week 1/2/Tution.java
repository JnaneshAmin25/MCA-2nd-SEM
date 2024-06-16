import java.util.Scanner;
class Tuition
{

    public static void main(String[] args)
    {

        double initialFee = 50000;
        double increaseRate = 0.05;
        System.out.println("Year\tTuition Fee");

        for (int year = 1; year <= 10; year++)
        {
            double tuitionFee = initialFee * Math.pow(1 + increaseRate, year);
            System.out.println(year + "\t" + tuitionFee);
        }
    }

}

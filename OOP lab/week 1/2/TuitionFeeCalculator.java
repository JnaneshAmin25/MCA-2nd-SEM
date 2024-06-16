import java.util.Scanner;
public class TuitionFeeCalculator
{
    public static void main(String[] args)
    {
        double initialFee = 50000;
        double increaseRate = 0.05;
        for (int year = 1; year <= 10; year++)
        {
			double increasePercent = initialFee * increaseRate;
            double tuitionFee = initialFee + increasePercent;
            increaseRate += 0.05;
            System.out.println("The fee after "+year+ "year = "+tuitionFee);
        }
    }

}

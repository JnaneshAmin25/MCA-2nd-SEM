import java.util.Scanner;

public class LoanPaymentCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        System.out.print("Enter the loan amount: ");
        double loanAmount = scanner.nextDouble();
        System.out.print("Enter the loan period in years: ");
        int loanPeriodYears = scanner.nextInt();

        System.out.printf("\nInterest Rate\tMonthly Payment\t\tTotal Payment\n");
        System.out.printf("---------------------------------------------------------------\n");

        for (double interestRate = 5.0; interestRate <= 8.0; interestRate += 0.125)
        {
            double monthlyInterestRate = interestRate / 1200;
            int numberOfPayments = loanPeriodYears * 12;
            double monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - 1 /(Math.pow(1 + monthlyInterestRate, numberOfPayments)));
            double totalPayment = monthlyPayment * numberOfPayments;

            System.out.printf(interestRate+"\t\t"+monthlyPayment+"\t"+totalPayment+"\n");
        }
        scanner.close();
    }
}

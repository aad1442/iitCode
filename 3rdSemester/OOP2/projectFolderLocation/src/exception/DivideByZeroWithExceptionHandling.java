package exception;

import java.util.InputMismatchException;
import java.util.Scanner;

public class DivideByZeroWithExceptionHandling {
	
	public static int quotient(int numerator, int denominator) {
		return numerator/denominator;
	}

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		boolean continueLoop = true;
		
		do {
			try {
				System.out.println("Please enter an integer numerator:");
				int numerator = sc.nextInt();
				System.out.println("Please enter an integer denominator:");
				int denominator = sc.nextInt();
				
				int result = quotient(numerator, denominator);
				System.out.printf("\nResult: %d / %d = %d\n",numerator,denominator,result);
				continueLoop = false;
			}
			catch(InputMismatchException inputMismatchException) {
				System.err.printf("\nException: %s",inputMismatchException);
				sc.nextLine();
				System.out.println("You must enter inters. Please try again.\n");
				
			}
			catch(ArithmeticException arithmeticException) {
				System.err.printf("\nException: %s\n",arithmeticException);
				System.out.println("Zero is an invalid denominator. Please try again.\n");
				
			}
			
		}while(continueLoop);
		
		
		
		

	}

}

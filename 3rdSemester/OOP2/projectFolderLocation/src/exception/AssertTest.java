package exception;

import java.util.Scanner;

public class AssertTest {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter number between 0 and 10: ");
		int number = input.nextInt();
		
		assert(number>=0 && number <=10): "badnumber:"+number;
		System.out.printf("You entered %d\n",number);

	}

}


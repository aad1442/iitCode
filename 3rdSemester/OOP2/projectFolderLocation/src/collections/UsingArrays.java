package collections;

import java.util.Arrays;

public class UsingArrays {
	private int intArray[] = { 1, 2, 3, 4, 5, 6 };
	private double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	private int filledArray[], intArrayCopy[];

	public UsingArrays() {
		filledArray = new int[10];
		intArrayCopy = new int[intArray.length];

		Arrays.fill(filledArray, 7);
		Arrays.sort(doubleArray);

		System.arraycopy(intArray, 0, intArrayCopy, 0, intArray.length);
	}

	public void printArrays() {
		System.out.println("\ndoubleArray: ");
		for (double doubleValue : doubleArray) {
			System.out.printf("%.2f ", doubleValue);
		}

		System.out.println("\nintArray: ");
		for (int intValue : intArray) {
			System.out.printf(" %d ", intValue);
		}

		System.out.println(" \nfilledArray");
		for (int intValue : filledArray) {
			System.out.printf("%d ", intValue);
		}
		System.out.println(" \nintArraycopy: ");
		for (int intValue : intArrayCopy) {
			System.out.printf("%d ", intValue);
		}
		System.out.println("\n\n\n");
	}

	public int serchForInt(int value) {
		return Arrays.binarySearch(intArray,value);
		
	}
	
	public void printEquality() {
		boolean b = Arrays.equals(intArray, intArrayCopy);
		System.out.printf("intArray %s intArrayCopy\n",b?"== ": "!=");
		
		b = Arrays.equals(intArray,filledArray);
		System.out.printf("intArray %s filledArray\n",b? "== ":"!=");
	}
	
	public static void main(String[] args) {
		UsingArrays usingArrays = new UsingArrays();
		usingArrays.printArrays();
		usingArrays.printEquality();
		
		int location= usingArrays.serchForInt(5);
		
		if(location >= 0) {
			System.out.printf("Found 5 at element %d in intArray\n",location);
		}
		else {
			System.out.println("5 not found in intArray. ");
		}
		
		location = usingArrays.serchForInt(2376);
		
		if(location >= 0) {
			System.out.printf("Found 5 at element %d in intArray\n",location);
		}
		else {
			System.out.println("5 not found in intArray. ");
		}
	}
	
	
	
}

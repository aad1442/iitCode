package generics;

public class GenericMethodTest {
	public static <E> void printArray(E[] inputArray) {
		for(E element : inputArray) {
			System.out.printf("%s ",element);
		}System.out.println();
	}


	
	public static void main(String[] args) {
		Integer[] integerArray = {1,2,3,4,5,6};
		Double[] doubleArray = {1.1,2.2,3.3,4.4,5.5};
		Character[] characterArray = {'a','d','n','a','n'};
		System.out.println("Integer array contains: ");
		printArray(integerArray);
		System.out.println("Double array contains ");
		printArray(doubleArray);
		System.out.println("Character array contains");
		printArray(characterArray);
	}

}

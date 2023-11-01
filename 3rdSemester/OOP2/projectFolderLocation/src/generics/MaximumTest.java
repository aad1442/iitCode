package generics;

public class MaximumTest {
	public static <T extends Comparable<T>> T maximum(T x, T y, T z) {
		T max = x;
		if(y.compareTo(max)>0) {
			max = y;
		}
		if(z.compareTo(max)>0) {
			max = z;
		}
		return max;
	}

	public static void main(String[] args) {
		System.out.printf("Maximum of 2,3,4: \n",maximum(2,3,4));
		System.out.printf("Maximum of 2.2,3.3,4.4\n",maximum(2.2,3.3,4.4));
		System.out.printf("Maximum of a,b,c\n",maximum("a","b","c"));

	}

}

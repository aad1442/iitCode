package generics;

public class Stack<E> {
	private final int size;
	private int top;
	private E[] elements;
	
	public Stack() {
		this(10);
	}
	
	public Stack(int s) {
		size =s > 0 ? s : 10;
		top = -1;
		elements = (E[]) new Object[size];
	}

}

package exception;

public class Assertion {
    public static void main(String[] args) {
        int x = 5;
        assert x == 10 : "x should be 10"; // If x is not 10, it will throw an AssertionError with the message.
        System.out.println("After assertion");
    }
}


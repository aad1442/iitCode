import java.io.*;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


//This Java project is an Online Bookstore Management System.
//        The system supports adding books to the inventory, displaying the book
//        catalog, searching for books, handling customer orders, and performing
//        asynchronous tasks. The project utilizes exception handling, file operations,
//        collections, generics, and threading.
//
//        Key Features:
//
//        Book Class: Represents a book with attributes such as title, author,
//        price, and quantity.
//
//        Inventory Class: Manages a collection of books. It supports adding books,
//        displaying the book catalog, and searching for books.
//
//        Order Class: Represents a customer order with details such as the book
//        title and quantity.
//
//        OrderProcessor Class: Handles customer orders asynchronously using threads.
//
//        Exception Handling: The project uses try-catch blocks to handle exceptions that may occur during file operations and order processing.
//
//        File Operations: The book inventory is loaded from and saved to a file (books.txt). This allows for persistent storage of book data.
//
//        Collections and Generics: The project utilizes the ArrayList class to store books in the inventory. Generics are used in the List declaration to ensure type safety.
//
//        Multithreading: The project includes an OrderProcessor class that simulates asynchronous processing of customer orders using threads.



class Book {
    private String title;
    private String author;
    private double price;
    private int quantity;

    public Book(String title, String author, double price, int quantity) {
        this.title = title;
        this.author = author;
        this.price = price;
        this.quantity = quantity;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    public void reduceQuantity(int amount) {
        if (amount > 0 && amount <= quantity) {
            quantity -= amount;
        }
    }

    @Override
    public String toString() {
        return "Book{title='" + title + "', author='" + author + "', price=" + price + ", quantity=" + quantity + '}';
    }
}

class Inventory {
    private List<Book> books;

    public Inventory() {
        this.books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public void displayCatalog() {
        System.out.println("Book Catalog:");
        books.forEach(System.out::println);
    }

    public Book findBook(String title) {
        return books.stream()
                .filter(book -> book.getTitle().equalsIgnoreCase(title))
                .findFirst()
                .orElse(null);
    }

    // Added method to get the list of books
    public List<Book> getBooks() {
        return Collections.unmodifiableList(books);
    }
}

class Order {
    private String bookTitle;
    private int quantity;

    public Order(String bookTitle, int quantity) {
        this.bookTitle = bookTitle;
        this.quantity = quantity;
    }

    public String getBookTitle() {
        return bookTitle;
    }

    public int getQuantity() {
        return quantity;
    }
}

class OrderProcessor {
    private Inventory inventory;
    private ExecutorService executorService;

    public OrderProcessor(Inventory inventory) {
        this.inventory = inventory;
        this.executorService = Executors.newFixedThreadPool(5);
    }

    public void processOrder(Order order) {
        executorService.submit(() -> {
            try {
                Book book = inventory.findBook(order.getBookTitle());
                if (book != null && book.getQuantity() >= order.getQuantity()) {
                    System.out.println("Processing Order: " + order.getBookTitle() +
                            ", Quantity: " + order.getQuantity() +
                            ", Total Price: " + (book.getPrice() * order.getQuantity()));
                    book.reduceQuantity(order.getQuantity());
                } else {
                    System.out.println("Error: Book not available or insufficient quantity for order: " + order.getBookTitle());
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public void shutdown() {
        executorService.shutdown();
    }
}

public class OnlineBookstoreDemo {
    public static void main(String[] args) {
        try {
            // Create an inventory
            Inventory inventory = new Inventory();

            // Load books from file or add sample books
            loadBooksFromFile(inventory, "books.txt");

            // Display the initial book catalog
            inventory.displayCatalog();

            // Simulate customer orders
            OrderProcessor orderProcessor = new OrderProcessor(inventory);
            orderProcessor.processOrder(new Order("The Great Gatsby", 2));
            orderProcessor.processOrder(new Order("To Kill a Mockingbird", 1));
            orderProcessor.processOrder(new Order("Nonexistent Book", 1));

            // Display the updated book catalog after orders
            inventory.displayCatalog();

            // Save the updated inventory to a file
            saveInventoryToFile(inventory, "books.txt");

            // Shutdown the order processor
            orderProcessor.shutdown();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void loadBooksFromFile(Inventory inventory, String fileName) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 4) {
                    String title = parts[0].trim();
                    String author = parts[1].trim();
                    double price = Double.parseDouble(parts[2].trim());
                    int quantity = Integer.parseInt(parts[3].trim());
                    Book book = new Book(title, author, price, quantity);
                    inventory.addBook(book);
                }
            }
        } catch (FileNotFoundException e) {
            // If the file is not found, add sample books to the inventory
            addSampleBooks(inventory);
        }
    }

    private static void addSampleBooks(Inventory inventory) {
        inventory.addBook(new Book("The Great Gatsby", "F. Scott Fitzgerald", 15.99, 10));
        inventory.addBook(new Book("To Kill a Mockingbird", "Harper Lee", 12.50, 8));
        inventory.addBook(new Book("1984", "George Orwell", 10.75, 15));
        inventory.addBook(new Book("Pride and Prejudice", "Jane Austen", 8.99, 20));
    }

    private static void saveInventoryToFile(Inventory inventory, String fileName) throws IOException {
        try (PrintWriter writer = new PrintWriter(new FileWriter(fileName))) {
            for (Book book : inventory.getBooks()) {
                writer.println(book.getTitle() + "," + book.getAuthor() + "," + book.getPrice() + "," + book.getQuantity());
            }
        }
    }
}

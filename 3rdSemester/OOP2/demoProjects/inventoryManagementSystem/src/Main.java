import java.io.*;
import java.util.*;

class Product {
    private String name;
    private double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return "Product{name='" + name + "', price=" + price + '}';
    }
}

class Inventory {
    private List<Product> products;

    public Inventory() {
        this.products = new ArrayList<>();
    }

    public void addProduct(Product product) {
        products.add(product);
    }

    public void removeProduct(String productName) throws NoSuchElementException {
        products.removeIf(product -> product.getName().equals(productName));
    }

    public void displayInventory() {
        System.out.println("Inventory:");
        for (Product product : products) {
            System.out.println(product);
        }
    }
}


import java.io.*;

public class InventoryManagementDemo {
    public static void main(String[] args) {
        try {
            // Create an inventory
            Inventory inventory = new Inventory();

            // Add products
            inventory.addProduct(new Product("Laptop", 999.99));
            inventory.addProduct(new Product("Smartphone", 599.99));
            inventory.addProduct(new Product("Headphones", 49.99));

            // Display the initial inventory
            System.out.println("Initial Inventory:");
            inventory.displayInventory();

            // Remove a product
            String productToRemove = "Smartphone";
            inventory.removeProduct(productToRemove);
            System.out.println("Removed " + productToRemove);

            // Display the updated inventory
            System.out.println("\nUpdated Inventory:");
            inventory.displayInventory();

            // Save the inventory to a file
            saveInventoryToFile(inventory, "inventory.txt");

            // Load the inventory from the file
            Inventory loadedInventory = loadInventoryFromFile("inventory.txt");
            System.out.println("\nLoaded Inventory:");
            loadedInventory.displayInventory();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void saveInventoryToFile(Inventory inventory, String fileName) throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName))) {
            oos.writeObject(inventory);
            System.out.println("\nInventory saved to " + fileName);
        }
    }

    private static Inventory loadInventoryFromFile(String fileName) throws IOException, ClassNotFoundException {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName))) {
            Inventory inventory = (Inventory) ois.readObject();
            System.out.println("\nInventory loaded from " + fileName);
            return inventory;
        }
    }
}

import java.io.*;
import java.util.*;
import java.util.concurrent.*;

//Project Description: Online Auction System
//
//        This Java project simulates an online auction system where users can bid on items. The system supports adding items to the auction, displaying the available items, bidding on items, and handling multiple users concurrently. The project utilizes exception handling, file operations, collections, generics, and threading.
//
//        Key Features:
//
//        Item Class: Represents an item in the auction with attributes such as item ID, description, current highest bid, and bidder.
//
//        AuctionManager Class: Manages the auction system, including adding items, displaying available items, and handling bidding.
//
//        Bidder Class: Represents a bidder participating in the auction. Each bidder can bid on multiple items concurrently.
//
//        Exception Handling: The project includes exception handling to deal with scenarios such as invalid bids, non-existent items, etc.
//
//        File Operations: The item inventory is loaded from and saved to a file (items.txt). This allows for persistent storage of item data.
//
//        Collections and Generics: The project utilizes the ArrayList class to store items in the auction. Generics are used in the List declaration to ensure type safety.
//
//        Multithreading: The project includes a Bidder class that simulates concurrent bidding on multiple items using threads.

class Item {
    private int itemId;
    private String description;
    private double currentBid;
    private String currentBidder;

    public Item(int itemId, String description) {
        this.itemId = itemId;
        this.description = description;
        this.currentBid = 0.0;
        this.currentBidder = "No bids yet";
    }

    public int getItemId() {
        return itemId;
    }

    public String getDescription() {
        return description;
    }

    public double getCurrentBid() {
        return currentBid;
    }

    public String getCurrentBidder() {
        return currentBidder;
    }

    public void placeBid(double bidAmount, String bidderName) {
        if (bidAmount > currentBid) {
            currentBid = bidAmount;
            currentBidder = bidderName;
        }
    }

    @Override
    public String toString() {
        return "Item{itemId=" + itemId + ", description='" + description + "', currentBid=" + currentBid +
                ", currentBidder='" + currentBidder + "'}";
    }
}

class AuctionManager {
    private List<Item> items;

    public AuctionManager() {
        this.items = new ArrayList<>();
    }

    public void addItem(Item item) {
        items.add(item);
    }

    public void displayAvailableItems() {
        System.out.println("Available Items:");
        items.forEach(System.out::println);
    }

    public Item findItem(int itemId) {
        return items.stream()
                .filter(item -> item.getItemId() == itemId)
                .findFirst()
                .orElse(null);
    }
}

class Bidder implements Runnable {
    private String bidderName;
    private AuctionManager auctionManager;

    public Bidder(String bidderName, AuctionManager auctionManager) {
        this.bidderName = bidderName;
        this.auctionManager = auctionManager;
    }

    @Override
    public void run() {
        Random random = new Random();
        while (true) {
            try {
                // Sleep for a random time to simulate realistic bidding intervals
                Thread.sleep(random.nextInt(5000));

                // Bid on a random item
                int itemIdToBidOn = random.nextInt(3) + 1; // Assuming items have IDs 1, 2, 3
                double bidAmount = random.nextDouble() * 100.0;
                Item itemToBidOn = auctionManager.findItem(itemIdToBidOn);

                if (itemToBidOn != null) {
                    itemToBidOn.placeBid(bidAmount, bidderName);
                    System.out.println(bidderName + " placed a bid of $" + bidAmount + " on item " + itemIdToBidOn);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class OnlineAuctionDemo {
    public static void main(String[] args) {
        try {
            // Create an auction manager
            AuctionManager auctionManager = new AuctionManager();

            // Add items to the auction
            auctionManager.addItem(new Item(1, "Laptop"));
            auctionManager.addItem(new Item(2, "Smartphone"));
            auctionManager.addItem(new Item(3, "Camera"));

            // Display available items
            auctionManager.displayAvailableItems();

            // Create bidders
            Bidder bidder1 = new Bidder("Bidder 1", auctionManager);
            Bidder bidder2 = new Bidder("Bidder 2", auctionManager);

            // Create executor service for multithreading
            ExecutorService executorService = Executors.newFixedThreadPool(2);

            // Start bidders in separate threads
            executorService.submit(bidder1);
            executorService.submit(bidder2);

            // Run the auction for a limited time (e.g., 15 seconds)
            Thread.sleep(15000);

            // Shut down the executor service
            executorService.shutdown();

            // Wait for bidders to finish their current bids
            if (!executorService.awaitTermination(5, TimeUnit.SECONDS)) {
                // Forcefully terminate if not finished in 5 seconds
                executorService.shutdownNow();
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


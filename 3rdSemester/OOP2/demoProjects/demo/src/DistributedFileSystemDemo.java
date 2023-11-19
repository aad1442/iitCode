import java.io.*;
import java.util.*;
import java.util.concurrent.*;

class FileMetadata {
    private String filename;
    private long size;
    private String owner;

    public FileMetadata(String filename, long size, String owner) {
        this.filename = filename;
        this.size = size;
        this.owner = owner;
    }

    public String getFilename() {
        return filename;
    }

    public long getSize() {
        return size;
    }

    public String getOwner() {
        return owner;
    }

    @Override
    public String toString() {
        return "FileMetadata{filename='" + filename + "', size=" + size + ", owner='" + owner + "'}";
    }
}

class FileSystem {
    private Map<String, FileMetadata> fileMetadataMap;

    public FileSystem() {
        this.fileMetadataMap = new HashMap<>();
    }

    public void uploadFile(FileMetadata fileMetadata) {
        fileMetadataMap.put(fileMetadata.getFilename(), fileMetadata);
    }

    public FileMetadata downloadFile(String filename) {
        return fileMetadataMap.get(filename);
    }

    public void deleteFile(String filename) {
        fileMetadataMap.remove(filename);
    }

    public List<String> listFiles() {
        System.out.println("Available Files:");
        fileMetadataMap.values().forEach(System.out::println);
        return null;
    }

    // Additional method for saving file metadata to a file
    public void saveToFile(String fileName) throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName))) {
            oos.writeObject(fileMetadataMap);
            System.out.println("File metadata saved to " + fileName);
        }
    }

    // Additional method for loading file metadata from a file
    @SuppressWarnings("unchecked")
    public void loadFromFile(String fileName) throws IOException, ClassNotFoundException {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName))) {
            fileMetadataMap = (Map<String, FileMetadata>) ois.readObject();
            System.out.println("File metadata loaded from " + fileName);
        }
    }

    public void uploadFile(String fileName, String fileContent) {
    }
}

class FileManager {
    private FileSystem fileSystem;
    private ExecutorService executorService;

    public FileManager(FileSystem fileSystem) {
        this.fileSystem = fileSystem;
        this.executorService = Executors.newFixedThreadPool(5);
    }

    public void uploadFile(FileMetadata fileMetadata) {
        executorService.submit(() -> {
            try {
                fileSystem.uploadFile(fileMetadata);
                System.out.println("File uploaded: " + fileMetadata.getFilename());
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public void downloadFile(String filename) {
        executorService.submit(() -> {
            try {
                FileMetadata fileMetadata = fileSystem.downloadFile(filename);
                if (fileMetadata != null) {
                    System.out.println("File downloaded: " + fileMetadata);
                } else {
                    System.out.println("Error: File not found - " + filename);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public void deleteFile(String filename) {
        executorService.submit(() -> {
            try {
                fileSystem.deleteFile(filename);
                System.out.println("File deleted: " + filename);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }
    public void listFiles() {
        executorService.submit(() -> {
            try {
                fileSystem.listFiles();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public void shutdown() {
        executorService.shutdown();
    }
}

public class DistributedFileSystemDemo {
    public static void main(String[] args) {
        try {
            // Create a file system
            FileSystem fileSystem = new FileSystem();

            // Load file metadata from file or start with an empty file system
            fileSystem.loadFromFile("file_metadata.txt");

            // Simulate file operations
            FileManager fileManager = new FileManager(fileSystem);
            fileManager.uploadFile(new FileMetadata("file1.txt", 1024, "user1"));
            fileManager.uploadFile(new FileMetadata("file2.txt", 2048, "user2"));
            fileManager.uploadFile(new FileMetadata("file3.txt", 3072, "user1"));
            fileManager.uploadFile(new FileMetadata("file4.txt", 4096, "user3"));

            fileManager.listFiles();
            fileManager.downloadFile("file2.txt");
            fileManager.deleteFile("file3.txt");

            fileManager.listFiles();

            // Save file metadata to a file
            fileSystem.saveToFile("file_metadata.txt");

            // Shutdown the file manager
            fileManager.shutdown();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

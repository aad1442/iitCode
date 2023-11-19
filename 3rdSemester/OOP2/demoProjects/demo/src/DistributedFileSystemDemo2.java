import java.util.*;
import java.util.concurrent.*;
import java.io.*;

//Project Description: Distributed File System
//
//        This project simulates a distributed file system with multiple clients interacting with a central server. Each client can perform operations like uploading files, downloading files, listing files, and deleting files. The server manages the file system and handles requests from multiple clients concurrently.
//
//        Key Features:
//
//        Client Class: Represents a client in the distributed file system. Each client can perform operations such as uploading, downloading, listing, and deleting files.
//
//        Server Class: Manages the distributed file system, handling requests from multiple clients concurrently using multithreading.
//
//        FileSystem Class: Represents the file system and manages the storage of files. It provides methods for uploading, downloading, listing, and deleting files.
//
//        FileData Class: Represents the data structure for storing file information, including file name, content, and metadata.
//
//        Exception Handling: The project includes exception handling to deal with error scenarios, such as file not found, permission issues, etc.
//
//        File I/O: File I/O operations are used for storing and retrieving files on the server.
//
//        Collections and Generics: Collections and generics are used for managing the file system's data structures, such as storing a collection of files.
//
//        Multithreading: The server handles multiple client requests concurrently using multithreading.

class FileData {
    private String fileName;
    private String content;

    public FileData(String fileName, String content) {
        this.fileName = fileName;
        this.content = content;
    }

    public String getFileName() {
        return fileName;
    }

    public String getContent() {
        return content;
    }
}

class FileSystem2 {
    private Map<String, FileData> files;

    public FileSystem2() {
        this.files = new ConcurrentHashMap<>();
    }

    public void uploadFile(String fileName, String content) {
        files.put(fileName, new FileData(fileName, content));
    }

    public String downloadFile(String fileName) {
        FileData fileData = files.get(fileName);
        return (fileData != null) ? fileData.getContent() : null;
    }

    public List<String> listFiles() {
        return new ArrayList<>(files.keySet());
    }

    public void deleteFile(String fileName) {
        files.remove(fileName);
    }
}

class Server {
    private FileSystem fileSystem2;
    private ExecutorService executorService;

    public Server() {
        this.fileSystem2 = new FileSystem();
        this.executorService = Executors.newCachedThreadPool();
    }

    public void processClientRequest(ClientRequest clientRequest) {
        executorService.submit(() -> {
            try {
                switch (clientRequest.getRequestType()) {
                    case UPLOAD:
                        fileSystem2.uploadFile(clientRequest.getFileName(), clientRequest.getFileContent());
                        break;
                    case DOWNLOAD:
                        String content = String.valueOf(fileSystem2.downloadFile(clientRequest.getFileName()));
                        clientRequest.setFileContent(content);
                        break;
                    case LIST:
                        List<String> fileList = fileSystem2.listFiles();
                        clientRequest.setFileList(fileList);
                        break;
                    case DELETE:
                        fileSystem2.deleteFile(clientRequest.getFileName());
                        break;
                }
            } catch (Exception e) {
                clientRequest.setError(true);
                clientRequest.setErrorMessage(e.getMessage());
            }
        });
    }

    public List<String> listFiles() {
        return fileSystem2.listFiles();
    }

    public void shutdown() {
        executorService.shutdown();
    }
}


enum RequestType {
    UPLOAD,
    DOWNLOAD,
    LIST,
    DELETE
}

class ClientRequest {
    private RequestType requestType;
    private String fileName;
    private String fileContent;
    private List<String> fileList;
    private boolean error;
    private String errorMessage;

    public ClientRequest(RequestType requestType, String fileName, String fileContent) {
        this.requestType = requestType;
        this.fileName = fileName;
        this.fileContent = fileContent;
    }

    public RequestType getRequestType() {
        return requestType;
    }

    public String getFileName() {
        return fileName;
    }

    public String getFileContent() {
        return fileContent;
    }

    public void setFileContent(String fileContent) {
        this.fileContent = fileContent;
    }

    public List<String> getFileList() {
        return fileList;
    }

    public void setFileList(List<String> fileList) {
        this.fileList = fileList;
    }

    public boolean isError() {
        return error;
    }

    public void setError(boolean error) {
        this.error = error;
    }

    public String getErrorMessage() {
        return errorMessage;
    }

    public void setErrorMessage(String errorMessage) {
        this.errorMessage = errorMessage;
    }
}

class Client {
    private String clientId;
    private Server server;

    public Client(String clientId, Server server) {
        this.clientId = clientId;
        this.server = server;
    }

    public void uploadFile(String fileName, String content) {
        ClientRequest clientRequest = new ClientRequest(RequestType.UPLOAD, fileName, content);
        server.processClientRequest(clientRequest);
        waitForResponse(clientRequest);
    }

    public String downloadFile(String fileName) {
        ClientRequest clientRequest = new ClientRequest(RequestType.DOWNLOAD, fileName, null);
        server.processClientRequest(clientRequest);
        waitForResponse(clientRequest);
        return clientRequest.getFileContent();
    }

    public List<String> listFiles() {
        ClientRequest clientRequest = new ClientRequest(RequestType.LIST, null, null);
        server.processClientRequest(clientRequest);
        waitForResponse(clientRequest);
        return clientRequest.getFileList();
    }

    public void deleteFile(String fileName) {
        ClientRequest clientRequest = new ClientRequest(RequestType.DELETE, fileName, null);
        server.processClientRequest(clientRequest);
        waitForResponse(clientRequest);
    }

    private void waitForResponse(ClientRequest clientRequest) {
        while (!clientRequest.isError() && (clientRequest.getFileContent() == null && clientRequest.getFileList() == null)) {
            try {
                Thread.sleep(100); // Wait for response
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        if (clientRequest.isError()) {
            System.out.println("Client " + clientId + " Error: " + clientRequest.getErrorMessage());
        } else {
            System.out.println("Client " + clientId + " Response: " + clientRequest.getFileContent());
        }
    }
}

public class DistributedFileSystemDemo2 {
    public static void main(String[] args) {
        try {
            // Create a server
            Server server = new Server();

            // Create clients
            Client client1 = new Client("1", server);
            Client client2 = new Client("2", server);

            // Upload files
            client1.uploadFile("file1.txt", "Content for file 1");
            client2.uploadFile("file2.txt", "Content for file 2");

            // List files
            System.out.println("Files on the server: " + server.listFiles());

            // Download files
            String content1 = client1.downloadFile("file1.txt");
            String content2 = client2.downloadFile("file2.txt");

            // Print downloaded content
            System.out.println("Content of file1.txt: " + content1);
            System.out.println("Content of file2.txt: " + content2);

            // Delete files
            client1.deleteFile("file1.txt");
            client2.deleteFile("file2.txt");

            // List files after deletion
            System.out.println("Files on the server after deletion: " + server.listFiles());

            // Shutdown the server
            server.shutdown();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;


class Task implements Serializable {
    private String description;
    private int priority;

    public Task(String description, int priority) {
        this.description = description;
        this.priority = priority;
    }

    public String getDescription() {
        return description;
    }

    public int getPriority() {
        return priority;
    }

    @Override
    public String toString() {
        return "Task{description='" + description + "', priority=" + priority + '}';
    }

    // Additional method for converting a Task to a CSV-formatted string
    public String toCsvString() {
        return description + "," + priority;
    }

    // Additional static method for creating a Task from a CSV-formatted string
    public static Task fromCsvString(String csvString) {
        String[] parts = csvString.split(",");
        String description = parts[0];
        int priority = Integer.parseInt(parts[1]);
        return new Task(description, priority);
    }
}

class TaskManager implements Serializable {
    private List<Task> tasks;

    public TaskManager() {
        this.tasks = new ArrayList<>();
    }

    public void addTask(Task task) {
        tasks.add(task);
    }

    public void removeTask(String taskDescription) throws NoSuchElementException {
        tasks.removeIf(task -> task.getDescription().equals(taskDescription));
    }

    public void displayTasksByPriority() {
        System.out.println("Tasks by Priority:");
        tasks.stream()
                .sorted(Comparator.comparingInt(Task::getPriority))
                .forEach(System.out::println);
    }

    public List<Task> getTasks() {
        return tasks;
    }

    // Additional method for converting the TaskManager to a CSV-formatted string
    public String toCsvString() {
        return tasks.stream()
                .map(Task::toCsvString)
                .collect(Collectors.joining("\n"));
    }

    // Additional static method for creating a TaskManager from a CSV-formatted string
    public static TaskManager fromCsvString(String csvString) {
        TaskManager taskManager = new TaskManager();
        Arrays.stream(csvString.split("\n"))
                .map(Task::fromCsvString)
                .forEach(taskManager::addTask);
        return taskManager;
    }
}

public class TaskManagementDemo {
    public static void main(String[] args) {
        try {
            // Create a task manager
            TaskManager taskManager = new TaskManager();

            // Add tasks
            taskManager.addTask(new Task("Complete project", 2));
            taskManager.addTask(new Task("Review code", 1));
            taskManager.addTask(new Task("Prepare presentation", 3));

            // Display tasks by priority
            System.out.println("Tasks by Priority:");
            taskManager.displayTasksByPriority();

            // Remove a task
            String taskToRemove = "Review code";
            taskManager.removeTask(taskToRemove);
            System.out.println("\nRemoved task: " + taskToRemove);

            // Display updated tasks by priority
            System.out.println("\nUpdated Tasks by Priority:");
            taskManager.displayTasksByPriority();

            // Save tasks to a file in CSV format
            saveTasksToCsvFile(taskManager, "tasks.csv");

            // Read and display the contents of the saved tasks file
            System.out.println("\nContents of the saved tasks file:");
            readTasksCsvFile("tasks.csv");

            // Load tasks from the file in CSV format
            TaskManager loadedTaskManager = loadTasksFromCsvFile("tasks.csv");
            System.out.println("\nLoaded Tasks by Priority:");
            loadedTaskManager.displayTasksByPriority();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void saveTasksToCsvFile(TaskManager taskManager, String fileName) throws IOException {
        try (PrintWriter writer = new PrintWriter(new FileWriter(fileName))) {
            writer.println(taskManager.toCsvString());
            System.out.println("\nTasks saved to " + fileName);
        }
    }

    private static void readTasksCsvFile(String fileName) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        }
    }

    private static TaskManager loadTasksFromCsvFile(String fileName) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            StringBuilder csvContent = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                csvContent.append(line).append("\n");
            }
            return TaskManager.fromCsvString(csvContent.toString());
        }
    }
}

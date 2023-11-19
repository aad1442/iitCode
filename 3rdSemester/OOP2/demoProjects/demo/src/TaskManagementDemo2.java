import java.io.*;
import java.util.*;

//This Java project is a Task Management System that allows users to create tasks,
//        assign priorities, and display tasks based on priority. The system supports a
//        dding tasks, removing tasks, and displaying the current task list. Additionally,
//        the project incorporates exception handling, file operations, collections, generics,
//        and provides a foundation for potential multithreading scenarios.

class Task2 implements Serializable {
    private String description;
    private int priority;

    public Task2(String description, int priority) {
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
}

class TaskManager2 implements Serializable {
    private List<Task> tasks;

    public TaskManager2() {
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
}

public class TaskManagementDemo2 {
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

            // Save tasks to a file
            saveTasksToFile(taskManager, "tasks.txt");

            // Read and display the contents of the saved tasks file
            System.out.println("\nContents of the saved tasks file:");
            readTasksFile("tasks.txt");

            // Load tasks from the file
            TaskManager loadedTaskManager = loadTasksFromFile("tasks.txt");
            System.out.println("\nLoaded Tasks by Priority:");
            loadedTaskManager.displayTasksByPriority();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void saveTasksToFile(TaskManager taskManager, String fileName) throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName))) {
            oos.writeObject(taskManager);
            System.out.println("\nTasks saved to " + fileName);
        }
    }

    private static void readTasksFile(String fileName) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        }
    }

    private static TaskManager loadTasksFromFile(String fileName) throws IOException, ClassNotFoundException {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName))) {
            TaskManager taskManager = (TaskManager) ois.readObject();
            System.out.println("\nTasks loaded from " + fileName);
            return taskManager;
        }
    }
}

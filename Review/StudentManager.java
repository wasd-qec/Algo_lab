package Review;

import java.util.ArrayList;
import java.util.Scanner;

class Student {
    private String id;
    private String name;
    private int age;

    public Student(String id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}

public class StudentManager {
    public static void main(String[] args) {
        ArrayList<Student> studentList = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        // Prepopulate with a couple of students
        studentList.add(new Student("e20110015", "Bob", 20));
        studentList.add(new Student("e20110016", "Alice", 21));

        while (true) {
            System.out.println("\n=== Student Management System ===");
            System.out.println("1. Add Student");
            System.out.println("2. View All Students");
            System.out.println("3. Edit Student");
            System.out.println("4. Delete Student");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");

            int choice = -1;
            if (scanner.hasNextInt()) {
                choice = scanner.nextInt();
                scanner.nextLine(); // Consume newline
            } else {
                scanner.nextLine(); // Consume invalid input
                System.out.println("Invalid choice. Please enter a number.");
                continue;
            }

            if (choice == 1) {
                System.out.print("Enter Student ID: ");
                String id = scanner.nextLine();
                System.out.print("Enter Student Name: ");
                String name = scanner.nextLine();
                System.out.print("Enter Student Age: ");
                int age = -1;
                if (scanner.hasNextInt()) {
                    age = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                } else {
                    scanner.nextLine(); // Consume invalid input
                    System.out.println("Invalid age. Student addition failed.");
                    continue;
                }

                studentList.add(new Student(id, name, age));
                System.out.println("Student added successfully!");
            } 
            else if (choice == 2) {
                if (studentList.isEmpty()) {
                    System.out.println("No students found.");
                } else {
                    System.out.println("\n--- Student List ---");
                    for (Student s : studentList) {
                        System.out.println("ID: " + s.getId() + " | Name: " + s.getName() + " | Age: " + s.getAge());
                    }
                }
            } 
            else if (choice == 3) {
                System.out.print("Enter Student ID to edit: ");
                String id = scanner.nextLine();
                Student foundStudent = null;
                for (Student s : studentList) {
                    if (s.getId().equals(id)) {
                        foundStudent = s;
                        break;
                    }
                }

                if (foundStudent != null) {
                    System.out.print("Enter New Name (current: " + foundStudent.getName() + "): ");
                    String newName = scanner.nextLine();
                    System.out.print("Enter New Age (current: " + foundStudent.getAge() + "): ");
                    int newAge = -1;
                    if (scanner.hasNextInt()) {
                        newAge = scanner.nextInt();
                        scanner.nextLine(); // Consume newline
                    } else {
                        scanner.nextLine(); // Consume invalid input
                        System.out.println("Invalid age. Editing failed.");
                        continue;
                    }

                    foundStudent.setName(newName);
                    foundStudent.setAge(newAge);
                    System.out.println("Student details updated successfully!");
                } else {
                    System.out.println("Student with ID " + id + " not found.");
                }
            }
            else if (choice == 4) {
                System.out.print("Enter Student ID to delete: ");
                String id = scanner.nextLine();
                Student toDelete = null;
                for (Student s : studentList) {
                    if (s.getId().equals(id)) {
                        toDelete = s;
                        break;
                    }
                }

                if (toDelete != null) {
                    studentList.remove(toDelete);
                    System.out.println("Student deleted successfully!");
                } else {
                    System.out.println("Student with ID " + id + " not found.");
                }
            }
            else if (choice == 5) {
                System.out.println("Exiting Student Management System. Goodbye!");
                break;
            } 
            else {
                System.out.println("Invalid option. Please try again.");
            }
        }
        scanner.close();
    }
}

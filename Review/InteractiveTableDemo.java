package Review;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

// Reuse the Student class structure from StudentManager.java
class TableStudent {
    private String id;
    private String name;
    private int age;

    public TableStudent(String id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public String getId() { return id; }
    public String getName() { return name; }
    public int getAge() { return age; }
}

public class InteractiveTableDemo {
    public static void main(String[] args) {
        // 1. Initialize local ArrayList of Students
        ArrayList<TableStudent> studentList = new ArrayList<>();
        studentList.add(new TableStudent("e20110015", "Bob", 20));
        studentList.add(new TableStudent("e20110016", "Alice", 21));

        // 2. Set up the JFrame
        JFrame frame = new JFrame("Student Table Manager");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 400);
        frame.setLayout(new BorderLayout());

        // 3. Set up the JTable with DefaultTableModel
        String[] columns = { "ID", "Name", "Age" };
        DefaultTableModel model = new DefaultTableModel(columns, 0);
        JTable table = new JTable(model);

        // Populate table initially
        for (TableStudent s : studentList) {
            model.addRow(new Object[]{ s.getId(), s.getName(), s.getAge() });
        }

        // Add table to JScrollPane
        JScrollPane scrollPane = new JScrollPane(table);
        frame.add(scrollPane, BorderLayout.CENTER);

        // 4. Create an input panel for adding new students
        JPanel inputPanel = new JPanel(new GridLayout(2, 4, 5, 5));
        JTextField idField = new JTextField();
        JTextField nameField = new JTextField();
        JTextField ageField = new JTextField();

        inputPanel.add(new JLabel(" ID:"));
        inputPanel.add(idField);
        inputPanel.add(new JLabel(" Name:"));
        inputPanel.add(nameField);
        inputPanel.add(new JLabel(" Age:"));
        inputPanel.add(ageField);

        // Buttons
        JButton addButton = new JButton("Add Student");
        JButton removeButton = new JButton("Remove Selected");
        inputPanel.add(addButton);
        inputPanel.add(removeButton);

        frame.add(inputPanel, BorderLayout.SOUTH);

        // 5. Add functionality to "Add" button
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String id = idField.getText().trim();
                String name = nameField.getText().trim();
                String ageText = ageField.getText().trim();

                if (id.isEmpty() || name.isEmpty() || ageText.isEmpty()) {
                    JOptionPane.showMessageDialog(frame, "Please fill in all fields.");
                    return;
                }

                try {
                    int age = Integer.parseInt(ageText);
                    
                    // Create and add Student to the ArrayList
                    TableStudent newStudent = new TableStudent(id, name, age);
                    studentList.add(newStudent);

                    // Add row to the Table Model
                    model.addRow(new Object[]{ newStudent.getId(), newStudent.getName(), newStudent.getAge() });

                    // Clear fields
                    idField.setText("");
                    nameField.setText("");
                    ageField.setText("");
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Age must be a valid number.");
                }
            }
        });

        // 6. Add functionality to "Remove" button
        removeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedRow = table.getSelectedRow();
                if (selectedRow == -1) {
                    JOptionPane.showMessageDialog(frame, "Please select a row to delete.");
                    return;
                }

                // Remove from ArrayList
                studentList.remove(selectedRow);

                // Remove from Table Model
                model.removeRow(selectedRow);
            }
        });

        frame.setVisible(true);
    }
}

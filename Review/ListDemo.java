package Review;

import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JList;

public class ListDemo {
    public static void main(String[] args) {
        JFrame f = new JFrame("List Demo");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create a model to hold items for the list
        DefaultListModel<String> l1 = new DefaultListModel<>();
        l1.addElement("Item1");
        l1.addElement("Item2");
        l1.addElement("Item3");
        l1.addElement("Item4");

        // Create the JList with the model
        JList<String> list = new JList<>(l1);
        list.setBounds(100, 100, 75, 75);

        f.add(list);
        f.setSize(400, 400);
        
        // Null layout allows manual absolute positioning using setBounds()
        f.setLayout(null);
        
        f.setVisible(true);
    }
}

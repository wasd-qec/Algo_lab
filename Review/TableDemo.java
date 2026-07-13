package Review;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class TableDemo {
    public static void main(String[] args) {
        JFrame f = new JFrame("Table Demo");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        String[][] data = {
            { "101", "Amit", "670000" },
            { "102", "Jai", "780000" },
            { "101", "Amit", "670000" },
            { "101", "Sachin", "700000" }
        };

        String[] column = { "ID", "NAME", "SALARY" };

        JTable jt = new JTable(data, column);
        
        // JScrollPane is required to display the column headers and add scrolling
        JScrollPane sp = new JScrollPane(jt);
        f.add(sp);

        f.setSize(300, 400);
        f.setVisible(true);
    }
}

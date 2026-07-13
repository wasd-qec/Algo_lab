package Review;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class DialogDemo {
    public static void main(String[] args) {
        JFrame f = new JFrame("Dialog Demo Frame");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton b = new JButton("Open Dialog");
        b.setActionCommand("click");
        b.setBounds(5, 5, 200, 40);
        f.add(b);

        // JDialog is a sub-window associated with the parent JFrame 'f'
        JDialog d = new JDialog(f, "Dialog Box");
        JLabel l = new JLabel("this is a dialog box", JLabel.CENTER);
        d.add(l);
        d.setSize(200, 150);
        d.setLocationRelativeTo(f); // Center dialog on top of the parent window

        // Set action listener using dynamic lambda
        b.addActionListener(e -> {
            if ("click".equals(e.getActionCommand())) {
                d.setVisible(true);
            }
        });

        f.setSize(400, 400);
        f.setLayout(null);
        f.setVisible(true);
    }
}

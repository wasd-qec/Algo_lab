package Review;

import java.awt.GridLayout;
import javax.swing.*;

public class hmm {
    public static void main(String[] args) {
        JFrame frame = new JFrame("My first Gui");
        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(4, 1));

        JLabel text = new JLabel("Meow");
        JTextField textfield = new JTextField("Type here");
        JButton button1 = new JButton("Button1");

        JPanel panel = new JPanel();

        panel.setLayout(new GridLayout(1, 2));
        JLabel textpanel = new JLabel("Meow");
        JTextField textfieldpanel = new JTextField("Type here");

        panel.add(textpanel);
        panel.add(textfieldpanel);

        button1.addActionListener(e -> {
            String input = textfield.getText();
            text.setText(input + " thankyou");
        });

        frame.add(textfield);
        frame.add(button1);
        frame.add(panel);
        frame.add(text);
        frame.setVisible(true);
    }
}
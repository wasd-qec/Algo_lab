package Review;

import java.awt.CardLayout;
import java.awt.BorderLayout;
import javax.swing.*;

public class SwitchPanelDemo {
    public static void main(String[] args) {
        JFrame frame = new JFrame("CardLayout Panel Switcher");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 1. Parent panel holding the CardLayout
        CardLayout cardLayout = new CardLayout();
        JPanel parentPanel = new JPanel(cardLayout);

        // 2. Panel A Setup
        JPanel panelA = new JPanel();
        panelA.setLayout(new BoxLayout(panelA, BoxLayout.Y_AXIS));
        JLabel labelA = new JLabel("Welcome to Screen A!");
        JButton buttonToB = new JButton("Go to Screen B");
        panelA.add(labelA);
        panelA.add(buttonToB);

        // 3. Panel B Setup
        JPanel panelB = new JPanel();
        panelB.setLayout(new BoxLayout(panelB, BoxLayout.Y_AXIS));
        JLabel labelB = new JLabel("You are now on Screen B!");
        JButton buttonToA = new JButton("Go back to Screen A");
        panelB.add(labelB);
        panelB.add(buttonToA);

        // 4. Add the cards to the parent panel
        parentPanel.add(panelA, "ScreenA");
        parentPanel.add(panelB, "ScreenB");

        // 5. Button action listeners to switch panels
        buttonToB.addActionListener(e -> cardLayout.show(parentPanel, "ScreenB"));
        buttonToA.addActionListener(e -> cardLayout.show(parentPanel, "ScreenA"));

        frame.add(parentPanel);
        frame.setVisible(true);
    }
}

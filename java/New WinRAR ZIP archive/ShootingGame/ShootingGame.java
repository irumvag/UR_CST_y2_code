import javax.swing.*;
import java.awt.*;

public class ShootingGame extends JFrame {
    private GamePanel gamePanel;
    private JButton shootButton;

    public ShootingGame() {
        setTitle("Shooting Game");
        setSize(500, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setLayout(new BorderLayout());

        // Game area
        gamePanel = new GamePanel();
        add(gamePanel, BorderLayout.CENTER);

        // Shoot button
        shootButton = new JButton("Shoot");
        shootButton.addActionListener(e -> gamePanel.shootBullet());
        add(shootButton, BorderLayout.SOUTH);

        setVisible(true);
    }

    public static void main(String[] args) {
        new ShootingGame();
    }
}

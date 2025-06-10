import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class GamePanel extends JPanel {
    private int rocketX, rocketY;
    private final int rocketWidth = 130, rocketHeight = 60;
    private ArrayList<Bullet> bullets;
    private int score;  // To track the score
    private Image rocketImage;
    private Image bulletImage;  // To hold the bullet image

    public GamePanel() {
        rocketX = 0; // Start at the left edge of the screen
        rocketY = 50; // Near the top
        bullets = new ArrayList<>();
        score = 0; // Initialize score

        // Load rocket image
        rocketImage = new ImageIcon(getClass().getResource("plane.png")).getImage();
        // Load bullet image (plane1.png)
        bulletImage = new ImageIcon(getClass().getResource("plane1.png")).getImage();

        // Start the rocket movement thread
        Thread rocketThread = new Thread(this::moveRocket);
        rocketThread.start();

        // Start the bullet movement thread
        Thread bulletThread = new Thread(this::moveBullets);
        bulletThread.start();
    }

    private void moveRocket() {
        while (true) {
            rocketX += 5; // Move right

            if (rocketX + rocketWidth >= getWidth()) {
                rocketX = 0; // Reset position to the left side
            }

            repaint(); // Repaint after each move
            try {
                Thread.sleep(30); // Rocket update rate
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void shootBullet() {
        bullets.add(new Bullet(getWidth() / 2, getHeight() - 50)); // Add bullet to list
        SoundPlayer.playSound("shoot.wav");  // Placeholder sound
    }

    private void moveBullets() {
        while (true) {
            for (Bullet bullet : bullets) {
                bullet.move();  // Move each bullet
                if (bullet.y < 0) {
                    bullets.remove(bullet); // Remove bullets that are off-screen
                    break;
                }

                // Check for collision with rocket
                if (bullet.x >= rocketX && bullet.x <= rocketX + rocketWidth && bullet.y <= rocketY + rocketHeight) {
                    // Collision detected
                    SoundPlayer.playSound("collision.wav");  // Collision sound
                    bullets.remove(bullet); // Remove bullet after collision
                    score++; // Increment score on hit
                    break;
                }
            }
            repaint();  // Repaint after each bullet move
            try {
                Thread.sleep(30); // Bullet update rate
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        setBackground(Color.BLACK);

        // Draw the rocket image
        if (rocketImage != null) {
            g.drawImage(rocketImage, rocketX, rocketY, rocketWidth, rocketHeight, this);
        } else {
            g.setColor(Color.RED);
            g.fillRect(rocketX, rocketY, rocketWidth, rocketHeight);
        }

        // Draw bullets as plane images
        for (Bullet bullet : bullets) {
            g.drawImage(bulletImage, bullet.x, bullet.y, 30, 50, this);  // Draw the bullet using the plane1 image
        }

        // Draw score
        g.setColor(Color.WHITE);
        g.setFont(new Font("Arial", Font.BOLD, 24));
        g.drawString("Score: " + score, 10, 30); // Display score at the top-left corner
    }
}

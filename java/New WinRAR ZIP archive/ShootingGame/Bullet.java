public class Bullet {
    int x, y;
    private final int speed = 10;

    public Bullet(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public boolean move() {
        y -= speed; // Move up
        return y < 0; // Remove when out of bounds
    }
}

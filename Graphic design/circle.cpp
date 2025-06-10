#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int CELL_SIZE = 20; // Grid cell size

class MidpointCircle {
private:
    int centerX, centerY, radius;
    sf::RenderWindow& window;
    sf::Vector2f offset;
    float zoom;

public:
    MidpointCircle(sf::RenderWindow& win, int x, int y, int r, float zm, sf::Vector2f off)
        : window(win), centerX(x), centerY(y), radius(r), zoom(zm), offset(off) {}

    void drawCircle() {
        int x = 0;
        int y = radius;
        int p = 1 - radius;

        drawCirclePoints(x, y); // Draw the initial points

        while (x < y) {
            x++;
            if (p < 0)
                p += 2 * x + 1;
            else {
                y--;
                p += 2 * (x - y) + 1;
            }
            cout<< "x: " << x << ", y: " << y << ", p: " << p << endl; // Debug output
            drawCirclePoints(x, y); // Draw the points at each step
        }
    }

    void drawActualCircle() {
        // Draw the actual circle in red
        sf::CircleShape actualCircle(radius * zoom);
        actualCircle.setPosition(centerX * zoom + offset.x - radius * zoom, 
                                 centerY * zoom + offset.y - radius * zoom);
        actualCircle.setOutlineColor(sf::Color::Blue); // Actual circle in red
        actualCircle.setOutlineThickness(2);
        actualCircle.setFillColor(sf::Color::Transparent);
        window.draw(actualCircle);
    }

private:
    void drawPixel(int x, int y) {
        // Draw the algorithm points as small dots (white color)
        sf::CircleShape dot(zoom / 3); // Small dot instead of rectangle
        dot.setFillColor(sf::Color::White);
        dot.setOrigin(zoom / 3, zoom / 3);
        dot.setPosition(x * zoom + offset.x, -y * zoom + offset.y); // Invert Y axis
        window.draw(dot);
    }

    void drawCirclePoints(int x, int y) {
        // Draw the algorithm points (small dots) for all octants
        // cout<< "Drawing points: (" << centerX + x << ", " << centerY + y << ")" << endl; // Debug output
        // cout<< "Drawing points: (" << centerX - x << ", " << centerY + y << ")" << endl; // Debug output
        // cout<< "Drawing points: (" << centerX + x << ", " << centerY - y << ")" << endl; // Debug output
        // cout<< "Drawing points: (" << centerX - x << ", " << centerY - y << ")" << endl; // Debug output
        // cout<< "Drawing points: (" << centerX + y << ", " << centerY + x << ")" << endl; // Debug output
        // cout<< "Drawing points: (" << centerX - y << ", " << centerY + x << ")" << endl; // Debug output
        // cout<< "Drawing points: (" << centerX + y << ", " << centerY - x << ")" << endl; // Debug output
        // cout<< "Drawing points: (" << centerX - y << ", " << centerY - x << ")" << endl; // Debug output
        drawPixel(centerX + x, centerY + y);
        drawPixel(centerX - x, centerY + y);
        drawPixel(centerX + x, centerY - y);
        drawPixel(centerX - x, centerY - y);
        drawPixel(centerX + y, centerY + x);
        drawPixel(centerX - y, centerY + x);
        drawPixel(centerX + y, centerY - x);
        drawPixel(centerX - y, centerY - x);
    }
    
};

void drawGrid(sf::RenderWindow& window, float zoom, sf::Vector2f offset, sf::Font& font) {
    sf::Color gridColor(150, 150, 150);

    // Draw grid lines
    for (int x = 0; x < WINDOW_WIDTH; x += CELL_SIZE) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, 0), gridColor),
            sf::Vertex(sf::Vector2f(x, WINDOW_HEIGHT), gridColor)
        };
        window.draw(line, 2, sf::Lines);
    }

    for (int y = 0; y < WINDOW_HEIGHT; y += CELL_SIZE) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, y), gridColor),
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH, y), gridColor)
        };
        window.draw(line, 2, sf::Lines);
    }

    // Draw axes
    sf::Vertex xAxis[] = {
        sf::Vertex(sf::Vector2f(0, offset.y), sf::Color::Red),
        sf::Vertex(sf::Vector2f(WINDOW_WIDTH, offset.y), sf::Color::Red)
    };
    sf::Vertex yAxis[] = {
        sf::Vertex(sf::Vector2f(offset.x, 0), sf::Color::Green),
        sf::Vertex(sf::Vector2f(offset.x, WINDOW_HEIGHT), sf::Color::Green)
    };
    window.draw(xAxis, 2, sf::Lines);
    window.draw(yAxis, 2, sf::Lines);

    // Draw coordinate numbers
    for (int x = -offset.x / zoom; x < (WINDOW_WIDTH - offset.x) / zoom; ++x) {
        if (x == 0) continue;
        sf::Text label;
        label.setFont(font);
        label.setCharacterSize(10);
        label.setFillColor(sf::Color::White);
        label.setString(std::to_string(x));
        label.setPosition(x * zoom + offset.x + 2, offset.y + 2);
        window.draw(label);
    }

    for (int y = -offset.y / zoom; y < (WINDOW_HEIGHT - offset.y) / zoom; ++y) {
        if (y == 0) continue;
        sf::Text label;
        label.setFont(font);
        label.setCharacterSize(10);
        label.setFillColor(sf::Color::White);
        label.setString(std::to_string(-y)); // Invert Y for screen
        label.setPosition(offset.x + 2, y * zoom + offset.y + 2);
        window.draw(label);
    }
}

int main() {
    int centerX, centerY, radius;
    cout << "Enter center x: ";
    cin >> centerX;
    cout << "Enter center y: ";
    cin >> centerY;
    cout << "Enter radius: ";
    cin >> radius;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Midpoint Circle Algorithm with Grid");
    window.setFramerateLimit(60);

    // Zoom and offset
    float zoom = CELL_SIZE;
    sf::Vector2f offset(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    // Load font (use a system-installed one like FreeSans)
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf")) {
        cout << "Failed to load font. Make sure FreeSans.ttf is available.\n";
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(50, 50, 50));

        drawGrid(window, zoom, offset, font);

        MidpointCircle circle(window, centerX, centerY, radius, zoom, offset);
        circle.drawCircle(); // Draw points of the algorithm
        circle.drawActualCircle(); // Draw the actual circle in red

        window.display();
    }

    return 0;
}

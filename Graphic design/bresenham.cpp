#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;
// Utility function to draw a line between two points
void drawLine(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f end, sf::Color color = sf::Color::Red) {
    sf::Vertex line[] = {
        sf::Vertex(start, color),
        sf::Vertex(end, color)
    };
    window.draw(line, 2, sf::Lines);
}

class BRESENHAM {
private:
    vector<sf::Vector2i> points;
    sf::Color lineColor = sf::Color::White;
    const int pixelSize = 10;

public:
    BRESENHAM(int x0, int y0, int x1, int y1) {
        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);
        int x = x0;
        int y = y0;
        int stepX = (x1 > x0) ? 1 : -1;
        int stepY = (y1 > y0) ? 1 : -1;

        bool steep = dy > dx;
        if (steep) {
            swap(x, y);
            swap(dx, dy);
            swap(stepX, stepY);
        }

        int pk = 2 * dy - dx;
        for (int i = 0; i <= dx; ++i) {
            points.emplace_back(steep ? sf::Vector2i(y, x) : sf::Vector2i(x, y));
            if (pk < 0) {
                pk += 2 * dy;
            } else {
                y += stepY;
                pk += 2 * (dy - dx);
            }
            x += stepX;
            cout << "Point: (" << x << ", " << y << ")" << endl; // Debug output
            cout << "pk: " << pk << endl; // Debug output
        }
    }

    void draw(sf::RenderWindow& window, float zoom, sf::Vector2f offset) {
        for (const auto& p : points) {
            sf::RectangleShape pixel(sf::Vector2f(pixelSize, pixelSize));
            pixel.setPosition(p.x * zoom + offset.x, p.y * zoom + offset.y);
            pixel.setFillColor(lineColor);
            window.draw(pixel);
        }
    }

    sf::FloatRect getBounds() {
        if (points.empty()) return {0, 0, 0, 0};

        auto xExtremes = minmax_element(points.begin(), points.end(),
            [](const sf::Vector2i& a, const sf::Vector2i& b) { return a.x < b.x; });
        auto yExtremes = minmax_element(points.begin(), points.end(),
            [](const sf::Vector2i& a, const sf::Vector2i& b) { return a.y < b.y; });

        return {
            static_cast<float>(xExtremes.first->x),
            static_cast<float>(yExtremes.first->y),
            static_cast<float>(xExtremes.second->x - xExtremes.first->x + 1),
            static_cast<float>(yExtremes.second->y - yExtremes.first->y + 1)
        };
    }
};

void drawGridAndLabels(sf::RenderWindow& window, float zoom, sf::Vector2f offset, int width, int height, sf::Font& font) {
    sf::VertexArray lines(sf::Lines);
    int cols = static_cast<int>(width / zoom);
    int rows = static_cast<int>(height / zoom);

    for (int x = -offset.x / zoom; x < (width - offset.x) / zoom; ++x) {
        float xPos = x * zoom + offset.x;
        lines.append(sf::Vertex(sf::Vector2f(xPos, 0), sf::Color(150, 150, 150)));
        lines.append(sf::Vertex(sf::Vector2f(xPos, height), sf::Color(150, 150, 150)));

        sf::Text label(to_string(x), font, 10);
        label.setFillColor(sf::Color::White);
        label.setPosition(xPos + 2, offset.y + 2);
        window.draw(label);
    }

    for (int y = -offset.y / zoom; y < (height - offset.y) / zoom; ++y) {
        float yPos = y * zoom + offset.y;
        lines.append(sf::Vertex(sf::Vector2f(0, yPos), sf::Color(150, 150, 150)));
        lines.append(sf::Vertex(sf::Vector2f(width, yPos), sf::Color(150, 150, 150)));

        sf::Text label(to_string(y), font, 10);
        label.setFillColor(sf::Color::White);
        label.setPosition(offset.x + 2, yPos + 2);
        window.draw(label);
    }

    window.draw(lines);
}

int main() {
    int x0, y0, x1, y1;
    cout << "Enter starting coordinates (x0 y0): ";
    cout << "\nEnter x0: "; cin >> x0;
    cout << "Enter y0: "; cin >> y0;
    cout << "Enter ending coordinates (x1 y1): ";
    cout << "\nEnter x1: "; cin >> x1;
    cout << "Enter y1: "; cin >> y1;

    BRESENHAM line(x0, y0, x1, y1);
    auto bounds = line.getBounds();

    const float margin = 2.0f;
    float zoom = min(
        800.0f / (bounds.width + 2 * margin),
        600.0f / (bounds.height + 2 * margin)
    );
    zoom = min(zoom, 40.0f);
 
    sf::Vector2f offset(
        (800 - bounds.width * zoom) / 2 - bounds.left * zoom,
        (600 - bounds.height * zoom) / 2 - bounds.top * zoom
    );

    sf::RenderWindow window(sf::VideoMode(800, 600), "Bresenham Line Drawing Algorithm");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        cerr << "Error loading font!" << endl;
        return -1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(100, 100, 100));
        drawGridAndLabels(window, zoom, offset, 800, 600, font);
        line.draw(window, zoom, offset);
         // Draw the perfect line from point A to B
         sf::Vector2f start(x0 * zoom + offset.x, y0 * zoom + offset.y);
         sf::Vector2f end(x1 * zoom + offset.x, y1 * zoom + offset.y);
         drawLine(window, start, end, sf::Color::Blue);
        window.display();
    }

    return 0;
}

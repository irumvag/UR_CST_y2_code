#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace std;
class DDA {
private:
    int x, y, dx, dy ,X1 ,Y1 ,m ,m1;
    float xIncrement, yIncrement;
    sf::RenderWindow& window;  // Store window reference
public:
    DDA(sf::RenderWindow& win, int x0, int y0, int x1, int y1) 
        : window(win)  // Initialize reference
    {
        x = x0;
        y = y0;
        dx = x1 - x0;
        dy = y1 - y0;
        X1=x1;
        Y1=y1;
        if(dx!=0){
        m=dy/dx;
        }
        else
        {
            cout<<"\nSlope is infinity!";
            return;
        }
        
    }
    void drawDDALine() {
        if(m<1)
        {
            for (x; x <= X1; ++x) {
                sf::RectangleShape pixel(sf::Vector2f(2, 2));  // Larger pixels
                pixel.setPosition(round(x), round(y));
                pixel.setFillColor(sf::Color::White);  // More visible color
                window.draw(pixel); 
                y=y+m;
            }
        }
        if(m>1)
        {
            for (y; y<=Y1; ++y) {
                sf::RectangleShape pixel(sf::Vector2f(2, 2));  // Larger pixels
                pixel.setPosition(round(x), round(y));
                pixel.setFillColor(sf::Color::White);  // More visible color
                window.draw(pixel); 
                    m1=1/m;
                    x+=m1;
                }
        }
    }
};

int main() {
    int x0, y0, x1, y1;  
    
    cout << "Enter starting coordinates (x0 y0): ";
    cout << "\nEnter x0:";
    cin >> x0;
    cout << "\nEnter y0:";
    cin >> y0;
    cout << "\nEnter ending coordinates (x1 y1): ";
    cout << "\nEnter x1:";
    cin >> x1 ;
    cout << "\nEnter y1:";
    cin >> y1;

    sf::RenderWindow window(sf::VideoMode(800, 600), "DDA Line Drawing");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        DDA obj(window, x0, y0, x1, y1);
        obj.drawDDALine();
        window.display();
    }
    return 0;
}
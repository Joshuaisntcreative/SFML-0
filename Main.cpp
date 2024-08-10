#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <SFML/Graphics.hpp>


int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Drawing");
    std::vector<sf::RectangleShape> rectangles;
    int currx = 100;
    for (int i = 0; i < 3; i++) {
        sf::RectangleShape rectangle(sf::Vector2f(100, 200));
        rectangle.setFillColor(sf::Color::White);                 
        rectangle.setOutlineColor(sf::Color::Green);                
        rectangle.setOutlineThickness(2.f);
        rectangle.setPosition(currx, 100);
        currx += 150;
        rectangles.push_back(rectangle);

    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (auto& rectangle : rectangles) {
            window.draw(rectangle);
        }
        window.display();
    }
}
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <SFML/Graphics.hpp>


int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Drawing");

	sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f)); // Width: 200, Height: 100
	rectangle.setFillColor(sf::Color::White);                 // Fill color: Green
	rectangle.setOutlineColor(sf::Color::Green);                // Outline color: Red
	rectangle.setOutlineThickness(2.f);                       // Outline thickness: 5
	rectangle.setPosition(100.f, 100.f);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }
}
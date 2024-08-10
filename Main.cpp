#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <SFML/Graphics.hpp>


const int windowWidth = 800;
const int windowHeight = 600;

void moveRectangles(sf::Clock& clock, sf::Time delay, std::vector<sf::RectangleShape>& rectangles, size_t& currentIndex) {
    if (currentIndex == rectangles.size() - 1) {
        return; // No more rectangles to move
    }

    if (clock.getElapsedTime() >= delay) {
        rectangles[currentIndex].setFillColor(sf::Color::Blue);
        currentIndex++;       // Move to the next rectangle
        clock.restart();      // Restart the clock for the next delay
    }
}


int main() {
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Drawing");
    std::vector<sf::RectangleShape> rectangles;
    size_t currentIndex = 0;

    sf::Clock clock;
    sf::Time delay = sf::seconds(4);

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
        sf::Time currentTime = clock.getElapsedTime();
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
        moveRectangles(clock, delay, rectangles, currentIndex);
        std::cout << currentTime.asSeconds() << std::endl;
        window.display();
    }
}
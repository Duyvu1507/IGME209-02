// PE5 - Playing with Windows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::RectangleShape myRect(sf::Vector2f(100, 150));
    myRect.setFillColor(sf::Color::Blue);
    myRect.setPosition(200, 350);

    sf::CircleShape myCircle(50.f);
    myCircle.setFillColor(sf::Color::Green);
    myCircle.setPosition(500, 400);

    sf::CircleShape myTriangle(80.f, 3);
    myTriangle.setFillColor(sf::Color::Yellow);
    myTriangle.setPosition(100, 100);

    sf::CircleShape myOctagon(80.f, 8);
    myOctagon.setFillColor(sf::Color::Magenta);
    myOctagon.setPosition(500, 100);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(myRect);
        window.draw(myCircle);
        window.draw(myTriangle);
        window.draw(myOctagon);

        // end the current frame
        window.display();
    }

    return 0;
}

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std; // possibly change this later

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ 800, 600 }),
        "Chess Engine"
    );

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::White);
        window.display();
    }

    return 0;
}
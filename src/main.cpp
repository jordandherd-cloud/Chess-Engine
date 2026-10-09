#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std; // possibly change this later


char board[8][8] = {
    {'r','n','b','q','k','b','n','r'},  // row 0 = rank 8 (top of screen)
    {'p','p','p','p','p','p','p','p'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'P','P','P','P','P','P','P','P'},
    {'R','N','B','Q','K','B','N','R'}   // row 7 = rank 1 (bottom of screen)
};
int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ 600, 600 }),
        "Chess Engine"
    );


    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
            std::cout << board[row][col] << ' ';
        std::cout << '\n';
    }

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        const float size = 75.f;
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                sf::RectangleShape square({ size, size });
                square.setPosition({ col * size, row * size });
                square.setFillColor((row + col) % 2 == 0
                    ? sf::Color(240, 217, 181)
                    : sf::Color(181, 136, 99));
                window.draw(square);
            }
        }

        window.display();
    }

    return 0;
}
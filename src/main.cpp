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

    sf::Texture pawnB("Textures/b-pawn.png");
    sf::Texture pawnW("Textures/w-pawn.png");

    sf::Texture rookB("Textures/b-rook.png");
    sf::Texture rookW("Textures/w-rook.png");

    sf::Texture knightB("Textures/b-knight.png");
    sf::Texture knightW("Textures/w-knight.png");

    sf::Texture queenB("Textures/b-queen.png");
    sf::Texture queenW("Textures/w-queen.png");

    sf::Texture kingB("Textures/b-king.png");
    sf::Texture kingW("Textures/w-king.png");

    sf::Texture bishopB("Textures/b-bishop.png");
    sf::Texture bishopW("Textures/w-bishop.png");

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
               
               
                char piece = board[row][col];

                if (piece == 'P') {
                    sf::Sprite WhitePawn(pawnW);
                    float scale = size / pawnW.getSize().x;   // 75 / 480 = 0.15625
                    WhitePawn.setScale({ scale, scale });
                    WhitePawn.setPosition({ col * size, row * size });
                    window.draw(WhitePawn);
                } 

                if (piece == 'p') {
                    sf::Sprite BlackPawn(pawnB);
                    float scale = size / pawnB.getSize().x;   // 75 / 480 = 0.15625
                    BlackPawn.setScale({ scale, scale });
                    BlackPawn.setPosition({ col * size, row * size });
                    window.draw(BlackPawn);
                }
              
                if (piece == 'Q') {
                    sf::Sprite WhiteQueen(queenW);
                    float scale = size / queenW.getSize().x;   // 75 / 480 = 0.15625
                    WhiteQueen.setScale({ scale, scale });
                    WhiteQueen.setPosition({ col * size, row * size });
                    window.draw(WhiteQueen);
                }

                if (piece == 'q') {
                    sf::Sprite BlackQueen(queenB);
                    float scale = size / queenW.getSize().x;   // 75 / 480 = 0.15625
                    BlackQueen.setScale({ scale, scale });
                    BlackQueen.setPosition({ col * size, row * size });
                    window.draw(BlackQueen);
                }

                if (piece == 'K') {
                    sf::Sprite WhiteKing(kingW);
                    float scale = size / kingW.getSize().x;  
                    WhiteKing.setScale({ scale, scale });
                    WhiteKing.setPosition({ col * size, row * size });
                    window.draw(WhiteKing);
                }

                if (piece == 'k') {
                    sf::Sprite BlackKing(kingB);
                    float scale = size / kingB.getSize().x;
                    BlackKing.setScale({ scale, scale });
                    BlackKing.setPosition({ col * size, row * size });
                    window.draw(BlackKing);
                }

                if (piece == 'B') {
                    sf::Sprite WhiteBishop(bishopW);
                    float scale = size / bishopW.getSize().x;
                    WhiteBishop.setScale({ scale, scale });
                    WhiteBishop.setPosition({ col * size, row * size });
                    window.draw(WhiteBishop);
                }

                if (piece == 'b') {
                    sf::Sprite BlackBishop(bishopB);
                    float scale = size / bishopB.getSize().x;
                    BlackBishop.setScale({ scale, scale });
                    BlackBishop.setPosition({ col * size, row * size });
                    window.draw(BlackBishop);
                } 
                
                if (piece == 'N') {
                    sf::Sprite WhiteKnight(knightW);
                    float scale = size / knightW.getSize().x;
                    WhiteKnight.setScale({ scale, scale });
                    WhiteKnight.setPosition({ col * size, row * size });
                    window.draw(WhiteKnight);
                }

                if (piece == 'n') {
                    sf::Sprite BlackKnight(knightB);
                    float scale = size / knightB.getSize().x;
                    BlackKnight.setScale({ scale, scale });
                    BlackKnight.setPosition({ col * size, row * size });
                    window.draw(BlackKnight);
                }
                
                if (piece == 'R') {
                    sf::Sprite WhiteRook(rookW);
                    float scale = size / rookW.getSize().x;
                    WhiteRook.setScale({ scale, scale });
                    WhiteRook.setPosition({ col * size, row * size });
                    window.draw(WhiteRook);
                }

                if (piece == 'r') {
                    sf::Sprite BlackRook(rookB);
                    float scale = size / rookB.getSize().x;
                    BlackRook.setScale({ scale, scale });
                    BlackRook.setPosition({ col * size, row * size });
                    window.draw(BlackRook);
                }










            }
        }

        window.display();
    }

    return 0;
}
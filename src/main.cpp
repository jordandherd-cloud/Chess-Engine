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

    sf::Texture pawnB("Textures/chess_piece_2_black_pawn.png");
    sf::Texture pawnW("Textures/chess_piece_2_white_pawn.png");

    sf::Texture rookB("Textures/chess_piece_2_black_rook.png");
    sf::Texture rookW("Textures/chess_piece_2_white_rook.png");

    sf::Texture knightB("Textures/chess_piece_2_black_knight.png");
    sf::Texture knightW("Textures/chess_piece_2_white_knight.png");

    sf::Texture queenB("Textures/chess_piece_2_black_queen.png");
    sf::Texture queenW("Textures/chess_piece_2_white_queen.png");

    sf::Texture kingB("Textures/chess_piece_2_black_king.png");
    sf::Texture kingW("Textures/chess_piece_2_white_king.png");

    sf::Texture bishopB("Textures/chess_piece_2_black_bishop.png");
    sf::Texture bishopW("Textures/chess_piece_2_white_bishop.png");

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
                    sf::Sprite pawnW(pawnW);
                    pawnW.setPosition({ col * size, row * size });
                    window.draw(pawnW);
                } 

                if (piece == 'p') {
                    sf::Sprite pawnB(pawnB);
                    pawnB.setPosition({ col * size, row * size });
                    window.draw(pawnB);
                }
              
                if (piece == 'Q') {
                    sf::Sprite queenW(queenW);
                    queenW.setPosition({ col * size, row * size });
                    window.draw(queenW);
                }

                if (piece == 'q') {
                    sf::Sprite queenB(queenB);
                    queenB.setPosition({ col * size, row * size });
                    window.draw(queenB);
                }

                if (piece == 'K') {
                    sf::Sprite kingW(kingW);
                    kingW.setPosition({ col * size, row * size });
                    window.draw(kingW);
                }

                if (piece == 'k') {
                    sf::Sprite kingB(kingB);
                    kingB.setPosition({ col * size, row * size });
                    window.draw(kingB);
                }

                if (piece == 'B') {
                    sf::Sprite bishopW(bishopW);
                    bishopW.setPosition({ col * size, row * size });
                    window.draw(bishopW);
                }

                if (piece == 'b') {
                    sf::Sprite bishopB(bishopB);
                    bishopB.setPosition({ col * size, row * size });
                    window.draw(bishopB);
                } 
                
                if (piece == 'N') {
                    sf::Sprite knightW(knightW);
                    knightW.setPosition({ col * size, row * size });
                    window.draw(knightW);
                }

                if (piece == 'n') {
                    sf::Sprite knightB(knightB);
                    knightB.setPosition({ col * size, row * size });
                    window.draw(knightB);
                }
                
                if (piece == 'R') {
                    sf::Sprite rookW(rookW);
                    rookW.setPosition({ col * size, row * size });
                    window.draw(rookW);
                }

                if (piece == 'r') {
                    sf::Sprite rookB(rookB);
                    rookB.setPosition({ col * size, row * size });
                    window.draw(rookB);
                }










            }
        }

        window.display();
    }

    return 0;
}
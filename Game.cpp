#include "Game.h"

void Game::Start(void)
{
    VideoMode VMode(windowWidth, windowHeight, 32);
    RenderWindow Window(VMode, "Peg Solitaire");
    Window.setFramerateLimit(60);
    Window.setPosition(Vector2i(300,40));

    gameObject background("Images/woodBackground.jpg", 0, 0);

    board gameBoard;

    Event event;
    while (Window.isOpen())
    {
        //get input
        while (Window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    Window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape)
                        Window.close();
                    break;
                default:
                    break;
            }
        }
        

        //update states
        gameBoard.updateBoardPieces(Window);

        //render screen
        background.showGameObject(Window);
        gameBoard.showBoard(Window);

        Window.display();
    }
}

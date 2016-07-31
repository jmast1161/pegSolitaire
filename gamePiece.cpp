#include "gamePiece.h"

void gamePiece::resetPiecePos(void)
{
    circle.setPosition(xBase, yBase);
    once = 1;
    xDiff = 0;
    yDiff = 0;
}

void gamePiece::setNewPiecePos(int x, int y)
{
    xBase = x;
    yBase = y;
    circle.setPosition(xBase, yBase);
}

int gamePiece::isPieceSelected(RenderWindow& Window)
{
    if(mouseOver(Window) && Mouse::isButtonPressed(Mouse::Left))
    {
        selected = 1;
    }
    if(!Mouse::isButtonPressed(Mouse::Left))
    {
        selected = 0;
    }
    return selected;
}

int gamePiece::mouseOver(RenderWindow& Window)
{
    Vector2i mousePos = Mouse::getPosition(Window);
    Vector2f circlePos = circle.getPosition();
    
    if(mousePos.x > circlePos.x &&
       mousePos.y > circlePos.y &&
       mousePos.x - 2*(int)circle.getRadius() < circlePos.x &&
       mousePos.y - 2*(int)circle.getRadius() < circlePos.y)
    {
        circle.setOutlineThickness(4.0f);
        return 1;
    }
    else
    {
        circle.setOutlineThickness(2.0f);
    }
    return 0;
}

void gamePiece::dragPiece(RenderWindow& Window)
{
    Vector2i mousePos = Mouse::getPosition(Window);
    Vector2f circlePos = circle.getPosition();

    int xPos;
    int yPos;
    
    if(once)
    {
        xDiff = mousePos.x - circlePos.x;
        yDiff = mousePos.y - circlePos.y;
        once = 0;
    }

    xPos = mousePos.x - xDiff;
    yPos = mousePos.y - yDiff;

    circle.setPosition(xPos, yPos);

}

Vector2f gamePiece::getBasePos(void)
{
    return Vector2f(xBase, yBase);
}

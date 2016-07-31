#include "gameCircleObject.h"

gameCircleObject::gameCircleObject(Color circleColor, int r, int x, int y)
{
    filled = 0;
    circle.setRadius(r);
    circle.setPointCount(50);
    circle.setFillColor(circleColor);
    circle.setOutlineColor(Color::Black);
    circle.setOutlineThickness(2.0f);
    circle.setPosition(x, y);
}

void gameCircleObject::initGameCircleObject(Color circleColor, int r, int x, int y)
{
    filled = 0;
    circle.setRadius(r);
    circle.setPointCount(50);
    circle.setFillColor(circleColor);
    circle.setOutlineColor(Color::Black);
    circle.setOutlineThickness(2.0f);
    circle.setPosition(x, y);
}

void gameCircleObject::showGameCircleObject(RenderWindow& Window)
{
    Window.draw(circle);
}

int gameCircleObject::mouseOver(RenderWindow& Window)
{
    Vector2i mousePos = Mouse::getPosition(Window);
    Vector2f circlePos = circle.getPosition();
    
    if(mousePos.x > circlePos.x &&
       mousePos.y > circlePos.y &&
       mousePos.x - 2*(int)circle.getRadius() < circlePos.x &&
       mousePos.y - 2*(int)circle.getRadius() < circlePos.y)
    {
        circle.setFillColor(Color::Cyan);
        return 1;
    }
    else
    {
        circle.setFillColor(Color::Black);
    }
    return 0;
}
void gameCircleObject::setFilled(int toggle)
{
    filled = toggle;
}

int gameCircleObject::isFilled(void)
{
    return filled;
}

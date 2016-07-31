#include "gameObject.h"

gameObject::gameObject(string objFile, int x, int y)
{
    texture.loadFromFile(objFile.c_str());
    sprite.setTexture(texture);
    xPos = x;
    yPos = y;
    sprite.setPosition(xPos, yPos);
}

void gameObject::initGameObject(string objFile, int x, int y)
{
    texture.loadFromFile(objFile.c_str());
    sprite.setTexture(texture);
    xPos = x;
    yPos = y;
    sprite.setPosition(xPos, yPos);
}

void gameObject::showGameObject(RenderWindow& Window)
{
    Window.draw(sprite);
}

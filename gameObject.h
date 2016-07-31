#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class gameObject
{
    protected:
        Texture texture;
        Sprite sprite;
        int xPos, yPos;
    public:
        gameObject(string objFile, int x, int y);
        void initGameObject(string objFile, int x, int y);
        void showGameObject(RenderWindow& Window);
};

#endif

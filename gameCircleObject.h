#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

#ifndef GAMECIRCLEOBJECT_H
#define GAMECIRCLEOBJECT_H

class gameCircleObject
{
    private:
        int filled;
    public:
        CircleShape circle;
        gameCircleObject(Color circleColor, int r, int x, int y);
        void initGameCircleObject(Color circleColor, int r, int x, int y);
        void showGameCircleObject(RenderWindow& Window);
        int mouseOver(RenderWindow& Window);
        void setFilled(int toggle);
        int isFilled(void);
};

#endif

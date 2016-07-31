#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#ifndef GAMEPIECE_H
#define GAMEPIECE_H

#include "gameCircleObject.h"

class gamePiece : public gameCircleObject
{
    protected:
        int xBase, yBase, once, xDiff, yDiff, selected;
    public:
        gamePiece(Color circleColor, int r, int x, int y): gameCircleObject(circleColor, r, x, y) {xBase = x; yBase = y; once = 1; xDiff = 0; yDiff = 0; selected = 0;};
        void resetPiecePos(void);
        void setNewPiecePos(int x, int y);
        int isPieceSelected(RenderWindow& Window);
        int mouseOver(RenderWindow& Window);
        void dragPiece(RenderWindow& Window);
        Vector2f getBasePos(void);
};

#endif

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#ifndef BOARD_H
#define BOARD_H

#include "gameCircleObject.h"
#include "gamePiece.h"
#define rowSize     7
#define colSize     7
#define horOffset   150
#define vertOffset  50

class board
{
    friend class gamePiece;
    private:
        static int boardLayout[colSize][rowSize];
        int boardSize;
        int numOfPegs;
        int selectPiece;
        gameCircleObject** pegPtr;
        gamePiece** piecePtr;
    public:
        board(void);
        void showBoard(RenderWindow& Window);
        void updateBoardPieces(RenderWindow& Window);
        int checkIntersection(RenderWindow& Window);
        void removePiece(int position);
        ~board(void);
};

#endif

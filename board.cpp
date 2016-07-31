#include "board.h"
#include <iostream>
int board::boardLayout[7][7] = {{2, 2, 1, 1, 1, 2, 2},
                                {2, 2, 1, 1, 1, 2, 2},
                                {1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 0, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1},
                                {2, 2, 1, 1, 1, 2, 2},
                                {2, 2, 1, 1, 1, 2, 2}};

board::board(void)
{
    int pegCounter = 0;
    int pieceCounter = 0;

    boardSize = 0;
    numOfPegs = 0;
    selectPiece = 0;

    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            
            if(boardLayout[j][i] == 1)
            {
                ++numOfPegs;
                ++boardSize;
            }
            if(boardLayout[j][i] == 0)
            {
                ++boardSize;
            }
        }
    }
    pegPtr = new gameCircleObject*[boardSize];
    piecePtr = new gamePiece*[numOfPegs];
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            if(boardLayout[j][i] == 1)
            {
                piecePtr[pieceCounter] = new gamePiece(Color::White, 40, 100*i + horOffset, 100*j + vertOffset);
                ++pieceCounter;

                pegPtr[pegCounter] = new gameCircleObject(Color::Black, 40, 100*i + horOffset, 100*j + vertOffset);
                ++pegCounter;
            }
            if(boardLayout[j][i] == 0)
            {
                pegPtr[pegCounter] = new gameCircleObject(Color::Black, 40, 100*i + horOffset, 100*j + vertOffset);
                ++pegCounter;
            }
        }
    }
    for(int j = 0; j < boardSize; ++j)
    {
        for(int i = 0; i < numOfPegs; ++i)
        {
            if(piecePtr[i]->circle.getPosition() == pegPtr[j]->circle.getPosition())
            {
                pegPtr[j]->setFilled(1);
            }
        }
    }
};

void board::showBoard(RenderWindow& Window)
{
    for(int i = 0; i < boardSize; i++)
    {
        pegPtr[i]->showGameCircleObject(Window);
    }
    for(int i = 0; i < numOfPegs; i++)
    {
        piecePtr[i]->showGameCircleObject(Window);
        if(selectPiece)
        {
            piecePtr[selectPiece - 1]->showGameCircleObject(Window);
        }
    }
}

void board::updateBoardPieces(RenderWindow& Window)
{
    for(int i = 0; i < numOfPegs; i++)
    {
        if(!selectPiece && piecePtr[i]->isPieceSelected(Window))
        {
            selectPiece = i + 1;
        }
        else if(selectPiece)
        {
            piecePtr[selectPiece - 1]->dragPiece(Window);
        }
        if(!Mouse::isButtonPressed(Mouse::Left))
        {
            checkIntersection(Window);
            selectPiece = 0;
            piecePtr[i]->resetPiecePos();
        }
    }
}

int board::checkIntersection(RenderWindow& Window)
{
    int pegCounter = 0;
    int positionToRemove = 0;
    for(pegCounter = 0; pegCounter < boardSize; ++pegCounter)
    {
        if(pegPtr[pegCounter]->mouseOver(Window) && selectPiece)
        {
            Vector2f circlePos = pegPtr[pegCounter]->circle.getPosition();
            Vector2f piecePos = piecePtr[selectPiece - 1]->getBasePos();
            if(!pegPtr[pegCounter]->isFilled())
            {
                if(circlePos.x == piecePos.x + 200)
                {
                    positionToRemove = 1;
                }
                else if(circlePos.x == piecePos.x - 200)
                {
                    positionToRemove = 2;
                }
                if(circlePos.y == piecePos.y + 200)
                {
                    positionToRemove = 3;
                }
                else if(circlePos.y == piecePos.y - 200)
                {
                    positionToRemove = 4;
                }
                
                if(positionToRemove)
                {
                    for(int i = 0; i < boardSize; ++i)
                    {
                        if(piecePtr[selectPiece - 1]->getBasePos() == pegPtr[i]->circle.getPosition())
                        {
                            pegPtr[i]->setFilled(0);
                        }
                    }
                    pegPtr[pegCounter]->setFilled(1);
                    piecePtr[selectPiece - 1]->circle.setPosition(circlePos);
                    piecePtr[selectPiece - 1]->setNewPiecePos(circlePos.x, circlePos.y);
                    piecePos = piecePtr[selectPiece - 1]->circle.getPosition();
                }

                switch(positionToRemove)
                {
                    case(1):
                        for(int i = 0; i < numOfPegs; ++i)
                        {
                            if(piecePos.x == piecePtr[i]->circle.getPosition().x + 100 &&
                               piecePos.y == piecePtr[i]->circle.getPosition().y)
                            {
                                for(int k = 0; k < boardSize; ++k)
                                {
                                    if(piecePtr[selectPiece - 1]->getBasePos().x - 100 == pegPtr[k]->circle.getPosition().x)
                                    {
                                         pegPtr[k]->setFilled(0);
                                    }
                                }
                                removePiece(i);
                                positionToRemove = 0;
                                break;
                            }
                        }
                    break;
                    case(2):
                        for(int i = 0; i < numOfPegs; ++i)
                        {
                            if(piecePos.x == piecePtr[i]->circle.getPosition().x - 100 &&
                               piecePos.y == piecePtr[i]->circle.getPosition().y)
                            {
                                for(int k = 0; k < boardSize; ++k)
                                {
                                    if(piecePtr[selectPiece - 1]->getBasePos().x + 100 == pegPtr[k]->circle.getPosition().x)
                                    {
                                         pegPtr[k]->setFilled(0);
                                    }
                                }
                                removePiece(i);
                                positionToRemove = 0;
                                break;
                            }
                        }
                    break;
                    case(3):
                        for(int i = 0; i < numOfPegs; ++i)
                        {
                            if(piecePos.y == piecePtr[i]->circle.getPosition().y + 100 &&
                               piecePos.x == piecePtr[i]->circle.getPosition().x)
                            {
                                for(int k = 0; k < boardSize; ++k)
                                {
                                    if(piecePtr[selectPiece - 1]->getBasePos().y - 100 == pegPtr[k]->circle.getPosition().y)
                                    {
                                         pegPtr[k]->setFilled(0);
                                    }
                                }
                                removePiece(i);
                                positionToRemove = 0;
                                break;
                            }
                        }
                    break;
                    case(4):
                        for(int i = 0; i < numOfPegs; ++i)
                        {
                            if(piecePos.y == piecePtr[i]->circle.getPosition().y - 100 &&
                               piecePos.x == piecePtr[i]->circle.getPosition().x)
                            {
                                for(int k = 0; k < boardSize; ++k)
                                {
                                    if(piecePtr[selectPiece - 1]->getBasePos().y + 100 == pegPtr[k]->circle.getPosition().y)
                                    {
                                         pegPtr[k]->setFilled(0);
                                    }
                                }
                                removePiece(i);
                                positionToRemove = 0;
                                break;
                            }
                        }
                    break;
                }
            }
        }
    }
    return 0;
}

void board::removePiece(int position)
{
    for(int x = position + 1; x < numOfPegs; ++x)
    {
        piecePtr[x - 1] = piecePtr[x];
    }
    --numOfPegs;
}

board::~board(void)
{
    for(int i = 0; i < boardSize; i++)
    {
        delete pegPtr[i];
    }
    delete[] pegPtr;

    for(int i = 0; i < numOfPegs; i++)
    {
        delete piecePtr[i];
    }
    delete[] piecePtr;
}

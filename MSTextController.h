#ifndef MSTEXTCONTROLLER_H
#define MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{

    MinesweeperBoard *ContrBoard;
    MSBoardTextView *viewContrBoard;

public:
    MSTextController(Board&, BoardView&);
    void play();
};


#endif // MSTEXTCONTROLLER_H

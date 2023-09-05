#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextViem.h"
#include <fstream>


MSBoardTextView::MSBoardTextView(MinesweeperBoard &Board){
    this->board = board;
}

void MSBoardTextView::display() {
    system("cls");
    for(int i=0; i<board.getBoardHeight();i++){
        for(int j=0; j<board.getBoardWidth(); j++){
            cout<<board.getFieldInfo(i,j);
        }
        cout<<endl;
    }
}

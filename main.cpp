#include <iostream>
#include "MinesweeperBoard.h"
#include "Field.h"
#include "MSBoardTextView.h"

using namespace std;


int main()
{
  MinesweeperBoard board (20, 10, GameMode::DEBUG);
  MSBoardTextView view = MSBoardTextView(board);
  view.display();
  board.revealField(0,5);
  view.display();
}


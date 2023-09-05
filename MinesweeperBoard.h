#ifndef MINESWEEPERBOARD_H_INCLUDED
#define MINESWEEPERBOARD_H_INCLUDED
#include "Field.h"

enum GameMode {DEBUG, EASY, NORMAL, HARD};
enum GameState {RUNNING, FINISHED_WIN, FINISHED_LOSS};

class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;
    int mines;
    int vision = 0;
    GameMode GMode;
    GameState GState;

  public:

    void clear_board();
    void debug_display() const;

    MinesweeperBoard(int a, int b, GameMode mode);

    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    GameState getGameState() const;
    char getFieldInfo(int row, int col) const;
};


#endif // MINESWEEPERBOARD_H_INCLUDED

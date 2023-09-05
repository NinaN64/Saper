#include <iostream>
#include "MinesweeperBoard.h"
#include "Field.h"

MinesweeperBoard::MinesweeperBoard(int a, int b, GameMode mode){
    GState = RUNNING;
    GMode = mode;
    bool firstMove = true;
    width = a;
    height = b;

    clear_board();

    if(mode == EASY){
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                mines = height*width*0.1;
            }
        }
    }

    if(mode == NORMAL){
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                mines = height*width*0.2;
            }
        }
    }

    if(mode == HARD){
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                mines = height*width*0.3;
            }
        }
    }

    if(mode == DEBUG){
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(i == j) board[i][j].hasMine = true;
                if(i == 0) board[i][j].hasMine = true;
                if(j == 0 && i%2 == 0) board[i][j].hasMine = true;
            }
        }
    }

}

void MinesweeperBoard::clear_board(){
    int row;
    int col;
    for(row=0; row<height; row++){
        for(col=0; col<width; col++){
            board[row][col].hasFlag = false;
            board[row][col].hasMine = false;
            board[row][col].isRevealed = false;
        }
    }
}

void MinesweeperBoard::debug_display() const{

    char a = ' ';
    char b = ' ';
    char c = ' ';
    for(int row=0; row<height; row++){
        for(int col=0; col<width; col++){
            std::string x;
            if(board[row][col].hasMine == true) a = 'M';
            else a = '.';
            if(board[row][col].hasFlag == true) b = 'f';
            else b = '.';
            if (board[row][col].isRevealed == true) c = 'o';
            else c = '.';
            x.push_back(a);
            x.push_back(b);
            x.push_back(c);
            std::cout<<"["<<x<<"]";
        }
        std::cout<<std::endl;
  }
}

int MinesweeperBoard::getBoardWidth() const{
    return width;
}
int MinesweeperBoard::getBoardHeight() const{
    return height;
}
int MinesweeperBoard::getMineCount() const{
    return mines;
}

int MinesweeperBoard::countMines(int row, int col) const{
    int MineCounter = 0;
    //if(board[row][col].isRevealed == false) return -1;
    if(row >= height || col >= width) return -1;
    else{
        for(int i=row-1; i<row+1; i++){
            for(int j=col-1; j<col+1; j++){
                if((i<0) || j<0 || i>=height || j>=width) continue;
                else if(board[row][col].hasMine == true) MineCounter++;
            }
        }
        if(board[row][col].hasMine == true) MineCounter --;
    }
    return MineCounter;
}

bool MinesweeperBoard::hasFlag(int row, int col) const{
    if(board[row][col].hasFlag == true) return true;
    else if(board[row][col].hasFlag == false) return false;
    else if(board[row][col].isRevealed == true) return false;
    else if(row>=height || col>=width || col<0 || row<0) return false;
}

void MinesweeperBoard::toggleFlag(int row, int col){
    if((col<0)||(row<0)||(col>=width)||(row>=height)) return;
    else if(board[row][col].isRevealed == false) board[row][col].hasFlag = !board[row][col].hasFlag;
}

void MinesweeperBoard::revealField(int row, int col){

    if((col<0)||(row<0)||(col>=width)||(row>=height)) return;
    else if(board[row][col].isRevealed == true) return;
    else if(board[row][col].hasFlag == true) return;
    if(board[row][col].hasMine == false && board[row][col].isRevealed == false){
        board[row][col].isRevealed = true;
        vision++;

    }
    else if((board[row][col].isRevealed == false) && (board[row][col].hasMine == true)){
        board[row][col].isRevealed = true;
        GState = FINISHED_LOSS;
    }
}

GameState MinesweeperBoard::getGameState() const{
    if (GState == FINISHED_LOSS) return FINISHED_LOSS;
    else if(vision != height*width) return RUNNING;
    else if(vision == height*width) return FINISHED_WIN;
}
char MinesweeperBoard::getFieldInfo(int row, int col) const{
    if(row>height || row<0 || col<0 || col>width) return '#';
    if(board[row][col].isRevealed == false && board[row][col].hasFlag == true) return 'F';
    if(board[row][col].isRevealed == false && board[row][col].hasFlag == false) return '_';
    if(board[row][col].isRevealed == true && board[row][col].hasMine == true) return 'x';
    if(board[row][col].isRevealed == true && countMines(row,col) == 0) return ' ';
    if(board[row][col].isRevealed == true && countMines(row,col) != 0) return (char) countMines(row,col)+48;

}



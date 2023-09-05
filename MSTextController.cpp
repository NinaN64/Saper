#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &admin, MSBoardTextView &view)
{
    Board = &admin;
    viewBoard = &view;
}

void MSTextController::play(){
    char PlayerChoice;
    int row, col;
    while(Board->getGameState() == RUNNING){
        viewBoard->display();
        cin>>PlayerChoice;
        switch(PlayerChoice){
            case '1':
                cout<<"Select your square\n"<<"Row: ";
                cin>>row;
                cout<<"\nColumn: ";
                cin>>col;
                Board->getFieldInfo(row, col);
                break;

            case '2':
                cout<<"Select your square\n"<<"Row: ";
                cin>>row;
                cout<<"\nColumn: ";
                cin>>col;
                Board->toggleFlag(row, col);
                break;

            default: cout<<"You have to pick one of two options";
        }
        if(Board->getGameState() == FINISHED_LOSS){
            Board->display();
            cout<<"BOOM! Game Over"
        }
    }


}


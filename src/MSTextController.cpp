#include "MSTextController.h"

BoardControl::BoardControl(Board &admin, BoardView &view)
{
    ContrBoard = &admin;
    viewContrBoard = &view;
}

void BoardControl::play()
{
    char PlayerChoice;
    int row, col;
    while(ContrBoard->getGameState() == RUNNING)
    {
        viewBoard->display();
        cin>>PlayerChoice;
        switch(PlayerChoice)
        {
        case '1':
            cout<<"Pick a square"<<endl<<"Row: ";
            cin>>row;
            cout<<endl<<"Col: ";
            cin>>col;
            ContrBoard->(row,column);
            break;
        case '2':
            cout<<"WYBIERZ POLE"<<endl<<"numer wiersza: ";
            cin>>row;
            cout<<endl<<"numer kolumny: ";
            cin>>column;
            debugBoard->toggleFlag(row,column);
            break;
        default:
            cout<<"NIE WCISNALES ZADNEJ Z DWOCH OPCJI, WSZYSTKO OK?";
            Sleep(1000);
        }
        if(debugBoard->getGameState() == FINISHED_LOSS)
        {
            viewBoard->display();
            cout<<"MINA! PRZEGRANA!"<<endl;
        }
    };
}

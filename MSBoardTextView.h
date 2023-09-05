#ifndef MSBOARDTEXTVIEW_H_INCLUDED
#define MSBOARDTEXTVIEW_H_INCLUDED

    class MSBoardTextView{

    MinesweeperBoard& board;

    public:
        MSBoardTextView(MinesweeperBoard& board);
        void display();

    };




#endif // MSBOARDTEXTVIEW_H_INCLUDED

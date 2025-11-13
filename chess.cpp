#include <bits/stdc++.h>
using namespace std;
enum Color {White,Black};
class piece{
    protected:
       Color color;
    public:
       virtual bool isValid(int sx,int sy,int dx,int dy)=0;
       virtual char getSymbol()=0;
       virtual ~piece();                
};
class Rook:public piece{
    public:
    Rook(Color c){
        color=c;
    }
    bool isValid (int sx,int sy,int dx,int dy) override{
        return (sx==sy || dx==dy);
    }
    char getSymbol() override{
        return (color==White?'R':'r');
    }
};
class Bishop:public piece{
    public:
    Bishop(Color c){
        color=c;
    }
    bool isValid (int sx,int sy,int dx,int dy) override{
        return (abs(sx-dx)==abs(sy-dy));
    }
    char getSymbol() override{
        return (color==White?'B':'b');
    }
};
class Board{
    piece *board[8][8];
    public:
       Board(){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                board[i][j]=nullptr;
            }
        }
        board[0][0] = new Rook(White);
        board[7][7] = new Rook(Black);
        // add bishops
        board[0][2] = new Bishop(White);
        board[7][5] = new Bishop(Black);

       }

    void printBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j])
                    cout << board[i][j]->getSymbol() << " ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }

    void movePiece(int sx,int sy,int dx,int dy){
        if(!board[sx][sy]){
            cout<<"No pieces at sources";
            return;
        }
        if(board[sx][sy]->isValid(sx,sy,dx,dy)){
            cout<<"Valid move";
            board[dx][dy]=board[sx][sy];
            board[sx][sy]=nullptr;
        }
        else{
            cout<<"Invalid move";
        }
    }
    ~Board(){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                delete board[i][j];
            }
        }
    }
};    
int main(){
    Board chess;
    chess.printBoard();
    chess.movePiece(0, 0, 0, 5); // valid rook move
    chess.printBoard();
    return 0;
}
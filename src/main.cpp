#include <vector>
#include <iostream>
using namespace std;

class snake{

};
class player{

};




class game{
            vector<vector<char>> board
    {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    public:
    //holds x and y values of map

    void run(){
        cout << "game running" << '\n';
    }
    void begin(){
    }
    void display(){
        for (int i =0; i < board.size();i++){
            for(int k=0; k < board[i].size(); k++){
                cout << board[i][k] << " ";
            }
            cout << '\n';
        }
    }
};

int main(){


    game main;
    main.run();
    main.display();

}
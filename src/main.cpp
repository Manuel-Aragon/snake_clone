#include <vector>
#include <iostream>

using namespace std;

enum direction{
    north,
    south,
    west,
    east
};

class snake{
    //length of snake
    int length;
    //variable to hold current direction
    direction facing;
    //variable that holds current body position on board
    vector<vector<bool>> body;
    //moves snake based on the direction the snake is facing 
    bool move(){}
    //changes direction of snake
    bool change(direction){}
    //increases the length of the snake
    bool increase(){};
    /*returns true if the snake collided with itself
    or the border*/
    bool collided(){};
    snake(){
        length = 1;
        facing = north;
    }
};


class game{
    private:
    //holds x and y values of map
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
    //snake instance

    int score = 0;
    int high_score = 0;
    bool end_game = false;

    public:
    //increases score by 1
    void increaseScore(){

    }
    //changes high score
    void newHighScore(int new_score){
        high_score = new_score;
    }
    /*starts the game.
    Loops and continuously updates the display while
    waiting for user input. 
    */
    void run(){
        while(!end_game){
            display();
        }
    }
    //resets initial values of game
    void reset(){
    }
    /*displays current value to screen,
    called 60 times a second
    */
    void display(){
        cout << "Score:" << score << '\n';
        for (int i =0; i < board.size();i++){
            for(int k=0; k < board[i].size(); k++){
                cout << board[i][k] << " ";
            }
            cout << '\n';
        }
    }
    /*will call the snakes collided function
    and if the result is true call the endGame
    function.*/
    void checkCollision(){
    }
    //ends game and updates high score 
    void endGame(){
    }
};

int main(){
    game main;
    main.run();
}
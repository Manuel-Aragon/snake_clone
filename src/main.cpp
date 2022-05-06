#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <cstdlib>

#include "input.h"

using namespace std;

enum direction{
    north,
    south,
    west,
    east
};

class Snake{
    //length of snake
    int length;
    //variable to hold current direction
    direction facing;
    //variable that holds current body position on board
    vector<vector<int>> body;
    //moves snake based on the direction the snake is facing 
    public:
    bool move(){}
    //changes direction of snake
    bool change(direction){}
    //increases the length of the snake
    bool increase(){};
    /*returns true if the snake collided with itself
    or the border*/
    bool collided(){};
    bool addToBoard(vector<vector<char>> &board){
        for (auto i: body){
            board[i[0]][i[1]] = 's'; 
        }
    }
    Snake(vector<vector<char>> &board){
        length = 1;
        facing = north;
        body.push_back(vector<int>{5,5});
        addToBoard(board);
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

    vector<char> game_over_text{'#', 
    'G','A','M','E','O','V','E','R','#'};

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

    void input(Snake s){
        switch (key_press())
		{
		case 'w':
			s.change(north);
			break;
		case 'a':
			s.change(west);
			break;
		case 's':
			s.change(south);
			break;
		case 'd':
			s.change(east);
			break;
		case 'x':
			end_game = true;
			break;
		}
    }
    /*starts the game.
    Loops and continuously updates the display while
    waiting for user input. 
    */
    void run(){
        Snake player(board);
        reset();
        while(!end_game){
            display();
            input(player);
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
        endGame();
        cout << "exited game\n";
    }
    //resets initial values of game
    void reset(){

    }
    /*displays current value to screen,
    called 60 times a second
    */
    void display(){
        cout << "Score:" << score << '\n';
        //display board
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
        //add end game screen
        board[5]= game_over_text;
        display();
    }
};

int main(){
    game main;
    main.run();
}
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "input.h"
#include "tools.h"
using namespace std;

enum direction{
    north,
    south,
    west,
    east
};

struct Coordinate{
    int x = -1;
    int y = -1;
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
    bool move();
    //changes direction of snake
    bool change(direction new_facing){
        facing = new_facing;
        return true;
    }
    //increases the length of the snake
    bool increase();
    /*returns true if the snake collided with itself
    or the border*/
    bool collided();
    bool addToBoard(vector<vector<char>> &board){
        for (auto i: body){
            board[i[0]][i[1]] = 's'; 
        }
        return true;
    }
    Snake(vector<vector<char>> &board){
        length = 1;
        facing = north;
        body.push_back(vector<int>{5,5});
        addToBoard(board);
    }
};

class Fruit{
    Coordinate position;
    public:
    //default constructors
    
    /*spawns the fruit and adds it to the board
    returns Coordinate holding location on board*/
    Coordinate spawn(vector<vector<char>> &board){
        bool board_collision = true;
        bool snake_collision = true;
        debug("before loop");
        //TODO: CHECK IF INFINITE LOOP
        while(board_collision || snake_collision){
            debug("before cond");
            position.x = rand() % 10;    //10 = board width
            position.y = rand() % 10;    //10 = board height
            //check if spawn location is valid
            board_collision = (board[position.x][position.y] == '#');
            snake_collision = (board[position.x][position.y] == 's');
        }
        debug(to_string(position.x));
        debug(to_string(position.y));
        debug(board[position.x][position.y]);
        board[position.x][position.y] = 'a';    //add to board
        debug(board[position.x][position.y]);
        return position;
    }
};


class Game{
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

    vector<char> game_over_text{'#', 
    'G','A','M','E','O','V','E','R','#'};
    vector<char> game_over_score{'#', 
    'S','C','O','R','E',':','0','0','#'};

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
        //debug("start of run");
        reset();
        debug("after reset");
        Snake player(board);
        Fruit apple;
        apple.spawn(board);
        std::this_thread::sleep_for(std::chrono::seconds(10));
        display();

        debug("after spawn");
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
        //reset board
        board ={
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

    }
    /*displays current value to screen,
    called 60 times a second
    */
    void display(){
        system("clear");
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
        board[6] = game_over_score;
        display();
    }
};



int main(){
    Game().run();   //starts game
}
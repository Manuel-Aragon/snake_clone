#include <vector>
using namespace std;
CSCE 3110 -Data Structures & ALogirthms Project Update
Snake Clone by Manuel Aragon


/*This class will hold all the information about the snake and a
instance will be updated as the game is played.*/
class snake{
    //length of snake
    int length;
    //variable to hold current direction
    enum direction;
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
};

/*This class holds information about the snakes target and its
current location on the board.*/
class objective{
    //holds location
    vector<vector><char>> location;
    /*randomizes a new location for the
    object and returns the new location*/
    int newLocation(){
    }
}

/*This class holds all the game logic. It has functions to
start the game, reset it, and end it once it is over.
It holds instances of the snake and the objective and 
updates their position on the board as the game is played.*/
class game{
    //holds x and y values of map
    vector<vector<char>> board;
    //snake instance
    snake
    //objective instance
    objective
    int score
    int high_score
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
    }
    //resets initial values of game
    void reset(){
    }
    /*displays current value to screen,
    called 60 times a second
    */
    void display(){
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

    //starts new instance of game
    game main;
    main.run();
}
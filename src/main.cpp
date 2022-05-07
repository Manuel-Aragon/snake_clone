#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <string>
#include <future>

#include "input.h"
#include "tools.h"
struct Coordinate{
    int x = -1;
    int y = -1;
};
struct Fruit{
	int x;
	int y;
	void spawn(int width, int height){
		x = rand() % width;
		y = rand() % height;
	};
};

using namespace std;
class Game{
	public:

	double SPEED = 9.5;
	bool gameOver;
	const int width = 20;
	const int height = 20;
	Fruit fruit;
	int x, y, score, high_score;
	vector<Coordinate> tail;
	int length;
	enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
	eDirecton dir;


void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruit.spawn(width, height);
	score = 0;
	int length = 1;
	tail = {{-1, -1}};
}
void Parse(char key)
{
        switch (key)
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
}
void Draw()
{
	system("clear");
		cout << "Score:" << score
	<< "    High Score:" << high_score << '\n';
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << 'O';
			else if (i == fruit.y && j == fruit.x)
				cout << 'a';
			else{
				bool print = false;
				for (int k = 0; k < length; k++){
					if (tail[k].x == j && tail[k].y == i){
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
				

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}


void Logic()
{
	if (length >= 1){

		//
		int prevX = tail[0].x;
		int prevY = tail[0].y;
		int prev2X, prev2Y;
		tail[0] = {x, y};

		for (int i = 1; i < length; i++)
		{
			prev2X = tail[i].x;
			prev2Y = tail[i].y;
			tail[i] = {prevX, prevY};
			prevX = prev2X;
			prevY = prev2Y;
		}
	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	//rollover snake to otherside of the screen
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	// if snake collides with itself, GAMEOVER
    for (int i = 0; i < length; i++){
		if (tail[i].x == x && tail[i].y == y)
			gameOver = true;
	}

	//snake gets fruit
	if (x == fruit.x && y == fruit.y){
		score += 10;
		if (score > high_score){
			high_score = score;
		}
		fruit.x = rand() % width;
		fruit.y = rand() % height;
		if (length < 10){
			length++;
		}
		tail.push_back({x, y});
	}
}
bool endGame(){
	//add end game screen
	std::cout << "GAME OVER" << '\n';
	std::cout << "Press space to play again" << '\n';
	std::cout << "Press x to exit" << '\n';
	while(1){
		std::this_thread::sleep_for(std::chrono::microseconds(100));
		int key = Input();
		if (key == ' '){
			return false;
		}
		else if (key == 'x'){
			return true;
		}
	}
}
void run(){
	Setup();
	Draw();
	while (!gameOver)
	//TODO GAME GETS FASTER
	{
		const int ms = 1/ SPEED * 1000000;	//micro
		std::chrono::microseconds span(ms);
		int key = Input();
		Parse(key);
		Logic();
		std::this_thread::sleep_for (span);
		Draw();
	}
}
	void Start(){
		bool exit = false;
		while(!exit){
			run();
			exit = endGame();
		}
	}
};


int main(){
	Game().Start();
}
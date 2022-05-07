#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <string>
#include <future>


#include "input.h"
#include "tools.h"


using namespace std;
class Game{
	public:
	const double SPEED = 10;
	bool gameOver;
	const int width = 20;
	const int height = 20;
	struct Fruit{
		int x;
		int y;
	};
	Fruit fruit;
	int x, y, score, high_score;
	vector<int> tailX;    
	vector<int> tailY;
	int length;
	enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
	eDirecton dir;


void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	
	fruit.x = rand() % width;
	fruit.y = rand() % height;
	score = 0;
	int length = 1;
	tailX = {-1};
	tailY = {-1};
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
				cout << "O";
			else if (i == fruit.y && j == fruit.x)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < length; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
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
		int prevX = tailX[0];
		int prevY = tailY[0];
		int prev2X, prev2Y;
		tailX[0] = x;
		tailY[0] = y;
		for (int i = 1; i < length; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
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

	//rollover
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < length; i++){
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}


	if (x == fruit.x && y == fruit.y)
	{
		score += 10;
		if (score > high_score){
			high_score = score;
		}
		fruit.x = rand() % width;
		fruit.y = rand() % height;
		length++;
		debug(length);
		tailX.push_back(x);
		debug(tailX.back());
		tailY.push_back(y);
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
		//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now() + span;
		//std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
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
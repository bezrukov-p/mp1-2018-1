#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <fstream> 
#include <string>
#include <vector>
#include <locale.h> 
#include <windows.h>
using namespace std;

//void SetColor(int text, int background)
//{
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
//}

enum eDirection {STOP = 0,LEFT,RIGHT,UP,DOWN};

struct XY {
	int x;
	int y;

	bool operator == (const XY &xy) const
	{
		if (this->x == xy.x && this->y == xy.y)
			return true;
		else
			return false;
	}
};

class GameSnake
{
	bool gameOver;
	bool gameWin;
	vector<XY> snake;
	XY fruit;
	eDirection dir;

	int width;
	int height;

	int snake_win;
	int speed;

	bool snake_xy;
public:

	bool GameOver(){
		return gameOver;
	}

	bool GameWin() {
		return gameWin;
	}

	void Draw(){
		system("cls");
		for (int i = 0; i < width + 4; i++) {
			cout << "#";
		}
		cout << endl;
		for (int i = 0; i < width + 4; i++) {
			cout << "#";
		}
		cout << endl;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width + 4; j++) {
				snake_xy = false;
				for (int k = 0; k < snake.size(); k++) {
					if (i == snake[k].y - 1 && j == snake[k].x + 1) {
						if (k == 0)
							cout << "0";
						else
							cout << "o";
						snake_xy = true;
					}
				}
				if (!snake_xy) {
					if (i == fruit.y - 1 && j == fruit.x + 1)
						cout << "F";
					else if (j == 0 || j == 1 || j == width + 2 || j == width + 3)
						cout << "#";
					else
						cout << " ";
				}
			}
			cout << endl;
		}

		for (int i = 0; i < width + 4; i++)
			cout << "#";
		cout << endl;
		for (int i = 0; i < width + 4; i++)
			cout << "#";
		cout << endl << endl;

		cout << "Width:" << width << endl;
		cout << "Height:" << height << endl;
		cout << "The length of the snake to win:" << snake_win << endl;
		cout << "Length snake now:" << snake.size() << endl;
		cout << "Speed(sec):" << speed / 1000 << endl;
		cout << "Press 'x' to exit" << endl;
	}

	void Setup(int _width,int _height,int _length_win,int _speed) {
		dir = STOP;
		gameOver = false;
		gameWin = false;
		speed = _speed;
		width = _width;
		height = _height;
		snake_win = _length_win;
	    SnakeRand();
		FruitRand();
	}

	void Input() {
		Sleep(speed);
		if (_kbhit()) {
			switch (_getch())
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
	}

	void Logic()
	{
		XY snake_2;
		snake_2 = snake[0];
		bool fruit_eat = false;
		if (snake[0] == fruit) {
			fruit_eat = true;
			FruitRand();
		}

		switch (dir)
		{
		case LEFT:
			snake[0].x--;
			break;
		case RIGHT:
			snake[0].x++;
			break;
		case UP:
			snake[0].y--;
			break;
		case DOWN:
			snake[0].y++;
			break;
		}

		if (dir != STOP)
		{
			if (fruit_eat) {
				snake.insert(snake.begin() + 1, snake_2);
			}
			else {
				snake.insert(snake.begin() + 1, snake_2);
				snake.pop_back();
			}
		}

		for (int i = 1; i < snake.size(); i++) {
			if (snake[i] == snake[0]) {
				gameOver = true;
				return;
			}
		}

		if (snake[0].x < 1 || snake[0].x>width || snake[0].y < 1 || snake[0].y > height)
			gameOver = true;
		if (snake_win == snake.size())
			gameWin = true;
	}

	void SnakeRand() {
		int x, y;
		x = rand() % (width-4) + 1;
		y = rand() % height + 1;
		snake.push_back({ x,y });
		for (int i = 1; i < 5; i++) {
			x++;
			snake.push_back({ x,y });
		}
	}

	void FruitRand() {
	fruitRand:
		fruit.x = rand() % width + 1;
		fruit.y = rand() % height + 1;
		for (int i = 0; i < snake.size(); i++) {
			if (fruit == snake[i])
				goto fruitRand;
		}
	}

};

int main()
{
	srand(time(0));
	int width;
	int height;
	int length_win;
	double speed;
	GameSnake gameSnake;

	cout << "Wight:";
	cin >> width;
	cout << "Height:";
	cin >> height;
	cout << "The length of the snake to win:";
	cin >> length_win;
	cout << "Speed(sec):";
	cin >> speed;
	speed *= 1000;
    gameSnake.Setup(width,height,length_win,speed);
	/*gameSnake.Setup(13, 7, 10,300);*/

	while (!gameSnake.GameOver() && !gameSnake.GameWin()){
		gameSnake.Draw();
		gameSnake.Input();
		gameSnake.Logic();
	}
	if (gameSnake.GameOver()) {
		cout << "GAME OVER" << endl;
	}
	if (gameSnake.GameWin()) {
		cout << "GAME WIN" << endl;
	}
	system("pause");
	return 0;
}
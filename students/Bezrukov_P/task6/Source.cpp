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
using namespace std;

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
	vector<XY> snake;
	XY fruit;
	int width;
	int height;
	int length_win;
	int length_snake;
public:
	/*GameSnake() {
		gameOver = false;
	}*/

	bool GameOver(){
		return gameOver;
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
				if (i == snake[0].y / 2 && j == snake[0].x/2)
					cout << "o";
				else if(i == fruit.y - 1 && j == fruit.x + 2)
					cout << "F";
				else if (j == 0 || j == 1 || j == width +2 || j == width + 3 )
					cout << "#";
				else
					cout << " ";
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
		cout << "The length of the snake to win:" << length_win << endl;
		cout << "Length snake now:" << length_snake << endl;
	}

	void Setup(int _width,int _height,int _length_win) {
		gameOver = false;
		width = _width;
		height = _height;
		length_win = _length_win;
	    SnakeRand();
	fruitRand: FruitRand();
		for (int i = 0; i < snake.size(); i++) {
			if (fruit == snake[i])
				goto fruitRand;
		}
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
		fruit.x = rand() % width + 1;
		fruit.y = rand() % height + 1;
	}

};

int main()
{
	srand(time(0));
	/*int width;
	int height;
	int length_win;*/
	GameSnake gameSnake;

	/*cout << "Wight:";
	cin >> width;
	cout << "Height:";
	cin >> height;
	cout << "The length of the snake to win:";
	cin >> length_win;
    gameSnake.Setup(width,height,length_win);*/
	gameSnake.Setup(19, 19, 10);

	while (!gameSnake.GameOver()) {
		gameSnake.Draw();
	}
	return 0;
}
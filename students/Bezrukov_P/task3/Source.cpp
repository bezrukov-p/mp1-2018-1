#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

class TranslatorDictionary
{
	char** eng;
	char** rus;
	int value;
public:

	TranslatorDictionary(int i = 300)
	{
		eng = new char*[i];
		rus = new char*[i];
	}


};

int main()
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	int a;
	char eng[100];
	char rus[100];	TranslatorDictionary dictionary;
	cout << "1.Добавить в словарь слово и его перевод" << endl;
	cout << "2.Изменить перевод указанного слова" << endl;
	cout << "3.Узнать перевод выбранного слова" << endl;
	cout << "4.Проверить наличие слова в словаре" << endl;
	cout << "5.Узнать число слов в словаре" << endl;
	cout << "6.Сохранить словарь в файл" << endl;
	cout << "7.Считать словарь из файла" << endl;
	cout << "8.Выход" << endl << endl;
	while (x == 0)
	{
		cout << "Выберите пункт меню: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "Введите слово на английском: " << endl;

			cout << "Введите слово на русском: " << endl;
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			exit(EXIT_SUCCESS);
			break;
		}
		}
	}

}
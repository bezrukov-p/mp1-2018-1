#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <fstream> 
using namespace std;

class TranslatorDictionary
{
	char **eng;
	char **rus;
	int size;
public:

	TranslatorDictionary(int _size = 0)
	{
		size = _size;
		eng = new char*[size];
		rus = new char*[size];
	}

	void IncreaseSize()
	{
		int i;
		char **_eng;
		char **_rus;
		_eng = new char*[size];
		_rus = new char*[size];
		for (i = 0; i < size; i++)
		{
			_eng[i] = eng[i];
			_rus[i] = rus[i];
		}
		delete[]eng;
		delete[]rus;
		eng = new char*[size + 1];
		rus = new char*[size + 1];
		for (i = 0; i < size; i++)
		{
			eng[i] = _eng[i];
			rus[i] = _rus[i];
		}
		delete[]_eng;
		delete[]_rus;
		size++;
	}

	void AddWordAndTranslation(char *_eng_in, char *_rus_in)
	{
		IncreaseSize();
		eng[size - 1] = new char[strlen(_eng_in) + 1];
		rus[size - 1] = new char[strlen(_rus_in) + 1];
		strcpy(eng[size - 1], _eng_in);
		strcpy(rus[size - 1], _rus_in);
	}

	/*char GetTranslate(char *eng_in)//
	{
	for (int i = 0; i < size; i++)
	{
	if (!strcmp(eng[i],eng_in))
	}
	}*/

	int NumberOfWords()
	{
		return size;
	}

	void SaveInFile()
	{
		ofstream dictionary;
		dictionary.open("dictionary.txt");
		dictionary << "Количество слов: " << size << endl;
		for (int i = 0; i < size; i++)
		{
			dictionary << eng[i] << "  " << rus[i] << endl;
		}
		dictionary.close();
	}

	void PrintDictionary()
	{
		for (int i = 0; i < size; i++)
		{
			cout << eng[i] << "  " << rus[i] << endl;
		}
	}

	~TranslatorDictionary()
	{
		delete[]eng;
		delete[]rus;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	int a;
	char eng_in[100];
	char rus_in[100];
	TranslatorDictionary dictionary;
	cout << "1.Добавить в словарь слово и его перевод" << endl;//
	cout << "2.Изменить перевод указанного слова" << endl;
	cout << "3.Узнать перевод выбранного слова" << endl;
	cout << "4.Проверить наличие слова в словаре" << endl;
	cout << "5.Узнать число слов в словаре" << endl;
	cout << "6.Сохранить словарь в файл" << endl;
	cout << "7.Считать словарь из файла" << endl;
	cout << "8.Вывести словарь на консоль" << endl;
	cout << "9.Выход" << endl << endl;
	while (x == 0)
	{
		cout << "Выберите пункт меню: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "Введите слово на английском: ";
			cin >> eng_in;
			cout << "Введите слово на русском: ";
			cin >> rus_in;
			dictionary.AddWordAndTranslation(eng_in, rus_in);
			cout << "Сохранено " << endl << endl;
			break;
		}
		case 2:
		{
			cout << "Введите слово,перевод которого хотите изменить: ";
			cin >> eng_in;
			cout << "Введите новый перевод: ";
			cin >> rus_in;
			break;
		}
		case 3:
		{
			cout << "Введите слово,перевод которого вы хотите узнать: ";
			cin >> eng_in;
			cout << "Его перевод: ";
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Введите слово,наличие которого вы хотите проверить: ";
			cin >> eng_in;

			break;
		}
		case 5:
		{
			cout << "Число слов в словаре:" << dictionary.NumberOfWords() << endl << endl;
			break;
		}
		case 6:
		{
			dictionary.SaveInFile();
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			exit(EXIT_SUCCESS);
			break;
		}
		}
	}

}
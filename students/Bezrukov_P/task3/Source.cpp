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

	TranslatorDictionary(const TranslatorDictionary &dict)
	{
		size = dict.size;
		eng = new char*[size];
		rus = new char*[size];
		for (int i = 0; i < size; i++)
		{
			eng[i] = new char[strlen(dict.eng[i]) + 1];
			rus[i] = new char[strlen(dict.rus[i]) + 1];
		}
		for (int i = 0; i < size; i++)
		{
			strcpy(eng[i], dict.eng[i]);
			strcpy(rus[i], dict.rus[i]);
		}
	}

	TranslatorDictionary& operator=(const TranslatorDictionary &dict)
	{
		if (this == &dict)
			 return *this;
		else 
		{
			for (int i = 0; i<size; i++)
				delete[] eng[i];
			delete[] eng;
			for (int i = 0; i<size; i++)
				delete[] rus[i];
			delete[] rus;
			size = dict.size;
			eng = new char*[size];
			rus = new char*[size];
			for (int i = 0; i < size; i++)
			{
				eng[i] = new char[strlen(dict.eng[i]) + 1];
				rus[i] = new char[strlen(dict.rus[i]) + 1];
			}
			for (int i = 0; i < size; i++)
			{
				strcpy(eng[i], dict.eng[i]);
				strcpy(rus[i], dict.rus[i]);
			}
			return *this;
		}
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

	int SearchDictionary(char *eng_in,char *rus_in)
	{
		for (int i = 0; i < size; i++)
		{
			if ((strcmp(eng[i], eng_in) == 0)&(strcmp(rus[i], rus_in) == 0))
			{
				return i;
			}
		}
		return -1;
	}

	void ChangeTranslation(int i,char *rus_in)
	{
		strcpy(rus[i], rus_in);
	}

	int SearchDictionaryIndex(int i,char *eng_in)
	{
		if ((strcmp(eng[i], eng_in) == 0))
		{
			return i;
		}
		else
			return -1;
	}

	char* GetTranslation(int i)
	{
		return rus[i];
	}

	bool CheckWordEng(char *eng_in)
	{
		for (int i = 0; i < size; i++)
		{
			if (strcmp(eng[i], eng_in) == 0)
				return true;
		}
			return false;
	}

	int NumberOfWords()
	{
		return size;
	}

	void SaveInFile()
	{
		ofstream dictionary;
		dictionary.open("dictionary.txt");
		dictionary << "Количество cлов: " << size << endl;
		for (int i = 0; i < size; i++)
		{
			dictionary << eng[i] << "  " << rus[i] << endl;
		}
		dictionary.close();
	}

	void LoadFromFile()
	{
		char x[300];
		char y[300];
		ifstream dictionary;
		dictionary.open("dictionary.txt");
		dictionary.getline(x, 300, ' ');
		dictionary.getline(x, 300, ' ');
		dictionary.getline(x, 300, '\n');
		size = atoi(x);
		eng = new char*[size];
		rus = new char*[size];
		for (int i = 0; i < size; i++)
		{
			dictionary.getline(y, 300, ' ');
			eng[i] = new char[strlen(y) + 1];
			strcpy(eng[i], y);
			dictionary.getline(y, 300, '\n');
			rus[i] = new char[strlen(y) + 1];
			strcpy(rus[i], y);
		}
		dictionary.close();
	}

	void PrintDictionary()
	{
		cout << "Число слов в словаре:" << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << eng[i] << "  " << rus[i] << endl;
		}
	}

	~TranslatorDictionary()
	{
		for(int i = 0; i<size; i++)
			delete[] eng[i];
		delete[] eng;
		for (int i = 0; i<size; i++)
			delete[] rus[i];
		delete[] rus;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	int a;
	int i = 0;
	char eng_in[100];
	char rus_in[100];
	char rus_in_2[100];
	TranslatorDictionary dictionary;
	cout << "Словарь пуст" << endl;
	cout << "1.Добавить в словарь слово и его перевод" << endl;//
	cout << "2.Изменить перевод указанного слова" << endl;//
	cout << "3.Узнать перевод выбранного слова" << endl;//
	cout << "4.Проверить наличие слова в словаре" << endl;//
	cout << "5.Узнать число слов в словаре" << endl;//
	cout << "6.Сохранить словарь в файл" << endl;//
	cout << "7.Считать словарь из файла" << endl;
	cout << "8.Вывести словарь на консоль" << endl;
	cout << "9.Очистить историю в консоли" << endl;
	cout << "10.Выход" << endl << endl;
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
			cout << "Введите его настоящий перевод: ";
			cin >> rus_in;
			cout << "Введите новый перевод: ";
			cin >> rus_in_2;
			i = dictionary.SearchDictionary(eng_in, rus_in);
			if (i >= 0)
			{
					dictionary.ChangeTranslation(i,rus_in_2);
					cout << "Перевод изменён" << endl;
			}
			else
				cout << "Такого перевода нет в словаре" << endl;
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Введите слово,перевод которого вы хотите узнать: ";
			cin >> eng_in;
			if (dictionary.CheckWordEng(eng_in))
			{
				for (i = 0; i < dictionary.NumberOfWords(); i++)  //Врядли это считается правильным,но по-другому не знаю как
				{
					if(dictionary.SearchDictionaryIndex(i,eng_in)>=0)
					cout << "Его перевод: " << dictionary.GetTranslation(i) << endl;
				}
			}
			else
				cout << "Такого слова нет в словаре" << endl;
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Введите слово,наличие которого вы хотите проверить: ";
			cin >> eng_in;
			if (dictionary.CheckWordEng(eng_in))
				cout << "Есть в словаре " << endl;
			else
				cout << "Нет в словаре " << endl;
			cout << endl;
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
			cout << "Сохранено" << endl << endl;
			break;
		}
		case 7:
		{
			dictionary.LoadFromFile();
			cout << "Загружено" << endl << endl;
			break;
		}
		case 8:
		{
			dictionary.PrintDictionary();
			cout << endl;
			break;
		}
		case 9:
		{
			system("cls");
			cout << "Число слов в словаре:" << dictionary.NumberOfWords() << endl;
			cout << "1.Добавить в словарь слово и его перевод" << endl;
			cout << "2.Изменить перевод указанного слова" << endl;
			cout << "3.Узнать перевод выбранного слова" << endl;
			cout << "4.Проверить наличие слова в словаре" << endl;
			cout << "5.Узнать число слов в словаре" << endl;
			cout << "6.Сохранить словарь в файл" << endl;
			cout << "7.Считать словарь из файла" << endl;
			cout << "8.Вывести словарь на консоль" << endl;
			cout << "9.Очистить историю в консоли" << endl;
			cout << "10.Выход" << endl << endl;
			break;
		}
		case 10:
		{
			exit(EXIT_SUCCESS);
			break;
		}
		}
	}

}
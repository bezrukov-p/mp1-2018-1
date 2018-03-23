#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <fstream> 
#include <string>
using namespace std;

//Класс должен хранить историю наблюдений за показаниями веса членов семьи (до пяти человек). Показания описываются датой (день, месяц, год) и именем члена семьи.
//При поступлении нового наблюдения для уже существующей даты старое наблюдение заменяется. Вес задается в килограммах с точностью до 50 граммов.
//Класс должен предоставлять следующие операции : 1) установить начальную дату наблюдений, 2) узнать начальную дату наблюдений, 3) задать наблюдение, 
//4) узнать вес в выбранном наблюдении, 5) найти средний вес члена семьи в выбранном месяце или за всю историю наблюдений, 
//6) найти минимальный вес члена семьи в выбранном месяце или за всю историю наблюдений и дату, когда он наблюдался 
//7) найти максимальный вес члена семьи в выбранном месяце или за всю историю наблюдений и дату, когда он наблюдался, 8) сохранить историю наблюдений в файл, 
//9) считать историю наблюдений из файла.

struct _data
{
	int day;
	int month;
	int year;
	_data& operator = (const _data &data)
	{
		this->day = data.day;
		this->month = data.month;
		this->year = data.year;
		return *this;
	}
	bool operator == (const _data &data) const
	{
		if (this->day == data.day && this->month == data.month && this->year == data.year)
			return true;
		else
			return false;
	}
};

class Scale
{
	_data *data;
	string name;
	double *weight;
	int size;
	int i_m;
public:

	Scale(string _name = "name")
	{
		name = _name;
		size = 0;
	}

	Scale(const Scale &sc)//
	{
		size = sc.size;
		name = sc.name;
		data = new _data[size];
		weight = new double[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = sc.data[i];
			weight[i] = sc.weight[i];
		}
	}

	Scale& operator=(const Scale &sc)//
	{
		if (this == &sc)
			return *this;
		else
		{
			delete[]data;
			delete[]weight;
			size = sc.size;
			name = sc.name;
			data = new _data[size];
			weight = new double[size];
			for (int i = 0; i < size; i++)
			{
				data[i] = sc.data[i];
				weight[i] = sc.weight[i];
			}
			return *this;
		}
	}

	void IncreaseSize()
	{
		_data *data2;
		double *weight2;
		data2 = new _data[size];
		weight2 = new double[size];
		for (int i = 0; i < size; i++)
		{
			data2[i] = data[i];
			weight2[i] = weight[i];
		}
		if (size != 0)
		{
			delete[]data;
			delete[]weight;
		}
		data = new _data[size + 1];
		weight = new double[size + 1];
		for (int i = 0; i < size; i++)
		{
			data[i] = data2[i];
			weight[i] = weight2[i];
		}
		delete[]data2;
		delete[]weight2;
		size++;
	}

	void KnowStartData() const//
	{
		cout << data[0].day << "." << data[0].month << "." << data[0].year << endl;
	}

	double GetWeight(_data _data1)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == _data1)
				return weight[i];
		}
		return 0;
	}

	bool CheckName(string _name) const//
	{
		if (name == _name)
			return true;
		else
			return false;
	}

	void ChangeName(string _name)
	{
		name = _name;
	}

	bool CheckData(_data _data1) const
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == _data1)
				return true;
		}
		return false;
	}

	int GetSize()
	{
		return size;
	}

	bool SetData(_data _data1, double _weight)
	{
		IncreaseSize();
		for (int i = 0; i < size - 1; i++)
		{
			if (data[i] == _data1)
			{
				weight[i] = _weight;
				return true;
			}
		}
		data[size - 1] = _data1;
		weight[size - 1] = _weight;
		return false;
	}

	double AverageWeight(int _month = 0, int _year = 0)
	{
		double av_weight = 0;
		int _size = 0;
		if ((_month == 0) && (_year == 0))
		{
			for (int i = 0; i < size; i++)
			{
				av_weight += weight[i];
			}
			return av_weight / size;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if ((data[i].month == _month) && (data[i].year == _year))
				{
					_size++;
					av_weight += weight[i];
				}
			}
			if (_size == 0)
				return 0;
			else
				return av_weight / _size;
		}
	}

	double MinWeight(int _month = 0, int _year = 0)
	{
		double min_weight = 0;
		if ((_month == 0) && (_year == 0))
		{
			min_weight = weight[0];
			i_m = 0;
			for (int i = 0; i < size; i++)
			{
				if (weight[i] < min_weight)
				{
					min_weight = weight[i];
					i_m = i;
				}
			}
			return min_weight;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if ((data[i].month == _month) && (data[i].year == _year))
				{
					min_weight = weight[i];
					break;
				}
			}
			if (min_weight == 0)
				return 0;
			else
			{
				for (int i = 0; i < size; i++)
				{
					if ((data[i].month == _month) && (data[i].year == _year))
					{
						if (weight[i] < min_weight)
						{
							min_weight = weight[i];
							i_m = i;
						}
					}
				}
			}
			return min_weight;
		}
	}

	double MaxWeight(int _month = 0, int _year = 0)
	{
		double max_weight = 0;
		if ((_month == 0) && (_year == 0))
		{
			max_weight = weight[0];
			i_m = 0;
			for (int i = 0; i < size; i++)
			{
				if (weight[i] > max_weight)
				{
					max_weight = weight[i];
					i_m = i;
				}
			}
			return max_weight;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if ((data[i].month == _month) && (data[i].year == _year))
				{
					max_weight = weight[i];
					break;
				}
			}
			if (max_weight == 0)
				return 0;
			else
			{
				for (int i = 0; i < size; i++)
				{
					if ((data[i].month == _month) && (data[i].year == _year))
					{
						if (weight[i] > max_weight)
						{
							max_weight = weight[i];
							i_m = i;
						}
					}
				}
			}
			return max_weight;
		}
	}

	void PrintDataMinMax() const
	{
		cout << data[i_m].day << "." << data[i_m].month << "." << data[i_m].year << endl;
	}

	void SaveInFile()
	{

	}

	void LoadFromFile()
	{

	}

	~Scale()
	{
		delete[] weight;
		delete[] data;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	int x = 0;
	int a;
	_data data;
	double weight;
	int month;
	int year;
	string name;
	int j = -1;
	int k = 0;
	Scale scale[5];
menu2:
	cout << "1.Добавить члена семьи" << endl;
	cout << "2.Выбрать члена семьи" << endl;
	cout << "3.Установить начальную дату наблюдений" << endl;
	cout << "4.Узнать начальную дату наблюдений" << endl;
	cout << "5.Задать наблюдение" << endl;
	cout << "6.Узнать вес в выбранном наблюдении" << endl;
	cout << "7.Найти средний вес члена семьи" << endl;
	cout << "8.Найти минимальный вес члена семьи" << endl;
	cout << "9.Найти максимальный вес члена семьи" << endl;
	cout << "10.Cохранить историю наблюдений в файл" << endl;
	cout << "11.Cчитать историю наблюдений из файла" << endl;
	cout << "12.Очистить консоль" << endl;
	cout << "13.Выход" << endl << endl;
	while (x == 0)
	{
	menu:
		cout << "Выберите пункт меню: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			if (j == 4)
			{
				cout << "Максимум 5 членов семьи" << endl << endl;
				goto menu;
			}
			cout << "Введите имя: ";
			cin >> name;
			for (int i = 0; i < 5; i++)
			{
				if (scale[i].CheckName(name))
				{
					cout << "Такое имя уже есть" << endl << endl;
					goto menu;
				}
			}
			j++;
			scale[j].ChangeName(name);
			cout << "Добавлено" << endl << endl;
			break;
		}
		case 2:
		{
			cout << "Введите имя: ";
			cin >> name;
			for (int i = 0; i < 5; i++)
			{
				if (scale[i].CheckName(name))
				{
					k = i;
					cout << "Выбрано" << endl << endl;
					goto menu;
				}
			}
			cout << "Такое имя не найдено" << endl << endl;
			break;
		}
		case 3:
		{
			cout << "Введите число: ";
			cin >> data.day;
			cout << "Введите номер месяца: ";
			cin >> data.month;
			cout << "Введите год: ";
			cin >> data.year;
			cout << "Введите значение веса(кг): ";
			cin >> weight;
			scale[k].SetData(data, weight);
			cout << "Сохранено" << endl << endl;
			break;
		}
		case 4:
		{
			if (scale[k].GetSize())
				scale[k].KnowStartData();
			else
				cout << "История наблюдений пуста" << endl;
			cout << endl;
			break;
		}
		case 5:
		{
			cout << "Введите число: ";
			cin >> data.day;
			cout << "Введите номер месяца: ";
			cin >> data.month;
			cout << "Введите год: ";
			cin >> data.year;
			cout << "Введите значение веса(кг): ";
			cin >> weight;
			if (scale[k].SetData(data, weight))
				cout << "Изменено" << endl;
			else
				cout << "Сохранено" << endl;
			cout << endl;
			break;
		}
		case 6:
		{
			if (scale[k].GetSize())
			{
				cout << "Введите число: ";
				cin >> data.day;
				cout << "Введите номер месяца: ";
				cin >> data.month;
				cout << "Введите год: ";
				cin >> data.year;
				if (scale[k].GetWeight(data))
					cout << "Значение веса= " << scale[k].GetWeight(data) << endl;
				else
					cout << "Наблюдение не найдено" << endl;
			}
			else
				cout << "История наблюдений пуста" << endl;
			cout << endl;
			break;
		}
		case 7:
		{
			if (scale[k].GetSize())
			{
				cout << "1.За всю историю наблюдений" << endl;
				cout << "2.В выбранном месяце" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "Средний вес =" << scale[k].AverageWeight() << endl;
					break;
				}
				case 2:
				{
					cout << "Введите номер месяца: ";
					cin >> month;
					cout << "Введите год: ";
					cin >> year;
					if (scale[k].AverageWeight(month, year))
						cout << "Средний вес =" << scale[k].AverageWeight(month, year) << endl;
					else
						cout << "В этом месяце нет наблюдений" << endl;
					break;
				}
				default:
				{
					cout << "Некорректный ввод." << endl;
				}
				}
			}
			else
				cout << "История наблюдений пуста" << endl;
			cout << endl;
			break;
		}
		case 8:
		{
			if (scale[k].GetSize())
			{
				cout << "1.За всю историю наблюдений" << endl;
				cout << "2.В выбранном месяце" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "Минимальный вес =" << scale[k].MinWeight() << endl;
					cout << "Дата: ";
					scale[k].PrintDataMinMax();
					break;
				}
				case 2:
				{
					cout << "Введите номер месяца: ";
					cin >> month;
					cout << "Введите год: ";
					cin >> year;
					if (scale[k].AverageWeight(month, year))
					{
						cout << "Минимальный вес =" << scale[k].MinWeight(month, year) << endl;
						cout << "Дата: ";
						scale[k].PrintDataMinMax();
					}
					else
						cout << "В этом месяце нет наблюдений" << endl;
					break;
				}
				default:
				{
					cout << "Некорректный ввод." << endl;
				}
				}
			}
			else
				cout << "История наблюдений пуста" << endl;
			cout << endl;
			break;
		}
		case 9:
		{
			if (scale[k].GetSize())
			{
				cout << "1.За всю историю наблюдений" << endl;
				cout << "2.В выбранном месяце" << endl;
				cin >> a;
				switch (a)
				{
				case 1:
				{
					cout << "Максимальный вес =" << scale[k].MaxWeight() << endl;
					cout << "Дата: ";
					scale[k].PrintDataMinMax();
					break;
				}
				case 2:
				{
					cout << "Введите номер месяца: ";
					cin >> month;
					cout << "Введите год: ";
					cin >> year;
					if (scale[k].AverageWeight(month, year))
					{
						cout << "Максимальный вес =" << scale[k].MaxWeight(month, year) << endl;
						cout << "Дата: ";
						scale[k].PrintDataMinMax();
					}
					else
						cout << "В этом месяце нет наблюдений" << endl;
					break;
				}
				default:
				{
					cout << "Некорректный ввод." << endl;
				}
				}
			}
			else
				cout << "История наблюдений пуста" << endl;
			cout << endl;
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			system("cls");
			goto menu2;
			break;
		}
		case 13:
		{
			exit(EXIT_SUCCESS);
			break;
		}
		default:
		{
			cout << "Некорректный ввод." << endl;
		}
		}
	}

}
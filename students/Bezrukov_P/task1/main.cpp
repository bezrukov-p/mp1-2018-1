#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

class ConvertorLength
{
	double length_m;  //metres

public:
	ConvertorLength(double _length_m = 0)
	{
		length_m = _length_m;
	}
	ConvertorLength & operator=(const ConvertorLength & length1)
	{
		length_m = length1.length_m;
		return *this;
	}

	void SetLengthInMetres(double _length_m)
	{
		length_m = _length_m;
	}

	double GetCurrentLengthInMetres()
	{
		return length_m;
	}

	double GetCurrentLengthInFoots()
	{
		return length_m * 3.28084;
	}

	double GetCurrentLengthInYards()
	{
		return length_m * 1.09361;
	}

	double GetCurrentLengthInInchs()
	{
		return length_m * 39.3701;
	}

	double GetCurrentLengthInMiles()
	{
		return length_m * 0.000621371;
	}

	void PrintCurrentLengthInMetres()
	{
		cout << "length=" << GetCurrentLengthInMetres() << "m \n";
	}

	void PrintCurrentLengthInFoots()
	{
		cout << "length=" << GetCurrentLengthInFoots() << "ft \n";
	}

	void PrintCurrentLengthInYards()
	{
		cout << "length=" << GetCurrentLengthInYards() << "yd \n";
	}

	void PrintCurrentLengthInInchs()
	{
		cout << "length=" << GetCurrentLengthInInchs() << "in \n";
	}

	void PrintCurrentLengthInMiles()
	{
		cout << "length=" << GetCurrentLengthInMiles() << "mi \n";
	}

};

int main()
{
	int i;
	int x = 0;
	double length_in;
	setlocale(LC_ALL, "Russian");
	ConvertorLength length, length1, length2(10);
	length1 = length2;//verification of the assignment operator
	cout << "length=0m now" << endl;
	cout << "1.Set length in metres" << endl;
	cout << "2.Get current length in metres" << endl;
	cout << "3.Get current length in foots" << endl;
	cout << "4.Get current length in yards " << endl;
	cout << "5.Get current length in inchs " << endl;
	cout << "6.Get current length in miles " << endl;
	cout << "7.Exit" << endl;
	while (x == 0)
	{
		cout << "Enter a menu item: ";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			cout << "Enter value: ";
			cin >> length_in;
			length.SetLengthInMetres(length_in);
			cout << "length=" << length_in << "m now \n";
			break;
		}
		case 2:
		{
			length.PrintCurrentLengthInMetres();
			break;
		}
		case 3:
		{
			length.PrintCurrentLengthInFoots();
			break;
		}
		case 4:
		{
			length.PrintCurrentLengthInYards();
			break;
		}
		case 5:
		{
			length.PrintCurrentLengthInInchs();
			break;
		}
		case 6:
		{
			length.PrintCurrentLengthInMiles();
			break;
		}
		case 7:
		{
			exit(EXIT_SUCCESS);
			break;
		}
		}
	}
	system("pause");
	return 0;
}
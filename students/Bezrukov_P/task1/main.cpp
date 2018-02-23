#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

class ConvertorLenght
{
	double lenght_m;  //metres
	double lenght_ft; //foot
	double lenght_yd; //yard
	double lenght_in; //inch
	double lenght_mi; //mile
	double lenght_cin;//for enter

public:
	ConvertorLenght()
	{
		lenght_m = 0;
		cout << "lenght = " << lenght_m << endl;
	}
	void SetLenghtInMetres()
	{
		cout << "Enter the length in metres: ";
		cin >> lenght_cin;
		lenght_m = lenght_cin;
	}
	void GetCurrentLenghtInMetres()
	{
		cout << "lenght=" << lenght_m << "m \n";
	}
	void GetCurrentLenghtInFoots()
	{
		lenght_ft = lenght_m * 3.28084;
		cout << "lenght=" << lenght_ft << "ft \n";
	}
	void GetCurrentLenghtInYards()
	{
		lenght_yd = lenght_m * 1.09361;
		cout << "lenght=" << lenght_yd << "yd \n";
	}
	void GetCurrentLenghtInInchs()
	{
		lenght_in = lenght_m * 39.3701;
		cout << "lenght=" << lenght_in << "in \n";
	}
	void GetCurrentLenghtInMiles()
	{
		lenght_mi = lenght_m * 0.000621371;
		cout << "lenght=" << lenght_mi << "mi \n";
	}
};

int main()
{
	int i;
	int x = 0;
	ConvertorLenght lenght;
	cout << "1.Set lenght in metres" << endl;
	cout << "2.Get current lenght in metres" << endl;
	cout << "3.Get current lenght in foots" << endl;
	cout << "4.Get current lenght in yards " << endl;
	cout << "5.Get current lenght in inchs " << endl;
	cout << "6.Get current lenght in miles " << endl;
	cout << "7.Exit" << endl;
	while (x == 0)
	{
		cout << "Enter a menu item: ";
		cin >> i;
		switch (i)
		{
		case 1:
		{
			lenght.SetLenghtInMetres();
			break;
		}
		case 2:
		{
			lenght.GetCurrentLenghtInMetres();
			break;
		}
		case 3:
		{
			lenght.GetCurrentLenghtInFoots();
			break;
		}
		case 4:
		{
			lenght.GetCurrentLenghtInYards();
			break;
		}
		case 5:
		{
			lenght.GetCurrentLenghtInInchs();
			break;
		}
		case 6:
		{
			lenght.GetCurrentLenghtInMiles();
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
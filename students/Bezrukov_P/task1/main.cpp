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
public:
	ConvertorLenght()
	{
		lenght_m = 0;
		cout << "lenght = " << lenght_m << endl;
	}
};

int main()
{
	int i;
	ConvertorLenght Lenght;
	cout << "1.Set lenght in metres" << endl;
	cout << "2.Get current lenght in metres" << endl;
	cout << "3.Get current lenght in foot" << endl;
	cout << "4.Get current lenght in yard " << endl;
	cout << "5.Get current lenght in inch " << endl;
	cout << "6.Get current lenght in miles " << endl;
	cout << "7.Exit" << " ";
	cin >> i;
	switch (i)
	{
	case 1:
	{
		system("pause");
		break;
	}
	case 2:
	{
		system("pause");
		break;
	}
	case 3:
	{
		system("pause");
		break;
	}
	case 4:
	{
		system("pause");
		break;
	}
	case 5:
	{
		system("pause");
		break;
	}
	case 6:
	{
		system("pause");
		break;
	}
	case 7:
	{
		exit(EXIT_SUCCESS);
		system("pause");
		break;
	}
	}
	system("pause");
	return 0;
}
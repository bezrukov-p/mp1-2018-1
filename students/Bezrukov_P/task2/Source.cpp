#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

class DynamicArray
{
	int array_m;
	double min;
	double *array_i;
	double *array_i_sub;
	int array_m_sub;

public:
	int i;
	int j;
	int odd;

	DynamicArray(int _array_m = 1)
	{
		array_m = _array_m;
		array_i = new double[array_m];
		for (i = 0; i < array_m; i++)
		{
			array_i[i] = 0;
		}
	}

	DynamicArray& operator=(DynamicArray &arr)
	{
			delete[] array_i;
			array_m = arr.array_m;
			array_i = new double[array_m];
			for (i = 0; i < array_m; i++)
			{
				array_i[i] = arr.array_i[i];
			}
			return *this;
	}

	void SetArraySize(int _array_m)
	{
		delete[] array_i;
		array_m = _array_m;
		array_i = new double[array_m];
		for (i = 0; i < array_m; i++)
		{
			array_i[i] = 0;
		}
	}
	
	void DisplayArraySize()
	{
		cout << " Array size=" << array_m << " now"; 
	}

	void SetElement(int i,double value)
	{
		if ((i>=0) && (i<array_m))
		array_i[i] = value;
		cout << " Incorrect index" << endl;
	}

	void DisplayElement(int i)
	{
		if ((i >= 0) && (i<array_m))
		cout << " The element at index " << i << " is equal to " << array_i[i] << endl;
		cout << " Incorrect index" << endl;
	}

	double GetMinimumElement()
	{
		min = array_i[0];
		for (i = 1; i < array_m; i++)
		{
			if (array_i[i] < array_i[i - 1])
				min = array_i[i];
		}
        return min;
	}

	void DisplayMinimumElement()
	{
		cout << " Minimal element= " << GetMinimumElement() << endl;
	}

	void CheckOrder()
	{
		int odd1 = 0;
		int odd2 = 0;
		for (i = 0; i < array_m - 1; i++)
		{
			if (array_i[i] <= array_i[i + 1])
			{
				odd1 = 0;
			}
			else
			{
				odd1 = 1;
				break;
			}

		};
		for (i = 0; i < array_m - 1; i++)
		{
			if (array_i[i] >= array_i[i + 1])
			{
				odd2 = 0;
			}
			else
			{
				odd2 = 1;
				break;
			}
		}
			if ((odd1 + odd2) == 0)
			{
				cout << " All elements are equal" << endl << endl;
			}
			else
			{
				if ((odd1 + odd2) == 2)
				{
					cout << " The array is not ordered" << endl << endl;
				}
				else
				{
					if (odd1 == 0)
					{
						cout << " The elements are ordered in ascending order" << endl << endl;
					}
					else
					{
						cout << " The elements are ordered in descending order";
					}					
				}			


		}

	}

	void SubArray()
	{
		delete[] array_i_sub;
		if (array_m == 1)
		{
			cout << " One element in array" << endl;
		}
		else
		{
			if (array_m % 2 == 0)
				array_m_sub = array_m / 2;
			array_m_sub = (array_m - 1) / 2;
			array_i_sub = new double[array_m_sub];
			for (i = 1; i < array_m; i = i + 2)
			{
				j = (i - 1) / 2;
				array_i_sub[j] = array_i[i];
				cout << " Index " << i << " Element = " << array_i_sub[j] << endl;
			}
			cout << endl;
		}
	}

	~DynamicArray()
	{
		delete[] array_i;
		delete[] array_i_sub;
	}
};

int main()
{
	int array_m_in;
	int index;
	int x = 0;
	int a;
	double value;
	DynamicArray array_obj;
	cout << "1.To set the size of the array" << endl;
	cout << "2.To know the size of the array" << endl;
	cout << "3.To specify an array element by its index" << endl;
	cout << "4.Display the array element by its index" << endl;
	cout << "5.Display the minimum element of the array" << endl;
	cout << "6.Check if the array is ordered" << endl;
	cout << "7.Display an array with elements with odd indexes from the array" << endl;
	cout << "8.Display a menu" << endl;
	cout << "9.Exit" << endl << endl;
	cout << " Now the array consists of one element = 0" << endl;
	while (x == 0)
	{
		cout << "Enter a menu item: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << " Enter the size: ";
			cin >> array_m_in;
			if (array_m_in < 1)
			{
				cout << "Size must be greater than zero" << endl << endl;
				break;
			}
			else
			{
				cout << endl;
				array_obj.SetArraySize(array_m_in);
				cout << " Array size=" << array_m_in << " now";
				cout << endl;
				break;
			}
		}
		case 2:
		{
			cout << endl;
			array_obj.DisplayArraySize();
			cout << endl;
			break;
		}
		case 3:
		{
			cout << " Enter the index of: ";
			cin >> index;
			cout << " Entered value: ";
			cin >> value;
			array_obj.SetElement(index,value);
			cout << endl;
			break;
		}
		case 4:
		{
			cout << " Enter the index of: ";
			cin >> index;
			array_obj.DisplayElement(index);
			cout << endl;
			break;
		}
		case 5:
		{
			array_obj.DisplayMinimumElement();
			cout << endl;
			break;
		}
		case 6:
		{
			array_obj.CheckOrder();
			break;
		}
		case 7:
		{
			array_obj.SubArray();
			cout << endl;
			break;
		}
		case 8:
		{
			cout << "1.To set the size of the array" << endl;
			cout << "2.To know the size of the array" << endl;
			cout << "3.To specify an array element by its index" << endl;
			cout << "4.Display the array element by its index" << endl;
			cout << "5.Display the minimum element of the array" << endl;
			cout << "6.Check if the array is ordered" << endl;
			cout << "7.Display an array with elements with odd indexes from the array" << endl;
			cout << "8.Display a menu" << endl;
			cout << "9.Exit" << endl << endl;
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


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
	double *array_i;
	double *array_i_sub;
	int array_m_sub;

public:

	DynamicArray(int _array_m = 1)
	{
		int i;
		array_m = _array_m;
		array_i = new double[array_m];
		for (i = 0; i < array_m; i++)
		{
			array_i[i] = 0;
		}
	}

	DynamicArray& operator=(const DynamicArray &arr)
	{
		int i;
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
		int i;
		delete[] array_i;
		array_m = _array_m;
		array_i = new double[array_m];
		for (i = 0; i < array_m; i++)
		{
			array_i[i] = 0;
		}
	}

	int GetArraySize()
	{
		return array_m;
	}

	void SetElement(int i, double value)
	{
		array_i[i] = value;
	}

	double GetElement(int i)
	{
		return array_i[i];
	}

	double GetMinimumElement()
	{
		int i;
		double min;
		min = array_i[0];
		for (i = 1; i < array_m; i++)
		{
			if (array_i[i] < array_i[i - 1])
				min = array_i[i];
		}
		return min;
	}

	int CheckOrder()
	{
		int i;
		int odd1 = 0;
		int odd2 = 0;
		int y;
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
			y = 0;
		}
		else
		{
			if ((odd1 + odd2) == 2)
			{
				y = 1;
			}
			else
			{
				if (odd1 == 0)
				{
					y = 2;
				}
				else
				{
					y = 3;
				}
			}
		}
		return y;

	}

	int GetSubArraySize()
	{
		if (array_m % 2 == 0)
		{
			array_m_sub = array_m / 2;
		}
		else
		{
			array_m_sub = (array_m - 1) / 2;
		}
		return array_m_sub;
	}

	double SubArray(int k)
	{
		int i;
		int j;
		delete[] array_i_sub;
		array_i_sub = new double[GetSubArraySize()];
		for (j = 0; j < GetSubArraySize(); j++)
		{
			i = j * 2 + 1;
			array_i_sub[j] = array_i[i];
		}
		return array_i_sub[k];
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
	int subsize;
	int j;
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
			cout << " Array size=" << array_obj.GetArraySize() << " now";
			cout << endl;
			break;
		}
		case 3:
		{
			cout << " Enter the index of: ";
			cin >> index;
			if ((index < 0) || (index >= array_obj.GetArraySize()))
			{
				cout << " Incorrect index" << endl << endl;
				break;
			}
			else {
				cout << " Entered value: ";
				cin >> value;
				array_obj.SetElement(index, value);
				cout << endl;
				break;
			}
		}
		case 4:
		{
			cout << " Enter the index of: ";
			cin >> index;
			if ((index < 0) || (index >= array_obj.GetArraySize()))
			{
				cout << " Incorrect index" << endl << endl;
				break;
			}
			else {
				cout << " The element at index " << index << " is equal to " << array_obj.GetElement(index) << endl;
				cout << endl;
				break;
			}
		}
		case 5:
		{
			cout << " Minimal element= " << array_obj.GetMinimumElement() << endl;
			cout << endl;
			break;
		}
		case 6:
		{
			if (array_obj.CheckOrder() == 0)
			{
				cout << " All elements are equal" << endl << endl;
			}
			else
				if (array_obj.CheckOrder() == 1)
				{
					cout << " The array is not ordered" << endl << endl;
				}
				else
					if (array_obj.CheckOrder() == 2)
					{
						cout << " The elements are ordered in ascending order" << endl << endl;
					}
					else
						cout << " The elements are ordered in descending order" << endl << endl;
			break;
		}
		case 7:
		{
			if (array_obj.GetArraySize() == 1)
			{
				cout << " One element in array" << endl << endl;
				break;
			}
			else
			{
				subsize = array_obj.GetSubArraySize();
				for (j = 0; j < subsize; j++)
				{
					cout << " Index = " << j * 2 + 1 << " Element = " << array_obj.SubArray(j) << endl;
				}
				cout << endl;
				break;
			}
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
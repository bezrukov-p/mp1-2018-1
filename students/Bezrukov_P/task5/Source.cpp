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

struct Product;
struct Check;
class CashBox;
class Stock;

//����� � ��������
//����������� ������ ����� � �����.
//����� ����� ������ ����������� ������ ��������� �������� �� ������������ ������� � ������������ ���� �� �������.
//������ ����� ���������������� ����� - �����(��� ��������� � ������ �� ������� ���� �� �0001� �� �9999�).
//���� � ��� �� ����� ����� ������������� ��������� ���, �� � ��� ���������� � ������ ������ ������ � ���� ������������� � ��������� �� �������(��� ��������� � ������ ��� ������)
//� ���������� � ����� ��������� �� �����.��� ������� �� ����� ��� �� ����� ������ ���������� ����.��� ������������� �������� ����� ��������� ������� � �������,
//��������� ������ � �������� ����� � ������(��� � ������).
//���� ������� �������� � ������ �����.����� ����������� ����� - �����, �������������, ���������� �� ������� ������, ������� � ��������� �� ���������.
//������ ��������������� �� ������ ����� ����������(� ��������� �� 1 �� 50 % ).
//����� ����� ������ ������������� ��������� �������� : 1) ������������� ��������� �����, 2) �������� �������� ������ �� ������, 3) �������� ������ � ������ � ���, 
//4) ������������ ��� �� �������, 5) ���������� �������� ����� � ������, 6) ������� ��������� ����� �� �������.
//����� ����� ������ �������������� ��� ��������� ������ ������ ����� � ����� ���� ���������� � ���������� - ����������� ��������.

struct Product
{
	string barcode;
	string name;
	double price;
	double discount;
	int count = 1;
	Product &operator=(const Product &g)
	{
		this->name = g.name;
		this->price = g.price;
		this->barcode = g.barcode;
		this->count = g.count;
		this->discount = g.discount;
		return *this;
	}
	friend ostream &operator<<(ostream &os, const Product &ch);
};

ostream &operator<<(ostream &os, const Product &pr)
{
	os << "��������: " << pr.barcode << endl;
	os << "������������: " << pr.name << endl;
	os << "����: " << pr.price << endl;
	os << "������: " << pr.discount << endl;
	os << "����������: " << pr.count << endl;
	return os;
}

struct Check
{
	vector<Product> products;
	double cost;
	double final_cost;//�� �������
	double sale_rub;
	Check &operator=(const Check &g)
	{
		this->products = g.products;
		this->cost = g.cost;
		this->final_cost = g.final_cost;
		this->sale_rub = g.sale_rub;
		return *this;
	}
	friend ostream &operator<<(ostream &os, const Check &pr);
};

ostream &operator<<(ostream &os, const Check &pr)
{
	os << "Check:" << endl;
	for (int i = 0; i < pr.products.size(); i++)
	{
		os << "��������: " << pr.products[i].barcode << endl;
		os << "������������: " << pr.products[i].name << endl;
		os << "����: " << pr.products[i].price << endl;
		os << "������: " << pr.products[i].discount << endl;
		os << "����������: " << pr.products[i].count << endl;
	}
	os << endl;
	os << "���������: " << pr.cost << endl;
	os << "��������� ������: " << pr.sale_rub << endl;
	os << "�������� ���������: " << pr.final_cost << endl << endl;
	return os;
};

class Stock
{
protected:
	vector<Product> product;
public:
	friend CashBox;

	/*Stock(const Stock &sc)
	{
		product = sc.product;
	} */

	Stock& operator=(const Stock &sc)
	{
		if (this == &sc)
			return *this;
		else
		{
			product = sc.product;
		}
	}

	void AddProductInStock(Product _product)
	{
		product.push_back(_product);
		cout << product.size() << endl;//������� ��� �������� �������� �������
	}
};

class CashBox :public Stock
{
	Check check;
	vector<Product> product_scan;
public:

	CashBox & operator=(const CashBox &sc)
	{
		if (this == &sc)
			return *this;
		else
		{
			check = sc.check;
			product_scan = sc.product_scan;
		}
	}

	bool ScanProduct(string _barcode)
	{
		cout << product.size() << endl;//������� ��� �������� �������� �������
		for (int i = 0; i < product_scan.size(); i++)
		{
			if (_barcode == product_scan[i].barcode)
			{
				product_scan[i].count++;
				return true;
			}
		}
		for (int i = 0;i <product.size();i++)
		{
			if (product[i].barcode == _barcode)
			{
				product_scan.push_back(product[i]);
				return true;
			}
		}
		return false;
	}

	void ShowProduct(string _barcode)
	{
		for (int i = 0; i < product.size(); i++)
		{
			if (_barcode == product[i].barcode)
			{
				cout << product[i] << endl;
				return;
			}
		}
	}

	void ShowStock()
	{
		for (int i = 0; i < product.size(); i++)
		{
			cout << product[i] << endl;;
		}
	}

	void ProductsInCheck()
	{
		for (int i = 0; i < product_scan.size(); i++)
		{
			check.products.push_back(product_scan[i]);
		}
	}

	Check FormCheck()
	{
		check.cost = 0;
		check.final_cost = 0;
		check.sale_rub = 0;
		for (int i = 0; i < check.products.size(); i++)
		{
			check.cost += check.products[i].price*check.products[i].count;
			check.final_cost += check.products[i].price*check.products[i].count*(1 - (check.products[i].discount / 100));
		}
		check.sale_rub = check.cost - check.final_cost;
		return check;
	}

	double FinalCost()
	{
		double _final_cost = 0;
		for (int i = 0 ; i < product_scan.size(); i++)
		{
			_final_cost += product_scan[i].price*(1 - (product_scan[i].discount / 100));
		}
		return _final_cost;
	}

	void DeleteProduct(string _barcode)
	{
		for (int i = 0; i < product_scan.size(); i++)
		{
			if (_barcode == product_scan[i].barcode)
			{
				if (product_scan[i].count == 1)
				{
					product_scan.erase(product_scan.begin() + i);
					return;
				}
				else
				{
					product_scan[i].count--;
					return;
				}
			}
		}
	}

	void Clear()
	{
		check.products.clear();
		product_scan.clear();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Stock stock;
	CashBox cashbox;
	string _barcode;
	string _name;
	double _price;
	double _discount;
	int x = 0;
	int a;
	cout << "1.�������� ������� �� �����." << endl;//
	cout << "2.�������� �������� ������ �� ������." << endl;//
	cout << "3.����������� �������." << endl;//
	cout << "4.�������� ������ � ������� � ���." << endl;//
	cout << "5.������������ ��� �� �������." << endl;//
	cout << "6.���������� �������� ����� � ������." << endl;//
	cout << "7.������� ��������� ����� �� �������." << endl;
	cout << "8.�������� ������� ������������ � ���." << endl;
	cout << "0.�����" << endl;
	while (x == 0)
	{
	metka:
		cout << "������� ����� ����: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "��������: ";
			cin >> _barcode;
			cout << "������������: ";
			cin >> _name;
			cout << "����: ";
			cin >> _price;
			cout << "������(%): ";
			cin >> _discount;
			stock.AddProductInStock({ _barcode,_name,_price,_discount});
			cout << endl;
			goto metka;
		}
		case 2:
		{
			cout << "��������: ";
			cin >> _barcode;
			cashbox.ShowProduct(_barcode);
			cout << endl;
			goto metka;
		}
		case 3:
		{
			cout << "��������: ";
			cin >> _barcode;
			if (cashbox.ScanProduct(_barcode))
			{
				cout << "�������������� " << endl << endl;
			}else
			cout << "����� �� ������ " << endl << endl;
			goto metka;
		}
		case 4:
		{
			cashbox.ProductsInCheck();
			cout << "���������" << endl << endl;
			goto metka;
		}
		case 5:
		{
			cout << cashbox.FormCheck();
			goto metka;
		}
		case 6:
		{
			cout << "����� � ������: " << cashbox.FinalCost() << endl << endl;
			goto metka;
		}
		case 7:
		{
			cout << "��������: ";
			cin >> _barcode;
			cashbox.DeleteProduct(_barcode);
			cout << "�������" << endl << endl;
			goto metka;
		}
		case 8:
		{
			cashbox.Clear();
			cout << "�������" << endl << endl;
			goto metka;
		}
		case 0:
		{
			exit(EXIT_SUCCESS);
			break;
		}
		default:
			break;
		}
	}
}

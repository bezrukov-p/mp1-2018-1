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

//Касса в магазине
//Разработать классы Касса и Склад.
//Класс Касса должен имитировать работу кассового аппарата по сканированию товаров и формированию чека за покупку.
//Каждый товар идентифицируется штрих - кодом(для упрощения – строка из четырех цифр от «0001» до «9999»).
//Один и тот же товар может сканироваться несколько раз, но в чек информация о каждом товаре входит в виде «наименование – стоимость за единицу(для упрощения в рублях без копеек)
//– количество – общая стоимость за товар».Чек состоит не менее чем из одной записи указанного вида.Чек дополнительно включает общую стоимость товаров в покупке,
//суммарную скидку и итоговую сумму к оплате(все в рублях).
//База товаров хранится в классе Склад.Товар описывается штрих - кодом, наименованием, стоимостью за единицу товара, скидкой в процентах от стоимости.
//Скидки устанавливаются на каждый товар независимо(в диапазоне от 1 до 50 % ).
//Класс Касса должен предоставлять следующие операции : 1) «сканировать» очередной товар, 2) получить описание товара со склада, 3) добавить данные о товаре в чек, 
//4) сформировать чек за покупку, 5) рассчитать итоговую сумму к оплате, 6) удалить выбранный товар из покупки.
//Класс Склад должен использоваться для поддержки работы класса Касса и может быть разработан в минимально - необходимом варианте.

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
	os << "Штрихкод: " << pr.barcode << endl;
	os << "Наименование: " << pr.name << endl;
	os << "Цена: " << pr.price << endl;
	os << "Скидка: " << pr.discount << endl;
	os << "Количество: " << pr.count << endl;
	return os;
}

struct Check
{
	vector<Product> products;
	double cost;
	double final_cost;//со скидкой
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
		os << "Штрихкод: " << pr.products[i].barcode << endl;
		os << "Наименование: " << pr.products[i].name << endl;
		os << "Цена: " << pr.products[i].price << endl;
		os << "Скидка: " << pr.products[i].discount << endl;
		os << "Количество: " << pr.products[i].count << endl;
	}
	os << endl;
	os << "Стоимость: " << pr.cost << endl;
	os << "Суммарная скидка: " << pr.sale_rub << endl;
	os << "Итоговая стоимость: " << pr.final_cost << endl << endl;
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
		cout << product.size() << endl;//Написал для проверки значения размера
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
		cout << product.size() << endl;//Написал для проверки значения размера
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
	cout << "1.Добавить продукт на склад." << endl;//
	cout << "2.Получить описание товара со склада." << endl;//
	cout << "3.Сканировать продукт." << endl;//
	cout << "4.Добавить данные о товарах в чек." << endl;//
	cout << "5.Сформировать чек за покупку." << endl;//
	cout << "6.Рассчитать итоговую сумму к оплате." << endl;//
	cout << "7.Удалить выбранный товар из покупки." << endl;
	cout << "8.Очистить историю сканирования и чек." << endl;
	cout << "0.Выход" << endl;
	while (x == 0)
	{
	metka:
		cout << "Введите пункт меню: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "Штрихкод: ";
			cin >> _barcode;
			cout << "Наименование: ";
			cin >> _name;
			cout << "Цена: ";
			cin >> _price;
			cout << "Скидка(%): ";
			cin >> _discount;
			stock.AddProductInStock({ _barcode,_name,_price,_discount});
			cout << endl;
			goto metka;
		}
		case 2:
		{
			cout << "Штрихкод: ";
			cin >> _barcode;
			cashbox.ShowProduct(_barcode);
			cout << endl;
			goto metka;
		}
		case 3:
		{
			cout << "Штрихкод: ";
			cin >> _barcode;
			if (cashbox.ScanProduct(_barcode))
			{
				cout << "Просканировано " << endl << endl;
			}else
			cout << "Товар не найден " << endl << endl;
			goto metka;
		}
		case 4:
		{
			cashbox.ProductsInCheck();
			cout << "Добавлено" << endl << endl;
			goto metka;
		}
		case 5:
		{
			cout << cashbox.FormCheck();
			goto metka;
		}
		case 6:
		{
			cout << "Сумма к оплате: " << cashbox.FinalCost() << endl << endl;
			goto metka;
		}
		case 7:
		{
			cout << "Штрихкод: ";
			cin >> _barcode;
			cashbox.DeleteProduct(_barcode);
			cout << "Удалено" << endl << endl;
			goto metka;
		}
		case 8:
		{
			cashbox.Clear();
			cout << "Очищено" << endl << endl;
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

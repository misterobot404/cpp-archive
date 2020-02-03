/*
���������� ���������� ��� ���������� ������� ����� ������� � ��������.
����������� ����������, ����������� �������� � ����������� �������� � ����������� � ���������� ������� ���������� ��������.
��������� ���������� ����������� ������ �������� ��������� ������: �����, �������������, ��������, ����������� ������, ���������� ������ � ��.
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;


class Manufacturer
{
public:
	string _name;
	string _addres;
};
class Document
{
public:
	Document(string s) : opp(s) {}
	string opp;
};

class Product
{
public:
	void set()
	{
		cout << "������ � ������:" << endl;
		cout << "ID: "; cin >> _id;
		cin.ignore();
		cout << "�������� ������: "; getline(cin,_title);
		cout << "���������� ������: "; cin >> _quantity;
		cout << "��������� ������: "; cin >> _price;
		cin.ignore();
		cout << "���������� �������������: "; getline(cin, _manufacturer._name);
		cout << "����� �������������: "; getline(cin, _manufacturer._addres);

	}
	void edit()
	{
		string title;
		size_t quantity;
		double price;
		char key;
		while (true)
		{
			cout << "��� ��������?" << endl
				<< "1. ��������" << endl
				<< "2. ����������" << endl
				<< "3. ���������" << endl
				<< "4. ��������� ���������" << endl
				<< ">";
			cin >> key;
			switch (key)
			{
			case '1':
				cout << "��������: ";
				cin.ignore();
				getline(cin, title);
				_title = title;
				break;
			case '2':
				cout << "����������: ";
				cin >> quantity;
				_quantity = quantity;
				break;
			case '3':
				cout << "���������: ";
				cin >> price;
				_price = price;
				break;
			case '4':
				return;
				break;
			}
		}//while
	}
	friend ostream& operator << (ostream&, const Product&);
	friend class Store;
	friend class AddProduct;
	friend class ReduceProduct;
private:
	size_t _id;
	string _title;
	size_t _quantity;
	Manufacturer _manufacturer;
	double _price;
};
ostream& operator<<(ostream& out, const Product& product)
{
	cout << setw(7) << product._id 
		<< setw(18) << product._title 
		<< setw(14) << product._quantity 
		<< setw(14) << product._price 
		<< setw(28) << product._manufacturer._name
		<< setw(21) << product._manufacturer._addres 
		<< endl;
	return out;
}

class Store
{
public:
	void show() 
	{
		cout << setw(7) << "ID" << setw(18) << "��������" << setw(14) << "����������" << setw(14) << "���������" << setw(28) << "���������� �������������" << setw(21) << "����� �������������" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		for (auto product : _products)
			cout << endl << product;
	}
	void showDoc()
	{
		for (auto document : _document)
			cout << endl << document.opp;
	}
	void find(int id)
	{
		for (auto& product : _products)
		{
			if (product._id == id)
			{
				product.edit();
				return;
			}
		}
		cout << "id �� ����������" << endl;
	}
	void search(int id)
	{
		for (auto product : _products)
		{
			if (product._id == id)
			{
				cout << "��������: " << product._title<<endl
					<< "����������: " << product._quantity << endl
					<< "����: " << product._price << endl;
				return;
			}
		}
		cout << "id �� ����������" << endl;
	}
	friend class AddProduct;
	friend class ReduceProduct;
private:
	vector <Product> _products;
	vector <Document> _document;
};

class ReduceProduct
{
public:
	static void erase(Store& store, int id)
	{
		for (int i = 0; i < store._products.size(); i++)
		{
			if (store._products[i]._id == id)
			{
				store._products.erase(store._products.begin() + i);
				cout << "����� ������!" << endl;
				return;
			}
		}
		cout << "id �� ����������" << endl;
	}
};
class AddProduct
{
public:
	static void add(Store& store, const Product& product)
	{
		if (!store._products.empty())
		{
			auto it = find_if(store._products.begin(), store._products.end(), [&product](const Product& s)
			{
				return (s._id != product._id) ? true : false;
			});
			if (it != store._products.end())
			{
				store._products.push_back(product);
				store._document.push_back(Document("�������� � ���������� ������. ����������: �������� ����� � ID: " + to_string(product._id)));
				cout << "����� ��������" << endl;
			}
			else cout << "����� id ��� ����������" << endl;
		}
		else {
			store._products.push_back(product);
			store._document.push_back(Document("�������� � ���������� ������. ����������: �������� ����� � ID: " + to_string(product._id)));
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	char key;
	Store store;
	Product product;
	int id;
	while (true)
	{
		cout << endl;
		cout << "*��������� ���������� ���������*" << endl
			<< "�������� ��������:" << endl
			<< "1. �������� �����." << endl
			<< "2. ������� �����." << endl
			<< "3. �������� ������ � ������." << endl
			<< "4. ����� �����." << endl
			<< "5. ������� ��� ������." << endl
			<< "6. ����� ���������� �� ���������." << endl
			<< "7. �����." << endl
			<< ">";
		cin >> key;
		switch (key)
		{
		case '1':
			product.set();
			AddProduct::add(store,product);
			break;
		case '2':
			cout << endl << "������� id: ";
			cin >> id;
			ReduceProduct::erase(store,id);
			break;
		case '3':
			cout << endl << "������� id ������: ";
			cin >> id;
			store.find(id);
			break;
		case '4':
			cout << endl << "������� id: ";
			cin >> id;
			store.search(id);
			break;
		case '5':
			store.show();
			break;
		case '6':
			store.showDoc();
			break;
		case '7':
			exit(1);
			break;
		}
	}
	system("pause");
	return 0;
}

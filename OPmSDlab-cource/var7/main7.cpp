#include <iostream>
#include <iomanip>
#include <vector>
#include <locale>
#include <fstream>
#include <windows.h>
using namespace std;
class worker
{
	char surname[64];
	char name[64];
	char patron[64];
	char post[128];
	double salary;
	double h_pay;
	int hours;
	int id;
public:
	worker() {};
	~worker() {};
	void set_data()
	{
		cout << "������ � ����������:" << endl;
		cout << "id: "; cin >> id;
		cout << "�������: "; cin >> surname;
		cout << "���: "; cin >> name;
		cout << "��������: "; cin >> patron;
		cout << "���������: "; cin >> post;
		cout << "���������� ����� � ���: "; cin >> h_pay;
		cout << "���������� ������������ �����: "; cin >> hours;
	}
	void Salary()
	{
		salary = h_pay * hours;
	}
	void show()
	{
		cout << setw(4) << id << setw(10) << surname << setw(6) << name << setw(11)
			<< patron << setw(12) << post << setw(25) << h_pay << setw(19) << hours << setw(11) <<
			salary;
	}
	void edit()
	{
		char d[128];
		int num;
		double hpay;
		char key;
		while (1)
		{
			cout << "that edit?" << endl
				<< "1. Post" << endl
				<< "2. h/pay" << endl
				<< "3. Hours" << endl
				<< "4. End edit" << endl;
			cin >> key;
			switch (key)
			{
			case '1':
				cout << "Post: ";
				cin >> d;
				break;
			case '2':
				cout << "Pay: ";
				cin >> hpay;
				h_pay = hpay;
				break;
			case '3':
				cout << "Hours: ";
				cin >> num;
				hours = num;
				break;
			case '4':
				return;
				break;
			}
		}//while
	}//func
	int get_id() const
	{
		return id;
	}
};

class arr
{
	vector <worker> w;
public:
	void add(worker emp)
	{
		w.push_back(emp);
	}
	void show()
	{
		cout << "������ � ��������" << endl;
		cout << setw(4) << "ID" << setw(10) << "�������" << setw(6) << "���" <<
			setw(11) << "��������" << setw(12) << "���������" << setw(25) << "���������� ����� � ���" << setw(19) << "���������� �����"
			<< setw(11) << "��������" << endl;
		cout << "----------------------------------------------------------------------------------------------------"
			<< endl;
		for (int i = 0; i < w.size(); i++)
		{
			cout << endl;
			w[i].show();
		}
	}
	void erase(int id_)
	{
		for (int i = 0; i < w.size(); i++)
		{
			if (w[i].get_id() == id_)
			{
				w.erase(w.begin() + i);
				return;
			}
		}
		cout << "id �� ����������" << endl;
	}
	void search(int id_)
	{
		for (int i = 0; i < w.size(); i++)
		{
			if (w[i].get_id() == id_)
			{
				w[i].show();
				return;
			}
		}
		cout << "id �� ����������" << endl;
	}
	void find(int id_)
	{
		for (int i = 0; i < w.size(); i++)
		{
			if (w[i].get_id() == id_)
			{
				w[i].edit();
				w[i].Salary();
				return;
			}
		}
		cout << "id �� ����������" << endl;
	}
	void to_file()
	{
		char file[64] = "database.txt";
		ofstream out(file, ios::binary);
		for (int i = 0; i < w.size(); i++)
		{
			out.write((char*)& w[i], sizeof(w[i]));
		}
		cout << "������ � ���������� ��������� � ���� database.txt (����� ��� ����� � ����� �������)" << endl;
		cout << "������� ���� � ������������?\n1. ��\n2. ���" << endl;
		char a;
		cin >> a;
		if (a == '1')
		{
			ShellExecute(0, 0, "notepad.exe", "database.txt", 0, SW_SHOW);
		}
	}
	void from_file()
	{
		char file[64] = "database.txt";
		char key;
		worker emp;
		ifstream in(file, ios::binary);
		cout << "�������� ������� ������ � �����������?" << endl;
		cout << "1. ��" << endl;
		cout << "2. ���" << endl;
		cin >> key;
		if (key == '1')
		{
			w.clear();
		}
		while (!in.eof())
		{
			in.read((char*)& emp, sizeof(emp));
			w.push_back(emp);
		}
		w.erase(w.end() - 1);
		cout << "������ ������� ��������� �� �����" << endl;
	}
	void Sort()
	{
		char key;
		cout << "��� �����������?" << endl
			<< "1. ���������" << endl;
		cin >> key;
		if (key == '1')
		{
			worker temp; // ��������� ���������� ��� �������� �������� �������
			bool exit = false; // ������� ���������� ��� ������ �� �����, ���� ������ ������������
			while (!exit) // ���� ������ �� ������������
			{
				exit = true;
				for (int int_counter = 0; int_counter < (w.size() - 1);
					int_counter++) // ���������� ����
					//���������� ��������� �� ����������� - ���� >
					//���������� ��������� �� �������� - ���� <
					if (w[int_counter].get_id() > w[int_counter +
						1].get_id()) // ���������� ��� �������� ��������
					{
						// ��������� ������������ ��������� �������
						swap(w[int_counter], w[int_counter + 1]);
						exit = false; // �� ��������� �������� ���� ����������� ������������ ���������
					}
			}
		}// if
	}// Sort
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	char key;
	arr mas;
	worker emp;
	int id_;
	while (1)
	{
		cout << endl
			<< "�������� ��������:"
			<< endl
			<< "1. �������� ���������." << endl
			<< "2. �������� ������ � ���������." << endl
			<< "3. ����� ���������." << endl
			<< "4. ������� ���������." << endl
			<< "5. ��������� � ����." << endl
			<< "6. �������� ������ �� �����." << endl
			<< "7. ������� ���� ����������." << endl
			<< "8. ������������� ����������." << endl
			<< "9. �����." << endl;
		cin >> key;
		switch (key)
		{
		case '1':
			emp.set_data();
			emp.Salary();
			mas.add(emp);
			break;
		case '2':
			cout << endl << "������� id: ";
			cin >> id_;
			mas.find(id_);
			break;
		case '3':
			cout << endl << "������� id: ";
			cin >> id_;
			mas.search(id_);
			break;
		case '4':
			cout << endl << "������� id: ";
			cin >> id_;
			mas.erase(id_);
			break;
		case '5':
			mas.to_file();
			break;
		case '6':
			mas.from_file();
			break;
		case '7':
			mas.show();
			break;
		case '8':
			mas.Sort();
			break;
		case '9':
			exit(1);
			break;
		}
	}
	system("pause");
	return 0;
}
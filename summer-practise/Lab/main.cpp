#include "SummerPractise.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int select;
	while (true)
	{
		system("cls");
		cout << "������� ����:" << endl;
		cout << " ������� 1" << endl;
		cout << " ������� 2" << endl;
		cout << " ������� 3" << endl;
		cout << " ������� 4" << endl;
		cout << " ������� 5" << endl;
		cout << " ������� 6" << endl;
		cout << " ������� 7" << endl;
		cout << " ������� 8" << endl;
		cout << " ������� 9" << endl;
		cout << " ������� 10" << endl;
		cout << "������� ����� ������� (��� 0 ��� ������): ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			system("cls");
			cout << "������� 1" << endl;
			cout << "�������� �������: ����� � ������� ����� �� n-���������� ��������" << endl << endl;

			char symbol;
			cout << "������� ������: "; cin >> symbol;
			unsigned int countSymbol;
			cout << "������� ���������� �������� � ������: "; cin >> countSymbol;
			unsigned int countLine;
			cout << "������� ���������� c����: "; cin >> countLine;
			SummerPractise::task1(symbol, countSymbol, countLine);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 2:
		{
			system("cls");
			cout << "������� 2" << endl;
			cout << "�������� �������: ����� � ������� ����� �� ���� �� number (����� �� ������������)" << endl << endl;

			int number;
			cout << "������� �����: "; cin >> number;
			SummerPractise::task2(number);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 3:
		{
			system("cls");
			cout << "������� 3" << endl;
			cout << "�������� �������: ����� � ������� ���� ����� �� ���������" << endl << endl;

			int start;
			cout << "������� ������ ���������: "; cin >> start;
			int end;
			cout << "������� ����� ���������: "; cin >> end;
			SummerPractise::task3(start, end);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 4:
		{
			system("cls");
			cout << "������� 4" << endl;
			cout << "�������� �������: ����� � ������� ���� ������ ����� �� ���������" << endl << endl;

			int start;
			cout << "������� ������ ���������: "; cin >> start;
			int end;
			cout << "������� ����� ���������: "; cin >> end;
			SummerPractise::task4(start, end);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 5:
		{
			system("cls");
			cout << "������� 5" << endl;
			cout << "�������� �������: ����� � ������� ���� �������� ����� �� ���������" << endl << endl;

			int start;
			cout << "������� ������ ���������: "; cin >> start;
			int end;
			cout << "������� ����� ���������: "; cin >> end;
			SummerPractise::task5(start, end);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 6:
		{
			system("cls");
			cout << "������� 6" << endl;
			cout << "�������� �������: ����� � ������� ���������� ���� � ����� number (����� �� ������������)" << endl << endl;

			int number;
			cout << "������� �����: "; cin >> number;
			SummerPractise::task6(number);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 7:
		{
			system("cls");
			cout << "������� 7" << endl;
			cout << "�������� �������: ����� � ������� ������ �����" << endl << endl;

			int number;
			cout << "������� �����: "; cin >> number;
			SummerPractise::task7(number);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 8:
		{
			system("cls");
			cout << "������� 8" << endl;
			cout << "�������� �������: ����� � ������� ��������� ���������� ����� � �������" << endl << endl;

			double number;
			cout << "������� �����: "; cin >> number;
			double degree;
			cout << "������� ������� (������������� ������� ��������������): "; cin >> degree;
			SummerPractise::task8(number, degree);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 9:
		{
			system("cls");
			cout << "������� 9" << endl;
			cout << "�������� �������: ����� � ������� ����� ���������� �������������� ������������ �� ������ �������" << endl << endl;

			unsigned int lineLength1;
			cout << "������� ����� ������� ������: "; cin >> lineLength1;
			unsigned int lineLength2;
			cout << "������� ����� ������� ������: "; cin >> lineLength2;
			SummerPractise::task9(lineLength1, lineLength2);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 10:
		{
			system("cls");
			cout << "������� 10" << endl;
			cout << "�������� �������: ����� � ������� ���������� ����� ����� ������� � ������������ (x,y,z)" << endl << endl;

			Point point1;
			cout << "���� ��������� ������ �����" << endl;
			cout << "x: "; cin >> point1.x;
			cout << "y: "; cin >> point1.y;
			cout << "z: "; cin >> point1.z;
			cout << endl;

			Point point2;
			cout << "���� ��������� ������ �����" << endl;
			cout << "x: "; cin >> point2.x;
			cout << "y: "; cin >> point2.y;
			cout << "z: "; cin >> point2.z;
			cout << endl;

			SummerPractise::task10(point1, point2);
			cout << endl;

			cout << "��� ����������� � ������� ���� ������� ����� �������...";
			cin.ignore(); cin.get();
		}
			break;
		case 0:
			return 0;
		default:
			system("cls");
			break;
		}
	}
}

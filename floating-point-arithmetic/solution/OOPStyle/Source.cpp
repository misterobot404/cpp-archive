#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class FloatPoint
{

private:
	// sign 0 = plus
	// sign 1 = minus
	bool sign = 0;
	string mantis = "";
	int exponent = 0;
	static FloatPoint stringToFPoint(string fPointString)
	{
		// Return value
		FloatPoint fPoint;

		// ���������� �������� ��� �����
		if (fPointString[0] == '-')
		{
			fPoint.sign = 1;
			fPointString.erase(0, 1);
		}

		// ������� ������ ������� ����
		while (fPointString[0] == '0'
			&& fPointString.length() != 1 // ��������� ������� �� ���� ����������
			&& fPointString[1] != '.' // ��������� ������� �� ���� �� �����
			&& fPointString[1] != ',') // ��������� ������� �� ���� �� �������
		{
			fPointString.erase(0, 1);
		}


		bool pointEntry = false;
		//  ������ ���������� (���������� ���� ����� ����������� ������)
		for (size_t i = 0; i < fPointString.length() && pointEntry == false; i++)
		{
			if (fPointString[i] == '.' || fPointString[i] == ',')
			{
				pointEntry = true;
				fPointString.erase(i, 1);
				fPoint.exponent = i - 1;
			}

			if (i + 1 == fPointString.length() && pointEntry == false && i > 1)
			{
				pointEntry = true;
				fPoint.exponent = i;
			}
		}

		// ���� � ����� ���� ����
		if (stold(fPointString) == 0) fPointString = '0';

		// ��������� ����� �� ����� �������
		if (pointEntry == true)
		{
			fPointString.insert(1, ".");
		}

		//������� ��������� ����� ������, ���� ����� ����� ������� ����� 0
		while (fPointString.length() > 2 && fPointString[0] == '0' && fPointString[1] == '.')
		{
			fPointString.erase(0, 2);
			if (fPointString.length() > 1) fPointString.insert(1, ".");
			fPoint.exponent--;
		}

		fPoint.mantis = fPointString;
		return fPoint;
	};
public:
	FloatPoint& operator = (const FloatPoint& right)
	{
		sign = right.sign;
		mantis = right.mantis;
		exponent = right.exponent;
		return *this;
	}
	friend FloatPoint operator + (const FloatPoint& left, const FloatPoint& right)
	{
		long double value1, value2;

		if (left.sign == 0)
			value1 = stold(left.mantis + "e" + to_string(left.exponent));
		else
			value1 = stold("-" + left.mantis + "e" + to_string(left.exponent));

		if (right.sign == 0)
			value2 = stold(right.mantis + "e" + to_string(right.exponent));
		else
			value2 = stold("-" + right.mantis + "e" + to_string(right.exponent));

		ostringstream streamObj;
		streamObj << setprecision(16);
		//Add double to stream
		streamObj << value1 + value2;
		// Get string from output string stream
		string stringFPoint = streamObj.str();

		return stringToFPoint(stringFPoint);
	}
	friend FloatPoint operator - (const FloatPoint& left, const FloatPoint& right)
	{
		long double value1, value2;

		if (left.sign == 0)
			value1 = stold(left.mantis + "e" + to_string(left.exponent));
		else
			value1 = stold("-" + left.mantis + "e" + to_string(left.exponent));

		if (right.sign == 0)
			value2 = stold(right.mantis + "e" + to_string(right.exponent));
		else
			value2 = stold("-" + right.mantis + "e" + to_string(right.exponent));

		ostringstream streamObj;
		streamObj << setprecision(16);
		//Add double to stream
		streamObj << value1 - value2;
		// Get string from output string stream
		string stringFPoint = streamObj.str();

		return stringToFPoint(stringFPoint);
	}
	friend FloatPoint operator * (const FloatPoint& left, const FloatPoint& right)
	{
		long double value1, value2;

		if (left.sign == 0)
			value1 = stold(left.mantis + "e" + to_string(left.exponent));
		else
			value1 = stold("-" + left.mantis + "e" + to_string(left.exponent));

		if (right.sign == 0)
			value2 = stold(right.mantis + "e" + to_string(right.exponent));
		else
			value2 = stold("-" + right.mantis + "e" + to_string(right.exponent));

		ostringstream streamObj;
		streamObj << setprecision(16);
		//Add double to stream
		streamObj << value1 * value2;
		// Get string from output string stream
		string stringFPoint = streamObj.str();

		return stringToFPoint(stringFPoint);
	}
	friend FloatPoint operator / (const FloatPoint& left, const FloatPoint& right)
	{
		long double value1, value2;

		if (left.sign == 0)
			value1 = stold(left.mantis + "e" + to_string(left.exponent));
		else
			value1 = stold("-" + left.mantis + "e" + to_string(left.exponent));

		if (right.sign == 0)
			value2 = stold(right.mantis + "e" + to_string(right.exponent));
		else
			value2 = stold("-" + right.mantis + "e" + to_string(right.exponent));

		ostringstream streamObj;
		streamObj << setprecision(16);
		//Add double to stream
		streamObj << value1 / value2;
		// Get string from output string stream
		string stringFPoint = streamObj.str();

		return stringToFPoint(stringFPoint);
	}

	friend ostream& operator<< (ostream& out, const FloatPoint& fPoint)
	{
		cout << "�����: ";
		if (fPoint.sign == 0)
			cout << fPoint.mantis << "e" << fPoint.exponent << endl;
		else
			cout << "-" << fPoint.mantis << "e" << fPoint.exponent << endl;

		cout << "�������� ���: ";
		if (fPoint.sign == 0)
		{
			cout << fPoint.sign << " (+)" << endl;
		}
		else
		{
			cout << fPoint.sign << " (-)" << endl;
		}
		cout << "�������: " << fPoint.mantis << endl;
		cout << "����������: " << fPoint.exponent << endl;
		cout << endl;

		return out;
	}
	friend istream& operator>> (istream& in, FloatPoint& fPoint)
	{
		string fPointString;
		cin >> fPointString;

		fPoint = stringToFPoint(fPointString);

		return in;
	}
};

int main()
{
	// ������������� ����
	setlocale(LC_ALL, "Russian");
	// ������������� �������� ������
	setlocale(LC_NUMERIC, "C");

	FloatPoint fPoint1, fPoint2, fPointRes;
	char selectedMenuItem;

	while (true)
	{
		cout << "���������� ����� � ��������� ������" << endl;
		cout << "1 ��������" << endl;
		cout << "2 ���������" << endl;
		cout << "3 ���������" << endl;
		cout << "4 �������" << endl;
		cout << "> ";
		cin >> selectedMenuItem;

		switch (selectedMenuItem)
		{
		case '1': {
			cout << "������� ������ �����: ";
			cin >> fPoint1;
			cout << "������� ������ �����: ";
			cin >> fPoint2;
			cout << endl;

			cout << fPoint1;
			cout << fPoint2;
			cout << endl;

			cout << "��������� ��������" << endl;
			cout << fPoint1 + fPoint2;
		} break;
		case '2': {
			cout << "������� ������ �����: ";
			cin >> fPoint1;
			cout << "������� ������ �����: ";
			cin >> fPoint2;
			cout << endl;

			cout << fPoint1;
			cout << fPoint2;
			cout << endl;

			cout << "��������� ���������" << endl;
			cout << fPoint1 - fPoint2;
		} break;
		case '3': {
			cout << "������� ������ �����: ";
			cin >> fPoint1;
			cout << "������� ������ �����: ";
			cin >> fPoint2;
			cout << endl;

			cout << fPoint1;
			cout << fPoint2;
			cout << endl;

			cout << "��������� ���������" << endl;
			cout << fPoint1 * fPoint2;
		} break;
		case '4': {
			cout << "������� ������ �����: ";
			cin >> fPoint1;
			cout << "������� ������ �����: ";
			cin >> fPoint2;
			cout << endl;

			cout << fPoint1;
			cout << fPoint2;
			cout << endl;

			cout << "��������� �������" << endl;
			cout << fPoint1 / fPoint2;
		} break;
		default:
			cout << "������ �����, ������� ����� �� 1 �� 4" << endl;
			break;
		}

		system("pause");
		system("cls");
	}
	return 0;
}

/*
 ����������� ��������� ���������, ���������, ���������������� ������,
 ������� �� ���������, �������� ������ ���������� �� ��������.
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
using namespace std;

//��������� �������
int linSearch(int arr[], int requiredKey, int size); // �������� �����
int Search_Binary(int arr[], int left, int right, int key); // �������� �����
int interpolatingSearch(int a[], int arraySize, int keyOfSearch); // ����������� �����
void showArr(int arr[], int size); // ����� �������

int main()
{
	setlocale(LC_ALL, "rus");
	const int arrSize = 160;
	int arr[arrSize];
	int requiredKey = 0; // ������� �������� (����)
	int nElement = 0; // ����� �������� �������
	clock_t start, stop; // �������� �������
	srand(time(NULL));

	//������ ����. ����� � ������ �� 1 �� 50
	for (int i = 0, iterNubmer = 0; i < arrSize; i++, iterNubmer += 50)
	{
		arr[i] = iterNubmer + rand() % 50;
	}

	showArr(arr, arrSize);

	while (true)
	{
		cout << "\n����� ����� ���������� ������? ";
		cin >> requiredKey; // ���� �������� �����
		cout << "������� ����� ��������� ������:" << endl;
		cout << "1.�������� ����� (��������� O(n))" << endl;
		cout << "2.�������� ����� (��������� O(log2(n))" << endl;
		cout << "3.��������������� ����� (��������� � ������� log(log(N))" << endl;
		cout << "> ";
		int numberMenu = 0;
		cin >> numberMenu;
		switch (numberMenu) {
		case 1:
		{
			start = clock();
			//����� �������� ����� � ������ ������ ��������
			nElement = linSearch(arr, requiredKey, arrSize);
			if (nElement != -1)
			{
				//���� � ������� ������� ������� ����� - ������� ������ �������� �� �����
				cout << "�������� " << requiredKey << " ��������� � ������ � ��������: " << nElement << endl;
			}
			else
			{
				//���� � ������� �� ������� ������� �����
				cout << "� ������� ��� ������ ��������" << endl;
			}
			stop = clock();
			cout << "������� ������������� " << 1000.0 * (stop - start) / CLOCKS_PER_SEC << " ms\n";

		}
		break;
		case 2:
		{
			start = clock();
			//����� �������� ����� � ������ ������ ��������
			nElement = Search_Binary(arr, 0, arrSize, requiredKey);
			if (nElement >= 0)
			{
				//���� � ������� ������� ������� ����� - ������� ������ �������� �� �����
				cout << "�������� " << requiredKey << " ��������� � ������ � ��������: " << nElement << endl;
			}
			else
			{
				//���� � ������� �� ������� ������� �����
				cout << "� ������� ��� ������ ��������" << endl;
			}
			stop = clock();
			cout << "������� ������������� " << 1000.0 * (stop - start) / CLOCKS_PER_SEC << " ms\n";
		}
		break;
		case 3:
		{
			start = clock();
			//�������� ������� ���������������� ������
			//���������, ������������ �� ��������, � ���������� result
			int result = interpolatingSearch(arr, arrSize, requiredKey);
			if (result != -1)
				//���� � ������� ������� ������� ����� - ������� ������ �������� �� �����
				cout << "�������� " << requiredKey << " ��������� � ������ � ��������: " << result << endl;
			else
				//�������� �� �������
				cout << "� ������� ��� ������ ��������" << endl;
			stop = clock();
			cout << "������� ������������� " << 1000.0 * (stop - start) / CLOCKS_PER_SEC << " ms\n";
		}
		break;
		}
	}
	system("pause");
	return 0;
}

//����� ������� �� �����
void showArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << setw(6) << arr[i];
		if ((i + 1) % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}
// �������� �����
int linSearch(int arr[], int requiredKey, int arrSize)
{
	int i = 0;
	for (; i < arrSize; i++)
	{
		if (arr[i] == requiredKey)
		{
			cout << "����� ��������!" << endl;
			cout << "���������� ������������ ���������: " << (i + 1) << endl;
			return i;
		}
			
	}
	cout << "����� ��������!" << endl;
	cout << "���������� ������������ ���������: " << (i+1) << endl;
	return -1;
}
// �������� ������ 
int Search_Binary(int arr[], int left, int right, int key)
{
	int midd = 0;
	int i = 0;
	while (true)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])       // ���� ������� ������ �������� � ������
			right = midd - 1;      // ������� ������ ������� ������
		else if (key > arr[midd])  // ���� ������� ������ �������� � ������
			left = midd + 1;    // ������� ����� ������� ������
		else                       // ����� (�������� �����)
		{
			cout << "����� ��������!" << endl;
			cout << "���������� ������������ ���������: " << (i+1) << endl;
			return midd;           // ������� ���������� ������ ������
		}
			

		if (left > right)          // ���� ������� ���������� 
		{
			cout << "����� ��������!" << endl;
			cout << "���������� ������������ ���������: " << (i + 1) << endl;
			return -1;
		}
		i++;
	}
}
// 
//�������, ����������� ��������������� �����
//� ������� ���������� ��������� ������, ������ ������� � ���� ������
int interpolatingSearch(int a[], int arraySize, int keyOfSearch)
{
	//��������� ����������� ��������� ����������
	//���������� ������������� ������ ������ �� ������ �������,
	//� ������ �� ����� �������
	int low = 0;
	int high = arraySize - 1;
	int mid;
	//���� ���������������� ������
	int countIt = 0;
	while (a[low] < keyOfSearch && a[high] >= keyOfSearch)
	{
		//��������������� ����� ���������� ������ ����� ������� ������
		//�� ���������� ����� ������ ������ � ������� �������� ��������
		mid = low + ((keyOfSearch - a[low]) * (high - low)) / (a[high] - a[low]);
		//���� �������� � ������ � �������� mid ������, �� ������� ������ �������
		if (a[mid] < keyOfSearch)
			low = mid + 1;
		//� ������, ���� �������� ������, �� ������� ������� �������
		else if (a[mid] > keyOfSearch)
			high = mid - 1;
		//���� �����, �� ���������� ������
		else
		{
			cout << "����� ��������!" << endl;
			return mid;
		}		
		countIt++;
	}
	//���� ���� while �� ������ ������ �������� ��������,
	//�� ��������� �� ��������� �� ��� � ������ ������� � �������� low,
	//����� ���������� -1 (�������� �� �������)
	if (a[low] == keyOfSearch)
	{
		cout << "����� ��������!" << endl;
		cout << "���������� ������������ ���������: " << (countIt + 1) << endl;
		return low;
	}
	else
	{
		cout << "����� ��������!" << endl;
		cout << "���������� ������������ ���������: " << (countIt + 1) << endl;
		return -1;
	}
}
#pragma once

struct Point;

class SummerPractise
{
public:
	/* ����� � ������� ����� �� �������� */
	static void task1(char symbol, unsigned int countSymbol, unsigned int countLines);
	/* ����� � ������� ����� �� ���� �� number */
	static void task2(int number);
	/* ����� � ������� ���� ����� �� ��������� */
	static void task3(int start, int end);
	/* ����� � ������� ���� ������ ����� �� ��������� */
	static void task4(int start, int end);
	/* ����� � ������� ���� �������� ����� �� ��������� */
	static void task5(int start, int end);
	/* ����� � ������� ���������� ���� � ����� number */
	static void task6(int number);
	/* ����� � ������� ������ ����� number */
	static void task7(int number);
	/* ����� � ������� ������� ����� number (����������� ������������� �������) */
	static void task8(double number, double degree);
	/* ����� � ������� ����� ���������� �������������� ������������ �� ����� ������� */
	static void task9(double sideLength1, double sideLength2);
	/* ����� � ������� ���������� ����� ����� ������� � ������������ (x,y,z) */
	static void task10(Point point1, Point point2);
};

struct Point
{
	double x;
	double y;
	double z;
};

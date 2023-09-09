#include <iostream>
#include <fstream>
using namespace std;

enum menuitem {QUIT};

double GetDouble() {
	double value = 0;
	while (!(cin >> value)) {
		while (getchar() != '\n'); {
			cin.clear();
			cout << "������ �����. ������� �����.";
		}
	}
	return value;
}

int ExitChoise() {
	int value1 = 0;
	cout << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "����� ������ ����� - ��������� ��������� ��������" << endl;
	while (!(cin >> value1)) {
		while (getchar() != '\n'); {
			cin.clear();
			cout << "������ �����. ������� �����.";
		}
	}
	return value1;
}

double Function(int number, double r1, double r2, double distance) {
	double function;
	if (number == 1) {
		function = 2 * acos((r1*r1 - r2 * r2 + distance * distance) / (2 * r1 * distance));
	}
	else {
		function = 2 * acos((r2*r2 - r1 * r1 + distance * distance) / (2 * r2 * distance));
	}
	return function;
}

double Square(double r, double f) {
	double square = 0;
	square = (r*r * (f - sin(f))) / 2;
	return square;
}

struct circle {
	double radius;
	double x;
	double y;
};

int main() {
	int userchoise = 0;
	do {
		setlocale(LC_ALL, "RU");
		double distance = 0;
		circle one = { 0, 0, 0 };
		circle two = { 0, 0, 0 };
		double f1, f2;
		double s, s1, s2;
		cout << "������� ������ ��� ������ ����������: " << endl;
		do {
			cout << "R1 = ";
			one.radius = GetDouble();
			if (one.radius < 0) {
				cout << "�������� ������� �� ����� ���� �������������. ���������� �����." << endl;
 			}
		} while (one.radius < 0);
		cout << "X1 = ";
		one.x = GetDouble();
		cout << "Y1 = ";
		one.y = GetDouble();
		system("cls");
		cout << "���������� � ������� � ����� (" << one.x << "," << one.y << ") � �������� " << one.radius << endl;
		cout << "������� ������ ��� ������ ����������: " << endl;
		do {
			cout << "R2 = ";
			two.radius = GetDouble();
			if (two.radius < 0) {
				cout << "�������� ������� �� ����� ���� �������������. ���������� �����." << endl;
			}
		} while (two.radius < 0);
		cout << "X2 = ";
		two.x = GetDouble();
		cout << "Y2 = ";
		two.y = GetDouble();
		system("cls");
		cout << "���������� � ������� � ����� (" << one.x << "," << one.y << ") � �������� " << one.radius << endl;
		cout << "���������� � ������� � ����� (" << two.x << "," << two.y << ") � �������� " << two.radius << endl;
		distance = sqrt((one.x - two.x) * (one.x - two.x) + (one.y - two.y) * (one.y - two.y));
		if (one.radius == 0 && two.radius == 0) {
			cout << "����������� �� ����������" << endl;
		}
		else if (distance >= one.radius + two.radius) {
			cout << "���������� �� ������������" << endl;
		}
		else if (distance <= fabs(one.radius - two.radius)) {
			cout << "���� ���������� ����� � ������" << endl;
		}
		else {
			f1 = Function(1, one.radius, two.radius, distance);
			f2 = Function(2, one.radius, two.radius, distance);
			s1 = Square(one.radius, f1);
			s2 = Square(two.radius, f2);
			s = s1 + s2;
			cout << "������� ����������� ����������� " << s << endl;
		}
		userchoise = ExitChoise();
	} while (userchoise != QUIT);
}
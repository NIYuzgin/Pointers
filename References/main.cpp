#include <iostream>

using namespace std;

//void Exchange(int a, int b);

void main() {
	setlocale(LC_ALL, "");

	int a = 2;
	int& ra = a; // ���������� ��� ������ ����� ����� ���������� 'a' � ���������� ��� � ������ 'ra';
	ra += 3;

	cout << a << endl;
	
	cout << &a << endl;
	cout << &ra << endl;
}


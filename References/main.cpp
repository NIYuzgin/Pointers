#include <iostream>

using namespace std;

//void Exchange(int a, int b);

void main() {
	setlocale(LC_ALL, "");

	int a = 2;
	int& ra = a; // компилятор сам неявно берет адрес переменной 'a' и записывает его в ссылку 'ra';
	ra += 3;

	cout << a << endl;
	
	cout << &a << endl;
	cout << &ra << endl;
}



#include <iostream>


// #define POINTERS_BASICS

using namespace std;

void main() {
	setlocale(LC_ALL, "");
	
	
	/*int a = 2;
	int* pa = &a;
	cout << a << endl; // вывод переменной 'a' на экран

	cout << &a << endl;// вывод адреса переменной 'a' прямо при выводе

	cout << pa << endl;// вывод адреса переменной 'a', хранящегося в указателе 'pa'
	cout << *pa << endl;// рызыменование указателя 'pa', и вывод на экран значения по адресу

	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;

*/

	const int n = 5;
	int arr[n] = { 3, 5, 8 , 13, 21 };

	cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << endl;
	}

	cout << endl;




}


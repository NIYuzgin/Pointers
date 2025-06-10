#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

/*
int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
*/

void main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n; 
	int* arr = new int[n]; // объявление динамического массива
	
	
	
	
	FillRand(arr, n);
	Print(arr, n);

	/*
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);
	
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_front(arr, n, value);

	arr = pop_back(arr, n);


	Print(arr, n);
	
	arr = pop_front(arr, n);


	Print(arr, n);
	*/
	
	delete[] arr;
}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
			*(arr + i) = rand() % 100; // через арифметику указателей и оператор разыменования 
		}
}

void Print(int arr[], const int n) {
	cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t"; // через оператор индексирования (Subscript operator)
	}
	cout << endl;
}

/*

int* push_back(int arr[], int& n, const int value)
{
	
	// 1) создаем буферный массив нужного размера:

	int* buffer = new int[n + 1];

	// 2) копируем все элементы из исходного массива в буферный:

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	// 3) удаляем исходный массив:

	delete[] arr;

	// 4) подменяем адрес исходного массива адресом нового массива:

	arr = buffer;
	buffer = nullptr;

	// 5) только после всего вышенаписанного в массиве 'arr' появляется элемент,
		  //в который можно сохранить добавленноре значение

	arr[n] = value;

	// 6) 
	n++;

	// 7) Mission complete - значение добавлено

	return buffer;
}

int* push_front(int arr[], int& n, const int value)
{
	
	// 1) создаем буферный массив нужного размера:

	int* buffer = new int[n + 1];
	
	// 2) копируем все элементы из исходного массива в буферный:

	for (int i = 0; i < n; i++)
	{

		buffer[i+1] = arr[i];
	}

	// 3) удаляем исходный массив:

	delete[] arr;

	// 4) 
	
	buffer[0] = value;

	n++;
	
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];

	for (int i = 0; i < n; i++)
	{

		buffer[i] = arr[i];
	}
	
	delete[] arr;

	return buffer;
}

int* pop_front(int arr[], int& n)
{
	
	int* buffer = new int[--n];

	for (int i = 0; i < n; i++) buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
*/








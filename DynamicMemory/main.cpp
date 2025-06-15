#include <iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(cons int rows, const int cols);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);


int* InsertElement(int* arr, int* size, int index, int element);
int* EraseElement(int* arr, int* size, int index);

// #define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main() {
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1



	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n]; // объявление динамического массива

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);


	cout << endl << endl << "Функция вставки элемента по указанному индексу" << endl;
	cout << "----------------" << endl;
	int element;
	int index;

	cout << endl << "Введите значение элемента, который необходимо добавить в массив" << endl;
	cin >> element;
	cout << endl << "Введите значение индекса, по которому необходимо добавить элемент в массив" << endl;
	cin >> index;

	while (index > n - 1) {
		cout << "Значение индекса НЕ должно быть больше: " << n - 1 << ".  Введите значение индекса, по которому необходимо добавить элемент в массив" << endl;
		cin >> index;
	}
	arr = InsertElement(arr, &n, index, element);
	cout << endl << "Новый массив:" << endl;
	Print(arr, n);

	cout << endl << endl << "Функция удаления элемента по указанному индексу" << endl;
	cout << "----------------" << endl;
	cout << endl << "Введите значение индекса, по которому необходимо удалить элемент из массива" << endl;
	cin >> index;
	while (index > n - 1) {
		cout << "Значение индекса НЕ должно быть больше: " << n - 1 << ".  Введите значение индекса, по которому необходимо добавить элемент в массив" << endl;
		cin >> index;
	}
	arr = EraseElement(arr, &n, index);
	cout << endl << "Новый массив:" << endl;
	Print(arr, n);

	delete[] arr;

#endif DYNAMIC_MEMORY_2

	int rows;
	int cols;

	cout << "ВВедите количество строк: "; cin >> rows;
	cout << "ВВедите количество элементов строки: "; cin >> cols;

	// Объявление двумерного динамического массива

	// 1) Создаем массив указателей:
	int** arr = new int* [rows];

	// 2) Выделяем память под строки:

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);

	
	// Удаление двумерного динамического массива

	// 1) Сначала удаляются строки двумерного массива:
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}

	// 2) Только теперь можно удалить массив указателей;
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand) {
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % (maxRand - minRand) + minRand; // через арифметику указателей и оператор разыменования 
	}
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
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

void Print(int** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, const int value) {

	// 1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	// 2) Копируем все элементы из исходного массива в буферный:
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}

	// 3) Удаляем исходный массив:
	delete[] arr;

	// 4) Подменяем адрес исходного массива адресом нового массива:
	arr = buffer;
	// buffer = nullptr; // nullptr - указатель на 0;

	// 5) Только после всего вышенаписанного в массиве 'arr' появляется элемент,
	//    в который можно сохранить добавляемое значение.
	arr[n] = value;

	// 6) после добавления элемента в массив, количество его элементов увеличивается на 1;
	n++;

	// 7) Mission complete - значение добавлено.

	return buffer;
}

int* push_front(int arr[], int& n, const int value) {

	// 1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	// 2) Копируем все элементы из исходного массива в буферный:
	for (int i = 0; i < n; i++) {
		buffer[i + 1] = arr[i];
	}

	// 3) Удаляем исходный массив:
	delete[] arr;

	// 4) 
	buffer[0] = value;

	// 5) 
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n) {
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n) {
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;

}

int** push_row_back(int** arr, int& rows, const int cols) {

	// 1) создаем буферный массив указателей нужного размера:
	int** buffer = new int* [rows + 1];

	// 2) Копируем адреса строк в новый массив:
	for (int i = 0; i < rows; i++) {
		buffer[i] = arr[i];
	}
	// удаляем исходный массив указателей
	delete[] arr;

	// 4) Добавляем добавляемую строку:
	buffer[rows] = new int[cols] {};

	// 5) После добавления строки, количество строк увеличивается на 1:
	rows++;

	// 6) Возвращаем новый массив
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols) {
	for (int i = 0; i < rows; i++) {

		// 1) Создаем буферную строку нужного размера:
		int* buffer = new int[cols + 1] {};

		// 2) копируем элементы из исходной строки в буферную:
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];

		// 3) Удаляем исходную строку:
		delete[] arr[i];

		// 4) Подменяем адрес исходной строки адресом новой строки:
		arr[i] = buffer;
	}
	cols++;
}

int* InsertElement(int* arr, int* size, int index, int element) {

	int new_size = *size + 1;
	int* temp = new int[new_size];
	for (int i = 0; i < index; i++) {
		*(temp + i) = *(arr + i);
	}
	*(temp + index) = element;
	for (int i = index + 1, j = index; i < new_size; i++, j++) {
		*(temp + i) = *(arr + j);
	}
	*size = new_size;
	return temp;
}

int* EraseElement(int* arr, int* size, int index) {
	int new_size = *size - 1;
	int* temp = new int[new_size];
	for (int i = 0, j = 0; i < *size; i++) {
		if (i == index) continue;
		*(temp + j) = *(arr + i);
		j++;
	}
	*size = new_size;
	return temp;

}



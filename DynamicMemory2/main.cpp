#include <iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int**& arr, const int rows, const int cols = 0);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);

int** pop_row_back(int** arr, int& rows);
int** pop_row_front(int** arr, int& rows);
int** erase_row(int** arr, int& rows, const int cols, const int index);

int** insert_row(int** arr, int& rows, const int cols, const int index);
void insert_col(int** arr, const int rows, int& cols, const int index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);

void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_cols(int** arr, const int rows, int& cols, const int index);

int* insert(int arr[], int& n, const int value, const int index);
int* erase(int arr[], int& n, const int index);

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

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

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите значение индекса, по которому необходимо добавить элемент в массив: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	
	cout << "Введите значение индекса, по которому необходимо удалить элемент из массива: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;

#endif DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;

	cout << "ВВедите количество строк: "; cin >> rows;
	cout << "ВВедите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);

	//Copy - функция НЕ изменяет переданную в нее память, а возвращает измененную копию полученной памяти.
	//Mutable - функция изменяет полученный блок памяти.

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);

	push_col_front(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][0] = rand() % 1000;
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows);
	Print(arr, rows, cols);

	arr = pop_row_front(arr, rows);
	Print(arr, rows, cols);

	int index;
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_cols(arr, rows, cols, index);
	Print(arr, rows, cols);
	
	Clear(arr, rows, cols);

#endif DYNAMIC_MEMORY_2
	
}

int** Allocate(const int rows, const int cols) {
	// Объявление двумерного динамического массива

	// 1) Создаем массив указателей:
	int** arr = new int* [rows];

	// 2) Выделяем память под строки:

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	return arr;
}

void Clear(int**& arr, const int rows, const int cols) {
	// Удаление двумерного динамического массива

	// 1) Сначала удаляются строки двумерного массива:
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}

	// 2) Только теперь можно удалить массив указателей;
	delete[] arr;

	// Зануляем указатель на массив
	arr = nullptr;
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

int** push_row_front(int** arr, int& rows, const int cols) {
	// 1) создаем буферный массив указателей нужного размера:
	int** buffer = new int* [rows + 1];

	// 2) Копируем адреса строк в новый массив:
	for (int i = 0; i < rows; i++) {
		buffer[i + 1] = arr[i];
	}
	// удаляем исходный массив указателей
	delete[] arr;

	// 4) Добавляем добавляемую строку:
	buffer[0] = new int[cols] {};

	// 5) После добавления строки, количество строк увеличивается на 1:
	rows++;

	// 6) Возвращаем новый массив
	return buffer;
}

int** pop_row_back(int** arr, int& rows) {
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int** pop_row_front(int** arr, int& rows) {
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int** erase_row(int** arr, int& rows, const int cols, const int index) {
	int** buffer = new int* [rows - 1];
	if (index < 0 || index > rows) {
		cout << "Error: Out of range exception" << endl;
		return arr;
	}

	for (int i = 0; i < rows; i++) {
		/*
		if (i < index)buffer[i] = arr[i];
		else buffer[i] = arr[i + 1];
		*/
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	//buffer[index] = new int[cols] {};
	rows--;
	return buffer;
}

int** insert_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows + 1] {};
	if (index < 0 || index > rows) {
		cout << "Error: Out of range exception" << endl;
		return arr;
	}
	
	/*
	for (int i = 0; i < index; i++)	buffer[i] = arr[i];
	for (int i = index; i < rows; i++) buffer[i + 1] = arr[i];
	*/
	
	for (int i = 0; i < rows; i++) {
		
		/*
		if (i < index)buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];
		*/
		
		//i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];

		buffer[i < index ? i : i + 1] = arr[i];
	}

	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
}

void insert_col(int** arr, const int rows, int& cols, const int index) {
	if (index < 0 || index > cols) {
		cout << "Error: Out of range exception" << endl;
	}

	for (int i = 0; i < rows; i++) {

		// 1) Создаем буферную строку нужного размера:
		int* buffer = new int[cols + 1] {};

		// 2) копируем элементы из исходной строки в буферную:
		for (int j = 0; j < cols; j++) buffer[j < index ? j : j + 1] = arr[i][j];

		// 3) Удаляем исходную строку:
		delete[] arr[i];

		// 4) Подменяем адрес исходной строки адресом новой строки:
		arr[i] = buffer;
	}
	cols++;
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

void push_col_front(int** arr, const int rows, int& cols) {
	for (int i = 0; i < rows; i++) {

		// 1) Создаем буферную строку нужного размера:
		int* buffer = new int[cols + 1] {};

		// 2) копируем элементы из исходной строки в буферную:
		for (int j = 0; j < cols + 1; j++) buffer[j + 1] = arr[i][j];

		// 3) Удаляем исходную строку:
		delete[] arr[i];

		// 4) Подменяем адрес исходной строки адресом новой строки:
		arr[i] = buffer;
	}
	cols++;
}

void pop_col_back(int** arr, const int rows, int& cols) {

	for (int i = 0; i < rows; i++) {

		// 1) Создаем буферную строку нужного размера:
		int* buffer = new int[cols - 1] {};

		// 2) копируем элементы из исходной строки в буферную:
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j];

		// 3) Удаляем исходную строку:
		delete[] arr[i];

		// 4) Подменяем адрес исходной строки адресом новой строки:
		arr[i] = buffer;
	}
	cols--;
}

void pop_col_front(int** arr, const int rows, int& cols) {
	for (int i = 0; i < rows; i++) {

		// 1) Создаем буферную строку нужного размера:
		int* buffer = new int[cols - 1] {};

		// 2) копируем элементы из исходной строки в буферную:
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j + 1];

		// 3) Удаляем исходную строку:
		delete[] arr[i];

		// 4) Подменяем адрес исходной строки адресом новой строки:
		arr[i] = buffer;
	}
	cols--;
}

void erase_cols(int** arr, const int rows, int& cols, const int index) {
	if (index < 0 || index > cols) {
		cout << "Error: Out of range exception" << endl;
	}

	for (int i = 0; i < rows; i++) {

		// 1) Создаем буферную строку нужного размера:
		int* buffer = new int[cols - 1] {};

		// 2) копируем элементы из исходной строки в буферную:
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j < index ? j : j + 1];
			
			//buffer[j] = arr[i][j + 1];

			// 3) Удаляем исходную строку:
			delete[] arr[i];

			// 4) Подменяем адрес исходной строки адресом новой строки:
			arr[i] = buffer;
		}
		cols--;
}

int* insert(int arr[], int& n, const int value, const int index) {
	if (index < 0 || index > n) {
		cout << "Error: Out of range exception" << endl;
	}
	
	// 1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	// 2) Копируем все элементы из исходного массива в буферный:
	for (int i = 0; i < n; i++) buffer[i < index ? i : i + 1] = arr[i];

	// 3) Удаляем исходный массив:
	delete[] arr;

	// 4) 
	buffer[index] = value;

	// 5) 
	n++;
	return buffer;
}

int* erase(int arr[], int& n, const int index) {
	if (index < 0 || index > n) cout << "Error: Out of range exception" << endl;
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++) buffer[i] = arr[i < index ? i : i + 1];
	delete[] arr;
	n--;
	return buffer;
}

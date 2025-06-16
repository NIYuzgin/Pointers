#include <iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T**& arr, const int rows, const int cols = 0);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

template <typename T> void Print(T arr[], const int n);
template <typename T> void Print(T** arr, const int rows, const int cols);

template <typename T>T* push_back(T arr[], int& n, const T value);
template <typename T>T* push_front(T arr[], int& n, const T value);
template <typename T>T* insert(T arr[], int& n, const T value, const int index);

template <typename T>T* pop_back(T arr[], int& n);
template <typename T>T* pop_front(T arr[], int& n);

template <typename T>T** push_row_back(T** arr, int& rows, const int cols);
template <typename T>T** insert_row(T** arr, int& rows, const int cols, const int index);
template <typename T>void push_col_back(T** arr, const int rows, int& cols);



template <typename T>T** pop_row_back(T** arr, int& rows, const int cols);





int* InsertElement(int* arr, int* size, int index, int element);
int* EraseElement(int* arr, int* size, int index);

//TO DO: Optimization


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

#define DATATYPE double
typedef double DataType;

void main() {
	setlocale(LC_ALL, "");
	
#ifdef DYNAMIC_MEMORY_1

	int n;
	cout << "Введите размер массива: "; cin >> n;
	DataType* arr = new DataType[n]; // объявление динамического массива

	FillRand(arr, n);
	Print(arr, n);

	DataType value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << endl << "Введите индекс добавляемого элемента: " << endl; cin >> index;
	cout << endl << "Введите значение добавляемого элемента: " << endl; cin >> value;
	/*
	arr = insert(arr, n, value, index);
	Print(arr, n);
	*/
	Print(arr = insert(arr, n, value, index), n);
	

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	/*
	cout << endl << endl << "Функция вставки элемента по указанному индексу" << endl;
	cout << "----------------" << endl;
	int element;
	//int index;

	cout << endl << "Введите значение элемента, который необходимо добавить в массив" << endl;
	cin >> element;
	//cout << endl << "Введите значение индекса, по которому необходимо добавить элемент в массив" << endl;
	//cin >> index;

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
	*/

	delete[] arr;

#endif DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;

	cout << "ВВедите количество строк: "; cin >> rows;
	cout << "ВВедите количество элементов строки: "; cin >> cols;

	DataType** arr = Allocate<DataType>(rows, cols);

	//Copy - функция НЕ изменяет переданную в нее память, а возвращает измененную копию полученной памяти.
	//Mutable - функция изменяет полученный блок памяти.

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][cols - 1] = double(rand() % 10000)/10;
	Print(arr, rows, cols);

	int index;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);

	


	Clear(arr, rows, cols);

#endif DYNAMIC_MEMORY_2

}

template<typename T>T** Allocate(const int rows, const int cols) {
	// Объявление двумерного динамического массива

	// 1) Создаем массив указателей:
	T** arr = new T* [rows];

	// 2) Выделяем память под строки:

	for (int i = 0; i < rows; i++) {
		arr[i] = new T[cols];
	}
	return arr;
}

template<typename T> void Clear(T**& arr, const int rows, const int cols) {
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

void FillRand(double arr[], const int n, int minRand, int maxRand) {
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % (maxRand - minRand) + minRand; // через арифметику указателей и оператор разыменования 
		arr[i] /= 100;
	}

}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}

void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand) {
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = double(rand() % (maxRand - minRand) + minRand)/100;
		}
	}
}

template<typename T> void Print(T arr[], const int n) {
	cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t"; // через оператор индексирования (Subscript operator)
	}
	cout << endl;
}

template<typename T> void Print(T** arr, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T> T* push_back(T arr[], int& n, const T value) {
	// 1) Создаем буферный массив нужного размера:
	T* buffer = new T[n + 1];

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

template<typename T> T* push_front(T arr[], int& n, const T value) {
// 1) Создаем буферный массив нужного размера:
	T* buffer = new T[n + 1];

	// 2) Копируем все элементы из исходного массива в буферный:
	for (int i = 0; i < n; i++) buffer[i + 1] = arr[i];
	// 3) Удаляем исходный массив:
	delete[] arr;

	// 4) 
	buffer[0] = value;

	// 5) 
	n++;
	return buffer;
}

template<typename T> T* insert(T arr[], int& n, const T value, const int index) {
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++) buffer[i < index ? i : i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

template<typename T> T* pop_back(T arr[], int& n) {
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T> T* pop_front(T arr[], int& n) {
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T> T** push_row_back(T** arr, int& rows, const int cols) {
	
	return push_back (arr, rows, new T[cols]); //повторное использование кода (Reusable code)
	// DRY - Don,t Repeat Yourself
}

template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index) {
	T** buffer = new T* [rows + 1] {};
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
	buffer[index] = new T[cols] {};
	rows++;
	return buffer;
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols) {
	for (int i = 0; i < rows; i++) {

		// 1) Создаем буферную строку нужного размера:
		T* buffer = new T[cols + 1] {};

		// 2) копируем элементы из исходной строки в буферную:
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];

		// 3) Удаляем исходную строку:
		delete[] arr[i];

		// 4) Подменяем адрес исходной строки адресом новой строки:
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>
T** pop_row_back(T** arr, int& rows, const int cols)
{
	
	delete[] arr[rows - 1];
	return pop_back(arr, rows);

	
	
	
	
	
	
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


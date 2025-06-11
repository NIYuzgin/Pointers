#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);

void FillRand(int** arr, const int rows, const int cols, int minRand=0, int maxRand=100);


void Print(int arr[], const int n);

void Print(int** arr, const int rows, const int cols);

//void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);


int* InsertElement(int* arr, int* size, int index, int element);
int* EraseElement(int* arr, int* size, int index);


int** push_row_back (int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);
//#define 



void main() {
	setlocale(LC_ALL, "");
	/*
	int n;
	cout << "Введите размер массива: "; cin >> n; 
	int* arr = new int[n]; // объявление динамического массива
	
	FillRand(arr, n);
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
	*/

	int rows;
	int cols;

	cout << "строки"; cin >> rows;

	cout << "столбцы"; cin >> cols;

	int** arr = new int* [rows];

for (int i = 0; i < rows; i++) {

				arr[i] = new int[cols];

			}
	
/*
for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			
			arr[i][j] = rand()%100;
		}

		
	}
*/
	
FillRand(arr, rows, cols);

Print(arr, rows, cols);

cout << endl;

arr = push_row_back(arr, rows, cols);
//FillRand(arr[rows-1], cols, 100, 10000);



Print(arr, rows, cols);

push_col_back(arr, rows, cols);

//for (int = 0; )

cout << endl;

Print(arr, rows, cols);


	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
			*(arr + i) = rand() % 100; // через арифметику указателей и оператор разыменования 
		}
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {


			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}


	}








}

void Print(int arr[], const int n) {
	//cout << arr << endl;
	//cout << *arr << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t"; // через оператор индексирования (Subscript operator)
	}
	//cout << endl;
}

void Print(int** arr, const int rows, const int cols)
{

for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout<< arr[i][j] << "\t";
		}
		cout << endl;

	}



}

int* InsertElement(int* arr, int* size, int index, int element)
{
	
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

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) создаем бу

	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows; i++) {
		
		buffer[i] = arr[i];

	}
	delete[]arr;

	buffer[rows] = new int[cols] {};
	rows++;




	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++) {

		int* buffer = new int[cols + 1] {};


		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];

		delete[]arr;

		arr[i] = buffer;

	}
	
	cols++;
}






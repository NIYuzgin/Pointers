#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* InsertElement(int* arr, int* size, int index, int element);
int* EraseElement(int* arr, int* size, int index);

void main() {
	setlocale(LC_ALL, "");
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
}

void FillRand(int arr[], const int n) {
	for (int i = 0; i < n; i++) {
			*(arr + i) = rand() % 100; // через арифметику указателей и оператор разыменования 
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






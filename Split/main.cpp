﻿#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main() {
	setlocale(LC_ALL, "");
	const int n = 10;

	int arr[n];

	FillRand(arr, n);
	Print(arr, n);

	int even_count = 0;
	int odd_count = 0;

	for (int i = 0; i < n; i++)
	{
		/*if (arr[i] % 2 == 0) even_count++;
		else odd_count++;
		*/
		(arr[i] % 2 ? odd_count : even_count)++;
	}
	cout << "Количество четных элементов: " << even_count << endl;

	cout << "Количество нечетных элементов: " << odd_count << endl;

	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	for (int i = 0, j=0, k=0; i < n; i++)
	{
		/*
		if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		else odd_arr[k++] = arr[i];
		*/

		(arr[i] % 2 ? odd_arr[j++] : even_arr[k++])=arr[i];

	}

	Print(even_arr, even_count);

	Print(odd_arr, odd_count);

	delete[] odd_arr;
	delete[] even_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	//cout << arr << endl;
	//cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

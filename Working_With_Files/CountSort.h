#pragma once
#include <iostream>
int getMax(int* arr, int n) // фунция для нахождения максимального элемента
{
	int max = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void countSort(int* arr, int n)
{
	int* output = new int[n]; //выделяем память под временный массив
	int max = getMax(arr, n); // находим максимальный элемент массива
	int* count = new int[max + 1]; //выделяем память под массив частот

	// заполняем массив нолями
	for (int i = 0; i < max + 1; ++i)
	{
		count[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		count[arr[i]]++; // подсчитываем частоту повторения элементов

	}
	
	for (int i = 0, j = 0; i <= max; i++)
	{
		while (count[i]--)
			output[j++] = i;
	}
	


	for (int i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}

	delete[]output;// удаляем ненужные массивы
	delete[]count;
}
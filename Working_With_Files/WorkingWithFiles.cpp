#include <string>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono> //  для получения времени

//#include "quickSort.h"
#include "CountSort.h"
//#include"RadixSort.h"
//#include"BucketSort.h"
//#include"BubbleSort.h"
//#include"MergeSort.h"
//#include"InsertionSort.h"
//#include"SelectionSort.h"
//#include"TimSort.h"

using namespace std;

void write_arr(const string& filename, const int* arr, const int n)
{
	fstream fs;
	fs.open(filename, fstream::out);
	if (fs.is_open())// проверяем что файл успешно открыт
	{
		fs << n << '\n';//записываем размер массива
		for (int i = 0; i < n; i++)
			fs << arr[i] << ' ';//записываем значения через пробел
		fs << '\n';

		fs.close();//закрываем файл
	}
}

void read_arr(const string& filename,  int* arr, int n)
{
	fstream fs;

	fs.open(filename, fstream::in);
	if (fs.is_open())// проверяем что файл успешно открыт
	{
		fs >> n; // читаем размер массива
		arr = new int[n];
		for (int i = 0; i < n; ++i)
			fs >> arr[i];// читаем из файла разделительные символы - пробел и перенос строки

		fs.close();//закрываем файл
	}
}
void fillingArray( int* rand_arr, const int size,const int  range_len)
{
	srand(time(nullptr));//используем текущее время, чтобы сгенерировать случайные значения
	int lef_border = 5;
		for (int i = 0; i < size; ++i)
		rand_arr[i] = lef_border + rand() % range_len;//генерируем число в указанном диапазоне и записываем в массив

}
int main()
{

	string filename = "array_little_data.txt";
	const int littleSize = 100;
	int *arr=new int[littleSize];

	for  (int i=0;i<littleSize;++i)
	{
		arr[i] = 5;
	}

	write_arr(filename, arr, littleSize);//записываем массив в файл

	int* array_from_file = nullptr;
	int n = 0;
	read_arr(filename, array_from_file, n);//читаем массив из файла

	auto start = chrono::high_resolution_clock::now(); //сохраняем время начала работы алгоритмма
	//quickSort(array_from_file, 0, n);//запускаем сортировку
	countSort(array_from_file,n);
	//radixSort(array_from_file, n);
	//bucketSort(array_from_file, n);
	//bubbleSort(array_from_file, n);
	//mergeSort(array_from_file, 0, n-1);
	//insertionSort(array_from_file, n)
	//selectionSort(array_from_file, n);
	//timSort(array_from_file, n);

	auto finish = chrono::high_resolution_clock::now(); // сохраняем время конца работы алгоритма
	chrono::duration<double>elapsed = finish - start;
	cout << "Elapsed time of a small array with values from a small range: " << elapsed.count() << " sec" << endl;
	delete[]arr;
	//----------------------------------------------------------------------------------------------------
    filename = "array_big_data_little.txt";
	const int bigSize = 500000;
	int* littleArr = new int[bigSize];

	fillingArray(littleArr, bigSize, 10);

	write_arr(filename, littleArr, bigSize);//записываем массив в файл

	array_from_file = nullptr;
	n = 0;
	read_arr(filename, array_from_file, n);//читаем массив из файла
	
	start = chrono::high_resolution_clock::now(); //сохраняем время начала работы алгоритмма
	//quickSort(array_from_file, 0, n);//запускаем сортировку
	countSort(array_from_file, n);
	//radixSort(array_from_file, n);
	//bucketSort(array_from_file, n);
	//bubbleSort(array_from_file, n);
	//mergeSort(array_from_file, 0, n - 1);
	//insertionSort(array_from_file, n);
	//selectionSort(array_from_file, n);
	//timSort(array_from_file, n);
	finish = chrono::high_resolution_clock::now(); // сохраняем время конца работы алгоритма
	elapsed = finish - start;
	cout << "Elapsed time is a large array with values from a small range: " << elapsed.count() << " sec" << endl;

	delete[] littleArr;
	//--------------------------------------------------------------------------------------------------

	filename = "array_big_data_big.txt";
	
	int* bigArr = new int[bigSize];

	fillingArray(bigArr, bigSize, 1000);

	write_arr(filename, bigArr, bigSize);//записываем массив в файл

	array_from_file = nullptr;
    n = 0;
	read_arr(filename, array_from_file, n);//читаем массив из файла
	
	start = chrono::high_resolution_clock::now(); //сохраняем время начала работы алгоритмма
	//quickSort(array_from_file, 0, n);//запускаем сортировку
	countSort(array_from_file, n);
	//radixSort(array_from_file, n);
	//bucketSort(array_from_file, n);
	//bubbleSort(array_from_file, n);
	//mergeSort(array_from_file, 0, n - 1);
	//insertionSort(array_from_file, n);
	//selectionSort(array_from_file, n);
	//timSort(array_from_file, n);
    finish = chrono::high_resolution_clock::now(); // сохраняем время конца работы алгоритма
    elapsed = finish - start;
    cout << "Elapsed time of a large array with values from a large range: " << elapsed.count() << " sec" << endl;

	delete[] bigArr;
	delete[] array_from_file;

	return 0;
}
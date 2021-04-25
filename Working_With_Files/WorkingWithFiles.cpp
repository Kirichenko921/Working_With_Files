#include <string>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include <ctime>
#include <chrono> //  для получения времени
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
void swap(int* a, int* b) // функция для смены местами двух значений
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[high];    // опорный элемент
    int i = (low - 1);  // индекс наименьшего элемента
    for (int j = low; j <= high - 1; j++)
    {
        // если текущий элемент меньше или равен опорнуму
        if (arr[j] <= pivot)
        {
            i++; // увеличиваем индекс минимального элемента
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // индекс опорного элемента

        // рекурсивыне вызовы для правой и левой частей входного массива
        if (pi > 0 && pi < high)
        {
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
        else if (pi == high)
        {

            --high;
            quickSort(arr, low, high);
        }
        else
        {
            ++low;
            quickSort(arr, low, high);
        }

    }
}
int main()
{
	string filename = "array_data.txt";
	const int size = 500000;
	int* rand_arr = new int[size];

	srand(time(nullptr));//используем текущее время, чтобы сгенерировать случайные значения
	int lef_border = 5;
	int range_len = 1000;//правая граница = range_len+lef_border
	for (int i = 0; i < size; ++i)
			rand_arr[i] = lef_border + rand() % range_len;//генерируем число в указанном диапазоне и записываем в массив

	write_arr(filename, rand_arr, size);//записываем массив в файл

	int* array_from_file = nullptr;
	int n = 0;
	read_arr(filename, array_from_file, n);//читаем массив из файла

	auto start = chrono::high_resolution_clock::now(); //сохраняем время начала работы алгоритмма
    quickSort(array_from_file, 0, n);//запускаем сортировку
    auto finish = chrono::high_resolution_clock::now(); // сохраняем время конца работы алгоритма
    chrono::duration<double>elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;

	delete[] rand_arr;
	delete[] array_from_file;

	return 0;
}
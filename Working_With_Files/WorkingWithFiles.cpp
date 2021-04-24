#include <string>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;

void write_arr(const string& filename, const int* arr, const int n)
{
	fstream fs;
	fs.open(filename, fstream::out);
	if (fs.is_open())// ��������� ��� ���� ������� ������
	{
		fs << n << '\n';//���������� ������ �������
		for (int i = 0; i < n; i++)
			fs << arr[i] << ' ';//���������� �������� ����� ������
		fs << '\n';

		fs.close();//��������� ����
	}
}

void read_arr(const string& filename,  int* arr, int n)
{
	fstream fs;

	fs.open(filename, fstream::in);
	if (fs.is_open())// ��������� ��� ���� ������� ������
	{
		fs >> n; // ������ ������ �������
		arr = new int[n];
		for (int i = 0; i < n; ++i)
			fs >> arr[i];// ������ �� ����� �������������� ������� - ������ � ������� ������

		fs.close();//��������� ����
	}
}

int main()
{
	string filename = "array_data.txt";
	const int size = 100;
	int* rand_arr = new int[size];

	srand(time(nullptr));//���������� ������� �����, ����� ������������� ��������� ��������
	int lef_border = 5;
	int range_len = 10;//������ ������� = range_len+lef_border
	for (int i = 0; i < size; ++i)
			rand_arr[i] = lef_border + rand() % range_len;//���������� ����� � ��������� ��������� � ���������� � ������

	write_arr(filename, rand_arr, size);//���������� ������ � ����

	int* array_from_file = nullptr;
	int n = 0;
	read_arr(filename, array_from_file, n);//������ ������ �� �����

	delete[] rand_arr;
	delete[] array_from_file;

	return 0;
}
#pragma once
#include <iostream>

using namespace std;

template <class T> class Array
{
private:
	T* Array;
	int size;
public:

	Array() : Array(T(), 3) {}

	//главный конструктор
	Array(const T* array_p, const int size_p) : Array{ new T * [size_p] }, size{ size_p }
	{
		if (array_p)
		{
			for (int i = 0; i < size; i++)
			{
				Array[i] = array_p[i];
			}
		}
	}

	//конструктор копирования
	Array(const Array& array_p) : Array(new T* [array_p.size]), size{ array_p.size }
	{

		for (int i = 0; i < size; i++)
		{
				Array[i] = array_p.Array[i];
		}
	}

	//конструктор переноса
	Array(Array&& array_p) : Array(new T* [array_p.size]), size{ array_p.size }
	{
		Array = array_p.Array;

		array_p.Array = nullptr;
	}

	//аксессоры и модификаторы
	void set_matrix(const T* array_p, const int size_p)
	{
		delete[] Array;

		size = size_p;

		Array = new T * [size];

		if (array_p)
		{
			for (int i = 0; i < size; i++)
			{
				Array[i] = array_p[i];
			}
		}
	}

	const T* get_matrix()const
	{
		return Array;
	}

	int get_size() const
	{
		return size;
	}

	//ввывод
	void print()
	{
		cout << "\n Массив \n";
		for (int i = 0; i < size; i++)
		{
		cout << Array[i] << " ";
		}
	}


	//ищет максимальный элемент
	void max()
	{
		T max_number = Array[0];

		for (int i = 0; i < size; i++)
		{
			if (Array[i] > max_number)
			{
				max_number = Array[i];
			}
		}
		cout << "\nмаксимальное число " << max_number;
	}

	//ищет минимальный элемент
	void min()
	{
		T min_number = Array[0];

		for (int i = 0; i < size; i++)
		{
			if (Array[i] < min_number)
			{
				min_number = Array[i];
			}
		}
		cout << "\nминимальное число " << min_number;
	}

	friend istream& operator>>(istream& cin, Array array_p)
	{
		for (int i = 0; i < array_p.size; i++)
		{
			cin >> array_p.Array[i];
		}

		return cin;
	}

	friend ostream& operator<<(ostream& cout, const Array& array_p)
	{
		for (int i = 0; i < array_p.size; i++)
		{
			cout >> array_p.Array[i];
		}

		return cout;
	}

	//перегрузка оператора копирующего присваивания
	const Array& operator=(const Array& array_p)
	{
		if (&array_p != this)
		{
			delete[] array;

			array = new T * [size];

			for (int i = 0; i < size; i++)
			{
				array[i] = array_p.Array[i];
			}
		}
		return *this;
	}

	~Array()
	{
		delete[] Array;
	}
};


#pragma once
#include <iostream>
using namespace std;

template <class T> class Array
{
private:
	T* mas;
	int size;
public:
	 Array() : Array(nullptr, 3) {}
	//главный конструктор
	 template <class T> Array(const T* array_p, const int size_p);
	//конструктор копирования
	Array(const Array& array_p) : mas(new T[array_p.size]), size{ array_p.size }
	{
		if (this != array_p)
		{
			for (int i = 0; i < size; i++)
			{
				mas[i] = array_p.mas[i];
			}
		}
	}
	//конструктор переноса
	Array(Array&& array_p) : mas(new T[array_p.size]), size{ array_p.size }
	{
		if (this != array_p)
		{
			mas = array_p.mas;

			array_p.mas = nullptr;
		}
	}

	//аксессоры и модификаторы
	void set_mas(const T* array_p, const int size_p)
	{
		delete[] mas;

		size = size_p;

		mas = new T * [size];

		if (array_p)
		{
			for (int i = 0; i < size; i++)
			{
				mas[i] = array_p[i];
			}
		}
	}
	const T* get_mas()const
	{
		return mas;
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
		cout << mas[i] << " ";
		}
	}
	//ищет максимальный элемент
	void max()
	{
		T max_number = mas[0];

		for (int i = 0; i < size; i++)
		{
			if (mas[i] > max_number)
			{
				max_number = mas[i];
			}
		}
		
		cout << "\nмаксимальное число " << max_number;
	}
	//ищет минимальный элемент
	void min()
	{
		T min_number = mas[0];

		for (int i = 0; i < size; i++)
		{
			if (mas[i] < min_number)
			{
				min_number = mas[i];
			}
		}
		cout << "\nминимальное число " << min_number;
	}

	friend istream& operator>>(istream& cin, Array array_p)
	{
		cin >> array_p.mas;

		return cin;
	}
	friend ostream& operator<<(ostream& cout, const Array& array_p)
	{
		for (int i = 0; i < array_p.size; i++)
		{
			cout >> array_p.mas[i];
		}

		return cout;
	}
	//перегрузка оператора копирующего присваивания
	const Array& operator=(const Array& array_p)
	{
		if (&array_p != this)
		{
			delete[] mas;

			mas = new T * [size];

			for (int i = 0; i < size; i++)
			{
				mas[i] = array_p.mas[i];
			}
		}
		return *this;
	}
	
	~Array()
	{
		delete[] mas;
	}
};
#include "array.inl"
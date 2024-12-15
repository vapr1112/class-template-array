#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template <class T> class Array
{
private:
	T* mas;
	int size;
public:
	Array() : Array(nullptr, 0) {}
	//������� �����������
	Array(const T* array_p, const int size_p);

	//����������� �����������
	Array(const Array& array_p);
	//����������� ��������
	Array(Array&& array_p);

	//��������� � ������������
	void set_mas(const T* array_p, const int size_p);

	const T* get_mas()const{return mas;}
	int get_size() const{return size;}

	//������
	void print();
	//���� ������������ �������
	void max();

	//���� ����������� �������
	void min();

	void find(T element);

	void add(T element);

	void del();

	template <typename T> friend istream& operator>>(istream& cin, Array<T> array_p);

	template <typename T> friend ostream& operator<<(ostream& cout, const Array<T>& array_p);

	//���������� ��������� ����������� ������������

	template<typename T> const Array<T>& operator=(const Array<T>& array_p)
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
	Array&& operator=(Array&& array_p)
{
	if (this != array_p)
	{
		delete[] mas;
		
		size = array_p.size;

		mas = new T[size];

		mas = array_p.mas;

		mas = array_p.mas;

		array_p.mas = nullptr;

		array_p.size = 0;
	}
	return *this;
}

	template <typename T> T* operator[](const int indx)
	{
		assert(indx > 0 && indx < size && "\n ������������ ������ \n");
		return mas[indx];
	}

	T* operator[](const int indx)const
	{
		assert(indx > 0 && indx < size && "\n ������������ ������ \n");
		return mas[indx];
	}

	~Array(){delete[] mas;}
};
#include "header.inl"


#pragma once
#include <iostream>
#include <cassert>
#include <string.h>

using namespace std;

template <class T> class Array
{
private:
	T* mas;
	int size;
public:
	Array() : Array(nullptr, 0) {}
	//главный конструктор
	Array(const T* array_p, const int size_p);
	//конструктор копирования
	Array(const Array& array_p);
	//конструктор переноса
	Array(Array&& array_p);

	//аксессоры и модификаторы
	void set_mas(const T* array_p, const int size_p);
	const T* get_mas()const{return mas;}
	int get_size() const{return size;}

	//ввывод
	void print();
	//ищет максимальный элемент
	void max();
	//ищет минимальный элемент
	void min();
	//поиск элемента
	void find(T element);
	void add(T element);
	void del();
	void copy(Array<T>& array_p);

	template <typename T> friend istream& operator>>(istream& cin, Array<T> array_p);
	template <typename T> friend ostream& operator<<(ostream& cout, const Array<T>& array_p);

	//перегрузка оператора копирующего присваивания
	const Array<T>& operator=(const Array<T>& array_p);
	//перегрузка оператора перемещающего присваивания
	Array<T>&& operator=(Array<T>&& array_p);

	T* operator[](const int indx);
	T* operator[](const int indx)const;

	~Array(){delete[] mas;}
};

#include "spec_template.inl"

#include "header.inl"
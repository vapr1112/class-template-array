#pragma once
#include <iostream>
#include <cassert>
#include <string.h>
#include <exception>
#include "empty_mas.h"

using namespace std;

template <class T> class Array
{
private:
	T* mas;
	size_t size;
public:
	Array()noexcept : Array(nullptr, 0) {}
	//������� �����������
	Array(const T* array_p, const size_t size_p)noexcept;
	//����������� �����������
	Array(const Array& array_p)noexcept;
	//����������� ��������
	Array(Array&& array_p)noexcept;

	//��������� � ������������
	void set_mas(const T* array_p, const size_t size_p);
	const T* get_mas()const noexcept {return mas;}
	int get_size() const noexcept{return size;}

	//������
	void print() const noexcept;
	//���� ������������ �������
	void max();
	//���� ����������� �������
	void min();
	//����� ��������
	bool find(T element);
	void add(T element)noexcept;
	void del();
	void copy(Array<T>& array_p);

	template <typename T> friend istream& operator>>(istream& cin, Array<T> array_p)noexcept;
	template <typename T> friend ostream& operator<<(ostream& cout, const Array<T>& array_p)noexcept;

	//���������� ��������� ����������� ������������
	const Array<T>& operator=(const Array<T>& array_p)noexcept;
	//���������� ��������� ������������� ������������
	Array<T>&& operator=(Array<T>&& array_p)noexcept;

	T* operator[](const int indx);
	T* operator[](const int indx)const;

	~Array(){delete[] mas;}
};

#include "spec_template.inl"

#include "header.inl"
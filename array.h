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
	//����� ��������
	void find(T element);
	void add(T element);
	void del();
	void copy(Array<T>& array_p);

	template <typename T> friend istream& operator>>(istream& cin, Array<T> array_p);
	template <typename T> friend ostream& operator<<(ostream& cout, const Array<T>& array_p);

	//���������� ��������� ����������� ������������
	const Array<T>& operator=(const Array<T>& array_p);
	//���������� ��������� ������������� ������������
	Array<T>&& operator=(Array<T>&& array_p);

	T* operator[](const int indx);
	T* operator[](const int indx)const;

	~Array(){delete[] mas;}
};

#include "spec_template.inl"

#include "header.inl"
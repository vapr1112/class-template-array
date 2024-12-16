template <class T> Array<T>::Array(const T* array_p, const int size_p) : mas{ new T[size_p] }, size{ size_p }
{
	if (array_p)
	{
		for (int i = 0; i < size; i++)
		{
			mas[i] = array_p[i];
		}
	}
}

template <class T> Array<T>::Array(const Array& array_p) : mas(new T[array_p.size]), size{ array_p.size }
{
	if (this != array_p)
	{
		for (int i = 0; i < size; i++)
		{
			mas[i] = array_p.mas[i];
		}
	}
}

template <class T> Array<T>::Array(Array&& array_p) : mas(new T[array_p.size]), size{ array_p.size }
{
	if (this != array_p)
	{
		mas = array_p.mas;

		array_p.mas = nullptr;
	}
}

template <class T> void Array<T>::set_mas(const T* array_p, const int size_p)
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

template <class T> void Array<T>::print()
{
	cout << "\n ������ \n";
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
}

//���� ������������ �������
template <class T> void Array<T>::max()
{
	T max_number = mas[0];

	for (int i = 0; i < size; i++)
	{
		if (mas[i] > max_number)
		{
			max_number = mas[i];
		}
	}

	cout << "\n������������ ����� " << max_number;
}

//���� ����������� �������
template <class T> void Array<T>::min()
{
	T min_number = mas[0];

	for (int i = 0; i < size; i++)
	{
		if (mas[i] < min_number)
		{
			min_number = mas[i];
		}
	}
	cout << "\n����������� ����� " << min_number;
}

//���� ��������
template <class T> void Array<T>::find(T element)
{
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == element)
		{
			cout << "\n ������� ������\n";
			return;
		}
	}
	cout << "\n������� �� ������\n";
}

//��������� ������� � ����� �������
template <class T> void Array<T>::add(T element)
{	
	T* new_mas = new T[++size];

	for (int i = 0; i < size - 1; i++)
	{
		new_mas[i] = mas[i];
	}

	new_mas[size - 1] = element;

	delete[] mas;

	mas = new_mas;
}

//������� ������� �� ����� �������
template <class T> void Array<T>::del()
{
	T* new_mas = new T[--size];

	for (int i = 0; i < size; i++)
	{
		new_mas[i] = mas[i];
	}

	delete[] mas;

	mas = new_mas;
}

//�������� ������
template <class T> void Array<T>::copy(Array<T>& array_p)
{
	size = array_p.size;
	for (int i = 0; i < size; i++)
	{
		mas[i] = array_p.mas[i];
	}
}

template <typename T> istream& operator>>(istream& cin, Array<T> array_p)
{
	cin >> array_p.mas;

	return cin;
}

template <typename T> ostream& operator<<(ostream& cout, const Array<T>& array_p)
{
	for (int i = 0; i < array_p.size; i++)
	{
		cout << array_p.mas[i] << " ";
	}

	return cout;
}

template<typename T> const Array<T>& Array<T>:: operator=(const Array<T>& array_p)
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
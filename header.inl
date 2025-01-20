template <class T> Array<T>::Array(const T* array_p, const size_t size_p)noexcept : mas{ new T[size_p] }, size{ size_p }
{
	if (array_p)
	{
		for (int i = 0; i < size; i++)
		{
			mas[i] = array_p[i];
		}
	}
}

template <class T> Array<T>::Array(const Array& array_p)noexcept : mas(new T[array_p.size]), size{ array_p.size }
{
	if (this != array_p)
	{
		for (int i = 0; i < size; i++)
		{
			mas[i] = array_p.mas[i];
		}
	}
}

template <class T> Array<T>::Array(Array&& array_p)noexcept : mas(new T[array_p.size]), size{ array_p.size }
{
	if (this != array_p)
	{
		mas = array_p.mas;

		array_p.mas = nullptr;
		array_p.size = 0;
	}
}

template <class T> void Array<T>::set_mas(const T* array_p, const size_t size_p)
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

template <class T> void Array<T>::print()const noexcept
{
	cout << "\n Массив \n";
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
}

//ищет максимальный элемент
template <class T> void Array<T>::max()
{
	if (size = 0) throw empty_mas("массив пуст");
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
template <class T> void Array<T>::min()
{
	if (size = 0) throw empty_mas("массив пуст");
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

//ищет элеммент
template <class T> bool Array<T>::find(T element)
{
	if (size = 0) throw empty_mas("массив пуст");
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == element)
		{
			return 1;
		}
	}
	return 0;
}

//добавляет эдемент в конец массива
template <class T> void Array<T>::add(T element)noexcept
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

//удаляет элемент из конца массива
template <class T> void Array<T>::del()
{
	if (size = 0) throw empty_mas("массив пуст");
	T* new_mas = new T[--size];

	for (int i = 0; i < size; i++)
	{
		new_mas[i] = mas[i];
	}

	delete[] mas;

	mas = new_mas;
}

//копирует объект
template <class T> void Array<T>::copy(Array<T>& array_p)
{
	if (array_p.size = 0) throw empty_mas("массив пуст");
	size = array_p.size;
	for (int i = 0; i < size; i++)
	{
		mas[i] = array_p.mas[i];
	}
}

//перегрузка операторов
template <typename T> istream& operator>>(istream& cin, Array<T> array_p)noexcept
{
	for (size_t i = 0; i < size; i++)
	{
		cin >> array_p.mas;
	}

	return cin;
}

template <typename T> ostream& operator<<(ostream& cout, const Array<T>& array_p)noexcept
{
	for (int i = 0; i < array_p.size; i++)
	{
		cout << array_p.mas[i] << " ";
	}

	return cout;
}

template<typename T> const Array<T>& Array<T>:: operator=(const Array<T>& array_p)noexcept
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

template<typename T> Array<T>&& Array<T>:: operator=(Array<T>&& array_p) noexcept
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

template<typename T> T* Array<T>:: operator[](const int indx)
{
	if (indx < 0 || indx > size) throw out_of_range("недопустимый индекс");
	return mas[indx];
}

template<typename T> T* Array<T>:: operator[](const int indx)const
{
	if (indx < 0 || indx > size) throw out_of_range("недопустимый индекс");
	return mas[indx];
}
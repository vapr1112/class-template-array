//специальная перегрузка типа данных string
template <> class Array<string>
{
private:
	string mas;
	size_t size;

public:
	Array()noexcept : Array(nullptr, 0) {}

	Array(string mas_p, const size_t size_p)noexcept : mas{ mas_p }, size{ size_p }{}

	void print()const noexcept
	{
		cout << mas;
	}


	//ищет подстроку
	bool find(string under_str)
	{
		if (size = 0) throw empty_mas("массив пуст");

		if (mas.find(under_str) != string::npos)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void max() = delete;

	void min() = delete;
	void add(string str)noexcept{mas.append(str);}

	void del(size_t pos)
	{
		if (mas.empty()) throw empty_mas("массив пуст");
		mas.erase(pos);
	}

	void copy(string str)
	{
		if (mas.empty()) throw empty_mas("массив пуст");
		mas = str;
	}

	const Array& operator=(const Array& array_p)noexcept
	{
		mas = array_p.mas;
	}
};


//специальная перегрузка типа данных char*
template <> class Array<char*>
{
private:
	char** mas;
	int size;//количество строк

public:

	Array()noexcept : Array(nullptr, 0) {}

	Array(const char** mas_p, const int size_p)noexcept : mas{ new char* [size_p] }, size{ size_p }
	{
		if (mas_p)
		{
			for (int i = 0; i < size; i++)
			{
				mas[i] = new char[strlen(mas_p[i] + 1)];
				strcpy_s(mas[i], strlen(mas_p[i] + 1), mas_p[i]);
			}
		}
	}

	Array(const Array& mas_p)noexcept : mas(new char* [mas_p.size]), size{ mas_p.size }
	{

		for (int i = 0; i < size; i++)
		{
			mas[i] = new char[strlen(mas_p.mas[i] + 1)];
			strcpy_s(mas[i], strlen(mas_p.mas[i] + 1), mas_p.mas[i]);
		}
	}

	Array(Array&& mas_p)noexcept : mas(new char* [mas_p.size]), size{ mas_p.size }
	{
		for (int i = 0; i < size; i++)
		{
			delete[] mas[i];
		}

		delete[] mas;

		mas = mas_p.mas;

		mas_p.mas = nullptr;
		mas_p.size = 0;
	}

	void set_matrix(const char** mas_p, const int size_p)noexcept
	{

		for (int i = 0; i < size; i++)
		{
			delete[] mas[i];
		}

		delete[] mas;

		size = size_p;

		mas = new char* [size];

		for (int i = 0; i < size; i++)
		{
			mas[i] = new char[strlen(mas_p[i]) + 1];
			strcpy_s(mas[i], strlen(mas_p[i]) + 1, mas_p[i]);
		}
	}

	void print()const noexcept
	{
		for (int i = 0; i < size; i++)
		{
			puts(mas[i]);
			cout << " ";
		}
	}

	void max() = delete;

	void min() = delete;

	//ищет подстроку
	void find(char* str)
	{
		if (size == 0) throw empty_mas("массив пуст");
		for (int i = 0; i < size; i++)
		{
			if (strstr(mas[i], str) != 0)
			{
				cout << "\nподстрока найдена\n";
				return;
			}
		}
		cout << "\nстрока не найдена\n";
	}

	//добавляет в конец строку в массив строк
	void add(char* str)noexcept
	{

		char** new_str = new char* [++size];

		for (int i = 0; i < size - 1; i++)
		{
			new_str[i] = new char[strlen(mas[i]) + 1];
			strcpy_s(new_str[i], strlen(mas[i]) + 1, mas[i]);
		}

		new_str[size - 1] = new char[strlen(str) + 1];
		strcpy_s(new_str[size - 1], strlen(str) + 1, str);

		if (size != 1)
		{
			for (int i = 0; i < size - 1; i++)
			{
				delete[] mas[i];
			}

			delete[] mas;
		}

		mas = new_str;
	}
	//удаляет последнюю строку из массива строк
	void del()
	{
		if (size == 0) throw empty_mas("массив пуст");
		char** new_mas = new char* [--size];

		for (int i = 0; i < size; i++)
		{
			new_mas[i] = new char[strlen(mas[i]) + 1];
			strcpy_s(new_mas[i], strlen(mas[i]) + 1, mas[i]);
		}

		if (size != 0)
		{
			for (int i = 0; i < size + 1; i++)
			{
				delete[] mas[i];
			}

			delete[] mas;
		}

		mas = new_mas;
	}

	void copy(char** mas_p)
	{
		if (size == 0) throw empty_mas("массив пуст");
		if (mas_p)
		{
			for (int i = 0; i < size; i++)
			{
				mas[i] = new char[strlen(mas_p[i]) + 1];
				strcpy_s(mas[i], strlen(mas_p[i] + 1), mas_p[i]);
			}
		}
	}

	const Array& operator=(const Array& array_p)noexcept
	{
		for (int i = 0; i < size; i++)
		{
			mas[i] = new char[strlen(array_p.mas[i]) + 1];
			strcpy_s(mas[i], strlen(array_p.mas[i] + 1), array_p.mas[i]);
		}
	}
};
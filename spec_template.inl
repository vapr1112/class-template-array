//специальная перегрузка типа данных string
template <> class Array<string>
{
private:
	string mas;
	size_t size;

public:
	void print()
	{
		cout << mas;
	}

	void find(string under_str)
	{
		if (mas.find(under_str) != string::npos)
		{
			cout << "\nподстрока найдена\n";
		}
		else
		{
			cout << "\nподстрока не найдена\n";
		}
	}

	void add(string str)
	{
		mas.append(str);
	}

	void del(size_t pos)
	{
		mas.erase(pos);
	}

	void copy(string str)
	{
		mas = str;
	}
};


//специальная перегрузка типа данных char*
template <> class Array<char*>
{
private:
	char** mas;
	int size;//количество строк

public:

	Array() : Array(nullptr, 0) {}

	Array(const char** mas_p, const int size_p) : mas{ new char* [size_p] }, size{ size_p }
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

	Array(const Array& mas_p) : mas(new char* [mas_p.size]), size{ mas_p.size }
	{

		for (int i = 0; i < size; i++)
		{
			mas[i] = new char[strlen(mas_p.mas[i] + 1)];
			strcpy_s(mas[i], strlen(mas_p.mas[i] + 1), mas_p.mas[i]);
		}
	}

	Array(Array&& mas_p) : mas(new char* [mas_p.size]), size{ mas_p.size }
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

	void set_matrix(const char** mas_p, const int size_p)
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

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			puts(mas[i]);
		}
	}

	void max() = delete;

	void min() = delete;

	void find(char* str)
	{
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

	void add(char* str)
	{

		char** new_mas = new char* [++size];

		for (int i = 0; i < size - 1; i++)
		{
			new_mas[i] = new char[strlen(mas[i]) + 1];
		}

		for (int i = 0; i < size - 1; i++)
		{
			strcpy_s(new_mas[i], strlen(mas[i]) + 1, mas[i]);
		}

		new_mas[size - 1] = new char[strlen(str) + 1];
		strcpy_s(new_mas[size - 1], strlen(str) + 1, str);

		if (size != 1)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] mas[i];
			}

			delete[] mas;
		}

		mas = new_mas;
	}
	void del()
	{

		char** new_mas = new char* [--size];

		for (int i = 0; i < size; i++)
		{
			new_mas[i] = new char[strlen(mas[i]) + 1];
			strcpy_s(new_mas[i], strlen(mas[i] + 1), mas[i]);
		}

		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] mas[i];
			}

			delete[] mas;
		}

		mas = new_mas;
	}

	void copy(char** mas_p)
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
};
#include "array.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int user;

	Array <int> mas;

	enum menu {MAX = 1, MIN, SEARCH, ADD, DELETE, COPY};

	do
	{
		cout << "введите \n1 максимальное число \n2 минимальное число \n3 поиск числа \n4 добавить элемент \n5 удалить элемент \n6 скопировать\n";

		cin >> user;

		switch (user)
		{
		case MAX:
			mas.max();
			break;
		case MIN:
			mas.min();
			break;

		default:
			break;
		}

	} while (user != 0);

	return 0;
}

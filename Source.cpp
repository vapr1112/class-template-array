#include "array.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int user, value;

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
		case SEARCH:
			cout << mas; 

			cout << "\nвведите значение, которое хотите найти\n";
			cin >> value;

			mas.find(value);
			break;
		case ADD:
			cout << "\nвведите значение\n";
			cin >> value;
			mas.add(value);
		default:
			break;
		}

	} while (user != 0);

	return 0;
}
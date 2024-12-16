#include "array.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int user, value;

	Array <int> mas, mas_2;

	Array<char*> mas_3;

	char buf[100];

	enum menu {MAX = 1, MIN, SEARCH, ADD, DELETE, COPY};

	do
	{
		cout << "введите \n1 максимальное число \n2 минимальное число \n3 поиск числа \n4 добавить элемент \n5 удалить элемент \n6 скопировать\n";

		cin >> user;

		cin.ignore();

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
//			cin >> value;
			gets_s(buf);
//			mas.find(value);
			mas_3.find(buf);
			break;
		case ADD:
			cout << "\nвведите значение\n";
//			cin >> value;
			gets_s(buf);
			//mas.add(value);
			mas_3.add(buf);
			break;
		case DELETE:
			//mas.del();
			mas_3.del();
			break;
		case COPY:
			mas_2.copy(mas);
			cout << mas_2;
			break;
		default:
			break;
		}

		mas_3.print();

	} while (user != 0);

	return 0;
}
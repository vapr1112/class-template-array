#include "array.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int user;

	Array <int> mas;

	enum menu {MAX = 1, MIN, SEARCH, ADD, DELETE, COPY};

	do
	{
		cout << "������� \n1 ������������ ����� \n2 ����������� ����� \n3 ����� ����� \n4 �������� ������� \n5 ������� ������� \n6 �����������\n";

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

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
		cout << "������� \n1 ������������ ����� \n2 ����������� ����� \n3 ����� ����� \n4 �������� ������� \n5 ������� ������� \n6 �����������\n";

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

			cout << "\n������� ��������, ������� ������ �����\n";
//			cin >> value;
			gets_s(buf);
//			mas.find(value);
			mas_3.find(buf);
			break;
		case ADD:
			cout << "\n������� ��������\n";
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
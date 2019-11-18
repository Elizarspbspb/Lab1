#include "Function.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

ARRAY::ARRAY() {
	cout << "Введите " << NARR << " записей:" << endl << endl;
	aero = new Aeroflot[NARR];
	cout << "\tСписок создан." << endl;
}

ARRAY::ARRAY(int d)
{
	i = d;
	cout << "Введите " << d << " записей:" << endl << endl;
	aero = new Aeroflot[d];
	cout << "\tСписок создан." << endl;
	cout << "\tСписок по умолчанию создан." << endl;
}

ARRAY::~ARRAY() {
	delete aero;
	cout << "Список удалён." << endl;
}

void ARRAY::sort()
{
	int n1, n2, n3, j = 0, k = 0;
	string n4;
	string n5;
	for (j = 0; j < (NARR - 1); ++j)
	{
		for (k = j + 1; k < NARR; ++k)
		{
			n1 = aero[j].get_number();
			n2 = aero[k].get_number();
			if (n1 > n2)
			{
				n3 = aero[j].get_number();
				aero[j].set_number(aero[k].get_number());
				aero[k].set_number(n3);

				n4 = aero[j].get_name();
				aero[j].set_name(aero[k].get_name());
				aero[k].set_name(n4);

				n5 = aero[j].get_plane();
				aero[j].set_plane(aero[k].get_plane());
				aero[k].set_plane(n5);
			}
		}
	}
	cout << "Сортировка завершена" << endl;
}

int ARRAY::proverka1(int k)
{

	int j = 0, i = 0, flag = 0;
	for (i = 0; i < NARR; i++)
	{
		if (aero[i].get_number() == k)
		{
			return 1;
		}
	}
	return 0;
}

int ARRAY::redact(int red, int red2)
{
	int i = 0, flag = 0;
	if (proverka1(red2) == 1)
	{
		throw exception("name reading exception");   //переходим в класс Exception, для обработки ошибки
	}
	cin >> aero[red];
	cout << "Запись рейса произошла успешно." << endl;
	return 0;
}

void ARRAY::show()
{
	cout << "Номер рейса | Направление | Тип самолета" << endl;
	for (unsigned i = 0; i < NARR; i++)
	{
		cout << aero[i] << endl;
	}
}

void ARRAY::search()
{
	cout << "Введите место направления" << endl;
	string name;
	cin >> name;
	int i;
	bool flag = true;
	for (i = 0; i < NARR; ++i)
	{
		if (aero[i].get_name() == name)
		{
			cout << aero[i] << '\n';
			flag = false;
		}
	}
	if (flag == true)
		throw ERROR_400;
}